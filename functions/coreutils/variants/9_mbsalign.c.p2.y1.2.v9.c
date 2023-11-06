mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t src_size = strlen (src) + 1;
  size_t n_cols = src_size - 1;

  char *copyStr = nullptr;
  wchar_t *multibyteStr = nullptr;

  size_t n_used_bytes = n_cols;
  size_t required_spaces = 0;

  bool conversion_needed = false;
  bool multibyte_conversion = false;

  char const *input_str = src;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > sizeof(char))
    {
      size_t src_length = mbstowcs (nullptr, src, 0);
      if (src_length == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto alternative_path;
          else
            goto cleanup;
        }
      src_length += 1;
      multibyteStr = ( wchar_t *)malloc (src_length * sizeof (wchar_t));
      if (multibyteStr == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto alternative_path;
          else
            goto cleanup;
        }
      if (mbstowcs (multibyteStr, src, src_length) != 0)
        {
          multibyteStr[src_length - 1] = L'\0';
          multibyte_conversion = true;
          conversion_needed = wc_ensure_printable (multibyteStr);
          n_cols = wcswidth (multibyteStr, src_length);
        }
    }
    
  if (multibyte_conversion && (conversion_needed || (n_cols > *width)))
  {
    if (conversion_needed)
      {
        src_size = wcstombs (nullptr, multibyteStr, 0) + 1;
      }
    copyStr = (char *)malloc (src_size);
    if (copyStr == nullptr)
      {
        if (flags & MBA_UNIBYTE_FALLBACK)
          goto alternative_path;
        else
          goto cleanup;
      }
    input_str = copyStr;
    n_cols = wc_truncate (multibyteStr, *width);
    n_used_bytes = wcstombs (copyStr, multibyteStr, src_size); 
  }

alternative_path:

  if (n_cols > *width)
    {
      n_used_bytes = *width;
      n_cols = *width;
    }

  if (*width > n_cols) /* Have excess space. Add padding spaces */
    required_spaces = *width - n_cols;

  *width = n_cols;
  
  // number of spaces needed at start and end depending on alignment.
  size_t pre_spaces = int(0.5 * required_spaces);
  size_t post_spaces = required_spaces - pre_spaces;
  
  if(!(align == MBS_ALIGN_LEFT || flags & MBA_NO_RIGHT_PAD))
  {
    switch(align)
    {
    case MBS_ALIGN_RIGHT:
      std::swap(pre_spaces, post_spaces);
      break;
    case MBS_ALIGN_CENTER:
      break;
    }
  }
  
  if (dest_size != 0)
    {
      char* ptr_string = mbs_align_pad(src, dest+dest_size - strlen(dest)-1, pre_spaces);
      void* new_dest = mempcpy(dest, ptr_string, MIN(n_used_bytes, dest_size -1));
      dest = mbs_align_pad((char*)new_dest, src + dest_size - strlen(dest) - potential_input_bytes, post_spaces);
    }
  size_t string_return = n_used_bytes + pre_spaces + post_spaces;
  
cleanup:
  free (multibyteStr);
  free (copyStr);
  return (string_return - MAX(pre_spaces, post_spaces));
}