/* Write a program which prompts the user to first enter a name, and then enter
an address. Your program should create a map and add the name and address to the
 map using the keys “name” and “address”, respectively. Your program should use
 Marshal() to create a JSON object from the map, and then your program should
 print the JSON obje
*/
package main

import (
	"encoding/json"
	"fmt"
	"os"
)

func main() {
	var userName, userAddr string
	fmt.Println("Enter your name: ")
	fmt.Scanln(&userName)
	fmt.Println("Enter your address")
	fmt.Scanln(&userAddr)

	userMap := make(map[string]string)
	userMap["name"] = userName
	userMap["address"] = userAddr

	barr, err := json.Marshal(userMap)
	if err != nil {
		fmt.Println("Failed during json.Marshal")
		os.Exit(0)
	}
	fmt.Println(string(barr))
}
