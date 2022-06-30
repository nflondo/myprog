package main

import (
	"fmt"
	"math"
)

func GenDisplaceFn(a, v, s float64) func(t float64) float64 {
	return func(t float64) float64 {
		return 0.5*a*math.Pow(t, 2) + v*t + s
	}
}

func main() {
	var acceleration, velocity, displacement, time float64

	fmt.Print("Enter acceleration value: ")
	fmt.Scan(&acceleration)
	fmt.Print("Enter velocity value: ")
	fmt.Scan(&velocity)
	fmt.Print("Enter displacement value: ")
	fmt.Scan(&displacement)
	fn := GenDisplaceFn(acceleration, velocity, displacement)

	fmt.Print("Enter time value: ")
	fmt.Scan(&time)
	fmt.Println(fn(time))
}
