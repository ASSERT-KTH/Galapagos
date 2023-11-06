import (
    "fmt"
    "os"
    "strings"
    "golang.org/x/text/language"
    "golang.org/x/text/message"
)

func emitAncillaryInfo(program string) {
    type infomap struct {
        program string
        node    string
    }
    infoMap := []infomap{
        {"[", "test invocation"},
        {"coreutils", "Multi-call invocation"},
        {"sha224sum", "sha2 utilities"},
        {"sha256sum", "sha2 utilities"},
        {"sha384sum", "sha2 utilities"},
        {"sha512sum", "sha2 utilities"},
    }

    node := program
    var mapProg infomap

    for _, m := range infoMap {
        if m.program == program {
            mapProg = m
            break
        }
    }

    if len(mapProg.node) != 0 {
        node = mapProg.node
    }

    package_name := os.Getenv("PACKAGE_NAME")
    package_url := os.Getenv("PACKAGE_URL")

    fmt.Printf("\n%s online help: <%s>\n", package_name, package_url)

    locale := language.English.String()
    if !strings.HasPrefix(locale, "en") {
        fmt.Fprint(os.Stdout, "Report any translation bugs to "+
            "<https://translationproject.org/team/>\n")
    }

    if program == "[" {
        program = "test"
    }

    tag := fmt.Sprintf("%s%s", package_url, program)

    if node == program {
        node += " invocation"
    }

    fmt.Printf("Full documentation <%s>\n", tag)

    fmt.Printf("or available locally via: info '(coreutils) %s'\n",node)
}