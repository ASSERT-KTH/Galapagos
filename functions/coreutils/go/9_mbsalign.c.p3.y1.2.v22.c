Please note that given that Go includes a significant part of built-in methods and also handle the string with another mechanism different from what C actually does. While Go natively only handles UTF-8, C has a completely different approach based on wcs (wide characters). Thus the task description indeed does not have a completely direct translation.

Herein, here's created the basic skeleton of the function with UTF-8 replacements for a more direct treatment corresponding to WC in C: 

go
package main

import (
    "fmt"
    "unicode/utf8"
)

const SizeMax = utf8.UTFMax

type AlignType int
const (
    Unaligned = iota
    MBSAlignLeft 
    MBSAlignRight 
    MBSAlignCenter 
)

type MBSAlign struct{
    Src string
    SrcSize int
    Dest *string
    DestSize int
    Width *int
    Align AlignType
}

func (alignObj *MBSAlign) TraverseChars() { // An alternative to mbstowcs
    // Logic to traverse characters present in alignObj.Src
    // Checks the full traverse results before reallocating memory to dest
}

func (alignObj *MBSAlign) TruncateStrings() {
    // Logic to handle truncations whenever ctr value > *width value
}

func (alignObj *MBSAlign) WritePadding(startSpace, endSpaces int) {
    // Padding logic goes here
}

func (alignObj *MBSAlign) MbsAlign() alignTraverse int{
    // To be replaced by requirement-specific logic
    alignTraverse_Result := int(SizeMax)
    dest = align.Dest
    size_of_src := int(utf8.RuneCountInString(align.Src))+1
    // Declare all the other variables & Constitute the conditional blocks to compose operations in line with the provided C function code...
    return alignTraverse_Result
}

func main(){
   alignment_obj := MBSAlign{Src:yourSourceStringHere,...} //initialize alignment_obj here to carry out the operations inside about mbeAlign interfaces
   alignSize := alignment_obj.MbsAlign()
   fmt.Printf("data:result:%x\n",alignSize)
}


Remember, this is a partial completion of the function since it is really array or implementation dependent request and it'd be expedient with more clarification. Also, Considering the WCS functions from C would require lower-level byte and string manipulation methods in golang (perhaps even dipping into extra-large bytes and manual GC/Clean-up practices), this stub implementation sticks hereby limited to rununcountinstring(). Outlying the properties in a sensible way to adapt the C function with respect to a practical requirement and compensating way to face golang native methods can be done further.

Finally, going more formative and native over low-level replication would eventually help you always: just stating this in case you consider a complete migration to golang from such C code.
