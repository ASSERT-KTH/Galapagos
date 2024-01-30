The Go code might look like this considering if `args` variable can be a global/scope available construct,
go
import "fmt"

var args = [...]string{}
var index = 0

func nextarg(str string) bool{
	if args[index] == ""{
		return false
	} else {
		r := strings.EqualFold(args[index], str)
		fmt.Println("r={{", r, "}} args01[{{", index, "}}] = ", args[index])
		index += uint8(r)
		return r
	}
}

However, as this doesn't feel like idiomatic to go because it uses a global cursor, `index` as an index for `args`. Proper action (like reseting or not overflowing array bounds) needs to be ensured seeing its code.

But If we consider a scenario where we pass the index as well then your function would look like this and is more idiomatic.

go
func nextarg(str string, args []string, index int) (bool, error) {
	if index >= len(args) {
		err := fmt.Errorf("index out of bounds exception at %d", index)
		return false, err
	}
	r := string.Compare(args[index], str) == 0
	index += int(r)
	return r, nil
}
