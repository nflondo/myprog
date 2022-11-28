// This writes log to stdout and then when program is run, redirect
// output of progra to a file
package main

import (
	"log"
)

func main() {
	for i := 1; i <= 5; i++ {
		log.Printf("Log iteration %d", i)
	}
}