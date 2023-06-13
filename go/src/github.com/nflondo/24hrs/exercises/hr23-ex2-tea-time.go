// Program to display whether it is before of after tea time if tea time is at 
// 1600 hours
package main

import (
	"fmt"	
	"time"
	"log"
)

func main() {
	current_time := time.Now()	
	//fmt.Println(current_time)
	tea_time:= "2023-06-12T16:00:00+00:00"	
	tea_time_rfc3399, err:= time.Parse(time.RFC3339, tea_time)
	tea_time_hour:= tea_time_rfc3399.Hour()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("current time: %v\n",current_time)
	fmt.Printf("tea time rfc3399: %v\n",tea_time_rfc3399)
	//fmt.Println(current_time_rfc3399)
	//fmt.Println(tea_time_rfc3399)
	
	if current_time.Hour() < tea_time_hour {
		fmt.Println("It is before tea time")
	} else {
		fmt.Println("It is after tea time")
	}
}