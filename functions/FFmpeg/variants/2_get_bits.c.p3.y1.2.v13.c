I'm sorry but it isn't possible to convert this code directly to Go due to the C specific macros/functions like OPEN_READER, UPDATE_CACHE, SHOW_UBITS, LAST_SKIP_BITS, and CLOSE_READER. These methods and macros are specific to the library/modal that has been used in the C project, they are not standard C functions.

We could assist better with more details about these methods and by gaining a better understanding of the lib used in the original code. But for now, an attempt to skip those implementation specific details, the rough equivalent code in Go can be structured as below.

go
type GetBitContext struct {
    // define GetBitContext members
}

func getBits(s *GetBitContext, n int) (uint, error) {
    if n <= 0 || n > 25 {
        return 0, fmt.Errorf("n should be greater than 0 and less than or equal to 25")
    }
    var tmp uint
    // Provide equivalent logic to CLOSED_READER, OPEN_READER methods
    // Updating and Manipulating the tmp variable
    if tmp >= uint64(1) << uint(n) {
        return 0, fmt.Errorf("tmp should be lesser than pow(1, n)")
    }
    return tmp, nil
}

Also, note that unlike C, Go supports error handling. It usually recommend to return values and errors instead of asserting and breaking the application. In safety-critical systems, assertions are filtered out unless explicitly turned on during compilation, whereas Go's error mechanism is always active.
  

But without knowing what the C macros/functions like OPEN_READER, UPDATE_CACHE, SHOW_UBITS, LAST_SKIP_BITS and CLOSE_READER do we can't fully translate the codes. This represents a guideline, and may not work ready-to-go until the interactions with those functions are replaced.