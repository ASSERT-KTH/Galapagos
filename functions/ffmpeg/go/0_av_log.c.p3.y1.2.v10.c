Unfortunately, it's impossible. C has a system for calling functions with variable arguments (using va_list), but Go does not support variadic function dispatch in the same way. 

That's to say, it's actually not possible to write a strictly equivalent port: you can't call a function f with a list of arguments in Go.

However, the closest equivalent function would look roughly like this:

go
import "log"

func av_log(avcl interface{}, level int, fmt string, v...interface{}) {
    formatted := fmt.Sprintf(fmt, v...)
    log.Println(avcl, level, formatted)
}

Note several key differences:

 - I am using `fmt.Sprintf` to substitute into the format string. This is a safe function, so you won't have errors at runtime if your format doesn't match your arguments list.
 
 - There's no explicit teardown, unlike with `va_end(vl)`. Nothing prevents you from recycling parts of `v` later on (Go has garbage collection), aliasing isn't an issue as such.
  
 - The result of `fmt.Sprintf` is output directly. Errors during formatting aren't handled, whereas the C standard library `vprintf` can and should handle errors during formatting.
   
Moreover, Go functions do not accept a general variable arguments (`...`) in the style of C, and also doesn't allow to forward variadic inputs as a group to another function, thus `av_vlog` equivalent won't be able to receive a variadic input forwarded from `av_log`.   

It's important to mention that because C and Go are very different languages, sometimes a direct line-for-line port doesn't make sense or isn't possible, as is the case here. It would be necessary to shift thinking more in line with the target language's norms and paradigms for more complex functions.