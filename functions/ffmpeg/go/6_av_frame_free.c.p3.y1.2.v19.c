Go does not typically allow working directly with pointers the same way like in C, but reflecting the cleanup functionality could be achieved differently. Problem here is with type AVFrame which is specific. Assuming it is a custom struct we can represent it in the way to reflect C-programming paradigm:

Go
type AVFrame struct {
	// ... type specifics
}

func (f *AVFrame) Unref() {
	// ... method specifics
}

type ManualMemoryManagement interface {
	Unref()
}

// This could require explicit passing the struct, checking for null
// in *C.method() represents in Go passing a nil struct
func AvFrameFree(frame *ManualMemoryManagement) {
	if frame == nil {
		return
	}

	// defer in go could represent freeing up allocated space commonly used in *C - similar to destructor. 
	// However, if f.Unref is used, it is assuming the f provides method .Unref 
	defer func() { frame = nil }()
	
	frame.Unref()
}

This shows the concept of translation but in slightly different implementation. Available features from both languages does not reflect 100% semantic in type of data pass, errors dealing and insurance of not creating memory leak does overlap here. 

When you create pointers-to-pointers (eg **AVFrame) in C, you allow modifying the variable value from within the function, which means that modification will be visible when the function exits. Here we provide same behavior. 

Books like 'Operating System Principles', in which there are many programming exercises solved in C can serve as solid introduction on topic and gives team more context heavy understanding of C programming paradigm interactions. [`doSomething()/DoesSomething'] is modification the team which works in both languages needs because understanding certain overlaps ensures strong transition from one programming language to another. Same applies if done between another pair of *non-similar' programming languages.