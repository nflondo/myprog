package main

import "fmt"

func call_me_again(count int) int {

	if count >= 10 {
		fmt.Printf("Reached full count: %d\n", count)
		return count
	}
	fmt.Printf("hey, I was called! count: %d\n", count)
	count = count + 1
	return call_me_again(count)
}

func main() {
	call_me_again(0)
}
