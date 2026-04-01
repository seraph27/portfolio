import type { IconMap, SocialLink, Site } from '@/types'

export const SITE: Site = {
  title: 'seraph',
  description:
    'give me a github star! right now!',
  href: 'https://seraph.tw',
  author: 'seraph',
  locale: 'en-US',
  featuredPostCount: 3,
  postsPerPage: 5,
}

export const NAV_LINKS: SocialLink[] = [
  {
    href: '/blog',
    label: 'blog',
  },
  {
    href: '/work',
    label: 'work',
  },
  {
    href: '/projects',
    label: 'projects',
  },
  {
    href: '/uses',
    label: 'stack',
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
    href: 'mailto:rexchao.careers@gmail.com',
    label: 'Email',
  },
]

export const ICON_MAP: IconMap = {
  Website: 'lucide:globe',
  GitHub: 'lucide:github',
  Twitter: 'lucide:twitter',
  Email: 'lucide:mail',
}
