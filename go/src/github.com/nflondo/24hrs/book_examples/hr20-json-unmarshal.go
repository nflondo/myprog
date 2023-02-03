package main

import (
	"encoding/json"
	"fmt"
	"log"
)
//struct tags tell the decoder to map a key to a field
type Person struct {
	Name    string   `json:"name"`
	Age     int      `json:"age"`
	Hobbies []string `json:"hobbies"`
}

func main() {
//	var p Person
	//json data first received as a string
	jsonStringData := `{"name":"George","age":40,"hobbies":["Cycling","Cheese","Techno"]}`
	//convert json data to byte
	jsonByteData := []byte(jsonStringData)
	//create the receiving object (based on struct interface)
	p := Person{}
	err := json.Unmarshal(jsonByteData, &p)
	if err != nil {
		log.Fatal(err)
	}
	//print instance of Person struct
	fmt.Printf("%+v\n", p)
}