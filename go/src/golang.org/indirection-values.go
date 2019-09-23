package main

import (
	"fmt"
	"math"
)

type Vertex struct {
	X, Y float64
}

func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func AbsFunc(v Vertex) float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func main() {
	v := Vertex{3, 4}
	fmt.Println(v.Abs())
	// functions that take a value argument must take a value of that specific type:
	fmt.Println(AbsFunc(v))

	p := &Vertex{4, 3}
	// methods with value receivers take either a value or a pointer as the receiver
	// when they are called.
	fmt.Println(p.Abs())
	fmt.Println(AbsFunc(*p))
}
