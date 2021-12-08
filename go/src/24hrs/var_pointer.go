package main

import (
	"fmt"
)

//takes a pointer as a parameter
func showMemoryAddress(x *int) {
	fmt.Println(x)  //no need for & here
	fmt.Println(*x) //print value of variable
	return
}

func main() {
	i := 1
	fmt.Println(&i)
	showMemoryAddress(&i)
}
