Unfortunately, there isn't an exact one-for-one replacement of this function in Go because how variadic functions are implemented in these two languages are different. 

However, the closest alternate using Go’s built-in log package would look something like this:

go
import "log"

func avLog(avcl interface{}, level int, fmt string, v ...interface{}) {
    msg := fmt.Sprintf(fmt, v...)
    log.Printf("%v: Level(%d), Msg(%s)\n", avcl, level, msg)
}
