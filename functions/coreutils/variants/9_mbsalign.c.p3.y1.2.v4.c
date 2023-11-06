The Go language semantic equivalent is not exactly feasible due to differences and limitations of low level handling between the two languages. Maximum characteristics can be maintained but due to restrictions an exact transformation cannot occur. Below is provided version.

go
import (
    "unicode/utf8"
    "unicode"
    "fmt"
)

type MbsAlignT int

const (
   MBS_ALIGN_LEFT MbsAlignT = iota
   MBS_ALIGN_RIGHT
   MBS_ALIGN_CENTER
   ...
   MBA_UNIBYTE_ONLY
   ...
   MBA_UNIBYTE_FALLBACK
   ...
   MBA_NO_LEFT_PAD
   ...
   MBA_NO_RIGHT_PAD
   ...
)

func mbsalign(src string, dest *string, dest_size int, width *int, align MbsAlignT, flags int) int {
  maxSize := int(^uint(0) >> 1)
  ret_val := maxSize
  src_runes := []rune(src)
  src_size := len(src_runes)

  n_cols := src_size
  n_used_bytes := n_cols

  n_spaces := 0
  str_to_print := string(src_runes)

  if (*width > n_cols) {
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
        start_spaces = n_spaces / 2 + n_spaces % 2
        end_spaces = n_spaces / 2
    }

  *dest = fmt.Sprintf("%*s%s", start_spaces, "", str_to_print + string(make([]rune,  end_spaces, end_spaces)))    

  if (len(*dest) > dest_size) {
    *dest = (*dest)[:dest_size-1]
  }

  ret_val = n_used_bytes + (start_spaces + end_spaces)
  return ret_val
}

This approximation clearly has limitations and may need adaptions according to specific requirements of the application. Many key functions from the C-version such `MB_CUR_MAX`, `wc_ensure_printable`, `mbstowcs` which are a low-level byte methods for Unicode handling can't be transposed into go as there is no equivalent functionality, as a consequences multibyte support is limited.

Here is an attempt to translate rather complex given C-function `mbsalign` into Go as close as go strict typing, Unicode handling functions, and the lack of certain low-level typ methods in go allow. Without clear understanding of the business domain, use cases, constraints, and dependencies of the function, the correctness of the 'best-chance' estimation cannot be guaranteed especially among memory low level functions. Code replication function was introduced assuming user-defined based on instruction restrictions. Those yet-marked objects are placeholders for user-defined required functionality. Int-type 'flags' placeholder arguments left intact on future bitwise requirements.

It is ultimately crucial that further addition of detailed user-defined implementations and non-existing replicas are formed keeping domain application practice.
