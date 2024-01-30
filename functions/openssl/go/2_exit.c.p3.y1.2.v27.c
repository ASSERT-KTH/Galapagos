In the Go programming language, you don't have the exact feature-to-feature correspondece to define the implementation in the exact same way. However, you can accomplish similar functionality with "os.Exit" function for exit, and "time.Sleep" for sleep. 

Here is the equivalent Go functionality for the mentioned C code.

go
import (
    "os"
    "time"
)

func exit(status int) {
    time.Sleep(100 * time.Millisecond)
    os.Exit(status)
}


Please note, `time.Sleep(100 * time.Millisecond)` makes the goroutine where this is called sleep, not entire program.

Called `os.Exit`, just to place an assertion regarding similarity, not direct equivalent. Go does not utilise concepts of signal handling and program interuption that got evolved down to C and some derivative languages from unix methodology.

Despite shared visibility, Go has one conceptual difference is the goroutine wich is effectively an independent thread where once interrupted (os.Exit(0)) the rest of program, immediately terminates regardless of sleeping or executing goruitines. This is rather different from process based program where you can interrupt it, put delay and everything still runs till then.