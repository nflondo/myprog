package main

import (
	"fmt"
	"flag"
)

func main() {
	//variable s initialized.  flag.String allows a command-line flag to be declared
	//with a name, a default value, and some help text
	//the return value of flag.String is a pointer
	s:= flag.String("s", "Hello world", "String help text")

	o:= flag.String("o", "myfile.txt", "-o <name of output file>")

	i:= flag.Int("i", 1, "Integer here")

	b:= flag.Bool("b", false, "Boolean here")
	//flag.Parse is called so that the program may pass arguments once they have
	//been declared
	flag.Parse()
	//print value of s. Use * to dereference the pointer and how underlying value
	fmt.Println("value of s:", *s)
	fmt.Println("value of o:", *o)
	fmt.Println("value of i:", *i)
	fmt.Println("value of b:", *b)
}