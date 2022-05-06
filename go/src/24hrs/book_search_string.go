package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(strings.Index("surface", "face"))
	fmt.Println(strings.Index("moon", "aer"))
	fmt.Println(strings.TrimSpace("    I don't need all    the space   ")) //trims leading and trailing whitespace
}
