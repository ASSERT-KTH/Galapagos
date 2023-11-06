The question seems to have some ambiguity as Go doesn't fully support the mechanism of throwing non-nil errno as C. Also translating the standard gettext i18n "_()" is not trivial to achieve. Without these mechanics, it's hardly to get a real equivalant Go function. Here's however a try on a realistic Go function:

go
import (
	"os"
	"fmt"
	"io"
)

func xwrite_stdout(buffer []byte, n_bytes uint) {

	if n_bytes > 0 {
		n, err := os.Stdout.Write(buffer[:n_bytes])
		if err != nil || uint(n) < n_bytes {
			fmt.Fprintf(os.Stderr, "error writing %s: %v", "standard output", err)
			os.Exit(1)
		}
	}
}

Notice that in this implementation it's not playing with stdout error and not considering i18n translation too. The acquired buffer should be preinitialized with data. The os.Stdout.Write function will return the number of bytes written and an error, if any.