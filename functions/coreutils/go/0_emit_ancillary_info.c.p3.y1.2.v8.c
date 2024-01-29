package main

import (
	"fmt"
	"strings"
)

func EmitAncillaryInfo(program string) {
	type InfoMap struct {
		program string
		node    string
	}

	infoMap := []InfoMap{
		{"[", "test invocation"},
		{"coreutils", "Multi-call invocation"},
		{"sha224sum", "sha2 utilities"},
		{"sha256sum", "sha2 utilities"},
		{"sha384sum", "sha2 utilities"},
		{"sha512sum", "sha2 utilities"},
		{"", ""},
	}

	node := program

	i := 0
	for ; i < len(infoMap) && infoMap[i].program != program; i++ {}

	if infoMap[i].node != "" {
		node = infoMap[i].node
	}

	fmt.Printf("\n%s online help: <%s>\n", "PACKAGE_NAME", "PACKAGE_URL")

	lcMessages := "en_US"
	if lcMessages != "" && !strings.HasPrefix(lcMessages, "en_") {
		fmt.Println("Report any translation bugs to <https://translationproject.org/team/>")
	}

	var urlProgram string
	if program == "[" {
		urlProgram = "test"
	} else {
		urlProgram = program
	}

	fmt.Printf("Full documentation <%s%s>\n", "PACKAGE_URL", urlProgram)
	if node == program {
		fmt.Printf("or available locally via: info '(coreutils) %s invocation'\n", node)
	} else {
		fmt.Printf("or available locally via: info '(coreutils) %s'\n", node)
	}
}