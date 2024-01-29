Because Go does not use header files or global variables similar to C++'s `PACKAGE_NAME`, `PACKAGE_URL`, or `LC_MESSAGES`, assume these variables are constants initialized earlier in the Go code.

go
import (
	"fmt"
	"golang.org/x/text/message"
	"os"
	"strings"
)

var (
	PACKAGE_NAME, PACKAGE_URL string
	infomap                   []map[string]string
	lc_messages               string
)

func emit_ancillary_info(program string) {
	infomap = []map[string]string{
		{"program": "[", "node": "test invocation"},
		{"program": "coreutils", "node": "Multi-call invocation"},
		{"program": "sha224sum", "node": "sha2 utilities"},
		{"program": "sha256sum", "node": "sha2 utilities"},
		{"program": "sha384sum", "node": "sha2 utilities"},
		{"program": "sha512sum", "node": "sha2 utilities"},
		{"program": "", "node": ""},
	}

	node := program
	for _, map_prog := range infomap {
		if program == map_prog["program"] {
			node = map_prog["node"]
			break
		}
	}

	fmt.Fprintf(os.Stdout, "\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL)

	if !strings.HasPrefix(lc_messages, "en_") {
		fmt.Fprintf(os.Stdout, "Report any translation bugs to "+
			"<https://translationproject.org/team/>\n")
	}

	url_program := program
	if strings.EqualFold(program, "[") {
		url_program = "test"
	}

	fmt.Fprintf(os.Stdout, "Full documentation <%s%s>\n", PACKAGE_URL, url_program)
	fmt.Fprintf(os.Stdout, "or available locally via: info '(coreutils) %s%s'\n", node,
		strings.Compare(node, program) == 0 ? " invocation" : "")
}


Note that a Go translation probably would encapsulate many elements of this function in top-level configuration data, but your restrictions to preserve global references, preserving the existing function signature, and not creating any ancillary helper functions severely limit idiomatic options. This translated code assumes `PACKAGE_NAME`, `PACKAGE_URL`, `infomap`, and `lc_messages` are globally initialized earlier in the same file. It does not account for data race conditions or localization.