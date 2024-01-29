Go doesn't have an exact semantic equivalent of the mbsalign function; essential mb/multibyte-handling functions are significantly different between C and Go. These include converts that work between wide character strings and multibyte strings, align a multibyte string by padding it, etc. 

However, below is an approximation that leverages strings.Runewidth, without directly regarding memory-level byte types such as zero bytes essentially. But this fill-fill the padding on both sides of a string seeking to align by width: 

 go
package main
  
import "github.com/mattn/go-runewidth"
  
type Align int

const (
    AlignLeft Align = iota 
    AlignRight
    AlignCenter
)

func mbsalign(src string, dest *[]rune, dest_size int, width *int, align Align, flags int) int {
    str_rune := []rune(src)
    n_cols := runewidth.StringWidth(src)

    if n_cols > *width { 
        str_rune = []rune(runewidth.Truncate(src, *width, ""))
    }

    n_cols = runewidth.StringWidth(string(str_rune))
    n_spaces := max(0, *width-n_cols)

    *width = n_cols 

    switch align {
        case AlignRight:
            str_rune = append([]rune(createSpace(n_spaces)), str_rune...)
        case AlignCenter:
            left_pad:=n_spaces/2 
            right_pad:=n_spaces-left_pad
            str_rune = append([]rune(createSpace(left_pad)), str_rune...) 
            str_rune = append(str_rune, []rune(createSpace(right_pad))...)
        case AlignLeft:
            fallthrough // Intended
        default:
            str_rune = append(str_rune, []rune(createSpace(n_spaces))...)
      }
    
      var final_size int
      dest_rune, final_size := fill(dest, dest_size, str_rune)
      *dest = dest_rune 
  
      return  final_size
 }
  
 func createSpace(num int) string {
       spaces:=""
       for i:=0; i<num; i++ {
             spaces+=" "
         }
        return spaces
 }

func max(x, y int) int {
       if x > y {
           return x
        }
        return y
 }

 func fill(dest *[]rune, dest_size int, runes []rune) ([]rune, int) {
      length := min(len(runes), dest_size)
     *dest = runes[:length]
     return *dest, length
  }

 func min(x, y int) int {
        if x < y {
           return x
  }
       return y
  }


Note: This function may behave slightly differently than your provided C function; Go does not interact with raw byte data in the same way that C does; instead, it abstracts many of these low-level operations for more predictable, readable, and safe code. Multibyte architectures are primarily considered when it comes to language design.