// This program prints information about a pet
// author: Nefi Munoz <nefi.munoz@gmail.com>
package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
)

type Pet struct{
  Name string
  Type string
  Color string
  Owners []string
  Age int
  Weight float32
}

func main(){

  //create a configuration file using json to describe the pet
  owners := []string{"Liliana", "Anna", "Naomi"}
  sasha := Pet {
    Name: "Sasha",
    Type: "cat",
    Color: "calico",
    Owners: owners,
    Age: 3,
    Weight: 6.5,
  }
  fmt.Printf("%+v\n", sasha)
  jsonByteData, err := json.Marshal(sasha)
  if err != nil {
    log.Fatal(err)    
  }
  //convert json byte into string for printing
  jsonStringData := string(jsonByteData)
  fmt.Println(jsonStringData)
  //write json byte data to a file
  err = ioutil.WriteFile("sasha.json",jsonByteData,0644)
  if err != nil {
    log.Fatal(err)    
  }
  //explore how you can represent different data types like arrays, integers, and
  //floats using JSON and TOML

}