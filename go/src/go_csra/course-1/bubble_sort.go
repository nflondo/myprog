/* Write a Bubble Sort program in Go. The program
should prompt the user to type in a sequence of up to 10 integers. The program
should print the integers out on one line, in sorted order, from least to
greatest. Use your favorite search tool to find a description of how the bubble
sort algorithm works.

As part of this program, you should write a
function called BubbleSort() which
takes a slice of integers as an argument and returns nothing. The BubbleSort()
function should modify the slice so that the elements are in sorted
order.

A recurring operation in the bubble sort algorithm is
the Swap operation which swaps the position of two adjacent elements in the
slice. You should write a Swap() function which performs this operation. Your Swap()
function should take two arguments, a slice of integers and an index value i which
indicates a position in the slice. The Swap() function should return nothing,
but it should swap the contents of the slice in position i with the contents in
position i+1.
Also see: https://www.bbc.co.uk/bitesize/guides/z2m3b9q/revision/2
*/
package main

import (
	"fmt"
	"os"
	"strconv"
)

// Modify the slice so that the elements are in sorted order
func BubbleSort(unsortedSlice []int) {
	//	fmt.Println("In BubbleSort()")
	i := 0
	iter := 0
	for {
		//		fmt.Printf("i: %d\n", i)
		if i+1 < len(unsortedSlice) { //end of slice plus one is the number to compare to
			if unsortedSlice[i] > unsortedSlice[i+1] { //if left num bigger than right, swap
				Swap(unsortedSlice, i)
				i++    // increase slice index
				iter++ //keep track of number of times Swap() has been called
			} else {
				i++ //increase index even if elements are not swapped
			}
		} else { //reached end of slice
			i = 0          //reset index to 0 to start iterating through slice again
			if iter == 0 { //if no Swap() was called, then we're done
				break
			} else { //reset iter flag to 0 to start over
				iter = 0
			}
		}
	}
	// fmt.Printf("Printing from BubbleSort: %v", unsortedSlice)}
}

//swap the contents of the slice in position i with the contents in position i+1
func Swap(intSlice []int, index int) {
	if intSlice[index] > intSlice[index+1] {
		temp := intSlice[index]
		// fmt.Printf("temp: %d\n", temp)
		intSlice[index] = intSlice[index+1]
		// fmt.Printf("intSlice[index]: %d\n", intSlice[index])
		intSlice[index+1] = temp
		// fmt.Printf("intSlice[index+1]: %d\n", intSlice[index+1])
	}
}

func main() {

	var userNums []int //Declare the slice
	var userInput string
	var convertedInt int
	var idx, maxInputNum = 0, 10

	for {
		if userInput == "q" || idx == maxInputNum {
			break
		}
		fmt.Println("Enter integers one at a time and press [enter], press 'q' to quit: ")
		_, err := fmt.Scan(&userInput)
		convertedInt, err = strconv.Atoi(userInput)
		if err != nil {
			fmt.Println("%e", err)
			os.Exit(1)
		}
		userNums = append(userNums, convertedInt)
		idx++
	}
	BubbleSort(userNums)
	fmt.Println(userNums)
	//	fmt.Println(sortedSlice)
}
