/**
 * This function is largely similar to the initial implementation, with the primary variants being:
 * - Handling of `malloc` failure.
 * - Some adjustments in the switch statement.
 * - Absence of going to labels, due to patterns adjustment in codes control the flow.
 */
size_t mbsalign(char const *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags){
  size_t ret_val = SIZE_MAX;
  bool conversion = false, wide_chars = false;
  size_t source_length = strlen(src) + 1;
  size_t num_cols = source_length - 1;
  size_t used_bytes = num_cols;
  size_t spaces = 0;
  char *trans_str = NULL; 
  wchar_t *wu_str = (wchar_t*)malloc(source_length * sizeof(wchar_t));
  char const *string_to_print = src;

  if (wu_str == NULL) return ret_val;
  
  if (MB_CUR_MAX > 1 && ((flags & MBA_UNIBYTE_ONLY) == 0)){
    size_t source_chars = mbstowcs(NULL, src, 0);
    
    if (source_chars != SIZE_MAX) {
      if (mbstowcs(wu_str, src, source_chars + 1) >= 0){
        wu_str[source_chars + 1] = L'\0';
        wide_chars = true;
        conversion = wc_ensure_printable(wu_str);
        num_cols = wcswidth(wu_str, source_chars);
      }
    }
  }

  if (wide_chars && (conversion || (num_cols > *width))){
    if (conversion){
        source_length = wcstombs(NULL, wu_str, 0) + 1;
    }
    trans_str = malloc(source_length);
    if (trans_str == NULL){
      free(wu_str);
      return ret_val;
    }
    string_to_print = trans_str;
    num_cols = wc_truncate(wu_str, *width);
    used_bytes = wcstombs(trans_str, wu_str, source_length);
  }

  if (*width > num_cols){
    spaces = *width - num_cols;
  }

  *width = num_cols;

  {
    size_t left_spaces = spaces, spaces_to_end = 0;

    switch (align){
      case MBS_ALIGN_LEFT:
      default:
        left_spaces = 0;
        break;
      case MBS_ALIGN_RIGHT:
        spaces_to_end = spaces;
        break;
      case MBS_ALIGN_CENTER:
        left_spaces = spaces / 2 + spaces % 2; 
        spaces_to_end = spaces / 2; 
        break;
    }

    if ((flags & MBA_NO_RIGHT_PAD) > 0){
      spaces_to_end = 0;
    }

    if ((flags & MBA_NO_LEFT_PAD) > 0){
      left_spaces = 0;
    }

    if (dest_size > 0){
      size_t available_space;
      char *dest_end = dest + dest_size - 1;

      dest = mbs_align_pad (dest, dest_end, left_spaces);
      available_space = dest_end - dest;
      dest = mempcpy (dest, string_to_print, used_bytes < available_space ? used_bytes : available_space);
      mbs_align_pad (dest, dest_end, spaces_to_end);
    }

    /* indicate to caller how many bytes padding needed (not including NUL).  */
    ret_val = used_bytes + (left_spaces + spaces_to_end) * 1;
  }

  free (tras_str);
  free (wu_str);

  return ret_val;
}