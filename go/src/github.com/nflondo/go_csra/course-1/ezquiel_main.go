package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	
	cow := Animal{
		name:             "cow",
		eatenFood:        "grass",
		locomotionMethod: "walk",
		spokenSound:      "moo",
	}
	
	bird := Animal{
		name:             "bird",
		eatenFood:        "worms",
		locomotionMethod: "fly",
		spokenSound:      "peep",
	}

	snake := Animal{
		name:             "snake",
		eatenFood:        "mice",
		locomotionMethod: "slither",
		spokenSound:      "hsss",
	}

	exit := false

	for exit != true {
		reader := bufio.NewReader(os.Stdin)
		fmt.Print("\nEnter the name of the animal that you want to know, and the action separated by space. For exit write exit. \n>")
		text, _ := reader.ReadString('\n')
		text = strings.TrimSuffix(text, "\n")
		text = strings.ToLower(text)
		if text == "exit"{
			exit = true
		}

		inputData := strings.Split(text, " ")
		if len(inputData) == 2 {
			animal := inputData[0]
			action := inputData[1]
			switch animal {
			case "cow":
				switch action {
				case "eat":
					fmt.Println(cow.eat())
				case "move":
					fmt.Println(cow.move())
				case "speak":
					fmt.Println(cow.speak())
				default:
					fmt.Println("That action is not available!")
				}
			case "bird":
				switch action {
				case "eat":
					fmt.Println(bird.eat())
				case "move":
					fmt.Println(bird.move())
				case "speak":
					fmt.Println(bird.speak())
				default:
					fmt.Println("That action is not available!")
				}
			case "snake":
				switch action {
				case "eat":
					fmt.Println(snake.eat())
				case "move":
					fmt.Println(snake.move())
				case "speak":
					fmt.Println(snake.speak())
				default:
					fmt.Println("That action is not available!")
				}
			default:
				fmt.Printf("%s.\n", "That animal is not on the list!! ")
			}
		} else {
			fmt.Println("\nYou must enter the animal and the action separated by space!!")
		}
	}


	fmt.Println("\nByee!")


}

type Animal struct {
	name string
	eatenFood string
	locomotionMethod string
	spokenSound string
}

func (a *Animal) eat() string{
	 return a.eatenFood

}

func (a *Animal) move() string {
	return a.locomotionMethod
}

func (a *Animal) speak() string {
	return a.spokenSound
}