import type { IconMap, SocialLink, Site } from '@/types'

export const SITE: Site = {
  title: 'Rex Chao',
  description:
    'Backend/ML Systems Engineer specializing in machine learning, software development, and scalable systems.',
  href: 'https://rexchao.dev',
  author: 'Rex Chao',
  locale: 'en-US',
  featuredPostCount: 3,
  postsPerPage: 5,
}

export const NAV_LINKS: SocialLink[] = [
  {
    href: '/work',
    label: 'work',
  },
  {
    href: '/projects',
    label: 'projects',
  },
  {
    href: '/playground',
    label: 'playground',
  },
]

export const SOCIAL_LINKS: SocialLink[] = [
  {
    href: 'https://github.com/Seraph27',
    label: 'GitHub',
  },
  {
    href: 'https://linkedin.com/in/rexchao',
    label: 'LinkedIn',
  },
  {
    href: 'mailto:ychao@ucsd.edu',
    label: 'Email',
  },
  {
    href: '/resume.pdf',
    label: 'CV',
  },
]

export const ICON_MAP: IconMap = {
  Website: 'lucide:globe',
  GitHub: 'lucide:github',
  LinkedIn: 'lucide:linkedin',
  Twitter: 'lucide:twitter',
  Email: 'lucide:mail',
  CV: 'lucide:file-text',
}
