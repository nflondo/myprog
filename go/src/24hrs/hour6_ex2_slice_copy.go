package main

import "fmt"

func main() {
	colors := []string{"blue", "green", "red", "yello"}
	fmt.Printf("Initial slice: %v\n", colors)
	sub_colors := make([]string, 2)
	copy(sub_colors, colors[2:])
	fmt.Printf("Sub_colors slice: %v\n", sub_colors)
}
