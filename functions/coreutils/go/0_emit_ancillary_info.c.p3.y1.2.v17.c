Go
package main

import (
    "fmt"
    "os"
    "strings"
)

func emitAncillaryInfo(program string) {
    type InfoMap struct {
		program string
		node    string
	}

	infoMapList := []InfoMap{
		{"[", "test invocation"},
		{"coreutils", "Multi-call invocation"},
		{"sha224sum", "sha2 utilities"},
		{"sha256sum", "sha2 utilities"},
		{"sha384sum", "sha2 utilities"},
		{"sha512sum", "sha2 utilities"},
		{"", ""},
	}

	node := program
	mapProg := infoMapList[0]
	i := 0
	
	for mapProg.program != "" && program != mapProg.program {
		i++
		mapProg = infoMapList[i]
	}

   	if mapProg.node != "" {
		node = mapProg.node
	}

	fmt.Printf("\n%s online help: <%s>\n", "PACKAGE_NAME", "PACKAGE_URL")

	LcMessages := "en_US.utf8" 

	if LcMessages != "" && !strings.HasPrefix(LcMessages, "en_") {
		message := "Report any translation bugs to " +
			"<https://translationproject.org/team/>\n"

		fmt.Fprintln(os.Stdout, message)
	}

	urlProgram := program
	if program == "[" {
		urlProgram = "test"
	}

	fmt.Printf("Full documentation <%s%s>\n","PACKAGE_URL", urlProgram)
	fmt.Printf("or available locally via: info '(coreutils) %s%s'\n", node, operator(node, program))
}

func operator(val1, val2 interface{}) string {
	if val1 == val2 {
		return " invocation"
	}
	return ""
}

