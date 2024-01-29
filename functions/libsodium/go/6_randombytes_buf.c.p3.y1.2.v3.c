Unfortunately, a function with exactly the same signature can't be created in Go. Go doesn't support having output parameters in a function like C and C++ does. For this example, the result would actually need to be returned rather than passed as an argument. Therefore here's a representative simple encryption function might look like in go.

Go
import "crypto/rand"

func randombytes_buf(size int) ([]byte, error) {
 	    buf := make([]byte, size)
	    _, err := rand.Read(buf)
	    if err != nil {
		    return nil, err
    	}
	    return buf, nil
}
