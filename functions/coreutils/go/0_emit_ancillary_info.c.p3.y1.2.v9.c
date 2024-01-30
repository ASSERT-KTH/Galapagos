The exact code conversion from C to Go would not be possible due to differences in language syntax, standard functions and behavior. However, here's a Go version with similar semantics:

go
package main

import (
    "fmt"
    "os"
    "strings"
)

var packageURL string = "..."

type InfoMap struct {
	program string
	node    string
}

func emitAncillaryInfo(program string) {
	mapProg := [7]InfoMap{
		{"[", "test invocation"},
		{"coreutils", "Multi-call invocation"},
		{"sha224sum", "sha2 utilities"},
		{"sha256sum", "sha2 utilities"},
		{"sha384sum", "sha2 utilities"},
		{"sha512sum", "sha2 utilities"},
		{"", ""},
	}

	node := program
	for _, v := range mapProg {
		if v.program == program {
			node = v.node
			break
		}
	}

	fmt.Printf("\n%s online help: <%s>\n", os.Getenv("PACKAGE_NAME"), packageURL)

	if !strings.HasPrefix(os.Getenv("LANG"), "en_") {
		fmt.Fprintf(os.Stdout, "Report any translation bugs to "+"<https://translationproject.org/team/>\n")
	}

	urlProgram := program
	if program == "[" {
		urlProgram = "test"
	}

	fmt.Printf("Full documentation <%s%s>\n", packageURL, urlProgram)
        suffix := " invocation"
        if node == program {
             suffix = ""
        }
	fmt.Printf("or available locally via: info '(coreutils) %s%s'\n", node, suffix)
}


Regarding the `PACKAGE_NAME` and `PACKAGE_URL` variables, they are not standard in Go. The assumption here is you will set these as os environment variables. Please make sure you are following the actual behavior/strategy for this. The translation of locale management and the `_()` translation function indicates the general direction but should be replaced with appropriate i18n or l10n libraries. As Golang does regulate system-locale-dependent behaviors strictly in the standard library, the functionality of 'LC_MESSAGES' equivalent couldn't be utilized properly. The assumption in the conversion above is the locale will be set in the 'LANG' environment variable.
