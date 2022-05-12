package main

import (
	"errors"
	"fmt"
	"io/ioutil"
)

func main() {
	/*** Basic error type checking ***/
	// var file []byte
	// var err error
	// file, err = ioutil.ReadFile("foo.txt")
	file, err := ioutil.ReadFile("foo.txt")
	if err != nil {
		fmt.Println(err)
		//return
	}
	fmt.Printf("%s", file)

	/*** Creating errors ***/ //use package "errors"
	err2 := errors.New("Something went wrong")
	if err2 != nil {
		fmt.Println(err2)
	}

	/*** Formatting Errors  ***/ //use Errorf()
	name, role := "Richar Jupp", "Pianist"
	err3 := fmt.Errorf("The %v %v quit", role, name)
	if err3 != nil {
		fmt.Println(err3)
	}
}
