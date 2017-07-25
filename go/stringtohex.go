package main

import (
	"encoding/hex"
	"fmt"
	"log"
)

func main() {
	test_str := "91cc47a797a3813188ecb1cb315a7b5a"
	decoded, err := hex.DecodeString(test_str)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(decoded)
	fmt.Println(string(decoded))

	nwkkey_str := "\x91\xcc\x47\xa7\x97\xa3\x81\x31\x88\xec\xb1\xcb\x31\x5a\x7b\x5a"

	fmt.Println(nwkkey_str)
}
