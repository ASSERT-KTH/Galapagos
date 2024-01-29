In Go programming language, it is a quite tricky to do a corresponding implementation since Go doesn't directly support C-style variable argument lists starting with variable name like C. But you can kind of mimic the same behavior with Go's interface{} type and variadic functions.

Here is the approximate equivalent version that you may found helpful.

go
import (
    "fmt"
)

func com_err(asWho string, code errCode, format string, args ...interface{}) {

    serializeArgs := format // Do any necessary serialization or formatting

    for _, arg := range args {
        serializeArgs += fmt.Sprint(arg)
    }
    com_err_va(asWho, code, serializeArgs)
}

In this code, `...interface{}` works like a variadic argument. The function `com_err` takes an unknown number of arguments `args`. They are accessible in `com_err` as a slice. Please notice the Go's way of processing variadic principles differ from C and requires proper debugging for accurate output.

Please keep in mind you may have to edit and refactor function `com_err_va`.
Keep in mind to define what `errCode` and `com_err_va` is in your go code. This is just a roughly equvialent port of your C code which demonstrates the handling of same function signature. Detailed handling logic of more complex call like `com_err_va`, you should implement based on actual needs and logic of your program.