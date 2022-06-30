/*A program which allows the user to get information about a predefined set of
animals. Three animals are predefined, cow, bird, and snake. Each animal can eat,
 move, and speak. The user can issue a request to find out one of three things
 about an animal: 1) the food that it eats, 2) its method of locomotion, and
 3) the sound it makes when it speaks.
 Your program should present the user with a prompt, “>”, to indicate that the
 user can type a request. Your program accepts one request at a time from the
 user, prints out the answer to the request, and prints out a new prompt. Your
 program should continue in this loop forever. Every request from the user must
 be a single line containing 2 strings. The first string is the name of an animal,
either “cow”, “bird”, or “snake”. The second string is the name of the
information requested about the animal, either “eat”, “move”, or “speak”. Your
program should process each request by printing out the requested data.
*/
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type Animal struct {
	food       string
	locomotion string
	noise      string
}

func (animal Animal) Eat() {
	fmt.Println(animal.food) //print animal's food
}

func (animal Animal) Move() {
	fmt.Println(animal.locomotion)
}

func (animal Animal) Speak() {
	fmt.Println(animal.noise)
}

func (animal *Animal) SetProperties(food, motion, noise string) {
	animal.food = food
	animal.locomotion = motion
	animal.noise = noise
}

func main() {
	var cow, bird, snake Animal
	cow.SetProperties("grass", "walk", "moo")
	bird.SetProperties("worms", "fly", "peep")
	snake.SetProperties("mice", "slither", "hsss")
	// cow.food = "grass"
	// cow.locomotion = "walk"
	// cow.noise = "moo"
	// bird.food = "worms"
	// bird.locomotion = "fly"
	// bird.noise = "peep"
	// snake.food = "mice"
	// snake.locomotion = "slither"
	// snake.noise = "hsss"
	//	bird := Animal(worms, fly, peep)
	//	snake := Animal(mice, slither, hsss)
	for {
		fmt.Print("> ")
		scanner := bufio.NewScanner(os.Stdin)
		scanner.Scan()

		input := strings.Split(scanner.Text(), " ") //returns a slice separate by space
		if len(input) != 2 {
			fmt.Println("Invalid input, please enter <name> <action>")
			continue
		}
		animal_name := input[0]
		requested_action := input[1]
		switch animal_name {
		case "cow":
			switch requested_action {
			case "eat":
				cow.Eat()
			case "move":
				cow.Move()
			case "speak":
				cow.Speak()
			}
		case "bird":
			switch requested_action {
			case "eat":
				bird.Eat()
			case "move":
				bird.Move()
			case "speak":
				bird.Speak()
			}
		case "snake":
			switch requested_action {
			case "eat":
				snake.Eat()
			case "move":
				snake.Move()
			case "speak":
				snake.Speak()
			}
		default:
			fmt.Println("Invalid Input, try again...")
		}
	}
}
