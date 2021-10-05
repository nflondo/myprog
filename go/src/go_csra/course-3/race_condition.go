/*Write two goroutines which have a race condition when executed concurrently.
Explain what the race condition is and how it can occur.
Submission: Upload your source code for the program along with your written
explanation of race conditions.
*/

package main

import (
	"fmt"
)

func main() {
	//create slice "starts"
	starts := []int{10, 40, 70, 100}

	for _, j := range starts {
		go func() { // make goroutine call
			// j variable gets changed outside of count function resulting
			// in race condition between range and count()
			count(j, j+20, 10) // call function count
		}(j)
	}

	fmt.Scanln() // wait for enter
}

func count(start, stop, delta int) {
	for i := start; i <= stop; i += delta {
		fmt.Println(i)
	}
}
