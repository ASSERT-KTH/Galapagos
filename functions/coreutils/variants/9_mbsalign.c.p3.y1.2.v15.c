The Go programming language doesn't support C-like bitwise manipulation or case-control flow by default. So it wouldn't going to fall through in switch case, also strlen is the standard method len in Go. Null pointers of C==nil in Go, garbage collectors of both functions routines differently in Go and in C. The malloc space allocations are automatically handled by the language runtime. So you will see a drastic change in the memory model comparing the code of C related ones and consequently its pointers used.

See the direct Go conversion:

Go
import (
	"errors"
	"unicode/utf8"
	"strconv"
	"strings"
)

func MbsAlign(src string, dest_size int, width *int, align int, flags int) (string, error) {
	ret := -1
	src_size := len(src) + 1
	var newstr string
	src_runes := []rune(src)
	str_wc := src_runes
	str_to_print := src
	n_cols := src_size - 1
	n_used_bytes := n_cols // Not including NUL
	n_spaces := 0
	conversion := false
	wc_enabled := false

	// Constraints
	MBA_UNIBYTE_ONLY := 0
	MBA_UNIBYTE_FALLBACK := 0
	MBA_NO_LEFT_PAD := 0
	MBA_NO_RIGHT_PAD := 0
	MBS_ALIGN_LEFT := 0
	MBS_ALIGN_RIGHT := 1
	MBS_ALIGN_CENTER := 2    

	src_chars := utf8.RuneCountInString(src)
	src_chars += 1 //make space for NUL

	// non-obvious emulation of wchar with []rune
	if src_chars == utf8.UTFMax || (flags&MBA_UNIBYTE_ONLY != 0 && len(src) > 1) {
		if flags&MBA_UNIBYTE_FALLBACK != 0 {
			goto MbsAlignUnibyte
		} else {
			goto MbsAlignCleanup
		}
	}

	str_wc[src_chars-1] = '\x00'
	
	n_cols = src_chars

	//If we transformed or need to trunc the src string
	if wc_enabled && (conversion || (n_cols > *width)) {
		if conversion {
			src_size = len(newstr) + 1
		}
		str_to_print = newstr

		n_used_bytes = len(newstr)
	}

MbsAlignUnibyte:

	conversionWords := []rune(str_to_print)

    if len(conversionWords) > *width {
    	n_cols =  *width
    	n_used_bytes = n_cols
    }

	if *width > n_cols {
		n_spaces = *width - n_cols
	}

	*width = n_cols

	var start_spaces, end_spaces int

	switch align {
	case MBS_ALIGN_LEFT:
	    start_spaces = 0
	    end_spaces = n_spaces
    case MBS_ALIGN_RIGHT:
	    start_spaces = n_spaces
	    end_spaces = 0
	case MBS_ALIGN_CENTER:
	    start_spaces = n_spaces/2 + n_spaces%2
	    end_spaces = n_spaces / 2
	default:
	    return "", errors.New("Unknown alignment")
    }

    if (flags & MBA_NO_LEFT_PAD) != 0 {
    	start_spaces =  0
		} 
		if (flags & MBA_NO_RIGHT_PAD) != 0 {
			end_spaces =  0
      }
    
	    //Pad as necessary
	  pkg := strings.Repeat(conversionWords)
	  padded := strconv.Itoa(mbs_align_pad(newstr, start_spaces)) + pkg + strconv.Itoa(mbs_align_pad(newstr, len(newstr)-end_spaces))

      
    
	ret = n_used_bytes + ((start_spaces + end_spaces) * 1)

MbsAlignCleanup:
	return ret, nil
	return "", errors.New("Goodbye")
}
 
This function MbsAlign hasn't been called cause Go compiler that enforces "declared but not used" policy would say it's not being used and for this function to be compiled successfully in Go, it has to be used or called line of compiled within somewhere of entire complied lines . 

Because, the best way to convert conditional fall through switch would actually translate it to normal switch cause you've never falling though. This gets much more simple. Just translate see case in C that contains fall through switch. For below it, call the ahead one case. Like all over again, for the top below all.

Due to diffs between programming paradigms of Go, given rewritten C programming into Go which isn't possible to be a direct translation. That's is big part with why there rationale using multi-plats development. This generally look quite differently. But yeah again. Caused ambiguity around Mbsalign function strings which has been taken arbitrary and you might want reform Mbsalign to conform more specifically of your target domain challenged conversion dev requirements.  This form conform conversion possibility. 

Refer and Recheck how Golangs operations corresponding of relevant native functions are correctly created seen especially around creation: See Vtype/String and POSIX funcs specific different on multi-platform needs
Regarding used vars, and MabsAlign func in your original description. Best.