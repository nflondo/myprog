package main

import "fmt"

func main() {
	m := make(map[string]int)
	
	// Insert or update element into a map
	m["Answer"] = 42
	fmt.Println("The value:", m["Answer"])
	
	// delete an element
	delete(m, "Answer")
	fmt.Println("The value:", m["Answer"])
	
	// Test that a key is present with a two-value assignment.  If key is
	// in m, ok is true.  If not, ok is false.
	// using short declaration for v, and ok
	v, ok := m["Answer"]
	fmt.Println("The value:", v, "Present?", ok)
	
}
