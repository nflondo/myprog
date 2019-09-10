package main

import "fmt"

// fibonacci is a function that returns a function that returns an int.
func fibonacci() func() int {
//	x1 := 0
//	x2 := 1
	x1, x2 := 0, 1
	return func() int {
		y := x1
//		x1 = x2
//		x2 = x2 + y
		x1, x2 = x2, x2 + y
		return y		
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}
