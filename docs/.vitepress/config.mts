import {defineConfig} from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
	title: "UniNotes",
	description: "Curated Knowledge",
	// base: '/Notes/',
	markdown: {
		math: true
	},
	themeConfig: {
		// https://vitepress.dev/reference/default-theme-config
		search: {
			provider: 'local'
		},
		nav: [
			{text: 'Home', link: '/'},
			{text: 'Courses', link: '/courses'}
		],

		sidebar: [
			{
				text: 'Courses',
				items: [
					{text: 'Abstract Algebra 1', link: '/Algebra-1/index'},
					{text: 'Computer Programming 1', link: '/Computer-Programming-1/index'},
				]
			}
		],

		socialLinks: [
			{icon: 'github', link: 'https://github.com/nablaFox/'}
		],
		footer: {
			copyright: 'Copyright © 2023 Antonio Farese'
		}
	}
})
