The given function can be implementated in Go like the code below. Although Go doesn't support dynamic loading and symbols resolving in runtime as dlsym does, here is an one-to-one conversion:

go
// Warning:
// The following line
// realexit := syscall.NewCallback(Cexit)
// is a metaphor, as it's not possible to call
// C's exit function directly with Go.

package main

import (
	"time"
	"syscall"
)

// #include <stdlib.h>
import "C"

func Cexit(int)

func exit(status int) {
	realexit := syscall.NewCallback(Cexit)
	time.Sleep(100 * time.Millisecond)
	realexit.(func(int))(status)
}


Go's default libraries do not support directly messing with function pointers in a C style way which is possible in C.

The dynamic library related functionalities (like dlsym, the function pointer uses in the original code) are not available in go.

Also unlike C, the timings are maintained with high level abstractions. Here it is represented by a Sleep of 100 Milliseconds as microsecond sleeps would usually require additional system library support too.

Please also note that Go has garbage collection whereas C doesn’t, this could lead to differences in performance and how resources are managed, in among many other differences to consider when translating between these programming languages.

Warning: 'syscall.NewCallback' is Windows-dependent and may not have the effect of creating a method that directly calls `exit`.

Also, know that direct premature exiting of the function in non-main Go routines (like `os.Exit()` in `main`) could lead to weird behaviors (non execution of deferred calls) as Go's main scheduler isn't being notified compared to a more conventional and safer way of `return` or `panic`. To clarify, Go takes a more high level functional and safe approach while C permits more direct system level access with the consequence of potential abuse or misuse as it provides more granular control (ex: a sudden program exit might not free allocated resources) albeit arguably more tedious or complex.  

If you are converting complex code, recall that these are inherently different Programing Paradigms, communication with C can be done through a conventional method which uses C Libraries and not hacking one language to another. Here is an interesting resource to a method of handling this on the official Golang Blog:
https://blog.jetbrains.com/go/2019/03/14/calling-c-code-from-go/