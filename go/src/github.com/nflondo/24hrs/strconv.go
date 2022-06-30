package main

import (
	"fmt"
	"reflect"
	"strconv"
)

func main() {
	var b bool = true
	fmt.Println(reflect.TypeOf(b))
	// convert type
	var s string = strconv.FormatBool(b)
	fmt.Println(reflect.TypeOf(s))

	b, _ = strconv.ParseBool(s)
	fmt.Println(reflect.TypeOf(b))
}
