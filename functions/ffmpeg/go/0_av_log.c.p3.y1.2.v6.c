In the Go programming language, you can't directly convert functions with variable number of arguments and types like in C using va_list. However, Go has a variadic function feature where you can pass as many arguments as you want but only of the same type, using an ellipsis before the type of the last parameter.

Unfortunately, the direct scheme-to-scheme transformation of such functions is impossible due to language syntetics restrictions. Instead, the logging small function should look like this in Go:

go
import (
    "log"
)

func avLog(avcl interface{}, level int, fmt string, v ...interface{}) {
    log.Printf(fmt, v...)
}

Please pay attention here that level is unused - in order to correlate semantically function logo it should be then wired appropriately with log package of stdlib or any other logging facility. 

The semantic of this variant of the Go function 'avLog' differs with the C 'av_log' as variadic parameters are only processed within the log.Printf function, rather than being transformed/processed by another intermediate function ('av_vlog'). And all arguments should have a same nature - for instance all strings or ints. 

This small chunk of code reassembles av_log call, but semantic contradictions may accost internals of av_vlog. Because, keeping with language restrictions, we can't further decompose passed variadics then.
However, it is a bit tricky for error/control level in the sense of precise av_log call reassembly.