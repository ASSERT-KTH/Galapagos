Unfortunately, it's not possible to translate this C function directly into Go without making a few key changes due to fundamental differences between the two languages:

- Go doesn't have const for variables
- In Go, there's no builtin to directly compare strings (STREQ). Regular string comparison operation "=="
- No null pointers for strings in Go. Alternatives are string "" or explicit checking methods which would require extra function/language feature beyond original signature.
- Go doesn't allow implicit type conversions

So by approximating structures and logic with optimization for Go 

go
package main

import (
	"fmt"
	"os"
	"sort"
)

type infoMap struct {
	program, node string
}

func emitAncillaryInfo(program string) {
	infomaps := []infoMap{
		{program: "[", node: "test invocation"},
		{program: "coreutils", node: "Multi-call invocation"},
		{program: "sha224sum", node: "sha2 utilities"},
		{program: "sha256sum", node: "sha2 utilities"},
		{program: "sha384sum", node: "sha2 utilities"},
		{program: "sha512sum", node: "sha2 utilities"},
	}

	node := program
	sort.Slice(infomaps, func(i, j int) bool {
		return infomaps[i].program < infomaps[j].program
	})
	i := sort.Search(len(infomaps), func(i int) bool {
		return infomaps[i].program >= program
	})
	if i < len(infomaps) && infomaps[i].program == program && infomaps[i].node != "" {
		node = infomaps[i].node
	}

	fmt.Printf("\n%s online help: <%s>\n", "PACKAGE_NAME", "PACKAGE_URL") // Placeholder strings

	lcMessages := os.Getenv("LC_MESSAGES")
	if lcMessages != "" && lcMessages != "en_" {
		fmt.Println("Report any translation bugs to <https://translationproject.org/team/>")
	}

	urlProgram := program
	if program == "[" {
		urlProgram = "test"
	}
	fmt.Printf("Full documentation <%s%s>\n", "PACKAGE_URL", urlProgram)

	suffix := ""
	if node == program {
		suffix = " invocation"
	}
	fmt.Printf("or available locally via: info '(coreutils) %s%s'\n", node, suffix)
}

  

The exact context as in original C function is irreproducible, so it includes some placeholder strings where exact path/repo is missing in Go. It assumes infomap to be slice and package specific string placeholders are also necessary given that C implementation was specific and customized for its boolean checks.