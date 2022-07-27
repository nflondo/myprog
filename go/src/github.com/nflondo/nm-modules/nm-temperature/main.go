package main

import (
	"fmt"

	"github.com/shapeshed/temperature"
)

func main() {
	f := temperature.CtoF(10)
	fmt.Println(f) // 10

	c := temperature.FtoC(32)
	fmt.Println(c) // 0
}
