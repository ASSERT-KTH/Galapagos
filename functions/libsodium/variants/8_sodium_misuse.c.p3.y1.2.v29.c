In Go, pointers to functions cannot be assigned to variables which makes the translation exercise from a C function like this to Go not feasible exactly. We lack equivalent internal critical section handling functions like 'sodium_crit_enter()', 'sodium_crit_leave()', and `_misuse_handler` similar to the C library 'sodium'. 

Instead, let's do a high-level interpretation of translating the general concepts of the function into Go.

go
func sodiumMisuse() {
    defer func() {
        if r := recover(); r != nil {
            if misuseHandler != nil {
                misuseHandler()
            }
        }
        os.Exit(1)
    }()

    critEnter()
}

func critEnter() {
    panic("entered critical section")
}


Note:
1. Assuming critEnter() and misuseHandler() already exist in our Go code.
2. panic and recover in Go can serve similar purpose as these 'sodium' low level API for error signification.
3. os.Exit(1) serves the same purpose as abort.
4. defer allows us to ensure that some code runs before function exit i.e., clean up jobs. It somewhat equivalent to `sodium_crit_leave()`

Remember, the given script does not provide the EXACT functionalities provided by Sodium API. This sample demonstrates semantically equivalent concepts applied using the functionalities available in GO Library. Complete implementation might still require different strategies.  This is due to more native level control over resources and memory in C compared to Go language. 

This answer assumes a simplistic interpretation of what 'sodium_crit_enter' does. The critical section handling aspect is just interpretational. Extension or addition of functionality to this simple case requires getting more into what the original functions aim to achieve. Concurrency-safe handling of critical sections involves the use of mutexes, channels, or appropriate go-routine-safe structures particularly relevant to the specific requirements.