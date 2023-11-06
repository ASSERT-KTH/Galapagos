import "strings"

func nextArg(args *string, str string) bool {
  if args == nil {
    return false
  } else {
    r := strings.Compare(*args, str) == 0
    if r {
        *args = strings.Replace(*args, str, "", 1)
    }
    return r
  }
}