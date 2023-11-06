The direct translation of C code to Go Language could be different due to differences in language semantics such as it's API "randombytes_init_if_needed()" and this "implementation" namespace which is possibly referring to some object or package that has a "buf" method attached which in C is able to mutate parameters directly due to them being passed by reference, however in go, we would need the buf to already be some predefined interface that can directly change its value, I'm using a pointer for bytes to represent a scenario that comes closest to your context.

go
import "crypto/rand"

func randombytes_buf(buf *[]byte, size uint) {
	*buf = make([]byte, size)
    if size > 0 {
		_, err := rand.Read(*buf)
		if err != nil {
			panic(err)
		}
	}
}
 

In the above function, the data being passed in to 'buf' is using pointers in order to edit the original variabel similar to what you could do in C but instead data modification in Go is performed through methods attached to structs/interfaces/functions for better mantainability. Here thats performed using 'rand.Read'. Please refer the appropriate place in your project to replace with of the way the randombytes are created. For this example we are using "crypto/rand" to generate randomness, please replace as needed.