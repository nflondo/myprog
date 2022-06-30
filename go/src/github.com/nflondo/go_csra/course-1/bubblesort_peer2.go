package main

import "fmt"


// swaps in place index and index + 1 in unsortedArray 
func InPlaceSwap(unsortedSlice []int, swapIndex int) {
	unsortedSlice[swapIndex], unsortedSlice[swapIndex + 1] 
		= unsortedSlice[swapIndex + 1], unsortedSlice[swapIndex]
}

func BubbleSort(arr []int){
	arrLen = len(arr)
	for i := 0; i < arrLen - 1; i++ {
		for j := 0; j < arrLen - i - 1; j++ {
			if (arr[j] > arr[j + 1]) {
				InPlaceSwap(v, j)
			}
		}
	}
}

func main() {
	fmt.Printf("enter 10 values: ")
	arr := make([]int, 10)
	for i := 0; i < 10; i++ {
		fmt.Scan(&arr[i])
	}

	fmt.Println(BubbleSort(arr))
}