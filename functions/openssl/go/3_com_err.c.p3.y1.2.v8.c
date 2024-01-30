In Go, there are no exact equivalent of varargs from C, so equivalent functions may not have an exact equivalent version in Go But attempting to approximate the arguments provides a rough conversion as follows:

Go
import (
	"fmt"
)

func com_err( whoami string, code errcode_t, fm string 
            , msg ...interface{}) {

    var errs = fmt.Sprintf(fm, msg...)
	com_err_va(whoami, code, errs)

}
