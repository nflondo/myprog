package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	fmt.Print("Enter a sequence of integers separated by a space: ")
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()

	input := strings.Split(scanner.Text(), " ")
	numArray := make([]int, 0, 1)

	for _, i := range input {
		num, err := strconv.Atoi(i)
		check(err)

		numArray = append(numArray, num)
	}

	fmt.Printf("Original: %v \n", numArray)

	BubbleSort(numArray)

	fmt.Printf("Sorted: %v \n", numArray)
}

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func BubbleSort(array []int) {

	// To prevent un-necessary iterations if array is already sorted
	swapped := false

	for i := 0; i < len(array)-1; i++ {
		for j := 0; j < len(array)-i-1; j++ {
			if array[j] > array[j+1] {
				Swap(array, j)
				swapped = true
			}
		}

		if !swapped {
			break
		}
	}
}

func Swap(array []int, index int) {
	array[index] = array[index] + array[index+1]
	array[index+1] = array[index] - array[index+1]
	array[index] = array[index] - array[index+1]
}
