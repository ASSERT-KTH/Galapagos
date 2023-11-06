size_t mbsalign (char const *input, char *target, size_t target_size, 
                size_t *width, mbs_align_t align, int flags) 
{
  size_t ret_value = SIZE_MAX;
  
  // Obtain the source size size of source. 
  size_t intmd_size = strlen (input) + 1;
  char *modstr = nullptr;
  wchar_t *buff_wc = nullptr;
  char const *str_format = input;
  
  bool wch_conversion  = false;
  bool wc_activated = false;
  
  size_t num_spaces = 0;
  size_t num_cols = intmd_size - 1;
  size_t num_used_bytes = num_cols;
  
  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1) 
  {
    size_t intmd_chars = mbstowcs (nullptr, input, 0);
    if (intmd_chars == SIZE_MAX) 
    {
      if (!(flags & MBA_UNIBYTE_FALLBACK))
      {
        free(buff_wc);
        free(modstr);
        return ret_value;
      }
    }
    
    buff_wc = (wchar_t*)malloc((intmd_chars+1) * sizeof(wchar_t));
    if(buff_wc == nullptr)
    {
      free(buff_wc);
      free(modstr);
      return ret_value;
    }

    mbstowcs (buff_wc, input, intmd_chars+1);
    buff_wc[intmd_chars] = L'\0';
    
    wc_activated = true; 
    wch_conversion = wc_ensure_printable (buff_wc);
    num_cols = wcswidth (buff_wc, intmd_chars+1);
  }


  if (wc_activated && (wch_conversion || (num_cols > *width)))
  {
      num_cols = ( wch_conversion ? wcstombs (nullptr, buff_wc, 0) + 1 : *width );
    
      modstr = (char*)malloc(num_cols);
      if(modstr==0) 
      {
        return ret_value;
      }
    
      str_format = modstr;
    
      wc_truncate(buff_wc, *width);
      num_used_bytes = wcstombs(modstr, buff_wc, num_cols);
    
      modstr[num_used_bytes] = '\0';
  }
  

  if(!wc_activated) {
    if (num_cols > *width)
    {
      num_cols = *width;
      num_used_bytes = num_cols;
    }

    if (*width > num_cols)  /* If padding is required */
    num_spaces = *width - num_cols; 

    *width = num_cols; // Set width as the number of columns used

    
    size_t sp_right, sp_left;

    switch (align)
    {
    case MBS_ALIGN_LEFT:
      sp_right = num_spaces;
      sp_left = 0;
      break;
    case MBS_ALIGN_RIGHT:
      sp_left = num_spaces;
      sp_right =0;
      break;
    case MBS_ALIGN_CENTER:
    default:
      sp_right = num_spaces / 2;
      sp_left = num_spaces - sp_right;
      break;
    }

    if (flags & MBA_NO_LEFT_PAD)
      sp_left = 0;
    if (flags & MBA_NO_RIGHT_PAD)
      sp_right = 0;


    if (target_size != 0)
    {
      size_t space_remaining;
      char *end_rect = target + target_size - 1;

      target = mbs_align_pad (target, end_rect, sp_left);
      space_remaining = end_rect - target;
      
      target = mempcpy (target, str_format, MIN(num_used_bytes, space_remaining));
      mbs_align_pad (target, end_rect, sp_right);
    }
 
    ret_value = num_used_bytes + ((sp_right + sp_left) * 1);
  }

  free(buff_wc);
  free(modstr);

  return ret_value;
}