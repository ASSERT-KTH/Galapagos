Unfortunately, the requirement of keeping the original function's signature with a char pointer wouldn't apply directly to Go as it doesn't have char pointers or exact equivalents of some C specific like `setlocale (LC_MESSAGES, nullptr)` But here is a semantically equivalent function in Go, transforming as much as it's possible from the original:

go
package main

import (
	"fmt"
	"os"
	"strings"
)

const (
	PACKAGE_NAME = "you_pkg_name"
	PACKAGE_URL  = "your_pkg_url"
)

func emitAncillaryInfo(program string) {
	type infomap struct {
		p *string
 		n *string
	}
	
	emInfo := [7]infomap{
		{p: newString("["), n: newString("test invocation")},
		{p: newString("coreutils"), n: newString("Multi-call invocation")},
		{p: newString("sha224sum"), n: newString("sha2 utilities")},
		{p: newString("sha256sum"), n: newString("sha2 utilities")},
		{p: newString("sha384sum"), n: newString("sha2 utilities")},
		{p: newString("sha512sum"), n: newString("sha2 utilities")},
		{p: nil, n: nil},
	}

	node := program
	i := 0

	for emInfo[i].p != nil && *(emInfo[i].p) != program {
		i++
	}

	if emInfo[i].n != nil {
		node = *(emInfo[i].n)
	}

	fmt.Printf("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL)

	// This is how you retrieve locale information in Go. The details may vary slightly
	// Depending on the specifics of the systems you target.
	loc, _ := time.LoadLocation("")

	// Assume English if a location isn't set
	if loc == nil || !strings.HasPrefix(loc.String(), "en_") {
			fm.Printf("Report any translation bugs to " +
					   "<https://translationproject.org/team/>\n");
	}

	url_program := program
	if url_program == "[" {
		url_program = "test"
	}

	fmt.Printf("Full documentation <%s%s>\n", PACKAGE_URL, url_program)
	fmt.Printf("or available locally via: info '(coreutils) %s%s'\n",node,node == program ? " invocation" : "")
}

func newString(s string) *string { return &s }
