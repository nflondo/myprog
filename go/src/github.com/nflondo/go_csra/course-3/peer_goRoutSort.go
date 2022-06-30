package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
	"sync"
)

func main() {
	var wtGrp sync.WaitGroup
	fmt.Println("Enter at least 4 numbers to proceed")
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	userChoices := treatInput(input)

	splittedArr := splitArray(userChoices)
	wtGrp.Add(5)
	init := 0
	chnl := make(chan int, 4)

	for idx, val := range splittedArr {
		slc := userChoices[init:val]
		go sortSlice(slc, &wtGrp, &chnl, idx)
		init = val
	}

	go finalPrint(userChoices, &wtGrp, &chnl)
	wtGrp.Wait()

}

func splitArray(toSplit []int) []int {
	toReturn := make([]int, 4)
	if len(toSplit) < 4 {
		return toReturn
	}

	remainder := len(toSplit) % 4
	step := (len(toSplit) - remainder) / 4

	for i := 1; i < 5; i++ {
		if i == 4 {
			toReturn[i-1] = len(toSplit)
		} else {
			toReturn[i-1] = step * i
		}
	}
	return toReturn
}

func treatInput(treat string) []int {
	var intSlc []int
	temp := strings.Fields(treat)

	for i := 0; i < len(temp); i++ {
		num, _ := strconv.Atoi(temp[i])
		intSlc = append(intSlc, num)
	}
	return intSlc
}

func sortSlice(slcToSort []int, wtGrp *sync.WaitGroup, chnl *chan int, ctrlNum int) {
	sort.Ints(slcToSort)
	fmt.Printf("Part num %v belongs to slice %v \n", ctrlNum+1, slcToSort)
	*chnl <- ctrlNum + 1
	wtGrp.Done()
}

func finalPrint(sl []int, wtGrp *sync.WaitGroup, chnl *chan int) {
	n := 0
	for {
		ctrlNum := <-*chnl
		n += ctrlNum
		if n == 10 {
			sort.Ints(sl)
			fmt.Println("The full sorted slice is:", sl)
			break
		}
	}
	wtGrp.Done()
}
