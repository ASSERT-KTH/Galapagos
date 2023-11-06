Since Go doesn't support variadic string formating in the same way as C and it's impossible to continuously specify function parameters as a string, it cannot implement function signatures that are semantically equivalent to C in fully unusual cases such as variadic parameters. Also Go doesn't accept a void variable type. Here is the closest translation of av_log function based on commonly adopted spec:

go
import (
    "log"
    "fmt"
)

func avLog(avcl interface{}, level int, fmt string, v ...interface{}){
    txt := fmt.Sprintf(fmt, v...)
    avLogImp(avcl, level, txt)
}


In this translation, `fmt` is format string and `v` is variadic arguments that can be any type (notice interface{}).

`fmt.Sprintf` will format the string according to `fmt`, and `v` will be the input to the format string, and the resulting string will be passed on to a `avLogImp` function (a placeholder replace av_vlog function here).

The specifics will still depend on the actual working details of `av_vlog` and structure of `a_cl` and whether and what logging features or specifics it has.