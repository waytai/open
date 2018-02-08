package main

import (
	"fmt"
)

func main() {
	str_list := []string{"a", "b", "c"}
	fmt.Println(str_list)
	for _, str := range str_list {
		fmt.Println(str)
	}
}
