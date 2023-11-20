<script setup lang="ts">
import { ref } from 'vue'
defineProps({
	title: String
})


const counter = ref(0)
</script>

<template>
  
  <button @click="counter++">
	{{ title }}
    {{ counter }}
  </button>
</template>
