In Golang, translated code can be:

go
package main

// #cgo CFLAGS: -I/usr/include -DPACKAGE_NAME="coreutils" -DPACKAGE_URL="https://www.gnu.org/software/coreutils/"
// #include <string.h>
// #include <locale.h>
import "C"
import (
	"fmt"
	"os"
)

func emitAncillaryInfo(program string) {
	type infomap struct {
		program string
		node    string
	}
	informap := []infomap{
		{program: "[", node: "test invocation"},
		{"coreutils", "Multi-call invocation"},
		{"sha224sum", "sha2 utilities"},
		{"sha256sum", "sha2 utilities"},
		{"sha384sum", "sha2 utilities"},
		{"sha512sum", "sha2 utilities"},
		{program: "", node: ""},
	}

	//c (node := program)
	node := program
	for _, mapProg := range informap {
		if mapProg.program == "" {
			break
		} else if mapProg.program == program {
			node = mapProg.node
			break
		}
	}

	fmt.Printf("\n%s online help: <%s>\n", "coreutils", "https://www.gnu.org/software/coreutils/")

	lcMessages := C.GoString(C.setlocale(C.LC_MESSAGES, nil))
	if lcMessages != "" && lcMessages[:3] != "en_" {
		fmt.Println(`Report any translation bugs to <https://translationproject.org/team/>`)
	}

	urlProgram := program
	if program == "[" {
		urlProgram = "test"
	}
	fmt.Printf("Full documentation <%s%s>\n", "https://www.gnu.org/software/coreutils/", urlProgram)
	if node == program {
		fmt.Printf("or available locally via: info '(coreutils) %s%s'\n", node, " invocation")
	} else {
		fmt.Printf("or available locally via: info '(coreutils) %s'\n", node)
	}
}

func main() {
	emitAncillaryInfo(os.Args[1])
}

In the program above, We are creating necessary C bindings, parsing information into structs, and mimicking the Input/Output of original C code in Golang.