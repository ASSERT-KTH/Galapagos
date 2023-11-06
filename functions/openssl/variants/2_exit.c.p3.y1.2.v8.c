Direct execution of external functions (like exit() in C) is not allowed in Go. Go has a built-in way to terminate the program and provides the equivalent of 'exit()' function through os.Exit function.
The Go 'os' package provides access to underlying operating system functionalities.

The function time.Sleep is to mimic the 'select' function behavior- Delaying the program execution by .1 second.

Here is what an equivalent may look like in Go:

go
import (
  "os"
  "time"
)

func exit(status int) {
  time.Sleep(100 * time.Millisecond)
  os.Exit(status)
}


This Go function seems very different from the C function at first glance due to the inability in Go to work directly with system functions like the 'exit' as has been done in the C function. The explicit sleep call is to resemble the tv timeout struct that select waits on in C. 

Please note, in Go, the main function will return an int to the system but an explicit call to os.Exit within a Goroutine will not respect any defer statements where it is called.

The os.Exit does not respects deferrable, and does not run them before the program exits. If deferrable need to be ran before the program exits, it is needed to correctly handle and return any errors to the place (typically the main function), which will decide whether to exit the program.