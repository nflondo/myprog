package main

import ("fmt"
		"encoding/json"
		"log"
)
// This is correct
// type Person struct {
// 	Name    string
// 	Age     int
// 	Hobbies []string
// }
//struct tags cause to ommit empty struct fields
type Person struct {
	Name    string   `json:"name,omitempty"`
	Age     int      `json:"age,omitempty"`
	Hobbies []string `json:"hobbies,omitempty"`
}

func main() {
	hobbies := []string{"Cycling", "Cheese", "Techno"}
	p := Person{
		Name:    "George",
		Age:     40,
		Hobbies: hobbies,
	}
	// Create empty person
	s := Person{}
	fmt.Printf("%+v\n", p)
	jsonByteData, err := json.Marshal(p)
	if err != nil {
		log.Fatal(err)
	}
	jsonStringData := string(jsonByteData)
	fmt.Println(jsonStringData)

	fmt.Printf("%+v\n", s)
	sjsonByteData, err := json.Marshal(s)
	if err != nil {
		log.Fatal(err)
	}
	sjsonStringData := string(sjsonByteData)
	fmt.Println(sjsonStringData)
}