---
layout: doc
---

<script setup>
import {
  VPTeamPage,
  VPTeamPageTitle,
  VPTeamMembers
} from 'vitepress/theme'

const members = [
  {
    avatar: 'https://www.github.com/yyx990803.png',
    name: 'Abstract Algebra',
    title: 'Part I',
    links: [
      { icon: 'github', link: 'https://github.com/yyx990803' },
      { icon: 'twitter', link: 'https://twitter.com/youyuxi' }
    ]
  },
]
</script>

<VPTeamPageTitle>
    <template #title>
        Available courses
    </template>
    <template #lead>
        There will be updates as time goes by
    </template>
</VPTeamPageTitle>

- [Abstract Algebra 1](algebra-1)
- [Computer Programming 1]()
- [Calculus 1]()
- [Linear Algebra and Geometry 1]()
- [Physics 1]()

