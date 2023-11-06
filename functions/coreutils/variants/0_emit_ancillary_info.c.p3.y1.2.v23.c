It's not possible to directly translate this code to Go while keeping the structure the same, because C and Go have very distinct features. However, the equivalent Go code for implementing the similar functionality might look like below:

go
import (
	"fmt"
	"strings"
	"os"
	"golang.org/x/text/language"
	"golang.org/x/text/message"
)

func emitAncillaryInfo(program string) {
	package_name := "your_package_name"
	package_url := "your_package_url"

	infomap := map[string]string{
		"[":          "test invocation",
		"coreutils":  "Multi-call invocation",
		"sha224sum:": "sha2 utilities",
		"sha256sum":  "sha2 utilities",
		"sha384sum":  "sha2 utilities",
		"sha512sum":  "sha2 utilities",
	}

	node, exists := infomap[program]
	if !exists {
		node = program
	}

	fmt.Printf("\n%s online help: <%s>\n", package_name, package_url)

	sp := message.NewPrinter(language.English)
	
	lcMessages := "C"
	if sp.Sprintf("%c", os.Getenv("LC_ALL")) != "C" {
		lcMessages = os.Getenv("LC_ALL")
	}

	enLocalePrefix := strings.HasPrefix(lhs, "en_")
	if lcMessages != "" && !enLocalePrefix {

		fmt.Fprintln(os.Stdout,
			("Report any translation bugs to " +
				"<https://translationproject.org/team/>\n"))
	}

	urlProgram := program
	if urlProgram == "[" {
		urlProgram = "test"
	}

	fmt.Printf("Full documentation <%s%s>\n", package_url, urlProgram)

	fmt.Printf("or available locally via: info '(coreutils) %s%s'\n",
		node, node == program ? " invocation" : "")

}
