package main

import (
	"fmt"
	"log"
	"regexp"
)

func main() {
	// This is case sensitive
	// needle := "chocolate"

	// Make it case insensitive by adding (?i)
	needle := "(?i)chocolate"
	haystack := "Chocolate is my favorite!"
	match, err := regexp.MatchString(needle, haystack)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(match)
}