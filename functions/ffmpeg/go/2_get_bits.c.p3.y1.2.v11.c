The exact transformation of this C code to Go language is not possible due to the differences in language semantics and available functionality. Go language does not support Macro functions usually relied on heavily in low level C modules (functions with all caps in your provided function).

However, this code provides the most direct conversion possible, considering Go’s language:
go
func getBits(s *GetBitContext, n int) (tmp uint32, err error) {
    if !(n > 0 && n <= 25) {
        return 0, errors.New("n should be within 1 and 25")
    }

    var re Reader
    re.Open(s)

    err = re.UpdateCache(s)
    if err != nil {
        return 0, err
    }

    tmp, err = re.ShowUbits(s, n)
    if err != nil {
        return 0, err
    }

    err = re.LastSkipBits(s, n)
    if err != nil {
        return 0, err
    }

    re.Close(s)

    if !(tmp < 1 << n) {
        return 0, errors.New("invalid value of tmp")
    }

    return tmp, nil
}

It does not replicate the exact functionality of your C function, as some of the C macros (like av_assert2) don't translate directly to Go. These usually perform very fast operations in the C language due to low-level manipulation, features that Go simply doesn't have. Instead, I replaced them with Go-style error handling.

I assumed that OPEN_READER, UPDATE_CACHE, SHOW_UBITS, LAST_SKIP_BITS, CLOSE_READER are methods operations related to some kind of a special "Reader" interface that handles the passed in context. The exact methods and their implementations would depend on what exactly your C macros are doing. You'd have to implement those operations yourself.