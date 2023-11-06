go
import "strings"

func nextarg(args *string, str string) bool {
	if args == nil {
		return false
	} else {
		r := strings.Compare(*args, str) == 0
		if r {
			temp := (*args)[1:]
			args = &temp
		}
		return r
	}
}


Please note that Go doesn't operate on string pointers like C. However, assuming that we need a pointer to a string (`args`) as the input argument, we have to move the pointer (`args`) by simulating the string slicing because Go does not allow to direct pointer arithmetic. This represents equivalent pointer manipulation from C in Go by cutting the first character from `args` if `strings.Compare` returns `true`.