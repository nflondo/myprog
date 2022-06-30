package main

import "fmt"

type Vertex struct {
	Lat, Long float64
}
// declaring the var map
var m map[string]Vertex

// m2 is a map literal
var m2 = map[string]Vertex{
	"Bell Labs": Vertex{
		40.68433, -74.39967,
	},
	"Google": Vertex{
		37.42202, -122.08408,
	},
}

func main() {
	m = make(map[string]Vertex)
	m["Bell Labs"]= Vertex {
		40.68, -74.39,
	}
	fmt.Println(m["Bell Labs"])
	fmt.Println("m2:",m2)
}
