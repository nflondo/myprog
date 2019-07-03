package main

import "fmt"

func main() {
	var message string
	var pi float64 = 3.14
//	var pi float32 = 3.14
	isTrue := true 
	message = "Hello, world from go!\n"
	
	message2 := "Hello, world from message2!\n"
	message3 := "The answer to life is %d\n"
	answer := 42
	
	fmt.Println(message)
	fmt.Println(message2)
	fmt.Printf(message3, answer)
	fmt.Printf("Value: %.4f\n", pi)
	fmt.Printf("Boolean Value: %t\n", isTrue)
}
