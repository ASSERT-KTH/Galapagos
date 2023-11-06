Due to differences between the syntaxes and concepts used in C and Go (like the use of registers in C or macros that perform complicated operations which are not directly transcribable), it's very difficult to perfectly rewrite this C function in Go without making any changes or auxiliary functions. However, here's a general equivalent in terms of structure, using assumptions about those macros:

go
import (
	"fmt"
)

type GetBitContext struct {
	//Some data
}

func getBits(s *GetBitContext, n int) uint {
	tmpl := uint(0)
	if n <= 0 || n > 25 {
		fmt.Print("Assertion Error: n > 0 and n <= 25")
		return 0
	}
	//updateCache(s)

	tmpl = showUBits(s, n)
	//skipLastBits(s, n)

	if tmpl >= uint(1)<<uint(n) {
		fmt.Println("Assertion Error: tmp < 1^n")
	}
	return tmpl
}

func showUBits(s *GetBitContext, n int) uint {
	// Some algorithm for showing unsigned bits.
	return uint(n) // Just for showcasing.
}


func skipLastBits(s *GetBitContext, n int) {
	// Some algorithm for skipping last n bits.
}

In the real refactoring to Go, implementations of `showUBits()` and `skipLastBits()` functions depended on how they were described in the original input file. I left them as outline so you may see where to put corresponding code. Assertions are replaced with error messages according to Go style.