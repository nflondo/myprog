// WordCount should return a map of the counts of each "word" in the string
// s.  The wc.Test function runs a test suite against the provided function
// and print success or failure
package main

import (
//	"golang.org/x/tour/wc"
	"strings"
	"fmt"
	)
	
//func WordCount(s string) map[string]string {
//	swords := strings.Fields(s)
//	wordMap := make(map[string]string)
//	for i := 0 ; i < len(swords); i += 2 {
//		wordMap[swords[i]] = swords[i +1]
//	}
//	fmt.Println(wordMap)	
//	return wordMap
//}

func WordCount(s string) map[string]int {
	swords := strings.Fields(s)
	wordMap := make(map[string]int)
	for _, v := range swords { 
			wordMap[v]++
	}	
	return wordMap
}

func main() {
//	wc.Test(WordCount)
	fmt.Println(WordCount("this is a palabra this is"))
}
