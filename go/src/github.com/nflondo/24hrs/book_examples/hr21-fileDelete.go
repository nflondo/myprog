package main

import (
	"log"
	"os"
)

func main() {
	// no way to undo this delete, could be considered bad practice
	err := os.Remove("./deleteme.txt")
	if err != nil {
		log.Fatal(err)
	}
}