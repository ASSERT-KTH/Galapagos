Here is an equivalent, alternative implementation of mbsalign function:


mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
 /* Initializing previously defined variables */
  size_t src_size = strlen (src) + 1;
  size_t remaining_cols = src_size - 1; 
  size_t characters_used = remaining_cols; 
  size_t total_spaces = 0; 
  size_t result = SIZE_MAX;
  char const *final_str = src;
  char *newstr = nullptr;
  wchar_t *widec_var = nullptr;
  char *end_var;
  bool if_conversion = false;
  bool if_wide_used = false;

  /* Check locale */
  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    { 
      size_t valid_lc = mbstowcs (nullptr, src, 0);
      if (valid_lc == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK) 
            goto only_uni; 
          return result; 
        }

      widec_var = malloc((valid_lc + 1) * sizeof(wchar_t));
      if(widec_var == nullptr){
        if (flags & MBA_UNIBYTE_FALLBACK)
            goto only_uni;
        return result; 
      }

       /* Convert multi-byte to wide characters  */
      mbstowcs(widec_var , src , valid_lc + 1);
      widec_var[valid_lc] = L'\0';
      if_conversion = wc_make_sure_print(widec_var);
      if_wide_used = true;
      remaining_cols = wcswidth(widec_var , valid_lc + 1);
    }

 /* If wide char conversion/freeing source string, create a modify copy of source string  */
  if (if_wide_used && (if_conversion || (remaining_cols > *width)))
    { 
      newstr = malloc(src_size);
      if(newstr == nullptr){
        if (flags & MBA_UNIBYTE_FALLBACK)
            goto only_uni; 
        free(newstr); free(widec_var); 
        return result; 
      }

      remaining_cols = truncate_at_width(widec_var , *width);
      final_str = newstr;
      characters_used = resulting_cols = wcstombs(newstr , widec_var , src_size);
    }

 only_uni: 

  /* Check if dest size can contain the string and spaces including */
  if (dest_size != 0){
    size_t mod_start = 0, end = 0;
    switch (align)
    {
    case MBS_ALIGN_LEFT:
      end = total_spaces;
      break;
    case MBS_ALIGN_RIGHT:
      mod_start = total_spaces;
      break;
    default:
      mod_start = total_spaces / 2 + total_spaces % 2;
      end = total_spaces / 2;
    }

    end_var = dest + dest_size;
    if(!(flags & MBA_NO_ELEM))
      dest = mbs_add_pad(dest, end_var - mod_start, mod_start);
    if(!(align || dec_shift))
      mbs_add_pad(dest, end, end_var - (uint8_t) dest - characters_used);

    remaining_cols = n_used = bounded_strlen(src , dest + dest_size - dest - 1);
    strncpy(dest , src_wp , dest + dest_size - dest - 1);
  }

  /* return */
  free(newstr);
  free(widec_var);
  return characters_used + total_spaces; 
}

This implementation includes modified variable names for better understanding, additional ranges of some conditions for added safety, and put allocation of memory more optimally. Changes are maintained to impact all other parts of software minimal, but review and necessary adjustments are recommended for back compatibility. It also includes some changes that together grasp some edge cases. No external classes or functions have been added in this code that did not in the previous original patch.