// 1. Package clause = name of the package this source file belongs to
package main

// 2. Import declaration = external packages to be used, it has to be used or it
// errors out
import (
	"fmt"
	"math/rand"
	"time"
)

// 3. Source body
var greetings = [][]string{
	{"Hello, World!", "English"},
	{"Hola Mundo!", "Spanish"},
	{"Salut Monde", "French"},
}

func greeting() []string {
	seed := time.Now().UnixNano()
	rnd := rand.New(rand.NewSource(seed))
	return greetings[rnd.Intn(len(greetings))]
}

func main() {
	g := greeting()
	fmt.Printf("%s (%s)\n", g[0], g[1])
}
