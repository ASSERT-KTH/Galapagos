Below is a basic implementation in Go language. It's important to mention that this function below could be adjusted based on the actual application dependencies:
go
import (
    "fmt"
    "os"
    "strings"
)

type infomap struct {
    program string
    node    string
}

func EmitAncillaryInfo(program string) {
    infoMap := []infomap{
        {"[", "test invocation"},
        {"coreutils", "Multi-call invocation"},
        {"sha224sum", "sha2 utilities"},
        {"sha256sum", "sha2 utilities"},
        {"sha384sum", "sha2 utilities"},
        {"sha512sum", "sha2 utilities"},
        {"", ""},
    }

    var node string = program
    for _, mapProg := range infoMap {
        if program == mapProg.program {
            node = mapProg.node
        }
    }

    _, _ = fmt.Printf("\n%s online help: <%s>\n", "PACKAGE_NAME", "PACKAGE_URL")

    lcMessages := os.Getenv("LC_MESSAGES")
    if lcMessages != "" && strings.Index(lcMessages, "en_") != 0 {
        fputs("Report any translation bugs to <https://translationproject.org/team/>\n", nil)
    }

    var urlProgram string = program
    if program == "[" {
        urlProgram = "test"
    }

    _, _ = fmt.Printf("Full documentation <%s%s>\n", "PACKAGE_URL", urlProgram)
    _, _ = fmt.Printf("or available locally via: info '(coreutils) %s%s'\n", node, program);
}


Please, do change constant values(seen as `"PACKAGE_NAME"`, `"PACKAGE_URL"`, and also function dependencies (`fputs`). 

1. In this Go translation, it is expected that "LC_MESSAGES" is represented as an Environment variable on a similar system.
2. The implementation takes in plain strings as an argument. 
3. Annotation method (seen as `(` and `)`) has not been implemented in this Go equivalent, You might add this onto your final transformation. Design choice depends on your application structure and Go function transformation way.  

Results in output formats should comply to the original c function translate way.