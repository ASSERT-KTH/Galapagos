The below code is a pseudo-conversion of the provided C code to Go as there's no direct equivalent of functions in Go such as malloc, wcswidth, wcstombs and mbstowcs which are part specific to C and also due to how byte and string handling works differently in the two languages. Also, the in place alteration of function parameters as seen with 'width' is not exactly scalable in Go as it values are passed by copy in Go in contrast to C.

Go:

Go

import "strings"

func mbsalign(src string, dest []string, best_size int, width *int, align mbs_align_t, flags int)


	ret := math.MaxInt64
	src_size := len(src) + 1
	newstr, str_wc := "", ""
	str_to_print := src
	n_cols := src_size - 1
	n_used_bytes := n_cols
	n_spaces := 0
	conversion := false
	wc_enabled := false 

	src_chars = len(src)
	if src_chars == math.MaxInt64 {
		if flags&MBA_UNIBYTE_FALLBACK != 0 {
			goto mbsalign_unibyte
		} else {
			goto mbsalign_cleanup
		}
	}
	src_chars += 1
	width, wc_enabled  = src_chars, true 
	extend_str_with_unicode_spaces(&str_wc, src)
	conversion, _ = IsPrint(str_wc)
	n_cols = runewidth.StringWidth(str_wc)

	if wc_enabled && (conversion || (n_cols > *width)) {
		if conversion {
			src_size = utf8.RuneCountInString(str_wc) + 1
		}
		
		str_to_print = str_wc
		n_cols = str_wc; wc_truncate(width)
		n_used_bytes = len(str_wc)
	}


	mbsalign_unibyte:

	if n_cols > *width{
		n_cols = *width
		n_used_bytes = n_cols
	}

	if *width > n_cols {
		n_spaces = *width - n_cols
	}

	*width = n_cols

	start_spaces, end_spaces := 0, 0

	switch align {
	case MBS_ALIGN_LEFT:
		start_spaces = 0
		end_spaces = n_spaces
	case MBS_ALIGN_RIGHT:
		start_spaces = n_spaces
		end_spaces = 0
	case MBS_ALIGN_CENTER, -1:
		start_spaces = n_spaces / 2  + n_spaces%2
		end_spaces = n_spaces / 2
	}

	if flags&MBA_NO_LEFT_PAD != 0 {
      		start_spaces = 0	
	}
   	
 	if flags&MBA_NO_RIGHT_PAD != 0 {
		end_spaces = 0
	}

	remaining_space := dest_size
	if len(dest) < dest_size {
		dest = append(dest, strings.Repeat(" ", start_spaces))
		remaining_space = dest_size - len(dest)
	}
	if len(dest) < dest_size {
		dest = append(dest, str_to_print[:remaining_space])
	}

	if len(dest) < dest_size {
		dest = append(dest, strings.Repeat(" ", end_spaces))
		remaining_space = dest_size - len(dest)
	}

	ret = n_used_bytes + (start_spaces + end_spaces)

	mbsalign_cleanup:

	newstr = "" // We've finally added the padding and truncate step for wide character aka unicode string

	return ret

