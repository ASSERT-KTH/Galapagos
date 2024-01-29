import "unsafe"
import "reflect"

func BtcMemzero(ptr unsafe.Pointer, len uintptr) {
	if len > 0 {
		b := (*[1 << 30]byte)(ptr)[:len:len]
		zero := [1]byte{}
		for i := range b {
			reflect.Copy(reflect.ValueOf(&b[i]), reflect.ValueOf(&zero))
		}
	}
}