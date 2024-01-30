go
package main

import (
	"fmt"
	"os"
	"strings"
)

func emitAncillaryInfo(program string) {
	infomap := []struct {
		program, node string
	}{
		{"[", "test invocation"},
		{"coreutils", "Multi-call invocation"},
		{"sha224sum", "sha2 utilities"},
		{"sha256sum", "sha2 utilities"},
		{"sha384sum", "sha2 utilities"},
		{"sha512sum", "sha2 utilities"},
	}

	node := program
	var mapProg struct{ program, node string }

	for _, v := range infomap {
		if v.program == program {
			mapProg = v
			break
		}

	}

	if mapProg.node != "" {
		node = mapProg.node
	}

	fmt.Printf("\n%s online help: <%s>\n", "PACKAGE_NAME", "PACKAGE_URL")

	lcMessages := os.Getenv("LC_MESSAGES")
	if lcMessages != "" && !strings.HasPrefix(lcMessages, "en_") {
		fmt.Printf("Report any translation bugs to "+
			"<https://translationproject.org/team/>\n")
	}

	urlProgram := program
	if program == "[" {
		urlProgram = "test"
	}

	fmt.Printf("Full documentation <%s%s>\n", "PACKAGE_URL", urlProgram)
	fmt.Printf("or available locally via: info '(coreutils) %s%s'\n",
		node, node == program ? " invocation" : "")
}

Note: Go does not directly provide locales on its standard library, to support locales one needs to use few 3rd party libraries or get the required information from system environment. This function handles it by reading the LC_Messages environment using `os.getenv()`.