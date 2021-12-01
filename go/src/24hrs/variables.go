package main

import (
	"fmt"
)

func main() {
	var i int
	var f float32
	var b bool
	var s string
	//https://pkg.go.dev/fmt
	// %v - default format
	// %q - single quoted character literal
	fmt.Printf("%v %v %v %q\n", i, f, b, s)
	if s == "" {
		fmt.Printf("s has not been assigned a value and is:%v\n", s)
	}
}
