package main

import "fmt"

// the adder function returns a closure.  Each closure is bound to its 
// own sum variable
func adder() func(int) int {
	sum := 0
	return func(x int) int {
		fmt.Printf("sum:%d\n",sum)
		sum += x
		return sum
	}
}

func main() {
	pos, neg := adder(), adder()
	for i := 0; i < 10; i++ {
		fmt.Println(
			pos(i),
			neg(-2*i),
		)
	}
}
