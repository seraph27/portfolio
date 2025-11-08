import type { IconMap, SocialLink, Site } from '@/types'

export const SITE: Site = {
  title: 'seraph',
  description:
    'give me a github star. right now.',
  href: 'https://seraph.tw',
  author: 'seraph',
  locale: 'en-US',
  featuredPostCount: 3,
  postsPerPage: 5,
}

export const NAV_LINKS: SocialLink[] = [
  {
    href: '/about',
    label: 'about',
  },
  {
    href: '/work',
    label: 'work',
  },
  {
    href: '/projects',
    label: 'projects',
  },
  // {
  //   href: '/playground',
  //   label: 'playground',
  // },
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
