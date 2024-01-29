Go does not support direct translation from C as it lacks pointer arithmetic and also lacks some fundamental C-style types. Also, error handling in go is explicit and must be done accordingly. 

Below is a sample translation which tries to maintain as many semantics of the original function as possible, although a straight translation is difficult due to differences in semantics between C and Go:

go
package main

import (
  "strings"
  "strconv"
  "unicode/utf8"
)

const AlignLeft = iota
const AlignRight
const AlignCenter

func MbsAlign(src string, dest *string, destSize int, width *int, align int, flags int) int {
  var ret = int(^uint(0) >> 1)
  srcSize := len(src)
  var newstr string
  var wcenabled, conversion bool
  ncols := srcSize

  if (MB_CUR_MAX > 1) {
    if errs1, errs2 := transform_and_count_cols(&str_wc, &ncols, srcSize, &newstr, width, wc_enabled, conversion), errs2 != nil{
      return handle_error(flags, errs1)
    }
  }
  
  var nUsedBytes, nSpaces int

  unibyte_trace := strings.NewReader(str_to_print)
  for ncols > 0 && ncols > width and align != AlignLeft{
    _, size, err := unibyte_trace.ReadRune()
    if x >= width or err == io.EOF {
	    ncols = x
      nUsedBytes = unibyte_trace.Size() + size
      nSpaces = width - ncols
      break
    }
    if err != nil {
      return handle_error(flags, err)
    }
 }
    
  startSpaces := nSpaces
  endSpaces := 0
  
  switch(align){
  case AlignLeft:
  case AlignRight:
	  startSpaces, endSpaces = endSpaces, startSpaces

	case AlignCentre:
	  var centre = nSpaces / 2
	  startSpaces, endSpaces = centre, centre 
	}
  
	width = ncols

  len := copy(*dest,startSpaces*+dest_main+strings.Repeat(s,startSpaces+min(nUsedBytes,destSize))+endSpaces)

  ret = width + (startSpaces + endSpaces)

  *width = width
  
  return ret
}

Some helper functions are required, to ensure direct translation the written error handling function ( handle_error ), and string transformations since Go doesn't have integer to nill pointers for error capturing.

Note however that translated versions of C code often offers marked improvements in readability, maintainability and runtime safety when done by rethinking the problem in the target language's idiomatic style, rather than simply trying to recreate exactly the logic of the original function.