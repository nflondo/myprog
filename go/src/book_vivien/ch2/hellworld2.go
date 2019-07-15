package main

import "fmt"
import "math/rand"
import "time"

var greetings = [][]string{
	{"Hello, World!", "English"},
	{"Hola Mundo!", "Spanish"},
	{"Salut Monde", "French"},
}

func greeting() [] string {
	seed := time.Now().UnixNano()
	rnd := rand.New(rand.NewSource(seed))
	return greetings[rnd.Intn(len(greetings))]
}

func main() {
	g := greeting()
	fmt.Printf("%s (%s)\n", g[0], g[1])
}
