package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
)

type User struct {
	// struct tags maps fields in json to fields in struct
	Name string `json:"name"`
	Blog string `json:"blog"`
}

func main() {
	var u User
	// get response from json API, returns an io.Reader
	res, err := http.Get("https://api.github.com/users/shapeshed")
	if err != nil {
		log.Fatal(err)
	}
	defer res.Body.Close()
	// use NewDecoder to decode stream.  It expects an io.Reader
	// Decode decodes data into a struct
	err = json.NewDecoder(res.Body).Decode(&u)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%+v\n", u)
}