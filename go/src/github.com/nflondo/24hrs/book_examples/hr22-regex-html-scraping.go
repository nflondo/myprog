package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"regexp"
)

func main() {
	resp, err := http.Get("https://petition.parliament.uk/petitions")
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}

	src := string(body)

	re := regexp.MustCompile("\\<h2\\>.*\\</h2\\>")
	// match HTML tags
	// match "<" then match anything not ">", zero or more times, then match ">"
	rHTML := regexp.MustCompile("<[^>]*>")
	//FindAllString() used to look for all occurrences of a regular expression
	//within a String
	titles := re.FindAllString(src, -1)
	//cleanTitles := rHTML.FindAllString(re, -1)

	for _, title := range titles {

		//fmt.Println(title)
		// replaced matched HTML tags with nothing
		fmt.Println(rHTML.ReplaceAllString(title, ""))
	}

}
