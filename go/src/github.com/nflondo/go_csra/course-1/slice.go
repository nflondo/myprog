/*Write a program which prompts the user to enter integers and stores the integers
in a sorted slice. The program should be written as a loop. Before entering the
loop, the program should create an empty integer slice of size (length) 3.
During each pass through the loop, the program prompts the user to enter an
integer to be added to the slice. The program adds the integer to the slice,
sorts the slice, and prints the contents of the slice in sorted order. The slice
 must grow in size to accommodate any number of integers which the user decides
 to enter. The program should only quit (exiting the loop) when the user enters
 the character ‘X’ instead of an integer.
*/
package main

import (
	"fmt"
	"sort"
	"strconv"
)

func main() {
	// Per forums, no point in creating slice of length 3, but capacity=3 is ok
	sortedSlice := make([]int, 0, 3) //make slice
	//	fmt.Printf("length of slice: %v\n", len(sortedSlice))
	var userInput string
	var i int
	//	var index = 0
	for {
		fmt.Println("Enter an integer: ")
		_, err := fmt.Scan(&userInput)
		if userInput == "X" {
			break
		}
		i, err = strconv.Atoi(userInput)
		if err == nil {
			sortedSlice = append(sortedSlice, i)
			sort.Ints(sortedSlice)
			fmt.Println(sortedSlice)
			//			fmt.Printf("length of slice: %v\n", len(sortedSlice))
		}

	}
	//	fmt.Println(sortedSlice)
}
