
size_t mbsalign (char const *src, char *dest, size_t dest_size,
                 size_t *width, mbs_align_t align, int flags) 
{
  size_t ret_val = SIZE_MAX;
  bool conversion_status = false;
  bool wide_char_conversion = false;
  size_t src_size = strlen (src) + 1;
  char *tmp_str = nullptr;
  wchar_t *wred_str = nullptr;
  char const *input_str = src;
  size_t col_num = src_size - 1;
  size_t used_bytes_num = col_num;
  size_t padding_num = 0;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chrs = mbstowcs (nullptr, src, 0);
      if (src_chrs != SIZE_MAX)
        {
          src_chrs++;
          wred_str = malloc (src_chrs * sizeof (wchar_t));
          if (wred_str != nullptr)
            {
              if (mbstowcs (wred_str, src, src_chrs) != 0)
                {
                  wide_char_conversion = true;
                  wred_str[src_chrs - 1] = L'\0';
                  conversion_status = wc_ensure_printable (wred_str);
                  col_num = wcswidth (wred_str, src_chrs);
                }
            }
        }
    }

  if (wide_char_conversion && (conversion_status || (col_num > *width)))
    {
      if (conversion_status)
        src_size = wcstombs (nullptr, wred_str, 0) + 1;

      tmp_str = malloc (src_size);
      if (tmp_str != nullptr)
        {
          input_str = tmp_str;
          col_num = wc_truncate (wred_str, *width);
          used_bytes_num = wcstombs (tmp_str, wred_str, src_size);
        }
    }

  if (col_num > *width) 
    col_num = used_bytes_num = *width;

  if (*width > col_num)
    padding_num = *width - col_num;

  *width = col_num;

  size_t left_pad_num = 0, right_pad_num = 0;

  switch (align) 
  {
    case MBS_ALIGN_LEFT:   
      right_pad_num = padding_num; break;
    case MBS_ALIGN_CENTER: 
      left_pad_num = padding_num / 2 + padding_num % 2; 
      right_pad_num = padding_num / 2; break;
    default:                
      left_pad_num = padding_num;
  }

  if (flags & MBA_NO_LEFT_PAD)
    left_pad_num = 0;

  if (flags & MBA_NO_RIGHT_PAD) 
    right_pad_num = 0;

  if (dest_size != 0) 
  {
    char *end_dest = dest + dest_size - 1;
    size_t left_space;

    dest = mbs_align_pad (dest, end_dest, left_pad_num);
    left_space = end_dest - dest;
    dest = mempcpy (dest, input_str, MIN (used_bytes_num, left_space));
    mbs_align_pad (dest, end_dest, right_pad_num);
  }

  ret_val = used_bytes_num + ((left_pad_num + right_pad_num) * 1);
  
  free (wred_str);
  free (tmp_str);
  
  return ret_val;
}
