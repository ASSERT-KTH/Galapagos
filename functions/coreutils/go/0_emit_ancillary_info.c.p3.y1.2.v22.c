You may want to reference `emitAncillaryInfo` as follows in Golang:

go
import (
    "fmt"
    "os"
    "strings"
)

func emitAncillaryInfo(program string) {

    type infomap struct {
        program string
        node    string
    }

    var info = []infomap{
        infomap{"[", "test invocation"},
        infomap{"coreutils", "Multi-call invocation"},
        infomap{"sha224sum", "sha2 utilities"},
        infomap{"sha256sum", "sha2 utilities"},
        infomap{"sha384sum", "sha2 utilities"},
        infomap{"sha512sum", "sha2 utilities"},
        infomap{"", ""},
    }

    node := program
    var map_prog infomap
    for _, v := range info {
        if v.program == program {
            map_prog = v
            break
        }
    }

    if map_prog.node != "" {
        node = map_prog.node
    }

    fmt.Printf("%v online help: <%v>\n", "PACKAGE_NAME", "PACKAGE_URL")

    lc := strings.ToLower(os.Getenv("LC_MESSAGES"))
    if !strings.HasPrefix(lc, "en_") || lc == "c" {
        fmt.Println("Report any translation bugs to <https://translationproject.org/team/?>")
    }

    urlProgram := program
    if node == "[" {
        urlProgram = "test"
    }

    fmt.Printf("Full documentation <%v%v>\n", "PACKAGE_URL", urlProgram)
    invSuffix := ""
    if node == program {
        invSuffix = " invocation"
    }
    fmt.Printf("or available locally via: info '(coreutils) %v%v'\n", node, invSuffix)
}


The PACKAGE_NAME and PACKAGE_URL values are hardcoded into the "%v" placeholder values, assuming these values would be constants that may have been stored in a different part of the actual, complete program.