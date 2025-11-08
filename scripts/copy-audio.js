import fs from 'node:fs'
import path from 'node:path'
import { fileURLToPath } from 'node:url'

const __dirname = path.dirname(fileURLToPath(import.meta.url))
const contentDir = path.join(__dirname, '../src/content/blog')
const publicDir = path.join(__dirname, '../public/blog')

// Recursively find all audio files in content/blog
function findAudioFiles(dir) {
  const files = []
  const items = fs.readdirSync(dir, { withFileTypes: true })
  
  for (const item of items) {
    const fullPath = path.join(dir, item.name)
    if (item.isDirectory()) {
      files.push(...findAudioFiles(fullPath))
    } else if (item.isFile() && /\.(mp3|wav|ogg|m4a)$/i.test(item.name)) {
      files.push(fullPath)
    }
  }
  
  return files
}

// Copy audio files to public directory, maintaining structure
function copyAudioFiles() {
  console.log('🎵 Copying audio files from content to public...')
  
  const audioFiles = findAudioFiles(contentDir)
  
  if (audioFiles.length === 0) {
    console.log('No audio files found.')
    return
  }
  
  for (const audioFile of audioFiles) {
    const relativePath = path.relative(contentDir, audioFile)
    const destPath = path.join(publicDir, relativePath)
    const destDir = path.dirname(destPath)
    
    // Create destination directory if it doesn't exist
    if (!fs.existsSync(destDir)) {
      fs.mkdirSync(destDir, { recursive: true })
    }
    
    // Copy the file
    fs.copyFileSync(audioFile, destPath)
    console.log(`  ✓ Copied: ${relativePath}`)
  }
  
  console.log(`✅ Copied ${audioFiles.length} audio file(s)`)
}

copyAudioFiles()

