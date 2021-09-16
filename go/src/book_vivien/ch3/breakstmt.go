package main

import (
	"fmt"
)

var words = [][]string{
	{"break", "lake", "go", "right", "strong", "kite", "hello"},
	{"fix", "river", "stop", "left", "weak", "flight", "bye"},
	{"fix", "lake", "slow", "middle", "sturdy", "high", "hello"},
}

func search(w string) {
	/* break DoSearch - will exit out of the innermost for loop and cause the execution
	   flow to continue after the outermost labeled for statement, in this case end of prog.
	*/
DoSearch:
	for i := 0; i < len(words); i++ {
		for k := 0; k < len(words[i]); k++ {
			if words[i][k] == w {
				fmt.Println("Found", w)
				break DoSearch
			}
		}
	}
}

func main() {
	search("lake")
}
