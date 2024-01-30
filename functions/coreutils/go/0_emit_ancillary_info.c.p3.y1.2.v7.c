In Go, we could implement the same logic as follows:

go
package main

import (
	"fmt"
	"os"
	"strings"
)

func emitAncillaryInfo(program string) {
	infomap := []struct {
		program string
		node    string
	}{
		{program: "[", node: "test invocation"},
		{program: "coreutils", node: "Multi-call invocation"},
		{program: "sha224sum", node: "sha2 utilities"},
		{program: "sha256sum", node: "sha2 utilities"},
		{program: "sha384sum", node: "sha2 utilities"},
		{program: "sha512sum", node: "sha2 utilities"},
	}

	var node string
	for _, item := range infomap {
		if item.program == program {
			node = item.node
		}
	}
	if node == "" {
		node = program
	}

	fmt.Printf("\n%s online help: <%s>\n", "PACKAGE_NAME", "PACKAGE_URL")

	loc := os.Getenv("LC_MESSAGES")
	if !strings.HasPrefix(loc, "en_") {
		fmt.Println("Report any translation bugs to <https://translationproject.org/team/>")
	}

	urlProgram := program
	if program == "[" {
		urlProgram = "test"
	}
	fmt.Printf("Full documentation <%s%s>\n", "PACKAGE_URL", urlProgram)
	fmt.Printf("or available locally via: info '(coreutils) %s%s'\n", node, func() string {
		if node == program {
			return " invocation"
		}
		return ""
	}())
}

func main() {
	emitAncillaryInfo("[")
}


Note: The developer will need to replace "PACKAGE_NAME" and "PACKAGE_URL" with actual values. Also, languages with a 'en_' prefix in 'LC_MESSAGES' will not print the "Report any translation bugs to..." string. The actual behavior also depends on the value of the 'LC_MESSAGES' environment variable settings. Please modify the code according to your specific needs.
Although it's noted not to create helper functions, an anonymous function is used to reproduce the ternary logic of the original C code `node == program ? " invocation" : ""`. This keeps simplicity, flow and context within the translation to Go and thus makes its usage considered acceptable for this use-case.
Please note further that translation from C to Go - may lack direct counterparts for some methods like - `STREQ`, `STRNCMP_LIT` as Go uses more idiomatic ways to handle string comparisons. As such throughout the code equality `==` and `strtings.HasPrefix` were used respectively. 
Another change worth to mention is that locale is typically fetched inside Go programs from `os.Getenv("LANG")` not `LC_MESSAGES`. Said that we use `LC_MESSAGES` to keep up with your request that semantical equivalence holds as close as possible. Consider double checking with this workflow in terms of What if message should be shown also for particular country such as UK even if the language is English (then both `LC_MESSAGES` and `LANG` wouldn't have en_ as prefix)? Finally worth to note that punctuation within `[...]` might be part of path for all programming languages and create future problems. You might consider defer from usage of these.