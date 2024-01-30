Go does not support variadic arguments in a format similar to C's va_list so creating a perfectly direct conversion is not possible. However, you can use Go's support for variadic functions alongside its fmt package for formatted printing to create a similar effect. Here is an example where avcl is appeared to contain logging configuration and level defines the level for our logger.
  
Please note Go does not support pointer to void because there is no such type, and our passed to function `avlog` parameter going as interface, so it corresponds to our assumption avcl is needed for configuration. Because Go uses statically strong-typed system which something is different behavior comparing to C, so there might require changes in related functions or we may have to incorporate type checks.

go
import (
    "fmt"
)

type Avcl struct {
    // your logger details goes here
}

func av_log(avcl *Avcl, level int, fmtstr string, exprs ...interface{}) {
    av_vlog(avcl, level, fmt.Sprintf(fmtstr, exprs...))
}

func av_vlog(avcl *Avcl, level int, str string) {
    // your logger functionality may vary
}


This implementation would then be compatible with the fmt suite of functions, including but not limited to fmt.Printf and fmt.Sprintf. When called with multiple arguments av_log first attempt to utilise those arguments in the formatting of a string, which is then passed on to `av_vlog` paired with first two original arguments. For the type checks or dynamic functionality, interface and reflect features will be helpful. 

That should achieve nearly the identical functionality as the given C code. Please inspect it considering the details restrictions and differences launched the C language and the Go. Not every specific detail has been inspected considering this C code is part of a larger system which we can't see. But hope this initial response will guide to put on the correct way. Feel free to provide feedback to much more suitable way.