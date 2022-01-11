package main

import "fmt"

func main() {
	var cheeses = make([]string, 4)
	cheeses[0] = "Mariolles"
	cheeses[1] = "Époisses de Bourgogne"
	cheeses[2] = "Camembert"
	cheeses[3] = "fresco"
	fmt.Println(len(cheeses))
	fmt.Println(cheeses)
	cheeses = append(cheeses[:2], cheeses[2+1:]...)
	fmt.Println("Slice after removing elem2")
	fmt.Println(len(cheeses))
	fmt.Println(cheeses)
}
