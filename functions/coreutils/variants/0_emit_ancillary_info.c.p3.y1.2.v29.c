Go currently doesn't support directly switching out locales like C does. Here's a version of the function that preserves the spirit of the original translating the main functionality as closely as possible given Go's current limitations:

go
package main

import (
	"fmt"
	"strings"
)

var (
	infomap = []struct {
		program string
		node    string
	}{
		{"[", "test invocation"},
		{"coreutils", "Multi-call invocation"},
		{"sha224sum", "sha2 utilities"},
		{"sha256sum", "sha2 utilities"},
		{"sha384sum", "sha2 utilities"},
		{"sha512sum", "sha2 utilities"},
	}

	packageURL  = "http://your.package.url/"
	packageName = "YOUR_PACKAGE_NAME"
)

func emitAncillaryInfo(program string) {
	node := program
	found := false

	for _, i := range infomap {
		if program == i.program {
			node = i.node
			found = true
			break
		}
		if !found {
			node = program
		}
	}

	fmt.Printf("\n%s online help: <%s>\n", packageName, packageURL)

	/*
	   Note that Go currently does not support changing locale dynamically,
	   so we create an English version.
	   Once Go 2.0 releases with support to set locales, then this could easily change to programmatically determine locale.
	*/
	fmt.Printf("Report any translation bugs to "+
		"<https://translationproject.org/team/>\n")

	urlProgram := ""
	if program == "[" {
		urlProgram = "test"
	} else {
		urlProgram = program
	}

	fmt.Printf("Full documentation <%s%s>\n", packageURL, urlProgram)
	if strings.Compare(node, program) == 0 {
		fmt.Printf("or available locally via: info '(%s) %s%s'\n", "coreutils", node, " invocation")
	} else {
		fmt.Printf("or available locally via: info '(%s) %s'\n", "coreutils", node)
	}
}
