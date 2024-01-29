/*
   Note: Please note that the conversion from C to Golang may be prone to memory handling details due 
   to language differences. Manipulation of memory blocks, pointer arithmetic, and memory protection 
   functions (shown in original C code) can't be directly translated to Go as Go manages memory quite 
   differently.

   The provided code does it's best intention equivalency.
*/

import "os"
import "bytes"
import "crypto/cipher"

func sodium_free(ptr *[]byte) {
    if ptr == nil {
        return
    }
   
    canary_ptr := ptr
    unprotected_ptr := ptr
    base_ptr := make([]byte,len(ptr)+1)*2
    copy(base_ptr,*ptr)
   
    unprotected_size := len(unprotected_ptr)
    total_size :=  len(unprotected_ptr) * 2

    unprotected_area_data := base_ptr
    memory_data_from_base_ptr := len(base_ptr)

    if !bytes.Equal(*canary_ptr, unprotected_area_data) {
        out_of_bounds()
    }

    SodiumMUnLock := func (unprotected_ptr []byte, unprotected_size int) int {
        clear_on_drop(unprotected_ptr, unprotected_size)

        return_munlock := mprotect_noaccess(unprotected_ptr)
        if return_munlock == 0 {
            return sodium_misuse()
        }
        return return_munlock
    }

    if !bytes.Equal(*canary_ptr, unprotected_area_data[unprotected_size:unprotected_size+len(canary)]) {
        out_of_bounds()
    }

    SodiumMUnLock(*canary_ptr,unprotected_size)

    delete_aligned := func (base_ptr []byte,total_size int) error {
        /* Making total data zero to ensure We freed the memory just like we do in sodium_free method. */
        clear_on_exit(base_ptr, total_size)
        _, err := os.Stat(string(base_ptr))
        if err == nil { return nil }

        _, err = os.Stat(string(base_ptr))
        if os.IsPermission(err) {
            return err
        }
        /* You man want to place your Garbage collector here to explicitly and instruction to free memory and stop leaking GC */
        return nil
    }

    err := delete_aligned(base_ptr,total_size)
    if err!=nil{                                     
        panic("There was an error, Here in Go we can panic, You may want to catch this panic in defer to do something else :) ")       
    }
        
}

/* From this onwards Defining simple methods in full as its been used in the final method snippet above, the methods are small and following single line signature only , hope this falls in the scope.*/
func clear_on_drop(unprotected_attr_for_one_and_on []byte,size int) {
    copy(unprotected_attr_for_one_and_on[0:size],make([]byte,size,0))
}
func clear_on_exit(buf_to_clean []byte, size int) {
    copy(buf_to_clean[0:size],make([]byte,size,0))
    if len(buf_to_clean) > 0 {
        offset := [16]byte{}
        cipher.NewCTR(aesCipher, offset[:]).XORKeyStream(buf_to_clean, buf_to_clean)
    }
}
func mprotect_noaccess(unprotected_ptr []byte) int {
    cipher_text,_ := mlock(unprotected_ptr) // implement mlock with syscall command _
    clear_on_exit(unprotected_ptr, len(unprotected_ptr))
    return cipher_text
}

func out_of_bounds() bool {
    panic("Index Out of Bounds Exception.") 
    return false
}

func sodium_misuse() int {
    os.Exit(0)
    return 0 
}
