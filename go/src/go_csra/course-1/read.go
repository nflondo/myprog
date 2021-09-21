/*Write a program which reads information from a file and represents it in a
slice of structs. Assume that there is a text file which contains a series of
names. Each line of the text file has a first name and a last name, in that
order, separated by a single space on the line.
Your program will define a name struct which has two fields, fname for the
first name, and lname for the last name. Each field will be a string of size 20
(characters).
Your program should prompt the user for the name of the text file. Your program
will successively read each line of the text file and create a struct which
contains the first and last names found in the file. Each struct created will be
 added to a slice, and after all lines have been read from the file, your
 program will have a slice containing one struct for each line in the file.
 After reading all lines from the file, your program should iterate through your
  slice of structs and print the first and last names found in each struct.
*/

package main

import (
	"fmt"
	"io"
	"os"
)

type Name struct {
	fname string
	lname string
	//fname [20]byte
	//lname [20]byte
}

func main() {
	var fileName string
	fmt.Print("Please enter name of text file: ")
	fmt.Scan((&fileName))
	f, err := os.Open(fileName)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	// create empty slice
	namesSlice := []Name{}
	for {
		p := new(Name)                                         // new struct Name
		_, err := fmt.Fscanf(f, "%s %s\n", &p.fname, &p.lname) //add to new struct
		if err == io.EOF {
			break
		}
		namesSlice = append(namesSlice, *p) //add struct p
		//fmt.Printf("Print this: %s %s", p.fname, p.lname)
		//	fmt.Print(string(b_array[:n]))
	}
	f.Close()
	//	fmt.Println(namesSlice)
	for i, v := range namesSlice {
		fmt.Printf("%d - First:%s Last:%s\n", i, v.fname, v.lname)
	}

}
