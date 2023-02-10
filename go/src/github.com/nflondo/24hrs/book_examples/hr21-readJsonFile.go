package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
)

type Config struct {
	Name   string `json:"name"`
	Awake  bool   `json:"awake"`
	Hungry bool   `json:"hungry"`
}

func main() {
	f, err := ioutil.ReadFile("config.json")
	if err != nil {
		log.Fatal(err)
	}
	// create go struct to receive json info
	c := Config{}
	// pass json file and go struct
	err = json.Unmarshal(f, &c)
	if err != nil {
		log.Fatal(err)
	}
	// print go object
	fmt.Printf("%+v\n", c)
}