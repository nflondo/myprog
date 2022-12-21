package main

import (
	"bytes"
	"fmt"
)

func main() {
	var mybuff bytes.Buffer //initialize empty buffer

	for i := 0; i < 500; i++ {
		mybuff.WriteString("z")
	}

	fmt.Println(mybuff.String()) //output result as a string
}
