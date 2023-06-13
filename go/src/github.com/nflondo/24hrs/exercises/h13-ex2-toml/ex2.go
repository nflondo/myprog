package main

import (
	"fmt"

	"github.com/pelletier/go-toml/v2"
)

type MyConfig struct {
	Version int
	Name    string
	Tags    []string
}

func main() {
	cfg := MyConfig{
		Version: 2,
		Name:    "go-toml",
		Tags:    []string{"go", "toml"},
	}

	b, err := toml.Marshal(cfg)
	if err != nil {
		panic(err)
	}
	fmt.Println(string(b))
}
