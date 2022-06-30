package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	intSlice := make([]int, 3)
	fmt.Println("To exit the program, press 'X'.")

	for {
		var stringValue string
		fmt.Println("Enter an integer: ")
		fmt.Scanln(&stringValue)

		if stringValue == "X" {
			os.Exit(0)
		}

		intValue, err := strconv.Atoi(stringValue)
		if err != nil {
			fmt.Println("Unkown input, please try again.")
			continue
		}

		intSlice = append(intSlice, intValue)

		sort.Ints(sort.IntSlice(intSlice))
		fmt.Println(intSlice)
		continue
	}

}
