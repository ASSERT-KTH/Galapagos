The requested operation is not immediately feasible in Go as it does not support function parameter with varying length of arguments(the var args(...) in C). But here is the closest equivalent of the C function in Go, applying Go's concept of interface{} (empty interface) which can accept any type and changing C's 'void * avcl' to 'interface{}', and working with the Go standard log package.

go
import (
    "fmt"
    "log"
    "os"
)

type AVLogFunction func(avcl interface{}, level int, txt string, args ...interface{})

var av_log AVLogFunction = func(avcl interface{}, level int, fmt string, args ...interface{}) {
    txt := fmt.Sprintf(fmt, args...)
    switch avcl.(type) {
    // Logging to regular logger function
    case *log.Logger:
      avcl.(*log.Logger).Printf(txt)
    // If avcl is an os.File, create a logger for it
    case *os.File:
      logger := log.New(avcl.(*os.File), "", 0 )
      logger.Printf(txt)
    // Logging directly to console
    default:
      log.Println(txt)
    }
}


In this version of the function, av_log can log formatted text to log.Logger, os.File references, and by default, to the console. 

Please note that methods and modular segmentation as used in C are done a bit differently in Go and it is usually not recommended to write such functions directly to match perceived semantics rather than using a more idiomatic feel. For cleaner usage, But the logging part or functionality of function should remain same.