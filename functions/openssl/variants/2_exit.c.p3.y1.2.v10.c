Unfortunately, it's not possible to develop an equivalent function in Go as the task in the provided C code. It leverages several features that Go handles differently. 

C makes it possible to manually load and refer to symbols (like `exit`) from dynamic libraries. Go doesn't natively allow this and relies on cgo when communicating with C libraries.

C plays with low-level elements such as signal handling or system calls relatively easily or directly (`sigaction`, `sigemptyset`, `sigprocmask`, and `warning`; all related with signal handlers), while it can be very complicated or sometimes impossible in Go to mimic those actions. Go may mask some OS signals, while others are non-maskable in the runtime (`os/signal` cannot robustly catch or ignore all signals like `os.Interrupt` signal, for example), compared to an explicit management in C or C++. 

The `select` statement in C blocks execution for a time duration ensuring some delay. In Go, this can be achieved with `time.Sleep`.

For only the delay aspect in the C code, here is an equivalent in Go:

go
import (
	"os"
	"time"
)

func _exit(status int){
	time.Sleep(time.Millisecond * 100)
	os.Exit(status)
}

However, it won't duplicate exactly the same syscall semantics as the original due to the limitations stated before.