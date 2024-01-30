func emitAncillaryInfo(program string) {
    infomap := []struct{
        program string
        node string
    }{
        {"[", "test invocation"},
        {"coreutils", "Multi-call invocation"},
        {"sha224sum", "sha2 utilities"},
        {"sha256sum", "sha2 utilities"},
        {"sha384sum", "sha2 utilities"},
        {"sha512sum", "sha2 utilities"},
        {"", ""},
    }

    node := program
    mapProg := infomap

    i := 0
    for mapProg[i].program != "" && mapProg[i].program != program {
        i++
    }

    if mapProg[i].node != "" {
        node = mapProg[i].node
    }

    fmt.Printf("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL)

    lcMessages := os.Getenv("LC_MESSAGES")
    if lcMessages != "" && !strings.HasPrefix(lcMessages, "en_") {
        fmt.Fprint(os.Stdout, "Report any translation bugs to <https://translationproject.org/team/>\n")
    }

    urlProgram := ""
    if program == "[" {
        urlProgram = "test"
    } else {
        urlProgram = program
    }

    fmt.Printf("Full documentation <%s%s>\n", PACKAGE_URL, urlProgram)

    extraNode := ""
    if node == program {
        extraNode = " invocation"
    }
    
    fmt.Printf("or available locally via: info '(coreutils) %s%s'\n", node, extraNode)
}