package main

import (
	"fmt"
)

func main() {
	// ex 2
	num := 8
	if num > 5 && num < 10 {
		fmt.Println("Number is greater than 5 but less than 10")
	} else {
		fmt.Println("Did not pass the test")
	}
	// ex3
	for i := 0; i < 20; i++ {
		fmt.Printf("\nValue of i: %d", i)
	}
}
