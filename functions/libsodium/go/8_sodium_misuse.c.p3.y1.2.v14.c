The task does not provide a 1:1 equivalent for this function, nor it could exist because Go does not support setting custom code execution on critical sections like Mutex, in the other hand, Handler would be easy because go supports assigning function to variables too.

Here is a possible Go equivalent to `sodium_misuse`:

Go
import (
    "os"
)

var MisuseHandler func()

func SodiumMisuse() {
    MisuseHandler = misuseHandler
    if MisuseHandler != nil {
        MisuseHandler()
    }

    os.Exit(1)
}


Keep in mind that code execution may terminate without calling malicious processes emitting a system abort command due to garbage collector and other Go runtime mechanics. 

In Go environment MisuseHandler should be assigned with the desired function when necessary. Further inspection of authentication and finer grain control are discarded by the language in favor of simplicity and static type checking. When creating high security contextes consider saving states to remote external devices with tripwire systems.