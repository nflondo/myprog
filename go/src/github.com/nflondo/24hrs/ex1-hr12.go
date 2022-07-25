package main

import (
	"fmt"
	"net/http"
	"os"
	"time"
)

func responseTime(url string, c chan string) {

	start := time.Now()

	res, err := http.Get(url)

	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
	elapsed := time.Since(start).Seconds()
	//c <- elapsed
	defer res.Body.Close()

	c <- fmt.Sprintf("%s took %v seconds \n", url, elapsed)

}

func main() {
	urls := make([]string, 3)
	urls[0] = "https://www.usa.gov/"
	urls[1] = "https://www.gov.uk/"
	urls[2] = "http://www.gouvernement.fr/"

	ch := make(chan string)
	//ch2 := make(chan float64)
	//ch3 := make(chan float64)

	for _, u := range urls {
		go responseTime(u, ch)
	}

	for {
		select {
		case msg := <-ch:
			fmt.Println(msg)
		// case msg2 := <-ch2:
		// 	fmt.Println("uk: ", msg2)
		// case msg3 := <-ch3:
		// 	fmt.Println("fr: ", msg3)
		case <-time.After(3000 * time.Millisecond):
			fmt.Println("Time out reached.")
			return
		}
	}
	//	time.Sleep(time.Second * 5)  // replace this sleep with channels

}
