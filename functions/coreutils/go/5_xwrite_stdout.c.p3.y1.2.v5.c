go
import (
	"fmt"
	"os"
)

func xwrite_stdout(buffer []byte, n_bytes int) {
	if n_bytes > 0 {
		_, err := os.Stdout.Write(buffer[:n_bytes])
		if err != nil {
			fmt.Fprintf(os.Stderr, "error writing %s: %v\n", "standard output", err)
			os.Exit(1)
		}
	}
}

Note:
In the original C implementation the char const pointer and size_t type were used for buffer and n_length respectively. However, Go uses byte array to represent combinations of characters and int for length manipulations. errno is a predefined global variable in C used for error handling. In Go style of concurrency control that is not in global scope, the err object is more equivalent to errno, it will be given a value if an Return value of writing is controlled, let underlying os.Stdout.Write function encounters an error.

The use of underscore ('_') when initializing variables including the write count returned from os.Stdout.Write(buffer[:n_bytes]) stands for an empty identifier and it means 'I don't care about the available-to-use returned data. It's common behavior in Go and called "Blank Identifier" practicing. The clearerr(stdout) line ignores user-space changes the underlie EOF and error indicators for the associated stdout, as that functionality isn't available in Go, it's omitted. 

Now, there is a user-level translation of characters; invoking fmt.Frpintf 's behaviour of C's fprintf(stderr, format, ... ) will send an organized errmsg into predefined global variable stderr. "standard output", err are analogous to the string pointed by quoteaf ("standard output")) sequence"%s", , and errno.

Finally, on event of encountering an error executing stdin.Write while erroring _not equal to nil error(EXIT_FAILURE,...), offers flexibility interms of describing abnormal program termination, contrast those work in handy on Go, using the os.Exit(1) to force the process to exit immediately-- with an status-- the calling function doesn't return control back to its caller. 

Wrap-around conclusion is:
This GO code does similar task; check bytes got written onto the File pointer returned by os.Stdout(). Patch captured error to a Format on stderr and cause abnormal exit, in basically behaving same as the C xwrite_stdout Function.