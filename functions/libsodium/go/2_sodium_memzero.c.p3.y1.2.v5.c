go
import (
	"crypto/rand"
	"reflect"
	"unsafe"
)

func sodium_memzero(pnt interface{}, len uint) {
	header := (*reflect.SliceHeader)(unsafe.Pointer(&pnt))

	_, err := rand.Read(make([]byte, header.Len*int(unsafe.Sizeof((header.Data)))))
	if err != nil {
		panic(err)
	}
}
