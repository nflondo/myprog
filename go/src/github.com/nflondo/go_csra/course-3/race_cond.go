/*
Write two goroutines which have a race condition when executed concurrently.
Explain what the race condition is and how it can occur.
Submission: Upload your source code for the program along with your written
explanation of race conditions.
--------EXPLANATION: ---------------------
add() and printInt() get executed concurrently via "go" directive.  The race
condition happens because the x variable gets printed before it gets incremented
by 1.  Ocassionally, the variable gets incremented and then printed.  The result
varies almost every time the program is run and is random, for example:
5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 7 5 5 5 5 5 5 5 5 5 5 5 5 5 7 5 7 7 7 5 7 ...
Without concurrency, the result is always the same, numbers start at 6 7 8 9 10
11 12 13 ... all the way to 95
*/
package main

import (
	"fmt"
)

func main() {
	x := 5
	for i := 0; i < 90; i++ {
		//add(&x)
		go add(&x)
		//fmt.Println(x)
		//printInt(x)
		go printInt(x)
		//time.Sleep(time.Second)
	}
	fmt.Scanln()
}

func add(x *int) {
	*x = *x + 1
}

func printInt(x int) {
	fmt.Printf("%d ", x)
}
