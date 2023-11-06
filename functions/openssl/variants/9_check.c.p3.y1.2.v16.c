The equivalent Go version has to look different due to the differences between C and Go. Here the equivalent is not exact (specifically the error handling part) since both languages handle errors very different ways:

go
package main

import (
	"fmt"
	"os"
	"log"
)

func check(code error) {
	if code != nil {
		_, err := fmt.Fprintf(os.Stderr, "%s\n", code.Error())
		if err != nil {
			log.Fatalf("Failed printing error message: %v", err)
		}
	}
	if code != nil {
		log.Fatal(code)
	}
}

Warning!: Remember that each language has its own model of thoughts and semantics. Always consider and respect the idioms and best practices of individually language as second step when you convert the syntax between languages.