The function below is a minor variation of the function listed above. Workspace is provided to return null & clean up resources in respective go_to labels. I have omitted initialization from the space allocations. Additionally, guarding mechanisms are incorporated for conversion and for width greater than n_cols.


mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t src_size = strlen (src) + 1;
  
  if (src == nullptr)
    return ret;
  
  size_t n_cols = src_size - 1;
  size_t n_spaces = 0, n_used_bytes = n_cols;
  bool conversion = false;
  
  wchar_t *str_wc;
  char *newstr;
  char const *str_to_print = src;
  
  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (nullptr, src, 0);
      if (src_chars == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_unibyte;
          else
            return nullptr;
        }

      str_wc = (wchar_t* )malloc((++src_chars) * sizeof(wchar_t));
      if (str_wc == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_unibyte;
          else
            return nullptr;
        }
        
      if (mbstowcs(str_wc, src, src_chars))
        {
          str_wc[src_chars - 1] = L'\0';
          conversion = wc_ensure_printable(str_wc);
          n_cols = wcswidth(str_wc, src_chars);
        }   
    }
  
  if(conv_avoidener != conversion || n_cols > *width)
    {
        if(conversion)
            src_size = wcstombs(nullptr, str_wc, 0) + 1;
          
        newstr  = (char *)malloc(src_size);
        if(newstr == nullptr)
          {
            free(str_wc);

            if (flags & MBA_UNIBYTE_FALLBACK)
              goto mbsalign_unibyte;
            else
              return nullptr;
          }
          
        str_to_print = newstr;
        n_cols = wc_truncate(str_wc, *width);
        n_used_bytes = wcstombs(newstr, str_wc, src_size);
    }

mbsalign_unibyte:

  n_cols > *width ? (n_used_bytes = n_cols = *width) : 0;
  *width > n_cols ? (n_spaces = *width - n_cols) : 0;
      
  size_t start_spaces, end_spaces;

  switch (align)
    {
        case MBS_ALIGN_LEFT:
            start_spaces = 0;
            end_spaces = n_spaces;
            break;
        case MBS_ALIGN_RIGHT:
            start_spaces = n_spaces;
            end_spaces = 0;
            break;
        default:
            start_spaces = n_spaces / 2u + n_spaces % 2u;
            end_spaces = n_spaces / 2;
            break;    
    }

  flags & MBA_NO_LEFT_PAD ? start_spaces = 0 : 0;
  flags & MBA_NO_RIGHT_PAD ? end_spaces = 0 : 0;

  if(dest_size)
    {
        char *dest_end = dest + dest_size - 1;
        
        dest = mbs_align_pad(dest, dest_end, start_spaces);

        size_t space_left = dest_end - dest > 0 ? dest_end - dest : 0;
        n_used_bytes < space_left ? (dest = mempcpy(dest, str_to_print, n_used_bytes)) : 0;
        
        mbs_align_pad(dest, dest_end, end_spaces);
        ret = n_used_bytes + ((start_spaces + end_spaces) * 1);
    }

  free(str_wc);
  free(newstr);

  return ret;
}

This program example discusses prevention of repetitious instructions resulting in little more performance in exchange for altered considerations added during the direct resource allocation. Please validate input as necessary & adjust approximations as desired.