package main

import (
	"fmt"
	"reflect"
	"strconv"
)

func main() {
	var b bool
	var s string = "string"
	var i int = 10
	var f float32 = 1.2

	fmt.Println(b) //false by default
	b = true
	fmt.Println(b)
	fmt.Println(reflect.TypeOf(b))
	// convert type
	var s2 string = strconv.FormatBool(true)

	fmt.Println(reflect.TypeOf(s))
	fmt.Println(reflect.TypeOf(i))
	fmt.Println(reflect.TypeOf(f))

	fmt.Println(reflect.TypeOf(s2))

}
