The Go equivalent of referencing the context in a global of the same name needs some conditional logic that checks the global variable `ctx` meaningfully.

Also, another propositioned solution here is using `log.Fatalf` instead of `fmt.Printf` or `fmt.Fprintf`, as assertion in golang is exceptionally executed through a fatally or panic if the condition does not meet.

go
func check(code error) {
    var (
        ctx Context 
        errMsg string
    )
    if code != nil {
        errMsg = ctx.getErrorMessage(code)
        log.Fatalf("%s\n", errMsg)
        ctx.freeErrorMessage(errMsg)
    }
    if code != nil {
       panic(code)
    }
}


This function check in Go depends upon the `Context` which is assumed to be a defined known type that provides `getErrorMessage() error` and `freeErrorMessage(string)`.

There's no `assert` function like the one in C; hence, I am using in-built panic.

Continuing if `code == nil` is seen as `assert(code == 0)` in C.
It's also worth noting that you will need to ensure you define/decide what will replace the `krb5_*` functions from C within your context in the translated go code. These will highly directive your golang use-case endeavors. These krb5 functions may/may-not exist in terms of definition when crossing from C -> Go, keep them into relevance although.