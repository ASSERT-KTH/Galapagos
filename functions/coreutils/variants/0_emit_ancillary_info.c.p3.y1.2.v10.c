Assuming `PACKAGE_NAME`, `PACKAGE_URL`, `_`, `fputs` as constants and providing semantic implementation details applicable to Golang but with functional equivalence to the C function. _NOTE_: Golang automatically handles UTF-8 and Language settings in its standard library and doesn't require explicit handling.

go
package main

import (
    "fmt"
    "strings"
)
const(
    PACKAGE_NAME = "coreutils"
    PACKAGE_URL = "< https://example.com/coreutils>"
)

type infomap struct {
    program string
    node    string
}

func emitAncillaryInfo(program string) {
    
    maps := []infomap{
        {"[", "test invocation"},
        {"coreutils", "Multi-call invocation"},
        {"sha224sum", "sha2 utilities"},
        {"sha256sum", "sha2 utilities"},
        {"sha384sum", "sha2 utilities"},
        {"sha512sum", "sha2 utilities"},
    }

    node := program
    for _, mapProg := range maps {
        if mapProg.program == program {
            node = mapProg.node
            break
        }
    }
    
    fmt.Printf("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL)

    fmt.Println("Report any translation bugs to " +
        "<https://translationproject.org/team/>")

    urlProgram := program

    if program == "[" {
        urlProgram = "test"
    }
    fmt.Printf("Full documentation <%s%s>\n", PACKAGE_URL, urlProgram)
    
    suffix := " invocation"
 
    if node != program {
        suffix = ""
    }

    fmt.Printf("Or available locally via: info '(coreutils)%s%s'\n", node,  suffix)
}
