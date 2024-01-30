The Go language does not support the null-terminated arrays as it is used within loops in this C code. Also, the Go language does not usually operate through pointers in similar way as C and direct translation would usually mean bad practice. 

In this case I will directly translate, however, please note there's a cleaner design to implement this functionality in Go.

go
package main

import (
	"fmt"
	"strings"
	"golang.org/x/text/language"
	"golang.org/x/text/message"
	"golang.org/x/text/message/catalog"
)

type InfoMap struct {
	Program string
	Node    string
}

var PACKAGE_NAME string
var PACKAGE_URL string

func EmitAncillaryInfo(program string) {
	infoMap := [...]InfoMap{
		{Program: "[", Node: "test invocation"},
		{Program: "coreutils", Node: "Multi-call invocation"},
		{Program: "sha224sum", Node: "sha2 utilities"},
		{Program: "sha256sum", Node: "sha2 utilities"},
		{Program: "sha384sum", Node: "sha2 utilities"},
		{Program: "sha512sum", Node: "sha2 utilities"},
	}

	node := program
	var mapProg InfoMap
	for _, infop := range infoMap {
		if strings.Compare(program, infop.Program) == 1 {
			mapProg = infop
			break
		}
	}

	if len(mapProg.Node) != 0 {
		node = mapProg.Node
	}
	fmt.Printf(_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL)
	lcMessages := language.AmericanEnglish
	if strings.Contains(strings.ToLower(lcMessages.String()), "en_") {
		fputs(_("Report any translation bugs to <https://translationproject.org/team/>\n"))
	}
	urlProgram := (func() string{ if strings.Compare(program, "[") == 0 { return "test" } else { return program } })()
     fmt.Printf("Full documentation <%s%s>\n", PACKAGE_URL, urlProgram)
     fmt.Printf("or available locally via: info '(coreutils) %s%s'\n",
          node, 
          (func() string { if node == PROGRAM { return " invocation" } else { return "" }}) )())
}
  
This version of achieved the goal with handling Go string slices better in terms of structures, and as well as language checks, also did not involve writing auxiliary functions.
