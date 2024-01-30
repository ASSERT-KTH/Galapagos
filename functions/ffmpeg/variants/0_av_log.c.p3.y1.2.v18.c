As Go doesn't support variadic arguments in the same way as C does, it's not exactly possible to translate this straightforwardly, since pointers to types aren't as interchangeable as they are in C. 
Here is a try at it in the same spirit as the C example might be intended.

Almost every Go logger implementation looks different because Go provides a variadic function feature which is very efficient. Below shows you how you can achieve the same functionality but can't get all semantics as like C.

Go
import (
    "log"
)

func avLog(avcl interface{}, level int, txt string, vals ...interface{}) {
    msg := fmt.Sprintf(txt, vals...)
    log.Println(level, msg)
}

Explanation: With this version of avLog receives any amount of arguments followed by the format string "txt" . Inside the function these arguments are formatted into the corresponding selection strings and display.
Again, this is not an exact copies of a C-version `av_log`, because that low level of system manipulation is highly discourage in Golang.