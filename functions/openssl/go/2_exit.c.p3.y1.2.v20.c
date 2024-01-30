This function doesn't have a straightforward Go equivalent - the reason for this is that Go doesn't provide direct support for dynamic linking and loading in the same way that C does. Go uses static linking instead.

This caution given, the final line, a 100 ms sleep delay before application exit, can be accomplished, but it lacks the attempted dynamic lookup for the "real" exit function:

go
import (
    "os"
    "time"
)

func exit(status int) {
    time.Sleep(100 * time.Millisecond)
    os.Exit(status)
}


Additionally, we can not put any delay by Exiting immediately without giving OS, scheduler etc chance to run other threads, as documented here https://en.wikipedia.org/wiki/Exit_(system_call).

Mostly, delay that we see before the termination of process is likely due to OS, parent process or job scheduler cleaning up resources, not functions running after the call to `exit()`. Therefore, putting a sleep before `os.Exit(status)` in a goroutine won't work as expected and it will terminate immediately as soon it reaches the line `os.Exit(status)`. Thus, only direct equivalent I can think of is:

go
import "os"

func exit(status int) {
    os.Exit(status)
}
