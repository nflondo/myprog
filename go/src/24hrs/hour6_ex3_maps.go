package main

import "fmt"

func main() {
	html_map := make(map[string]string)
	html_map["p"] = "Paragraph"
	html_map["img"] = "Image"
	html_map["h1"] = "Heading One"
	html_map["h2"] = "Heading Two"
	fmt.Printf("HTML map: %v\n", html_map)
	fmt.Printf("Element \"img\": %v\n", html_map["img"])
}
