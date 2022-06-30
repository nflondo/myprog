/******************************************************************************\
Implement the dining philosopher’s problem with the following
constraints/modifications.

1. There should be 5 philosophers sharing chopsticks, with one chopstick between
each adjacent pair of philosophers.

2. Each philosopher should eat only 3 times (not in an infinite loop as we did in
	lecture)

3. The philosophers pick up the chopsticks in any order, not lowest-numbered first
(which we did in lecture).

4. In order to eat, a philosopher must get permission from a host which executes
in its own goroutine.

5. The host allows no more than 2 philosophers to eat concurrently.

6. Each philosopher is numbered, 1 through 5.

7. When a philosopher starts eating (after it has obtained necessary locks) it
prints “starting to eat <number>” on a line by itself, where <number> is the
number of the philosopher.

8. When a philosopher finishes eating (before it has released its locks) it
prints “finishing eating <number>” on a line by itself, where <number> is the
number of the philosopher.
\******************************************************************************/
package main

import (
	"fmt"
	"sync"
	"time"
)

type ChopS struct {
	sync.Mutex
}

type Philo struct {
	leftCS, rightCS *ChopS
}

func (p Philo) eat(num int, wg *sync.WaitGroup) {
	for i := 0; i < 3; i++ { //Each philosopher only eat 3 times
		p.leftCS.Lock() //All philosophers might lock their left chopsticks concurrently
		p.rightCS.Lock()

		fmt.Printf("starting to eat %d\n", num)
		time.Sleep(time.Second)
		fmt.Printf("finishing eating %d\n", num)
		p.rightCS.Unlock() //order here doesn't matter
		p.leftCS.Unlock()
	}
	wg.Done()
}

func main() {
	var wg sync.WaitGroup
	// Create chopsticks
	Csticks := make([]*ChopS, 5)
	for i := 0; i < 5; i++ {
		Csticks[i] = new(ChopS)
	}
	// Create philosophers
	philos := make([]*Philo, 6)
	for i := 0; i < 5; i++ {
		//philos[i] = &Philo{Csticks[i], Csticks[(i+1)%5]} //%5 so fifth element is 0
		philos[i+1] = &Philo{Csticks[i], Csticks[(i+1)%5]} //%5 so fifth element is 0
		wg.Add(1)
		go philos[i+1].eat(i+1, &wg)
	}
	wg.Wait()
}
