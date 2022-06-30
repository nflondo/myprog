// Create a struc to represent a console game, game name, release date, platform.
package main

import "fmt"

type FavGame struct {
	Name        string
	ReleaseYear int32
	Platform    string
}

func main() {
	kart := FavGame{
		Name:        "Mario Kart",
		ReleaseYear: 1992,
		Platform:    "Nintendo",
	}
	fmt.Printf("Name: %v\n", kart.Name)
	fmt.Printf("ReleaseYear: %v\n", kart.ReleaseYear)
	fmt.Printf("Platform: %v\n", kart.Platform)
}
