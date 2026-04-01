---
title: "6 Months of Startup Experience"
description: "What building at a YC startup actually feels like"
date: 2026-03-31
tags: ["Startup", "Reflection", "AI", "Engineering"]
draft: true
image: wallhaven-ly9qzq.webp
audio: "in_the_pool.opus"
audioStartTime: 15
audioVolume: 70
authors: ["seraph"]
---

## intro

Six months ago I joined [LunaBill](https://lunabill.com/) as a founding engineer straight out of UCSD. This is a brain dump of what I've learned — about startups, engineering at speed, and what "founding engineer" actually means in practice.

---

## the role

Founding engineer at a 5-person YC company means you own things end to end. There's no "that's someone else's problem." When something breaks at 2am, it's your problem. When the product needs to go in a completely new direction by Monday, you build it by Monday.

The title sounds cool. The reality is you're part PM, part infra, part ML engineer, part on-call, part customer support. It's chaotic in the best way.

---

## what we built

LunaBill automates the medical AR (accounts receivable) revenue cycle — the process hospitals and clinics go through to get paid by insurance companies. Think: submitting claims, checking eligibility, fetching portal statuses, making outbound calls to payers, filing appeals when claims get denied.

All of that, automated. The system I helped architect handles the full pipeline:

- **Claim ingestion** — intake and normalization
- **Eligibility checks** — real-time payer verification
- **Portal automation** — multi-payer portal scraping
- **Outbound voice agents** — automated calls to insurance reps
- **Smart routing** — phone book resolution and payer-specific call strategies
- **Appeal generation** — LLM-written appeal letters with denial context

The result: replaced ~$19k/month in manual labor and outbound calls.

---

## things i didn't expect

### speed is the only metric that matters early on

At big companies, there's process. PRs get reviewed, tickets get groomed, architecture gets debated. At a startup, the cadence is: does this work? ship it. The ability to move fast without breaking everything critical is a real skill. You develop a sense for what corners you can cut and what you absolutely cannot.

### the customer is always in the room

At every company I'd interned at before, engineers were shielded from customers. Here, I'd be on calls with billing directors at hospital systems, watching them use the product live. That direct feedback loop is brutal but incredibly clarifying. You stop building features you think are cool and start building what actually unblocks people.

### infra debt compounds fast

When you're moving fast, shortcuts are taken. That's fine. But you have to *know* where the debt is and have a plan. I had moments where a one-day feature ballooned into a week because of something we'd rushed 2 months earlier. Keeping a mental map of your debt is important.

### LLMs are still unreliable in production at scale

We use LLMs throughout the pipeline — classification, appeal writing, transcript analysis. Getting them to work in a demo is trivial. Getting them to be reliably correct on 27k+ real calls across diverse payer types, denial codes, and edge cases is a different problem entirely. Fine-tuning, evals, and fallback logic are not optional.

---

## what i'd tell myself 6 months ago

- **Read every line of the codebase before you touch anything.** You'll save yourself days of confusion.
- **Over-communicate with your cofounder/CEO.** They need context; don't assume they know what you're working on.
- **Learn the domain.** I had no idea what an ERA, EOB, or denial code was. Spending a week understanding the actual healthcare billing process made me 10x more effective.
- **Ship ugly, iterate fast.** Your v1 will be embarrassing. That's correct.

---

## closing

Six months in, I'm still learning. The scope of what we're building has expanded — what started as call auditing is now a full orchestration engine for the entire revenue cycle. I don't know what the next six months look like but I'm excited to find out.

If you're a student thinking about joining an early-stage startup: do it. But go in with your eyes open — it's not a resume line, it's a crash course in everything.
