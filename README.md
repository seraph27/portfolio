# Rex Chao's Portfolio

Personal portfolio showcasing my work in backend systems, machine learning, and competitive programming.

Built with Astro and Tailwind CSS, based on [astro-erudite](https://github.com/jktrn/astro-erudite) by [enscribe](https://enscribe.dev).

## Tech Stack

- **Astro** - Framework
- **Tailwind CSS** - Styling
- **shadcn/ui** - Components
- **MDX** - Content
- **TypeScript** - Language

## Development

```bash
npm install
npm run dev
```

Visit `http://localhost:4321`

## Build

```bash
npm run build
npm run preview
```

## Structure

```
src/
├── pages/           # Routes
│   ├── index.astro  # Home
│   ├── work.astro   # Work experience
│   └── projects.astro # Projects
├── content/
│   ├── blog/        # Blog posts (.md)
│   └── projects/    # Project entries
└── components/      # UI components
```

## Adding Content

### Blog Posts
Create `.md` files in `src/content/blog/`:
```markdown
---
title: "Post Title"
description: "Description"
date: 2025-01-15
tags: ["tag1", "tag2"]
---

Content here...
```

### Projects
Create `.md` files in `src/content/projects/`:
```markdown
---
name: "Project Name"
description: "Description"
tags: ["Python", "TypeScript"]
image: "../../../public/static/work/image.png"
link: "https://example.com"
startDate: 2025-01-01
---
```

## Contact

- Email: ychao@ucsd.edu
- GitHub: [Seraph27](https://github.com/Seraph27)
- LinkedIn: [rexchao](https://linkedin.com/in/rexchao)

## License

MIT