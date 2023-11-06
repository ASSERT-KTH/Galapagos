The Go programming language does not support mapping like C or passing unnamed objects. Moreover, strings in Go are compared using `==` rather than methods like `STREQ` The best straightforward conversion, upholding the function’s logic but ignoring the 'i18n' and '[...] for 'C'/'en_' locale checks as there is no straightforward correspondence of locale checks or `_()` gettext calls would look like:

go
package main

import (
    "fmt"
    "os"
    "strings"
)

type infoMap struct {
    program string
    node    string
}

func emitAncillaryInfo(program string) {
    infomap := []infoMap {
        {program: "[", node: "test invocation"},
        {program: "coreutils", node: "Multi-call invocation"},
        {program: "sha224sum", node: "sha2 utilities"},
        {program: "sha256sum", node: "sha2 utilities"},
        {program: "sha384sum", node: "sha2 utilities"},
        {program: "sha512sum", node: "sha2 utilities"},
        {program: "", node: ""},
    }

    node := program
    mapProg := infomap[0]
    index := 0
    for mapProg.program != "" && program != mapProg.program {
        index++
        mapProg = infomap[index]
    }
    
    if mapProg.node != "" {
        node = mapProg.node
    }
    
    fmt.Fprintf(os.Stdout, "\n%s online help: <%s>\n", "PACKAGE_NAME", "PACKAGE_URL")
    
    // C getEndOfLiteral substitution since C deals in '`' as locale changers.
    fmt.Fprintf(os.Stdout, "Report any translation bugs to "+
    "<https://translationproject.org/team/>\n")
    
    urlProgram := program
    if program == "[" {
        urlProgram = "test"
    }
    
    fmt.Fprintf(os.Stdout, "Full documentation <%s%s>\n", "PACKAGE_URL", urlProgram)
    qualifier := ""
    if node == program {
        qualifier = " invocation"
    }
    fmt.Fprintf(os.Stdout, "or available locally via: info '(coreutils) %s%s'\n", node, qualifier)
}


Please review and test this code. This will only output _(stdout)_ messages following your original format as according to the language _C_ literals (`_\("literal")`). replacing `"PACKAGE_NAME"` and `"PACKAGE_URL"` for the accurate references, these elements in this code have to be correctly specified before it can compile without errors.