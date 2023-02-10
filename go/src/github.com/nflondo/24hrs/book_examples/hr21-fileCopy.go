package main

import (
	"io"
	"log"
	"os"
)

func main() {
	// read file from disk
	from, err := os.Open("./example03.txt")
	if err != nil {
		log.Fatal(err)
	}
	// close file at end of program
	defer from.Close()
	// Open or create file (name, flags, permissions)
	to, err := os.OpenFile("./example03.copy.txt", os.O_RDWR|os.O_CREATE, 0666)
	if err != nil {
		log.Fatal(err)
	}
	// close this file after other execution has finished
	defer to.Close()
	// copy from source file to destination
	_, err = io.Copy(to, from)
	if err != nil {
		log.Fatal(err)
	}
}