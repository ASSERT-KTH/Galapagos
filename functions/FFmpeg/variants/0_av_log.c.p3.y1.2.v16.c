There is no direct equivalent to variadic arguments in Go's standard library. Due to the types system and safety characteristics of Go, function user must specify types of all arguments, it means format is needed: 

Here is an example of how to otherwise change it. A `interface{}` in Go is equivalent to a `void*` in C so this can be used for the `avcl`:

go
import (
	"fmt"
	"log"
)

func av_log(avcl interface{}, level int, format string, v ...interface{}) {
	log.SetPrefix(fmt.Sprintf("Level: %d ", level))
	log.Printf(format, v...)
}

Here, I've used `log`'s `Printf` method as a stand in for `av_vlog`. It essentially works similarly to `printf`: `format` is expected to be a string that specifies how to format the rest of the arguments, which are passed as a variadic slice of interfaces. I've used `log.SetPrefix` to include the `level` argument - whatever is specified here will be prepended to each line printed with this logger.

It's also worth noting, When you define a function with variadic parameters, you can pass to it parameters one-by-one just like any other function. Or the "...interface{}" means it can take a signal parameter or multiple parameter of any type. You should use slice for define a function with an arbitrary number of parameters. Variadic arguments provide flexibility, but since Go is statically typed so you would often know the input types - could become difficult to handle too much flexibility. Therefore, Proper design decision have to take while using "...interface{}". 

Also You have to be clear: All the syscall type of functions are those normally a programmer would NOT use directly, including the Printf.
Here I use Printf as example, or you can use google's Glog or logrus or other module to substitute the method "av_vlog" fitting your demand.