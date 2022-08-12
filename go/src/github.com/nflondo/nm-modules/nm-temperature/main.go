package main

import (
	"fmt"

	temperature "github.com/nflondo/nm-modules/nm-temperature"
)

func main() {
	f := temperature.CtoF(10)
	fmt.Println(f) // 50

	c := temperature.FtoC(32)
	fmt.Println(c) // 0

	k := temperature.CtoK(-253.150)
	fmt.Println(k) // 0
}
