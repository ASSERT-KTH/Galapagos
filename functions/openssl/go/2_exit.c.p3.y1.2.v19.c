Due to differences in language design, it's impossible to directly translate this code into Golang. The main roadblocks are:

1) Golang does not support the concept of signal processing or dlsym-like functionality as in C. One rough approximation we can use is os.Exit function. But unlike the C version where you might schedule cathable signals, in the case of os.Exit, defer functions don't run.

2) Time delays can be implemented using time.Sleep function in Go.

Here is an approximate translation:
go
package main

import (
    "os"
	"time"
)

func exit(status int) {
    time.Sleep(100 * time.Millisecond)
    os.Exit(status)
}

Please note that this translation doesn't cater for setting up signal handling or linking to other libraries (functions defined in other link files) like the pointer to exit function in 'dlfcn.h' which is very C specific.