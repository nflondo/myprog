package main

import (
	"fmt"
	"regexp"
)

func main() {
	// regex checks for:
	// - longer than 4 characters but no longer than 12
	// - Only alphanumeric characters
	// - characters may be upper or lowercase
	re := regexp.MustCompile("^[a-zA-Z0-9]{5,12}$")
	fmt.Println(re.MatchString("slimshady99"))
	fmt.Println(re.MatchString("!asdf£33£3"))
	fmt.Println(re.MatchString("roger"))
	fmt.Println(re.MatchString("iamthebestuserofthisappevaaaar"))
}