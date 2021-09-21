package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// read file input
	var fileName string
	fmt.Print("Enter the file name(No space separated): ")
	fmt.Scan(&fileName)
	fmt.Println()

	// open file and read file contents
	file, err := os.Open(fileName)
	if err != nil {
		fmt.Fprintf(os.Stderr, "File not found: %s\n", fileName)
	}

	// create structure for name
	type name struct {
		fname [20]byte
		lname [20]byte
	}

	// create slice to holds name and
	var nameSlice []name = make([]name, 0)
	scanner := bufio.NewScanner(file)
	scanner.Split(bufio.ScanLines)
	for scanner.Scan() {
		fname := scanner.Text()
		fnameSlice := strings.Split(fname, " ")
		nameObj := new(name)
		copy(nameObj.fname[:], fnameSlice[0])
		copy(nameObj.lname[:], fnameSlice[1])
		nameSlice = append(nameSlice, *nameObj)
	}

	for _, v := range nameSlice {
		fmt.Printf("first name: %s, last name: %s\n", v.fname, v.lname)
	}

	file.Close()
}
