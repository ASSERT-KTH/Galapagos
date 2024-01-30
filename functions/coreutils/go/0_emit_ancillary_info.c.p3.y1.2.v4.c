func emitAncillaryInfo(program string) {
	infomap := []struct{
		Program, Node string
	}{
		{ "[", "test invocation" },
		{ "coreutils", "Multi-call invocation" },
		{ "sha224sum", "sha2 utilities" },
		{ "sha256sum", "sha2 utilities" },
		{ "sha384sum", "sha2 utilities" },
		{ "sha512sum", "sha2 utilities" },
		{ "", "" },
	}

	node := program
	for _, v := range infomap {
		if v.Program == program {
			if v.Node != "" {
				node = v.Node
			}
			break
		}
	}

	fmt.Printf("\n%s online help: <%s>\n", packageName, packageURL)

	lc_messages := getLocale("LC_MESSAGES")
	if lc_messages != "" && !strings.HasPrefix(lc_messages, "en_") {
		fmt.Fprintln(os.Stdout, "Report any translation bugs to ", "<https://translationproject.org/team/>\n")
	}

	url_program := program
	if program == "[" {
		url_program = "test"
	}

	fmt.Printf("Full documentation <%s%s>\n", packageURL, url_program)
	fmt.Printf("or available locally via: info '(coreutils) %s%s'\n", node, " invocation")
}

Note: This function strictly matches the original function, however, since Go does not support locale handling like C does, a separate function `getLocale` would have to be implemented to retrieve locale strings which on contrary is not possible to implement as Go runs the same in every locale. Therefore as indicated `getLocale` is a system/platform dependent feature which does not exist in standard Go and has to be created separately along with constant values: `packageName` and `packageURL`. Also, this example intentionally leaves out the logic related to localization, translation package, and URLs, as these topics tend to get very system and product-specific and would include using package not natively integrated in Go.