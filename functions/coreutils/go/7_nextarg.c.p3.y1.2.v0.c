import "strings"

func nextarg(args *string, str string) bool {
	if args == nil {
		return false
	} else {
		r := strings.Compare(*args, str) == 0
		if r {
			*args = (*args)[1:]
		}
		return r
	}
}