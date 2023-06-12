// Program to compute number of days before Christmas
package main

import (
	"fmt"
	"log"
	"time"
)

func main() {
	christmas := "2023-12-25T00:00:00+00:00"
	day := "2023-05-08T00:00:00+00:00"
	//current_time := time.Now()

	christmas_day, err := time.Parse(time.RFC3339, christmas)
	if err != nil {
		log.Fatal(err)
	}

	today, err := time.Parse(time.RFC3339, day)
	if err != nil {
		log.Fatal(err)
	}

	hours_til_chirstmas := (christmas_day.Sub(today))
	days_to_christ := hours_til_chirstmas/24
	fmt.Printf("Days to Christmas: %v", (days_to_christ))

}
