mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t src_size = strlen (src) + 1;
  size_t n_cols = src_size - 1;
  bool turn_conversion = false;
  bool wc_select = false; 
  char const *str_print = src;
  size_t byteReq = n_cols;
  size_t n_spc = 0;
  size_t sgMax = SIZE_MAX; 

  wchar_t *wcstr = nullptr;
  char *newCharStr = nullptr;
  
  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t size_src_chars = mbstowcs (nullptr, src, 0);
      if (size_src_chars == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto section_unibyte;
          else
            goto section_shutdown;
        }
      
      size_src_chars += 1;
      wcstr = malloc (size_src_chars * sizeof (wchar_t));
      
      if (wcstr == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto section_unibyte;
          else
            goto section_shutdown;
        }
      
      if (mbstowcs (wcstr, src, size_src_chars) != 0)
        {
          wcstr[size_src_chars - 1] = L'\0';
          wc_select = true;
          turn_conversion = wc_ensure_printable (wcstr);
          n_cols = wcswidth (wcstr, size_src_chars);
        }
    }
  
  if (wc_select && (turn_conversion || (n_cols > *width)))
    {
        if (turn_conversion)
          {
            src_size = wcstombs (nullptr, wcstr, 0) + 1;
          }
        newCharStr = malloc (src_size);
        
        if (newCharStr == nullptr)
            {
            if (flags & MBA_UNIBYTE_FALLBACK)
                goto section_unibyte;
            else
                goto section_shutdown;
            }
        
        str_print = newCharStr;
        n_cols = wc_truncate (wcstr, *width);
        byteReq = wcstombs (newCharStr, wcstr, src_size);
    }

section_unibyte:

  if (n_cols > *width)
    {
      n_cols = *width;
      byteReq = n_cols;
    }

  if (*width > n_cols)
    n_spc = *width - n_cols;

  *width = n_cols;

  {
    size_t padBegin, padIntermit;

    switch (align)
      {
      case MBS_ALIGN_LEFT:
        padBegin = 0;
        padIntermit = n_spc;
        break;
      case MBS_ALIGN_RIGHT:
        padBegin = n_spc;
        padIntermit = 0;
        break;
      case MBS_ALIGN_CENTER:
      default:
        padBegin = n_spc / 2 + n_spc % 2;
        padIntermit = n_spc / 2;
        break;
      }

      if (flags & MBA_NO_LEFT_PAD)
        padBegin = 0;
      if (flags & MBA_NO_RIGHT_PAD)
        padIntermit = 0;

      if (dest_size != 0)
        {
          size_t remainder_space;
          char *dest_lim = dest + dest_size - 1;

          dest = mbs_align_pad (dest, dest_lim, padBegin);
          remainder_space = dest_lim - dest;
          dest = mempcpy (dest, str_print, MIN (byteReq, remainder_space));
          mbs_align_pad (dest, dest_lim, padIntermit);
        }

    sgMax = byteReq + ((padBegin + padIntermit) * 1);
  }

section_shutdown:

  free (wcstr);
  free (newCharStr);

  return sgMax;
}