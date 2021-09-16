/* Write a program which prompts the user to enter a string. The program
searches through the entered string for the characters ‘i’, ‘a’, and ‘n’.
The program should print “Found!” if the entered string starts with the
character ‘i’, ends with the character ‘n’, and contains the character ‘a’.
The program should print “Not Found!” otherwise. The program should not be
case-sensitive, so it does not matter if the characters are upper-case or lower-case.

Examples: The program should print “Found!” for the following example entered
strings, “ian”, “Ian”, “iuiygaygn”, “I d skd a efju N”. The program should print
 “Not Found!” for the following strings, “ihhhhhn”, “ina”, “xian”.
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	//Read strings including spaces
	// https://tutorialedge.net/golang/reading-console-input-golang/
	// https://stackoverflow.com/questions/28558711/read-multi-word-string-from-console
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Please enter a string: ")
	text, _ := reader.ReadString('\n')
	//remove \n char
	text = strings.Replace(text, "\n", "", -1)
	// toLower to ignore case
	newString := strings.ToLower(text)

	//	fmt.Println("New string: " + newString)
	if strings.HasPrefix(newString, "i") && strings.HasSuffix(newString, "n") &&
		strings.Contains(newString, "a") {
		fmt.Println("Found!")
	} else {
		fmt.Println("Not Found!")
	}

}
