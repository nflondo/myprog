package main

import (
	"fmt"
	"regexp"
)

func main() {
	usernames := []string{
		"slimshady99",
		"!asdf£33£3",
		"roger",
		"Iamthebestuserofthisappevaaaar",
		"user1ALPHA",
	}

	re := regexp.MustCompile("^[a-zA-Z0-9]{5,12}$")
	an := regexp.MustCompile("[[:^alnum:]]")

	for _, username := range usernames {
		if len(username) > 12 {
			username = username[:12]
			fmt.Printf("trimmed username to: %v\n", username)
			continue
		}
		if !re.MatchString(username) {
			username = an.ReplaceAllString(username, "x")
			fmt.Printf("rewrote username to: %v\n", username)
			continue
		}		
		fmt.Printf("Found valid username: %v\n", username)
	}

}