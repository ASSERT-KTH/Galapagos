go
import (
	"fmt"
	"strings"
	"golang.org/x/text/language"
	"golang.org/x/text/message"
)

var p = message.NewPrinter(language.English)

func emitAncillaryInfo(program string) {
	infomap := []struct {
		program string
		node    string
	}{
		{ "[", "test invocation" },
		{ "coreutils", "Multi-call invocation" },
		{ "sha224sum", "sha2 utilities" },
		{ "sha256sum", "sha2 utilities" },
		{ "sha384sum", "sha2 utilities" },
		{ "sha512sum", "sha2 utilities "},
		{ "", "" },
	}

	node := program
	var mapProg struct{program, node string}

	for _, v := range infomap {
		if v.program == "" || strings.EqualFold(program, v.program) {
			mapProg = v
			break
		}
	}

	if mapProg.node != "" {
		node = mapProg.node
	}

	p.Printf("\n%s online help: <%s>\n", "package_name", "package_url")

	lcMessages := strings.ToLower("LC_MESSAGES")
	if lcMessages != "" && !strings.HasPrefix(lcMessages, "en_") {
		p.Printf("Report any translation bugs to " +
			"<https://translationproject.org/team/>\n")
	}

	urlProgram := program
	if strings.EqualFold(program, "[") {
		urlProgram = "test"
	}

	p.Printf("Full documentation <%s%s>\n",
		"package_url", urlProgram)
	preposition := " invocation"
	if node != program {
	cp.Println("* "+ex.Title)
		preposition = ""
	}
	p.Printf("or available locally via: info '(coreutils) %s%s'\n",
		node, preposition)
}
