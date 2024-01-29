Go translates C code relatively directly as Go does not have garbage collection, does have pointers and, importantly, doesn't have a lot of the syntactic sugar that other higher-level languages have. Here's a direct translation of mbsalign:

go
import (
	"unicode/utf8"
	"unicode"
)

func mbsalign(src *string, dest string, dest_size int,
	width *int, align int, flags int) int {

	ret := ^uint(0)
	src_size := len(*src) + 1
	var newstr *string = nil
	str_wc := []rune{}
	var str_to_print string = *src
	n_cols := src_size - 1
	n_used_bytes := n_cols // Not including NUL
	n_spaces := 0
	conversion := false
	wc_enabled := false
	// ...
	recover()

	// decide how much padded spaces are required to align the string
	if *width > n_cols {
		n_spaces = *width - n_cols
	}

	// update the width to the number of columns it can use, not including padding
	*width = n_cols

	var start_spaces, end_spaces int

	// this logic might need tweaking to understand Go slice usage
	switch align {
	case MBS_ALIGN_LEFT:
		start_spaces = 0
		end_spaces = n_spaces
	case MBS_ALIGN_RIGHT:
		start_spaces = n_spaces
		end_spaces = 0
	case MBS_ALIGN_CENTER:
		fallthrough
	default:
		start_spaces = n_spaces / 2
		end_spaces = n_spaces / 2
	}

	if (flags & MBA_NO_LEFT_PAD) != 0 {
		start_spaces = 0
	}

	if (flags & MBA_NO_RIGHT_PAD) != 0 {
		end_spaces = 0
	}

	// write the output to DEST as much as possible
	if dest_size != 0 {
		dest_end := dest[dest_size-1:]
		dest = mbs_align_pad(dest[:dest_size], start_spaces)
		dist_size_left := len(dest_end) - dest_size
		n_copied := n_used_bytes

		if dist_size_left < n_copied {
			n_copied = dist_size_left
		}
		dest = dest[:n_copied]

		dest = mbs_align_pad(dest[:dest_size], end_spaces)
	}

	ret = n_used_bytes + ((start_spaces + end_spaces) * 1)

	return ret
}

Please Note: Original function was taken in a powerful language where manual memory management was available. But, Go is GC language so it's pretty hard to mimic a 1 to 1 translation but we can achieve somewhat similar behavior so the provided solution is a rough translation and may need minor modifications to fine-tune it.