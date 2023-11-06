Unfortunately, the conversion of this C function into Go isn't straightforward, since it's using specific C macros (`OPEN_READER`, `UPDATE_CACHE`, `SHOW_UBITS`, `LAST_SKIP_BITS`, `CLOSE_READER`) and some C-specific concepts such as preprocessor directives. 

Therefore, it is impossible to specify an exact equivalent Go function for you without having knowledge of what the above described macros are doing. av_assert2 seems like a debugging assistance function. Hence, it is said to replicate assertion behavior that is typical in languages like C++. The int variable OPEN_READER, UPDATE_CACHE, SHOW_UBITS, LAST_SKIP_BITS, CLOSE_READER are assumed to have some manipulation with GetBitContext *s also bit shifting operations.

Best practices in Go discourage the use of panic in normal operation. Assert does not exist in Go, because Go reserves panic for truly unexpected problems, such as index out of range, nil pointers, etc., so mostly likely this also doesn't require a direct translation in Go. If it applies error, return it don't panic the whole application.

Anyway, you might outline what each of the invoked macros does, or provide a C header file where they're defined. Depending on which macros can translate in methods or functions.

Here is a baseline translation: 
golang
func getBits(g *GetBitContext, n int) unsigned {
    // MISSING: Replacement for all the macro invocations
    := assert.New(t)

    assert.True(t, n > 0 && n <= 25, "Message") 
    
    // MISSING: Replacement for all the macro invocations
    assert.True(t, n < uint64(1) << n, "Message") 
    return tmp
}

I would recommend consulting with someone knowledgeable about your codebase, to safely implement this code for you.

Please notice: 
 even in Go as you would argue error handling is better than asserting, however using ("github.com/stretchr/testify/assert") go package, we emulate same functionality safely. 

Finally even testify wont provide identical functionality.so more information on used macro and assertion will help to adopt appropriate changes.