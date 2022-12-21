package main

import (
	"fmt"
	"strconv"
)

func main() {
	var i = 1                      // int
	intToString := strconv.Itoa(i) //strconv package
	var s = " egg"                 //string
	var breakfast = intToString + s
	fmt.Println(breakfast)
}
