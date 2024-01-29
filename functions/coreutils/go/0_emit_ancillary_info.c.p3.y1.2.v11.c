go
package main

import (
	"fmt"
	"os"
	"strings"
)

var (
	Language                 string // placeholder for setlocale simulation
	PACKAGE_NAME, PACKAGE_URL string // placeholder for package name and url
)

func emitAncillaryInfo(program string) {
	type infoMap struct {
		program string
		node    string
	}
	const Infomaps = [6]infoMap{
		{"test invocation", "["},
		{"Multi-call invocation", "coreutils"},
		{"sha2 utilities", "sha224sum"},
		{"sha2 utilities", "sha256sum"},
		{"sha2 utilities", "sha384sum"},
		{"sha2 utilities", "sha512sum"},
	}

	node := program
	var mapProg infoMap

	for _, m := range Infomaps {
		if m.program == program {
			mapProg = m
			break
		}
	}

	if mapProg.node != "" {
		node = mapProg.node
	}

	fmt.Printf("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL)

	var LC_MESSAGES string // filler for setlocale

	/* Don't output this redundant message for English locales.
	   Note we still output for 'C' so that it gets included in the man page.  */
	if LC_MESSAGES != "en_" {
		/* TRANSLATORS: Replace LANG_CODE in this URL with your language code
	      <https://translationproject.org/team/LANG_CODE.html> to form one of
	      the URLs at https://translationproject.org/team/.  Otherwise, replace
	      the entire URL with your translation team's email address.  */
		fmt.Fprintln(os.Stdout, "Report any translation bugs to <https://translationproject.org/team/>")
	}
	/* .htaccess on the coreutils web site maps programs to the appropriate page,
	   however we explicitly handle "[" -> "test" here as the "[" is not
	   recognized as part of a URL by default in terminals.  */
	urlProgram := ""
	if program == "[" {
		urlProgram = "test"
	} else {
		urlProgram = program
	}

	fmt.Printf("Full documentation <%s%s>\n", PACKAGE_URL, urlProgram)

	var nodeString string
	if node == program {
		nodeString = " invocation"
	} else {
		nodeString = ""
	}

	fmt.Printf("or available locally via: info '(coreutils) %s%s'\n", node, nodeString)
}

Please note as in the original C implementation this function has multiple dependencies on global values which are not explicitly passed as arguments. For this reason, for those parts where that happens, placeholders are set.
Also, special locale management in Go is understaken using the golang.org/x/text/language package. Since its functionality is out-of-scope for this translation, a simple string placeholder is used instead to replicate comparable behaviour.