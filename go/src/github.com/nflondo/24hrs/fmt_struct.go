
package main

import (
	"fmt"
)

type Animal struct {
	Name  string
	Color string
}

func main() {
	a := Animal{
		Name:  "Cat",
		Color: "Black",
	}
	fmt.Printf("%v\n", a)
	// +v prints the variable names in a struct
	fmt.Printf("%+v\n", a)
}