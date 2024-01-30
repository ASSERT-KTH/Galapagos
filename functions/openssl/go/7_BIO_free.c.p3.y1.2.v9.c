Golang's primary paradigm is far removed from the C programming environment. The primary issues are lack of a class-based system (implication for *method invocation, and property access), as well as lack of built-in direct memory handling side (freeing, occupying, etc ). Such hardware-side actions are generally abstracted away from the user to reach the best level of operational safety and make it garbage collector-driven.
Hence, an exact translation of C code into Go language is not entirely possible in a way that shadows every functionality obtained from the usual libraries like OPENSSL.

Here is a conceptually referencing implementation with context-based substitutions of what could be equivalent function BIO_Free in Go. Remember that in Go you cannot have NULL object nor undefined structure fields, only occurance for similar situation happens with respect to nil interface.

Go
type BIO struct {
    References int
    DoneChan chan (bool)
    Method *MethodScheme
    ExData interface{}
}

type MethodScheme struct {
    DestroyMethod func(a *BIO)
}

func BIO_free(a *BIO) int {
    if a == nil {
        return 0
    }

    var ret int
    select {
    case <-a.DoneChan:
        ret += 1
    default:
        return 0
    }

    if ret < 0 {
	    panic("unexpected negative ref")
    }
    
    if ret > 0 {
        return 1
    }

    if a.Method != nil && a.Method.DestroyMethod != nil {
        a.Method.DestroyMethod(a)
    }

	ret = 1 // at place of invoking ex_data clean method calls
	ret = 1 // at place of freeing the lock on the current `a` object
		
	// mimic cleaning, basically ignoring since Go runtime does this work
	a = nil
	
	if ret > 0  {
	    return 1 
	}

	return 0
}

Such Go function cannot entirely address the essence of the functionality achieved from the standard C libraries which are impossible or unnecessary in Golang. */
It's crucial to analyze such semantic equivalent transformations according to the context they are applied for the capabilities of the target language.  

Keep in mind complexities about porting low-level C-based logic into a high-level language like Go and intentional abstractions designed into Go's language features.