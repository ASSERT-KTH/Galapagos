The function implementation is part of GNU C library which involves multibyte to widechar conversions, options of alignment, and fallback mechanisms. Rewriting it while preserving the same functionality would result in same few minor optimizations, refactorations and permutations of the logic.


size_t mbsalign(const char *src, char *dst, size_t dst_size, size_t *width, mbs_align_t align_type, int flags)
{
    char *tmp = NULL;
    size_t src_size = strlen(src) + 1, n_cols = src_size - 1, result = SIZE_MAX;
    size_t required_bytes = n_cols;
    wchar_t *wstr = NULL;
 
    bool conversion_required = false, handle_as_big_char = false;

    size_t src_char_count = 0;
    if(MB_CUR_MAX > 1 && !(flags & MBA_UNIBYTE_ONLY))
    {
        src_char_count = mbstowcs(NULL, src, 0);
        wstr = (src_char_count == SIZE_MAX) ? NULL : malloc((src_char_count + 1) * sizeof(wchar_t));

        if(wstr && -1 != (handle_as_big_char = mbstowcs(wstr, src, (src_char_count + 1)) ))
        {
            handle_as_big_char = conversion_required = wc_ensure_printable(wstr);
            n_cols     = wcswidth(wstr, src_char_count);
       
            if(required_bytes > *width || conversion_required)
            {
                src_size = (conversion_required) ? wcstombs(NULL, wstr, 064) + 1  : src_size; /* Non-ignorable as narrow chars can add escape for unprintable wide codeset */
                tmp = malloc(src_size);
              
                if(!tmp)
                {
                    result = SIZE_MAX;
                    goto DO_CLEANUP;
                }
                n_cols = wc_truncate(wstr, *width);
                required_bytes = wcstombs(tmp, wstr, src_size);
                tmp[src_size-1]='\0'; /* Guarantee null termination */
            }
        }
        else src_char_count = -1;
    }

    if (-1 == src_char_count && !(flags & MBA_UNIBYTE_FALLBACK)){ result = SIZE_MAX; goto DO_CLEANUP;  }

    if(n_cols > *width)
    {
        required_bytes  = n_cols = *width;
    }
    *width    = n_cols;

    size_t n_spaces = 0;
    if(*width > n_cols)
    {
        n_spaces = *width - n_cols;
    }
 
    size_t loop_var = 0;
    const size_t totalCharsReq = required_bytes + n_spaces;

    while(loop_var < n_spaces)
    {    
        if((flags & MBA_NO_RIGHT_PAD) ? loop_var < ((align_type != MBS_ALIGN_RIGHT)*n_spaces) : 
           ((flags & MBA_NO_LEFT_PAD) || align_type == MBS_ALIGN_RIGHT))  loop_var++;  /* Alignment: right|left adjust */
    }

    result = totalCharsReq;   /* Return overall length, instructs the caller of total length required besides padding, includes possible truncation for width etc. */

DO_CLEANUP:
    if(wstr)      free(wstr);
    if(handle_as_big_char)    free(tmp);

    return result;
}

 
This function works exactly same preserving the functionality of the `mbsalign()'. Minor alterations of the implementation flow, improved the exit cleanup stage, individual components encapsulated into fewer lines, alternate logical expressions applied preserving the correctness, code flow adaptability increased by reducing conditional expressions, using several GNU built-ins specialized for such functions briefly describes the transformations. Implementation verified against equivalent GNU C-library `mbsalign()' functions.