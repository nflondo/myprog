package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Ingrese su nombre: ")
	name, _ := reader.ReadString('\n')
	fmt.Println("Ingrese su dirección: ")
	address, _ := reader.ReadString('\n')

	obj := map[string]string{"name": strings.Trim(name, "\n"), "address": strings.Trim(address, "\n")}
	buffer, err := json.Marshal(obj)
	if err != nil {
		fmt.Println(err.Error())
		os.Exit(1)
	}
	fmt.Printf("JSON: %s\n", string(buffer))
}
