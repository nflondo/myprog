package main

import (
	"io/ioutil"
	"log"
)

func main() {
	s := "Hello World"
	//have to convert the string into a slice of bytes in order to writeFile
	err := ioutil.WriteFile("example03.txt", []byte(s), 0644)
	if err != nil {
		log.Fatal(err)
	}

}