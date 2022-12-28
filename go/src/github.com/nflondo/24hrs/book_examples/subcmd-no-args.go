package main

import (
	"flag"
	"fmt"
	"os"
	"strings"
)

func flagUsage() {
	usageText := `example05 is an example cli tool.
        
Usage:
example05 command [arguments]
The commands are:
uppercase  uppercase a string 
lowercase  lowercase a string
Use "example05 [command] --help" for more information about a command.`
	fmt.Fprintf(os.Stderr, "%s\n\n", usageText)
}

func uppercaseHelp() {
	usageText := `subcmd-no-args is an example cli tool.
        
Usage:
subcmd-no-args uppercase -s <text>
For example:
./subcmd-no-args uppercase -s "convert me to uppercase"
Use "example05 [command] --help" for more information about a command.`
	fmt.Fprintf(os.Stderr, "%s\n\n", usageText)
}

func lowercaseUsage() {
	usageText := `subcmd-no-args is an example cli tool.
        
Usage:
subcmd-no-args lowercase -s <text>
For example:
./subcmd-no-args lowercase -s "TO LOWERCASE"
Use "example05 [command] --help" for more information about a command.`
	fmt.Fprintf(os.Stderr, "%s\n\n", usageText)
}

func main() {

	flag.Usage = flagUsage
	// NewFlagSet are used to crate subcommands in the program
	uppercaseCmd := flag.NewFlagSet("uppercase", flag.ExitOnError)	
	lowercaseCmd := flag.NewFlagSet("lowercase", flag.ExitOnError)
	lowercaseCmd.Usage = lowercaseUsage
	// if program is called with no args, then display usage()
	if len(os.Args) == 1 {
		flag.Usage()
		return
	}

	// if len(os.Args) == 3 {
	// 	fmt.Println(os.Args[2:])
	// 	return
	// }

	switch os.Args[1] {
	case "uppercase":
		s := uppercaseCmd.String("s", "", "A string of text to be uppercased")
		if len(os.Args) < 4 {
			uppercaseHelp()
			return
		}
		uppercaseCmd.Parse(os.Args[2:])
		fmt.Println(strings.ToUpper(*s))
	case "lowercase":
		s := lowercaseCmd.String("s", "", "A string of text to be lowercased")
		lowercaseCmd.Parse(os.Args[2:])
		if *s == "" {
			lowercaseCmd.Usage()
			return
		}
		fmt.Println(strings.ToLower(*s))
	default:
		flag.Usage()
	}

}
