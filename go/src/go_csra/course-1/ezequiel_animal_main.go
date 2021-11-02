package main

import (
	"fmt"
	"strings"
)

func main() {
	
	cow := Cow{
		name:             "cow",
		eatenFood:        "grass",
		locomotionMethod: "walk",
		spokenSound:      "moo",
	}
	
	bird := Bird{
		name:             "bird",
		eatenFood:        "worms",
		locomotionMethod: "fly",
		spokenSound:      "peep",
	}

	snake := Snake{
		name:             "snake",
		eatenFood:        "mice",
		locomotionMethod: "slither",
		spokenSound:      "hsss",
	}




	for  true {

		var firstParam  string
		var secondParam string
		var thirdParam  string

		//reader := bufio.NewReader(os.Stdin)
		fmt.Print("\n>")
		fmt.Scan(&firstParam, &secondParam, &thirdParam)

		firstParam  = strings.ToLower(firstParam)
		secondParam = strings.ToLower(secondParam)
		thirdParam  = strings.ToLower(thirdParam)
		var animal Animal

		if firstParam != "" && secondParam != "" && thirdParam != ""{

			if firstParam == "query"{
				if secondParam == "bird" || secondParam == "cow" || secondParam == "snake"{
					switch secondParam {
					case "bird":
						animal = &bird
						if thirdParam == "eat"{
							animal.Eat()
						}
						if thirdParam == "move"{
							animal.Move()
						}
						if thirdParam == "Speak"{
							animal.Speak()
						}
					case "cow":
						animal = &cow
						if thirdParam == "eat"{
							animal.Eat()
						}
						if thirdParam == "move"{
							animal.Move()
						}
						if thirdParam == "Speak"{
							animal.Speak()
						}
					case "snake":
						animal = &snake
						if thirdParam == "eat"{
							animal.Eat()
						}
						if thirdParam == "move"{
							animal.Move()
						}
						if thirdParam == "Speak"{
							animal.Speak()
						}
					}
				}
			}

			if firstParam == "newanimal"{
				if thirdParam == "bird" || thirdParam == "cow" || thirdParam == "snake"{
					switch thirdParam {
					case "bird":


						fmt.Println("\nCreated it!")
					case "cow":

						fmt.Println("\nCreated it!")
					case "snake":
						fmt.Println("\nCreated it!")
					default:
						fmt.Println("\n This is not an animal type available! You just choose between bird, cow or snake. ")
					}
				}
			}

		} else {
			fmt.Println("\nYou should enter your input in a 3 strings separated by comma way! E.G : 'query cow eat' or 'newanimal Braian cow' ")
		}

	}


}

type Animal interface {
	Eat()
	Move()
	Speak()
}

type Bird struct {
	name string
	eatenFood string
	locomotionMethod string
	spokenSound string
}

type Cow struct {
	name string
	eatenFood string
	locomotionMethod string
	spokenSound string
}

type Snake struct {
	name string
	eatenFood string
	locomotionMethod string
	spokenSound string
}

func (a *Bird) Eat() {
	fmt.Println("\n"+a.eatenFood)
}

func (a *Bird) Move() {
	fmt.Println("\n"+a.locomotionMethod)
}

func (a *Bird) Speak() {
	fmt.Println("\n"+a.spokenSound)
}

func (a *Cow) Eat() {
	fmt.Println("\n"+a.eatenFood)
}

func (a *Cow) Move() {
	fmt.Println("\n"+a.locomotionMethod)
}

func (a *Cow) Speak() {
	fmt.Println("\n"+a.spokenSound)
}

func (a *Snake) Eat() {
	fmt.Println("\n"+a.eatenFood)
}

func (a *Snake) Move() {
	fmt.Println("\n"+a.locomotionMethod)
}

func (a *Snake) Speak() {
	fmt.Println("\n"+a.spokenSound)
}


