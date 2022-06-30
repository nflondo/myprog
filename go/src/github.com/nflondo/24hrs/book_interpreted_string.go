package main

import "fmt"

func main() {
	s := "After a backslash, certain single character escapes represent special values\nn is a line feed or new line \n\t t is a tab"
	fmt.Println(s)
	s2 := "Can you hear me?"
	s2 += "\nHear me screamin'?"
	fmt.Println(s2)
}
