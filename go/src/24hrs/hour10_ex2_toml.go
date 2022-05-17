/*** This program does Marshaling: Represents  Go structure as a TOML document
Unmarshal reads a TOML document and fills a Go structure with its content. ***/
package main

import (
	"fmt"
	"log"

	toml "github.com/pelletier/go-toml/v2"
)

func main() {
	type Postgres struct {
		User     string `toml:"user"`
		Password string `toml:"password"`
		Database string `toml:"db" commented:"true" comment:"not used anymore"`
	}
	type Config struct {
		Postgres Postgres `toml:"postgres" comment:"Postgres configuration"`
	}

	config := Config{Postgres{User: "pelletier", Password: "mypassword", Database: "old_database"}}
	b, err := toml.Marshal(config)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(string(b))
}
