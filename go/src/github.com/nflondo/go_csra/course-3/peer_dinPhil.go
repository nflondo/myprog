package main

import (
	"fmt"
	//"math/rand"
	"sync"
	"time"
)

var wg sync.WaitGroup

var host = make(chan bool, 2)

type ChopSticks struct{ sync.Mutex }

type Philosopher struct {
	id              int
	leftCS, rightCS *ChopSticks
}

func (p Philosopher) eat() {

	for i := 0; i < 3; i++ {

		host <- true

		p.leftCS.Lock()
		p.rightCS.Lock()

		sayAction("starting to eat", p.id)
		time.Sleep(time.Second)
		sayAction("finishing eating", p.id)
		p.leftCS.Unlock()
		p.rightCS.Unlock()
		<-host
	}
	wg.Done()
}

func sayAction(str string, id int) {
	fmt.Printf("Philosopher %d is %s \n", id, str)
}

func main() {

	CSticks := make([]*ChopSticks, 5)
	for i := 0; i < 5; i++ {
		CSticks[i] = new(ChopSticks)
	}

	philos := make([]*Philosopher, 5)
	for i := 0; i < 5; i++ {
		philos[i] = &Philosopher{i + 1, CSticks[i], CSticks[(i+1)%5]}
	}

	for i := 0; i < 5; i++ {
		wg.Add(1)
		go philos[i].eat()
	}
	wg.Wait()
}
