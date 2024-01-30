go
package main

import (
	"fmt"
	"golang.org/x/text/language"
	"golang.org/x/text/message"
)

var (
	p = message.NewPrinter(language.English)
)

func emitAncillaryInfo(program string) {
	type Infomap struct {
		program string
		node    string
	}
	
	infomap := []Infomap {
		{program: "[",		node: "test invocation"},
		{program: "coreutils",    node: "Multi-call invocation" },
		{program: "sha224sum",    node: "sha2 utilities" },
		{program: "sha256sum",    node: "sha2 utilities" },
		{program: "sha384sum",    node: "sha2 utilities" },
		{program: "sha512sum",    node: "sha2 utilities" },
		{program: "",             node: "" }, // replacement of nullptr in Go
	}

	var node string = program

	for _, im := range infomap {
		node = program
		if program == im.program {
			node = im.node
			break
		}
	}
	
	fmt.Println(p.Sprintf("\n%s online help: <%s>\n", packageName, packageURL))

	languageTag, err := language.Parse(getLocale())
	if err != nil || languageTag != language.English {
		fmt.Println(p.Sprintf("Report any translation bugs to <https://translationproject.org/team/>\n"))
	}
	
	urlProgram := program
	if program == "[" {
		urlProgram = "test"
	}

	fmt.Println(p.Sprintf("Full documentation <%s%s>\n", packageURL, urlProgram))
	
	deferPostfix := ""
	if node == program {
		deferPostfix = " invocation"
	}
	fmt.Println(p.Sprintf("Or available locally via: info '(coreutils) %s%s'\n", node, deferPostfix))
}
