Here is the equivalent function in Go:

go
import (
    "fmt"
    "os"
    "strings"
)

func EmitAncillaryInfo(program string) {
	infomap := []struct{ Program, Node string }{
		{"[", "test invocation"},
		{"coreutils", "Multi-call invocation"},
		{"sha224sum", "sha2 utilities"},
		{"sha256sum", "sha2 utilities"},
		{"sha384sum", "sha2 utilities"},
		{"sha512sum", "sha2 utilities"},
	}

	node := program

	for _, item := range infomap {
		if item.Program == program {
			node = item.Node
			break
		}
	}

	fmt.Printf("\n%s online help: <%s>\n", PackageName, PackageURL)

	if !strings.HasPrefix(os.Getenv("LC_MESSAGES"), "en_") {
		fmt.Printf("Report any translation bugs to <https://translationproject.org/team/>\n")
	}

	urlProgram := program
	if program == "[" {
		urlProgram = "test"
	}

	fmt.Printf("Full documentation <%s%s>\n", PackageURL, urlProgram)

	invocation := ""
	if node != program {
		invocation = " invocation"
	}

	fmt.Printf("or available locally via: info '(coreutils) %s%s'\n", node, invocation)
}

This code assumes that the constants `PackageName` and `PackageURL` are declared elsewhere in the same package. Their case (upper camel case) also suggests that these names should exported constants in the Go code.