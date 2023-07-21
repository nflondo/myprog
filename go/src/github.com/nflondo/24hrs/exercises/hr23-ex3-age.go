//Program to display my age by comparing current time with the time of my birthday
package main

import (
	"fmt"
	"time"
	"log"
)

func main(){
	current_time := time.Now()
	birthday := "1976-10-12T00:00:00+00:00"
	birthday_rfc3399, err:= time.Parse(time.RFC3339, birthday)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("current time: %v\n",current_time)
	fmt.Printf("birthday rfc3399: %v\n",birthday_rfc3399)
	//substract my birthday from current time in years
	age := current_time.Year() - birthday_rfc3399.Year()
	if current_time.Month() < birthday_rfc3399.Month() {
		age:= age - 1
		fmt.Printf("I am %v years old\n",age)
		//fmt.Println("My birthday has not yet come")
	} else {
		fmt.Printf("I am %v years old\n",age)
		//fmt.Println("My birthday has passed")
	}	
	
}