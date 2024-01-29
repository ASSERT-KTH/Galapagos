In Go, you don't have as many things like `mbstowcs`, `wcswidth`, `malloc`, and others from the given C code. Direct conversion from C to Go would not be possible in this case. However, we can create a simplified version of this function leveraging Go's utf-8 support.

Here goes the "semantically" equivalent function in Go:

go
import (
	"strings"
	"unicode/utf8"
)

type mbs_align_t int

const (
	MBS_ALIGN_LEFT mbs_align_t = iota
	MBS_ALIGN_RIGHT
	MBS_ALIGN_CENTER
)

func mbsalign(src string, dest *string, dest_size int, width *int, align mbs_align_t, flags int) int {
	n_cols := utf8.RuneCountInString(src)  // Count characters with UTF-8 support
	n_spaces := 0

	if n_cols > *width { // Truncation required.
		n_cols = *width
		src = string([]rune(src)[:*width])  // truncate the source string
	}

	if *width > n_cols {
		n_spaces = *width - n_cols  // Padding required	
	}
	*width = n_cols  // Set width

	start_spaces, end_spaces := 0, 0
	switch align {
	case MBS_ALIGN_LEFT:
		start_spaces = 0
		end_spaces = n_spaces
	case MBS_ALIGN_RIGHT:
		start_spaces = n_spaces
		end_spaces = 0
	case MBS_ALIGN_CENTER: 
		start_spaces = n_spaces / 2 + n_spaces % 2
		end_spaces = n_spaces / 2
	default:
		return -1
	}
	padding := ""
	for i := 0; i < start_spaces; i++ {
		padding += " "
	}
	src = padding + src
	padding = ""
	for i := 0; i < end_spaces; i++ {
		padding += " "
	}
	src += padding

	// Write as much output to DEST as possible
	if dest_size != 0 {
		*dest = string([]byte(src)[:dest_size-1])	
	}

	// Indicate to caller how many bytes needed
	return len(src)
}

This Go procedure aligns `src` string with the specified `width` per the requested alignment `align`. It writes as much as possible into `dest` given the provided `dest_size`. Padding is detailed in the logic.

Compared with the original C function, the complex part of multi-byte to wide-characters conversion has been handled elegantly by Go's UTF-8 alphanumeric character set. Thus, the function in Go and the code becomes much simpler and more human-readable. This function no longer attends to unicorn/multibyte flags, which were part of the originally complex conversion processes involved in C. Zeal from auto pointer-garbage control can also be observed in statement `dest` which is earlier declared as `dest_size` string pointer. 

Please regard this version as reducing most complexities found in C not due to C's functions/API but rather with Go's smart handling of pointers and UTF-8.

While doing a "transliteration" from one language to another, it is critical to understand the inherent differences, assumptions, and alternatives present in each so as to form suitable matches in system-level functionalities coding thus arrives most optimized – as done in this initiative.

Therefore the above Go code is a "canonical" copy that does fairly the same operation as the C code does.