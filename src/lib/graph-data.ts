export interface NodeInfo {
  id: number
  label: string
  title: string
  description: string
  content: string[]
}

export const nodeData: NodeInfo[] = [
  {
    id: 0,
    label: 'tech\nstack',
    title: 'Tech Stack',
    description: 'Languages and tools I work with',
    content: ['C++ - 4/10', 'Python - 2/10', 'TypeScript - 1.5/10'],
  },
  {
    id: 1,
    label: 'currently\nreading',
    title: 'Currently Reading',
    description: 'Operating Systems: Three Easy Pieces',
    content: [
      'by Remzi H. Arpaci-Dusseau',
      'Virtualization, concurrency, and persistence',
    ],
  },
  {
    id: 2,
    label: 'music',
    title: 'Last Played',
    description: "Music I'm currently listening to",
    content: ['YouTube Music integration coming soon'],
  },
  {
    id: 3,
    label: 'piano',
    title: 'Favorite Piano Piece',
    description: 'Chopin - Prelude No. 11',
    content: ['Op. 28 No. 11 in B major', 'Audio preview coming soon'],
  },
  {
    id: 4,
    label: 'projects',
    title: 'Current Projects',
    description: "What I'm working on",
    content: [
      'Portfolio website with interactive features',
      'CP dashboard for competitive programming',
      'Exploring LLM applications',
    ],
  },
  {
    id: 5,
    label: 'interests',
    title: 'Interests',
    description: 'Things I enjoy',
    content: [
      'Competitive programming and algorithms',
      'Machine learning and AI',
      'Piano and classical music',
    ],
  },
]

export const edgeData = [
  { source: 0, target: 4 },
  { source: 0, target: 5 },
  { source: 1, target: 5 },
  { source: 2, target: 3 },
  { source: 3, target: 5 },
  { source: 4, target: 5 },
]
