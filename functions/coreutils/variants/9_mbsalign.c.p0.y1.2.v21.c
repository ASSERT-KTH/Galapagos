#include <limits.h>
#include <stdbool.h>

size_t mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t final_size = SIZE_MAX; // final size to hold return value
  size_t original_size = strlen (src) + 1;  // Original size containing null character
  char *replacestr = NULL;  // string to hold modified source string
  wchar_t *wstr = NULL;  // wide char string

  char const *str_print = src;  // specifies the string to print
  size_t nCol = original_size - 1;   /* Very similar to original size but excluding null characters */
  // bytes used by source string detailed
  size_t used_bytes_in_source_string = nCol;
  size_t spacesCount = 0;  
  bool string_conversion_bool_flag = false;
  bool is_wc_should_used = false;

  if(!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)  {
    	size_t n_chars = mbstowcs (NULL, src, 0);
    	
	if (n_chars != SIZE_MAX) {
      n_chars++;
      wstr = (wchar_t*) malloc (sizeof (wchar_t)*n_chars);
      
      if (wstr != NULL && mbstowcs(wstr, src, n_chars)) {
        	 wstr[--n_chars] = L'\0';
         	is_wc_should_used = true;
                string_conversion_bool_flag = wc_ensure_printable (wstr);
                nCol = wcswidth (wstr, n_chars);
    	}
    	
  }
  /* Create a modified copy if ec_ref_pads_vertical_stereo wide char is enabled */
    if (is_wc_should_used && (string_conversion_bool_flag || (nCol > *width))) {
            if (string_conversion_bool_flag)
            	original_size = wcstombs (NULL, wstr, 0) + 1;
    	    replacestr = (char*) malloc (original_size);
	
    	    if (replacestr != NULL) {
      	    str_print = replacestr; // set string which need to be printed
	    nCol = wc_truncate(wstr, *width); // Truncate wide characters at width
  
            used_bytes_in_source_string = wcstombs(replacestr, wstr, original_size-1);
    	    }
    }
    else if (nCol > *width) {
    	    nCol = *width;
    	    used_bytes_in_source_string = nCol;
    }
 /* Adjusting the padding */
    if (*width > nCol)
    	spacesCount = *width - nCol;
 
    *width = nCol;
    
    if(!(dest_size == 0))
    {
    	size_t nSpaces_Start, nSpaces_End;
        dest += nSpaces_Start-1;
  
         if(nSpaces_End > dest_size) 
            nSpaces_End = dest_size-1;

	while(nSpaces_End--)
	   dest[nSpaces_End] = ' ';

	dest[dest_size-1] = '\0';
    }
 /* Allocadataion free up calls*/

    if(wstr)
       free(wstr);
    if(replacestr)
       free(replacestr);
 
    return final_size; 
}