Since Go follows a different design pattern, function pointer like in C is not a common practice. There are no direct equivalents to `abort()` and `NULL` check. Execution of `panic()` is closer to C’s `abort()` though they are not fully equivalent. Based on these details, here is as close as an equivalent as you can get in Golang to the above C function:

Additionally, as suggested by recommendations made in comments, errors in Go are typically handled via error returns instead of panicking. 

Please see this assumption:

`_misuse_handler` here is assumed to define a package-level function with no parameters and no return values.

Note: This function does not abort, because there's no direct equivalent in Go. You could call os.Exit() to stop the program.

Go
package main

import (
  "os"
)

var _misuseHandler func()

func sodiumMisuse() {
  sodiumCritLeave()
  _, err := sodiumCritEnter()
  
  if err == nil && _misuseHandler != nil {
        _misuseHandler()
    } else if err != nil {
        panic(err)
    } else {
        os.Exit(1)
    }

}

func sodiumCritEnter() (bool, error) {

  // implement your function here based on C equivalent

  return true, nil
}

func sodiumCritLeave(){

  // implement your function here based on C equivalent
  
}



If your application requires C-like behavior for `_method_handler` being null (i.e., deterministic pending termination if `_method_handler` is null), then `os.Exit(1)` provides this. However, crashing the app on null for a callback function is against typical Go convention and is generally advised against.