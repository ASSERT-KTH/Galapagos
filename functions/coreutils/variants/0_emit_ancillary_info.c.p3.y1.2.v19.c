Here's the Go equivalent of the provided C function:

go
import (
	"fmt"
	"os"
	"strings"
)

type infoMap struct {
	program string
	node    string
}

func emitAncillaryInfo(program string) {
	infoMaps := []infoMap{
		{"[", "test invocation"},
		{"coreutils", "Multi-call invocation"},
		{"sha224sum", "sha2 utilities"},
		{"sha256sum", "sha2 utilities"},
		{"sha384sum", "sha2 utilities"},
		{"shs512sum", "sha2 utilities"},
		{"", ""},
	}

	var node string = program
	var mapProg infoMap

	for _, mapZ := range infoMaps {
		if program == mapZ.program {
			mapProg = mapZ
			break
		}
	}

	if mapProg.node != "" {
		node = mapProg.node
	}

	fmt.Printf("\n%s online help: <%s>\n", "PACKAGE_NAME", "PACKAGE_URL")

	lcMessages := os.Getenv("LC_MESSAGES")
	if lcMessages != "" && !strings.HasPrefix(lcMessages, "en_") {
		fmt.Printf("Report any translation bugs to <https://translationproject.org/team/>\n")
	}

	urlProgram := program
	if program == "[" {
		urlProgram = "test"
	}

	fmt.Printf("Full documentation <%s%s>\n", "PACKAGE_URL", urlProgram)

	if program == node {
		fmt.Printf("Or available locally via: info '(coreutils) %s invocation'\n", node)
	} else {
		fmt.Printf("Or available locally via: info '(coreutils) %s'\n", node)
	}
}


Note: 
As "PACKAGE_NAME" and "PACKAGE_URL" are likely defined as macros in C code, you might need to replace them accordingly. Also, in Go, getenv is used to read an environment variable unlike setlocale in C. Environment variables might not provide equivalent functionality to set local. "LC_MESSAGES" would be typically configured in Unix based systems and might not exist everywhere. Hence add necessary checks for its existence before using.
