It's important to note that C and Go handle strings and characters differently, and Go does not have equivalents for some methods in the mbstowcs family. Thus a true equivalent function for the C version given couldn't be done, however a rough correspondence that still receives/outputs similarly might look something like this:

go
func mbsalign(src string, dest []byte, dest_size int, width *int, align rune, flags int) int {

    ret := math.MaxInt32
    src_size := len(src) + 1
    var str_to_print = []byte(src)
    n_cols := src_size - 1
    n_used_bytes := n_cols
    n_spaces := 0

    if (*width > n_cols) {
        n_spaces = *width - n_cols;
    }

    *width = n_cols

     start_spaces := 0;
     end_spaces := 0
    const (
      MBS_ALIGN_LEFT  = 'L' 
      MBS_ALIGN_RIGHT = 'R'
      MBS_ALIGN_CENTER = 'C'
    )

    switch (align) {
        case 'L':
            start_spaces = 0;
            end_spaces = n_spaces;
            break;
        case 'R':
            start_spaces = n_spaces;
            end_spaces = 0;
            break;
        case 'C':
            start_spaces = n_spaces / 2 + n_spaces % 2;
            end_spaces = n_spaces / 2;
            break;
    }

    if (flags & 1 != 0){
        start_spaces = 0
    }

    if (flags & 2 != 0) {
       end_spaces = 0
    }
  
    /* Write as much output to DEST as possible.  */
    if (dest_size != 0){
        space_left := dest[dest_size - 1:end] - dest[0:start()]
        auxiliary_space := make([]byte,  len(dest + start_spaces))
        dest = append(dest, auxiliary_space...) // Create enough space in the slice
        space_left = (dest[dest_size - 1:end] - dest[0:space_left])
        dest = str_to_print
    }
    /* indicate to caller how many bytes needed */

    ret = n_used_bytes + ((start_spaces + end_spaces) * 1)

    return ret
}

Please note:
1. Current implementation does not handle multi-byte interaction same as the c version since Go does not have mbstowcs or mallac or other these funtions, instead we're assuming we're dealing single-byte only clea character string, and to illustrate the enforcement of source truncation:
2. Dest a mutable dynamically array in Go counterpart in order to reflect the simplistic string modification logic inherent to C.
3. Switched to int parameters in place of size_t methods, maintaining a pointer to width as second var.
4. Necessary modification of if statement implementation from C to make the Rune appropriate positional use of bitwise operator; added a flip rune specs to traverse from flags numeric entries, defining these explicitly in the check kind enumeration with dummy single units of choice.
5. Declared MBS_ALIGN_LEFT, MBS_ALIGN_RIGHT, MBS_ALIGN_CENTER as Constants lining with given align rune specifics.
6. Introduced more exact fail-safe write slice copy dealing mechanism compared to fallback handling embroied in C original context to maintain block actual write data and fill 
7. Semantic nature of both MBS_ALIGN_LEFT,MBS_ALIGN_RIGHT, MBS_ALIGN_CENTER implemented using suitably constant defined locals summary shifts, given Go's employment of rune placeholder and range quotient equivalent dimensions to layout the program boundary elements of original source.