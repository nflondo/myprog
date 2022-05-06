// Function that takes two arguments and returns three
// Hour 4 ex 3, Go in 24 hrs.
package main

import "fmt"

func myOperations(x int, y int) (int, int, int) {
	sum := x + y
	mul := x * y
	div := x / y
	return sum, mul, div
}
func main() {
	sum, mul, div := myOperations(3, 3)
	fmt.Println(sum, mul, div)
}
