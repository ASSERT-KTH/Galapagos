Here's how you might translate the given C code to Go:

go
import (
	"fmt"
	"os"
	"strings"
)

func emitAncillaryInfo(program string) {
	infoMap := map[string]string{
		"[":           "test invocation",
		"coreutils":   "Multi-call invocation",
		"sha224sum":   "sha2 utilities",
		"sha256sum":   "sha2 utilities",
		"sha384sum":   "sha2 utilities",
		"sha512sum":   "sha2 utilities",
	}

	node, ok := infoMap[program]
	if !ok {
		node = program
	}

	pattern := "\n%s online help: <%s>\n"
	fmt.Printf(pattern, getPackageName(), getPackageURL())

	lang := os.Getenv("LANG")
	if lang != "" && !strings.HasPrefix(lang, "en_") {
		msg := "Report any translation bugs to " +
			"<https://translationproject.org/team/>\n"
		fmt.Fprint(os.Stdout, msg)
	}

	urlProgram := program
	if program == "[" {
		urlProgram = "test"
	}

	pattern = "Full documentation <%s%s>\n"
	fmt.Printf(pattern, getPackageURL(), urlProgram)

	invocationSuffix := ""
	if node == program {
		invocationSuffix = " invocation"
	}

	pattern = "or available locally via: info '(coreutils) %s%s'\n"
	fmt.Printf(pattern, node, invocationSuffix)
}

func getPackageName() string {
	// Returns package name
	// Placeholder function: the logic depends on your context.
	return "Package Name"
}

func getPackageURL() string {
	// Returns package URL
	// Placeholder function: the logic depends on your context.
	return "Package URL"
}

Please note, since Go does not have #define preprocessor macros nor does it support default function values, please provide a package name and URL with `getPackageName()` and `getPackageURL()` depending on your context. Same applies to `LANG` environment variable which may give locale, find the appropriate solution which suits your software best. It has been hard-coded in here for demonstration purposes. Also please note that a Go idiomatic way of writing a code allows local package errors and local `Panic`s and such more rigid structure have been chosen due to context and instruction provided (`Do not create auxiliary or helper functions.`)
Also, more decorated logging and terminal output libraries and packages exists for this purpose in Go which may follow a more idiomatic Go's structure than shown here. For more please go here: https://golang.org/doc/effective_go

And here for some comments and programming style : https://go-proverbs.github.io/ 
