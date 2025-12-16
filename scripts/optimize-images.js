/**
 * Image Optimization Script
 * Creates optimized WebP copies of large images without replacing originals.
 * 
 * Usage: node scripts/optimize-images.js
 * 
 * - Finds all images > 500KB in src/content/blog
 * - Creates .webp versions with same name (e.g., image.png → image.webp)
 * - Keeps original files untouched
 * - Target: ~200KB or less while maintaining visual quality
 */

import { readdir, stat, mkdir } from 'fs/promises'
import { join, extname, basename, dirname } from 'path'
import { fileURLToPath } from 'url'
import sharp from 'sharp'

const __dirname = dirname(fileURLToPath(import.meta.url))
const BLOG_DIR = join(__dirname, '..', 'src', 'content', 'blog')
const SIZE_THRESHOLD = 500 * 1024 // 500KB
const MAX_WIDTH = 1600 // Max width for blog images
const WEBP_QUALITY = 82 // Good balance of quality/size

const IMAGE_EXTENSIONS = ['.png', '.jpg', '.jpeg']

async function findLargeImages(dir) {
  const largeImages = []
  
  async function scan(currentDir) {
    const entries = await readdir(currentDir, { withFileTypes: true })
    
    for (const entry of entries) {
      const fullPath = join(currentDir, entry.name)
      
      if (entry.isDirectory()) {
        await scan(fullPath)
      } else if (entry.isFile()) {
        const ext = extname(entry.name).toLowerCase()
        if (IMAGE_EXTENSIONS.includes(ext)) {
          const stats = await stat(fullPath)
          if (stats.size > SIZE_THRESHOLD) {
            largeImages.push({
              path: fullPath,
              size: stats.size,
              name: entry.name
            })
          }
        }
      }
    }
  }
  
  await scan(dir)
  return largeImages
}

function formatSize(bytes) {
  if (bytes < 1024) return `${bytes} B`
  if (bytes < 1024 * 1024) return `${(bytes / 1024).toFixed(1)} KB`
  return `${(bytes / (1024 * 1024)).toFixed(2)} MB`
}

async function optimizeImage(imagePath) {
  const dir = dirname(imagePath)
  const name = basename(imagePath, extname(imagePath))
  const outputPath = join(dir, `${name}.webp`)
  
  try {
    const image = sharp(imagePath)
    const metadata = await image.metadata()
    
    // Resize if wider than MAX_WIDTH, maintaining aspect ratio
    const resizeOptions = metadata.width > MAX_WIDTH 
      ? { width: MAX_WIDTH, withoutEnlargement: true }
      : {}
    
    await image
      .resize(resizeOptions)
      .webp({ quality: WEBP_QUALITY, effort: 6 })
      .toFile(outputPath)
    
    const outputStats = await stat(outputPath)
    return { outputPath, outputSize: outputStats.size }
  } catch (error) {
    console.error(`  ❌ Failed to optimize: ${error.message}`)
    return null
  }
}

async function main() {
  console.log('🔍 Scanning for large images (> 500KB)...\n')
  
  const largeImages = await findLargeImages(BLOG_DIR)
  
  if (largeImages.length === 0) {
    console.log('✅ No large images found!')
    return
  }
  
  console.log(`Found ${largeImages.length} large images:\n`)
  
  let totalOriginal = 0
  let totalOptimized = 0
  
  for (const img of largeImages) {
    const relativePath = img.path.replace(BLOG_DIR, 'src/content/blog')
    console.log(`📷 ${relativePath}`)
    console.log(`   Original: ${formatSize(img.size)}`)
    
    const result = await optimizeImage(img.path)
    
    if (result) {
      const savings = ((1 - result.outputSize / img.size) * 100).toFixed(1)
      console.log(`   WebP:     ${formatSize(result.outputSize)} (${savings}% smaller)`)
      totalOriginal += img.size
      totalOptimized += result.outputSize
    }
    console.log()
  }
  
  console.log('─'.repeat(50))
  console.log(`📊 Summary:`)
  console.log(`   Original total: ${formatSize(totalOriginal)}`)
  console.log(`   Optimized total: ${formatSize(totalOptimized)}`)
  console.log(`   Total savings: ${formatSize(totalOriginal - totalOptimized)} (${((1 - totalOptimized / totalOriginal) * 100).toFixed(1)}%)`)
  console.log()
  console.log('✅ Done! WebP files created alongside originals.')
  console.log('💡 Update your frontmatter to use .webp versions for best performance.')
}

main().catch(console.error)

