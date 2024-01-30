Here is an equivalent Go version of the function. Since function overloading and default argument values do not exist in Go, we do not need to maintain the original function's signature which has a default value of `null`.

Go
package main

import (
	"fmt"
	"golang.org/x/text/language"
	"golang.org/x/text/message"
	"os"
	"strings"
)

type InfoMap struct {
	program string
	node    string
}

func emitAncillaryInfo(program string) {
	var infomap = [...]InfoMap{
		InfoMap{"[", "test invocation"},
		InfoMap{"coreutils", "Multi-call invocation"},
		InfoMap{"sha224sum", "sha2 utilities"},
		InfoMap{"sha256sum", "sha2 utilities"},
		InfoMap{"sha384sum", "sha2 utilities"},
		InfoMap{"sha512sum", "sha2 utilities"},
		InfoMap{"", ""},
	}

	node := program
	m := &infomap[0]

	for i := 0; i < len(infomap); i++ {
		if infomap[i].program == "" || program == infomap[i].program {
			m = &infomap[i]
			break
		}
	}

	if m.node != "" {
		node = m.node
	}

	p := message.NewPrinter(language.English)
	p.Printf("\n%s online help: <%s>\n", "PACKAGE_NAME", "PACKAGE_URL")
	lc_messages := os.Getenv("LC_MESSAGES")

	if lc_messages != "" && !strings.HasPrefix(lc_messages, "en_") {
		fmt.Fprintln(os.Stdout.
			"Report any translation bugs to <https://translationproject.org/team/>")
	}

	url_program := program
	if program == "[" {
		url_program = "test"
	}

	p.Printf("Full documentation <%s%s>\n", "PACKAGE_URL", url_program)
	if node == program {
		p.Printf("or available locally via: info '(coreutils) %s%s'\n", node, " invocation")
	} else {
		p.Printf("or available locally via: info '(coreutils) %s%s'\n", node, "")
	}
}

The "printf" method of an instance of the "Printer" struct in the "golang.org/x/text/message" goes further and does the formatting according to a specified locale.

Also note that Go package names are lowercased by convention.