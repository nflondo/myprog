//nmc - verified this works
package main

import (
	"fmt"
	"math"
)

func main() {
	var number float64
	var tnum float64
	fmt.Println("Enter the floating point number")
	fmt.Scan(&number)
	tnum = math.Trunc(number)
	fmt.Println(tnum)
}
