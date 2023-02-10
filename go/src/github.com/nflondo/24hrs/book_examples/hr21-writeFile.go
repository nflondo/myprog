package main

import (
	"io/ioutil"
	"log"
)

func main() {
	// create empty slice of bytes
	b := make([]byte, 0)
	// write empty file
	err := ioutil.WriteFile("example02.txt", b, 0644)
	if err != nil {
		log.Fatal(err)
	}
}