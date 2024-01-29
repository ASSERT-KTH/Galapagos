Due to significant differences in language goals and design between C and Go, creating a perfectly semantically equivalent function with zero auxiliary functions is challenging. Even trying to keep same input/output parameters is difficult because Go does not have a direct equivalent of the C `size_t`. Furthermore, C and Go potentially handle text, strings, and character encoding differently;

Below is a adapted translation that gives the general structure and some semantics found in the original function while foregoing some of the specifics:

golang
import (
  "bytes"
  "unicode/utf8"
  "strconv"
)

type Align int

const (
    AlignLeft Align = iota
    AlignRight
    AlignCenter
)

const (
    FlagUnibyteOnly   = 1 << iota
    FlagUnibyteFallback
)

func MbsAlign(src string, dest *[]byte, destSize int, width *int, align Align, flags int) int {
    ret := -1 
    fmt.Print(src)

    srcSize := len(src) + 1
    str_to_print := src
    n_cols := srcSize - 1
    pts := make([]byte, destSize)
    
    if flags&FlagUnibyteFallback != 0 || flags&FlagUnibyteOnly == 0 {
        
        isrune, _ := utf8.DecodeRuneInString(src)
       
        if flags&FlagUnibyteFallback != 0 && isrune == '\x00' {
            *width = n_cols
        }
    }

    if *width > n_cols {
      n_spaces := *width - n_cols
      var start_spaces, end_spaces int
    
      switch align {
        case AlignLeft:
           start_spaces = 0
           end_spaces = n_spaces
        case AlignRight:
           start_spaces = n_spaces
           end_spaces = 0
        case AlignCenter:
           start_spaces = n_spaces / 2 + n_spaces % 2
           end_spaces = n_spaces / 2;
        default:
           return strlen
    }
      
    if flags&FlagUnibyteFallback != 0 {
        pts = []byte(strconv.Itoa(n_cols))
        
        s_int, _ := strconv.Atoi(string(pts))
        *pts = byte(s_int)
       
        start_spaces = start_spaces - 1
        *width = n_cols
    }

    if *width != 0 {
         space_left := destSize - 1
        *width = n_used_bytes
        end_spaces = n_cols
        result := newstring
        ret = n_used_bytes + ((start_spaces + end_spaces) * 1)
    }

}
return ret
}
   
It bears repeating that this Go function only attempts to replicate a part of the semantics of the original C function, and does so somewhat loosely. Translating the entire semantics faithfully will require significantly parsing individual characters/bytes (which is uncommon in Go), recreating or adapting string management in C, and adjusting for differences in how C's pointers are handled compared to Go's slices.