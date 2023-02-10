package main

import (
	"fmt"
	"io/ioutil"
	"log"
)

func main() {
	// ReadDir expects a dir name as a string; returns list of dir sorted by filename
	files, err := ioutil.ReadDir(".")
	if err != nil {
		log.Fatal(err)
	}

	for _, file := range files {
		fmt.Println(file.Mode(), file.Name())		
	}
}