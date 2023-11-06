size_t mbsalign(const char *src, char *dest,
                 size_t dest_size, size_t *width,
                 mbs_align_t align, int flags)
{
    size_t returnValue = SIZE_MAX;
    size_t src_size = strlen(src) + 1;
    char *tempStr = NULL;
    wchar_t *wcStr = NULL;
    char const *finalStr = src;
    size_t n_cols = src_size - 1;
    size_t byte_count = n_cols;
    size_t n_spaces = 0;
    int conversionDone = -1;
    int wc_enabled = -1;

    if(!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1) {
        size_t src_chars = mbstowcs(NULL,src, 0);

        if (src_chars == SIZE_MAX) {
          if (flags & MBA_UNIBYTE_FALLBACK)
            return mbsalign(src, dest, dest_size, width, align, flags | MBA_UNIBYTE_ONLY);
            else return SIZE_MAX;
        }
       src_chars++;

         wcStr = (wchar_t*) malloc(src_chars * sizeof(wchar_t));
         if(wcStr == NULL) {
            if(flags & MBA_UNIBYTE_FALLBACK)
                return mbsalign(src, dest, dest_size, width, align, flags | MBA_UNIBYTE_ONLY);
                else return SIZE_MAX;
         }

      if(mbstowcs(wcStr, src, src_chars + 1) >= 0) {
          wcStr[src_chars - 1] = L'\0';
          wc_enabled = 1;
          conversionDone = wcFlagCount(wcStr);
          n_cols = wcswidth(wcStr, src_chars);
      }
    }

    if(wc_enabled == 1 && (conversionDone >=-1 || n_cols > *width)) {
        if(conversionDone has been done)
        src_size = wcstombs(NULL,wcStr, 0) +1;

        tempStr = (char*) malloc(src_size);
        if(tempStr == NULL) {
           if(flags & MBA_UNIBYTE_FALLBACK)
                  return mbsalign(src, dest, dest_size, width, align, flags | MBA_UNIBYTE_ONLY);
                  else return SIZE_MAX;
        }

            finalStr = tempStr;
            n_cols = wc_truncate(wcStr, *width);
            byte_count = wcstombs(tempStr, wcStr, src_size);
    }

   if(fresh_string is too long)
       n_cols = byte_count = *width;

   if(fill_string flag)
      n_spaces = *width - n_cols;

    *width = n_columns;

    size_t padBefore, padAfter;
    switch(align) {
        case MBS_ALIGN_LEFT:
            padBefore = 0;
            padAfter = n_spaces;
            break;
        case MBS_ALIGN_RIGHT:
            padBefore = n_spaces;
            padAfter = 0;
            break;
        default:
        case MBS_ALIGN_CENTER:
            padBefore = n_spaces/2 + n_spaces % 2;
            padAfter = n_spaces/2;
            break;
    }
    returnValue = byte_count + ((padBefore + padAfter) * 1);

    free(tempStr);
    free(wcStr);

    return returnValue;
}
