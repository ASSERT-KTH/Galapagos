Go does not support varargs in the same way as C or C++, so we cannot use the same varaibles [...]. Below is an example of Go function varargs:

import (
    "fmt"
    "log"
)

func avLog(avcl interface{}, level int, fmt string, val ...interface{}) {
    return log.Printf(fmt, val...)
}