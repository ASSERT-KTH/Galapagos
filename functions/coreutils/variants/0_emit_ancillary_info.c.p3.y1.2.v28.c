go
package main

import (
    "fmt"
    "os"
    "strings"
)

type infoMap struct {
    program string
    node string
}

func emitAncillaryInfo(program string) {
    infomap := []infoMap{
        {program: "[", node: "test invocation"},
        {program: "coreutils", node: "Multi-call invocation"},
        {program: "sha224sum", node: "sha2 utilities"},
        {program: "sha256sum", node: "sha2 utilities"},
        {program: "sha384sum", node: "sha2 utilities"},
        {program: "sha512sum", node: "sha2 utilities"},
    }

    node := program

    for _, v := range infomap {
        if v.program == program {
            node = v.node
            break
        }
    }
    
    packageName := "PACKAGE NAME HERE"
    packageURL := "PACKAGE URL HERE"

    fmt.Printf("\n%s online help: <%s>\n", packageName, packageURL)

    lcMessages := os.Getenv("LANG")
    
    if !strings.HasPrefix(lcMessages, "en_") {

        fmt.Printf("%s", 
        "Report any translation bugs to "+
        "<https://translationproject.org/team/>\n")
    }
 
    
    var urlProgram string
    if program == "[" {
        urlProgram = "test"
    } else {
        urlProgram = program
    }

    fmt.Printf("Full documentation here: <%s%s> \n",
        packageURL, urlProgram);
    
    fmt.Printf("or available locally via: info '(coreutils) %s%s'\n",
    node, 
    func() string {
        if node == program { return " invocation" }
        return ""
    }()}}
