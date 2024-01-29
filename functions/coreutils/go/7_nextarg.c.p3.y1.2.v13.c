import "strings"

func nextarg(str string, args *[]string) bool {
  if args == nil || len(*args) == 0 {
    return false
  }
  r := strings.Compare((*args)[0], str) == 0
  if r {
    *args = (*args)[1:]
  }
  return r
}