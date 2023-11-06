func emitAncillaryInfo(program string) {
	type infomap struct {
		program string
		node    string
	}

	infomaps := []infomap{
		{"[", "test invocation"},
		{"coreutils", "Multi-call invocation"},
		{"sha224sum", "sha2 utilities"},
		{"sha256sum", "sha2 utilities"},
		{"sha384sum", "sha2 utilities"},
		{"sha512sum", "sha2 utilities"},
		{"", ""},
	}

	node := program
	for _, map_prog := range infomaps {
		if program == map_prog.program {
			node = map_prog.node
			break
		}
	}

	const packageName = "your_package_name"
	const packageUrl = "your_package_url"

	fmt.Printf("\n%s online help: <%s>\n", packageName, packageUrl)
	_, lcMessages, _ := gotextlang.GetLang()
	if lcMessages != nil && !strings.HasPrefix(*lcMessages, "en_") {
		fmt.Fprint(os.Stdout, _("Report any translation bugs to <https://translationproject.org/team/>\n"))
	}

	urlProgram := program

	if program == "[" {
		urlProgram = "test"
	}

	fmt.Printf("Full documentation <%s%s>\n", packageUrl, urlProgram)
	nodeAppend := " invocation"
	if node == program {
		nodeAppend = ""
	}
	fmt.Printf("or available locally via: info '(coreutils) %s%s'\n", node, nodeAppend)
} 

Please consider that there's no one-to-one equivalence for some specific C functionalities/constants in Go e.g., setlocale or PACKAGE_NAME and SETREQ (a macro in gnulib for comparing strings). I have provided an equivalent working solution by using package gotextlang that resembles closely to the function in C except for  handling of C's language locale features. You should fill packaging constants yourself.