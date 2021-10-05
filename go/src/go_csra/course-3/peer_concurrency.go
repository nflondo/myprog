package main

import (
	"log"
	"sync"
)

var x int = 0
var waitGroup sync.WaitGroup

func main() {
	for i := 0; i < 10; i++ {
		waitGroup.Add(3)
		go inc()
		go dec()
		go printX()
	}
	waitGroup.Wait()
}

func inc() {
	defer waitGroup.Done()
	x++
}

func dec() {
	defer waitGroup.Done()
	x--
}

func printX() {
	defer waitGroup.Done()
	log.Println(x)
}
