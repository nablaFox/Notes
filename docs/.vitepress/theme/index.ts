// https://vitepress.dev/guide/custom-theme
import { h } from 'vue'
import type { Theme } from 'vitepress'
import DefaultTheme from 'vitepress/theme'
import './style.css'

const components = []
const modules = import.meta.glob('./components/*.vue', { eager: true })

for (const path in modules) {
	components.push(modules[path].default)
}

export default {
  extends: DefaultTheme,
  Layout: () => {
    return h(DefaultTheme.Layout, null, {
      // https://vitepress.dev/guide/extending-default-theme#layout-slots
    })
  },
  enhanceApp({ app, router, siteData }) {
    components.forEach(component => {
		  app.component(component.__name, component)
	  })
  }
} satisfies Theme
