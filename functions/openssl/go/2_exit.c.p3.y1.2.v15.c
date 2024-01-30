Here's an equivalent code snippet in Go:

go
// NOTE: This example DOES NOT compile. The Go stdlib does not provide a direct
// replacement for all parts of this function, for reasons of safety and
// cleanliness. Go does not permit direct access to symbols as per C via `dlsym`
// etc..

 

This version does not completely copy the function, due to Go's different nature compared to C. Since we cannot call symbols or stack variables as we can do in a relatively low-level language like C , we might need to opt for more portable and wrapper-oriented code. 
Despite that, this replicates the main three steps of sleeping for a bit, then exiting with the status. Please note that we also can't directly translate "exit(int)", because Go puts an hard constraint on us using os.Exit only, which takes int as a parameter but cannot be hooked or change. But other UNIX systems or well some libraries might want to add a post-hook to clean up which would not work in most conditions bevause programm would be terminated before calling realexit. 
Due to this safety concerns or limitations the function might show an error which needed to be strongly considered. Kindly writing a tailor made function applicable to the task can be most efficent. 

Function:

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
