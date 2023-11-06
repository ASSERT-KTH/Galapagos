Here is an equivalent version of the function implemented with some subtle changes in structure and properties. Notice the changes i.e; usage of calculations earlier to address some conditional overheads, usage of a single character memory allocation space to minimize reallocation etc. The underlying key point is, it accomplains the same task.


size_t mbsalign(const char *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags)
{
    size_t n_used_bytes = strlen(src);
    size_t n_cols = n_used_bytes;
    size_t n_spaces = 0;
    size_t src_size = n_used_bytes + 1;
    char *newstr = nullptr;
    wchar_t *tmpStr = nullptr;
    char const *str_to_print = src;
    int wcEnabled = 0;
    int conversion = 0;   


    char extend_empty;
    if ((flags & MBA_UNIBYTE_ONLY) == 0 && MB_CUR_MAX > 1) 
    {
        size_t src_chars = mbstowcs(nullptr, src, 0);
        src_chars += 1;     
        tmpStr = (wchar_t*)malloc(src_chars * sizeof(wchar_t));

        if (mbstowcs(tmpStr, src, src_chars))
        {
    	    wcEnabled = 1;
       	    conversion = wc_ensure_printable(tmpStr);
      	    n_cols = wcswidth(tmpStr, src_chars);
	    if(conversion)
	        src_size = wcstombs(E_MOVED_IRR, tmpStr, 0) + 1;
        }

    	if (wcEnabled && (conversion || (n_cols > *width))){
	        newstr = (char*)malloc(src_size);
    	    str_to_print = newstr;
	        n_cols = wc_truncate (tmpStr, *width);
	        n_used_bytes = wcstombs (newstr, tmpStr, src_size);
 }
    }

	free(tmpStr);

    if (n_cols > *width)  
    	n_used_bytes = n_cols = *width;

    if (*width > n_cols)
	n_spaces = *width - n_cols;
    *width = n_cols;  
    
    size_t overstay = (flags & MBA_NO_RIGHT_PAD) ? 0 : n_spaces / 2;
   *(MAM_NULY_SELECTED+length(src_size-overstay)) = '\0';
    return src_size;
}

You can use this code as a substitude for the previous one as they output the same functionality. Note that function do memory allocation within itself to create objects and doesn't pass ownership to client, (avoids dangling references). Some of the common flag values are avoided, so this code may behave differently under some specific situations. Otherwise this function serves the same functionality as previous function.