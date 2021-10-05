package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type Animal interface {
	Speak()
	Eat()
	Move()
}

type Cow struct{}

func (a *Cow) Speak() {
	fmt.Println("moo")
}

func (a *Cow) Eat() {
	fmt.Println("grass")
}

func (a *Cow) Move() {
	fmt.Println("walk")
}

type Bird struct{}

func (a *Bird) Speak() {
	fmt.Println("peep")
}

func (a *Bird) Eat() {
	fmt.Println("worms")
}

func (a *Bird) Move() {
	fmt.Println("fly")
}

type Snake struct{}

func (a *Snake) Speak() {
	fmt.Println("hss")
}

func (a *Snake) Eat() {
	fmt.Println("mice")
}

func (a *Snake) Move() {
	fmt.Println("slither")
}

func getRequest() (string, string, string) {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		fmt.Print("> ")
		if scanner.Scan() {
			line := scanner.Text()
			tokens := strings.Split(line, " ")
			if len(tokens) != 3 {
				fmt.Println("Error: propper query format is,\n[query type] [animal name] [action]")
			} else {
				return tokens[0], tokens[1], tokens[2]
			}
		}
	}
}

func createAnimal(animal_type string) Animal {
	switch animal_type {
	case "cow":
		return &Cow{}
	case "bird":
		return &Bird{}
	case "snake":
		return &Snake{}
	default:
		return &Cow{}
	}
}

func makeAction(animal Animal, action string) {

	switch action {
	case "speak":
		animal.Speak()
	case "move":
		animal.Move()
	case "eat":
		animal.Eat()
	default:
		fmt.Println("Requested action does not exist")
	}
}

func main() {
	var animals map[string]Animal = map[string]Animal{}

	for {
		query, name, option := getRequest()
		option = strings.ToLower(option)

		switch query {
		case "query":
			if animal, exists := animals[name]; exists {
				makeAction(animal, option)
			} else {
				fmt.Println("Requested animal does not exist")
			}
		case "newanimal":
			if option != "cow" && option != "bird" && option != "snake" {
				fmt.Println("Requested animal type does not exist")
			} else {
				animals[name] = createAnimal(option)
				fmt.Println("Created it!")
			}
		default:
			fmt.Println("Error: first argument must be query or newanimal")
		}
	}
}
