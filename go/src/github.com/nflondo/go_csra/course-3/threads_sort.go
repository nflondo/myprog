/* Write a program to sort an array of integers. The program should partition
the array into 4 parts, each of which is sorted by a different goroutine. Each
partition should be of approximately equal size. Then the main goroutine should
merge the 4 sorted subarrays into one large sorted array.
The program should prompt the user to input a series of integers. Each goroutine
 which sorts ¼ of the array should print the subarray that it will sort. When
 sorting is complete, the main goroutine should print the entire sorted list.
*/
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
	"sync"
)

//swap the contents of the slice in position i with the contents in position i+1
// supports BubbleSort()
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

// Modify the slice so that the elements are in sorted order
func BubbleSort(unsortedSlice []int, wg *sync.WaitGroup) {
	fmt.Printf("Will sort: %v\n", unsortedSlice)
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
	wg.Done()
}

func main() {
	var userNums []int //Declare the slice
	var finalSortedList []int
	var wg sync.WaitGroup

	fmt.Print("> ")
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()

	input := strings.Split(scanner.Text(), " ") //returns a slice separate by space
	if len(input) < 4 {
		fmt.Println("Invalid input, please enter at least 4 numbers")
	}
	for _, element := range input {
		convertedInt, err := strconv.Atoi(element)
		if err != nil {
			fmt.Println("Unable to convert to integer: ", err)
			os.Exit(1)
		}
		userNums = append(userNums, convertedInt)
	}
	fmt.Printf("Initial user list: %v\n", userNums)
	subArraysLength := len(userNums) / 4

	subArray1 := userNums[:subArraysLength]
	subArray2 := userNums[subArraysLength : subArraysLength*2]
	subArray3 := userNums[subArraysLength*2 : subArraysLength*3]
	subArray4 := userNums[subArraysLength*3:]

	wg.Add(4)
	go BubbleSort(subArray1, &wg)
	go BubbleSort(subArray2, &wg)
	go BubbleSort(subArray3, &wg)
	go BubbleSort(subArray4, &wg)
	wg.Wait()

	finalSortedList = append(subArray1, subArray2...)
	finalSortedList = append(finalSortedList, subArray3...)
	finalSortedList = append(finalSortedList, subArray4...)

	sort.Ints(finalSortedList)
	//fmt.Printf("Initial array: %v\n", userNums)
	fmt.Printf("Final sorted list: %v\n", finalSortedList)

}
