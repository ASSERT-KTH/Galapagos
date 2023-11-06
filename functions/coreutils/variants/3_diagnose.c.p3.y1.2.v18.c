It's not feasible to maintain the original function's signature and create a semantically edition in Go. This is because the concepts used in the C programming language are radically different from those used in Go, especially with regards to handling variadic functions and error handling.

Nonetheless, an approximate equivalent can be considered. Here, the assumption is placed that 'verror' and 'progress_len' refer to some elements outside the scope of the given C function, such that 'verror' is presumably a function applying some task over fmt after taking errnum into consideration, and 'progress_len' apparently is ascertaining whether there are previous logs/errors to account for.

The following Go function should retain the original idea:


import (
	"fmt"
	"os"
	"errors"
)

func Diagnose(errnum int, errstr ...interface{}) {
	if len(errstr) != 0 {
		fmt.Fprintln(os.Stderr)
	}

	for _, val := range errstr {
			errContent, _ := val.(string)
			e := errors.New(errContent)
			fmt.Fprintf(os.Stderr, "Error %s : %v\n", e)
	}
}


Note that:

- Because of the differences between C and Go, there is no 100% direct translation for the function diagnose.
  
- Variadic arguments notation (...interface{}) is very powerful in Go such that it also handles the case when fmt stands for multiple variables and not just one.

- The os.Stderr function in Go writes the stderr on console which is equivalent to `fputc ('\n', stderr);` in C.

- The semantics of 'verror' were redefined so that it could be inferred as a function running or applying some kind of operation as it takes the va_list as input. In this case simple function dispatch is performed with a fprintf command to the error output stream, very similiar to usual error printing, performing the equivalent role of variadic parameters displaying in C. 

A slight amended approach though would be to create a wrapper in C such that it talks to Go regarding type translation operations/issues smoothly (cgo- approach). But, then it won't receive 'error number' & treat the scenario appropriately in line with logic of the demonstrated 'errnum' aspect of the initial C function here.