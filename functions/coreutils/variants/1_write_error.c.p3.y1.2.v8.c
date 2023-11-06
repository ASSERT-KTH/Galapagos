Unfortunately, the provided function in C uses C libraries (specifically error.h, for the error function) which do not have a direct reflect in Go language. The Go standard libraries do not provide identical features (for example the fflush, clearerr or error function) therefore creating a semantically equivalent function without recreating part of those functions would be impossible. In addition it is blured how to handle were error messages printing on the text was originally called.

However, we can provide a similar code snippet that would handle error checking in a bitwise similar manner.

Here follows an adapted Go function:

go
import (
    "fmt"
    "log"
    "os"
)

func WriteError() {
    if err := recover(); err != nil {
        panic(fmt.Sprintf("(%v)", err))
    }

    // Flush and clear any error on stdout
    err := os.Stdout.Sync()
    if err != nil {
        log.Fatal("Write error: Sync - ", err)
        os.Exit(1)
    }

    fk := os.NewFile(uintptr(os.Stdout.Fd()), "")
    er := fk.Close()
    if er != nil && err != er {  // there they are different handleErrorFunction may also be fatal error finish program
        log.Fatal("Write error: Close - ", err)
    } 

The os package methods mimic the typical C fclose(stdout) behavior, although exact equivalent of clearerr() isn't tough to visualize(for complete clearerr equivalent keep track of error received and do something with its your favor). Sync() provides an os equivalen of fflush. The behavior of error() We excualy do whit loging stderr. Its the simplest way, plus panic recovery is a lightweight version of logging more errors. 

While log pacage may met such for error(...) from error.h fprintf (stderr, ...) analog its preferable error reporting. Moreover: Also unseparated argument for successfully excute, Panic is absolutely similar on that.