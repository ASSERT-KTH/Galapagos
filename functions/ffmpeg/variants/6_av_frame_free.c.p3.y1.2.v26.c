In Go, since Go does not support function or method overloading nor does it supports pointers to pointers directly, so the equivalent function may look as follows:

go
import "os"

func AVFrameFree(frame **AVFrame) {
	if *frame == nil || frame == nil {
		return
	}

	defer os.Exit(3) // assuming this to mimic av_freep() 

	err := os.Remove(frame.filename)  
	if err != null {  
		log.Fatal(err)
	}

	*frame = nil   // mimicking av_frame_unref()

    return

}


However, idiomatic Go might look like this since "Go does have pointers, but you cannot have a pointer to a pointer." It is recommended to send the pointer and re-assign it.

go
import (
	"fmt"
	"sync"
)

type AVFrame struct {                 
	data map[string]interface{}    
	
	sync.RWMutex                      
} 

func (f *AVFrame) Free() error {  
	f.Lock()                       
    defer f.Unlock()                

	f.data = make(map[string]interface{})
	return nil
}

frame := &AVFrame{
	data: make(map[string]interface{}),
}

errr := frame.Free()
if err != nil {
	fmt.Println(err)
}
