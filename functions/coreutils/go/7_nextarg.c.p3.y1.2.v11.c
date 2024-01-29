Here is the Go equivalent for the given C function:

go
import "strings"

func nextarg(str string, args *string) bool {
	if args == nil {
		return false
	} else {
		r := strings.Compare(*args, str) == 0
		if r {
			(*args) = (*args)[1:]
		}
		return r
	}
}


Please note that Go does not support directly incrementing and decrementing for string. It adjusts the string by slicing. Also, it's not clear from the code to what `STREQ` is referring. If it is referring `strcmp`, then `strings.Compare` equals to that or if it is referring to strict equality then we use simple `==` operator in Go. Here I've assumed STREQ is referring to string comparison, hence I used `strings.Compare`.
Please adjust your Go code according to your `STREQ` definition.