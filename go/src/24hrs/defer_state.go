package main

import "fmt"

func main() {
	// Defer statements execute after return or end of function
	// They get execute in reverse order they were declared
	defer fmt.Println("I am the first defer statement")
	defer fmt.Println("I am the second defer statement")
	defer fmt.Println("I am the third defer statement")
	fmt.Println("Hello World!")
}
