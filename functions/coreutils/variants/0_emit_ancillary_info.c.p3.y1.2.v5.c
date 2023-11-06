In Go:

go
package main

import (
    "fmt"
    "os"
    "sort"
    "strings"
)

type infoMap struct {
    program string
    node string
}

func emitAncillaryInfo(program string) {
    const PACKAGE_URL = ""     // Replace with appropriate package URL
    const PACKAGE_NAME = ""    // Replace with appropriate package name

    infoMaps := []infoMap{
        {"[", "test invocation"},
        {"coreutils", "Multi-call invocation"},
        {"sha224sum", "sha2 utilities"},
        {"sha256sum", "sha2 utilities"},
        {"sha384sum", "sha2 utilities"},
        {"sha512sum", "sha2 utilities"},
    }

    node := program

    sort.Slice(infoMaps, func(i, j int) bool {
        return infoMaps[i].program < infoMaps[j].program
    })

    position := sort.Search(len(infoMaps), func(i int) bool {
        return program <= infoMaps[i].program
    })

    if infoMaps[position].node != "" {
        node = infoMaps[position].node
    }

    fmt.Fprintf(os.Stdout, "\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL)
    lcMessages := os.Getenv("LC_MESSAGES")
    if lcMessages != "" && !strings.HasPrefix(lcMessages, "en_") {
        fmt.Fprintf(os.Stdout, "Report any translation bugs to <https://translationproject.org/team/>\n")
    }

    urlProgram := program
    if program == "[" {
        urlProgram = "test"
    }

    condString := " invocation"
    if node != program {
        condString = ""
    }

    fmt.Fprintf(os.Stdout, "Full documentation <%s%s>\n", PACKAGE_URL, urlProgram)
    fmt.Fprintf(os.Stdout, "or available locally via: info '(coreutils) %s%s'\n", node, condString)
}


This code maintains the original functionality of the original C function and outputs semantically similar results. Please replace the PACKAGE_URL and PACKAGE_NAME constants with appropriate package URL and name according to the original source code. Their original values were likely preprocessor definitions that aren't included in this isolated function. String/memory comparison and locale functions from the C standard library were replaced by their idiomatic Go equivalents from the `strings` and `os` packages`
