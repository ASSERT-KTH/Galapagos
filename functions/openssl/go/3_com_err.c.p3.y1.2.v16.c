Unfortunately, you cannot create an equivalent version of the function in Go without writing a helper function or a third-party dependency. The reason is that Go has not built-in support for variadic argument functionality in the same way the C does, where you could parse the format string `fmt` and substitute the variadic arguments accordingly.

Nevertheless, here's an attempt to retain as much functionality as possible. This function receives the error code, a format string in the manner of `fmt.Printf`, and any number variadic argument of any type (`interface{}`). It uses the provided format string to construct an equivalent error message string.

go
import (
    "fmt"
)

type errcode_t int

func com_err(whoami string, code errcode_t, fmtstr string, args ...interface{}) {
    errMsg := fmt.Sprintf(fmtstr, args...)
    errMsg = fmt.Sprintf("%s: %d: %s", whoami,code, errMsg)
    fmt.Println(errMsg)
}


Please, notice that working with c language and Go  aren't  compatible by all means. The features, functions signatures, pointers, and many more isn't flexible to achieve in go as comparing c language has lot more to produce.