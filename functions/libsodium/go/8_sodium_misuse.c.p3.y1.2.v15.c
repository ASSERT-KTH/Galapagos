Considering that Go and C have not totally identical feature sets (as well as significantly different idioms and coding philosophies), a direct 1:1 translation doesn't provide complete result. Here’s a conceivable pass at something reminiscent, but conversion will not provide the total functionality.

go
import (
    "os"
    "sync"
)

//Assuming "_misuse_handler" as the equivalent to a function that has no parameters and no return
var misuseHandler func()

func SodiumMisuse() {
    var handler func()

    // _sodium_crit semaphore instance
    _sodium_crit := &sync.Mutex{}

    _sodium_crit.Unlock()
    _sodium_crit.Lock()

    handler = misuseHandler
    if handler != nil {
        handler()
    }

    // cause the current program to exit with a panic
    // similar to abort()
    os.Exit(1)
}


Some explanation:

1. Go's `sync.Mutex` methods `Lock()` and `Unlock()` are used as Go does not handle accessing resources the same way as C does and a Mutex is one of many approaches to manage thread-safe resource access for sodium varieties. To formulate equivalent functionality to atomic action like `sodium_crit_enter()`, a low-level Lock/Unlock available via a structure like sync.Mutex appears suitable.
2. As opposed to C's common mind-set of manipulating memory directly via pointers, Go shun it by confining those kinds of operations to particular situations and stressing "elude sharing by communicating". When pointers are required, Go (blike many other C-offspring programming languages) inclines raising the abstraction level to preclude mishaps/errors during human developmeny, thus making it difficult to screen pointer assignments.
3. Avoid putting any code after `os.Exit()` or `log.Fatal()`, It’s the only assurance that your Go code will stop immediately. Note that C's `abort()` and Go's `os.Exit(1)` does not have exact equivalence. os.Exit(1) just terminates the process as abort() does, but it does not generate a core dump. Using panic() in go could have constituent parts of crash dump but still semantically not the functional total equivalent of abort().