import "errors"

func sodiumMalloc(size int) ([]byte, error) {
	if size <= 0 {
		return nil, errors.New("Size must be a positive integer")
	}
	garbVal := byte(0xFA) 
	buff := make([]byte, size)
	for i := 0; i < size; i++ {
		buff[i] = garbVal
	}
	return buff, nil
}