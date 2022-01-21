//Add a method called "Talk" to robot interface and modify structs
//to implement the method
package main

import (
	"errors"
	"fmt"
)

type Robot interface {
	PowerOn() error
	Talk()
}

type T850 struct {
	Name string
}

func (a *T850) PowerOn() error {
	return nil
}

func (r *T850) Talk() {
	fmt.Println("Speaking for T850")
}

type R2D2 struct {
	Broken bool
}

func (r *R2D2) PowerOn() error {
	if r.Broken {
		return errors.New("R2D2 is broken")
	} else {
		return nil
	}
}

func (r *R2D2) Talk() {
	fmt.Println("Speaking for R2D2")
}

func Boot(r Robot) error {
	return r.PowerOn()
}

func Speak(r Robot) {
	r.Talk()
}

func main() {

	t := T850{
		Name: "The Terminator",
	}

	r := R2D2{
		Broken: true,
	}

	err := Boot(&r)

	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println("Robot is powered on!")
	}

	err = Boot(&t)

	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println("Robot is powered on!")
	}

	Speak(&t)
	Speak(&r)

}
