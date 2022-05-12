package main

import (
	"fmt"
	"strings"
)

func main() {
	mystr := "Oh I do like to be beside the seaside"

	//my_str_uppercase := strings.ToUpper(mystr)
	//fmt.Printf("Uppercase: %v\n", my_str_uppercase)
	fmt.Printf("Uppercase: %v\n", strings.ToUpper(mystr))
	fmt.Printf("Replace seaside with bar: %v\n", strings.Replace(mystr, "seaside", "bar", 1))
	fmt.Printf("Index of \"the\": %v\n", strings.Index(mystr, "the"))

}
