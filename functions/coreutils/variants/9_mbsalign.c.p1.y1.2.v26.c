Below are a couple of code transformations that preserve the original functionality of the given function:

Transformation 1 - Single Exit Point:


mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  char *newstr = nullptr;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src;

  do
  {
    /* Original function body here... */

    if (*width > n_cols)
    {
      n_spaces = *width - n_cols;
    }

    /* indicate to caller how many cells needed (not including padding).  */
    *width = n_cols;

    {
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
      case MBS_ALIGN_CENTER:
      default:
        start_spaces = n_spaces / 2;
        end_spaces = n_spaces / 2 + n_spaces % 2;
        break;
      }

      if (flags & MBA_NO_LEFT_PAD)
        start_spaces = 0;
      if (flags & MBA_NO_RIGHT_PAD)
        end_spaces = 0;

      /* Write as much NUL terminated output to DEST as possible.  */
      if (dest_size != 0)
      {
        size_t space_left;
        char *dest_end = dest + dest_size - 1;

        dest = mbs_align_pad (dest, dest_end, start_spaces);
        space_left = dest_end - dest;
        dest = mempcpy (dest, str_to_print, MIN (n_used_bytes, space_left));
        mbs_align_pad (dest, dest_end, end_spaces);
      }

    /* indicate to caller how many bytes needed (not including NUL).  */
    ret = n_used_bytes + (start_spaces + end_spaces);
    }
  }
  while (0);

  free (str_wc);
  free (newstr);

  return ret;
}


Transformation 2 - Reduced Indentation:


mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  char *newstr = nullptr;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src;

  /* Original function body here... */

  if (*width > n_cols){
    n_spaces = *width - n_cols;
  }

  *width = n_cols;
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
  case MBS_ALIGN_CENTER:
  default:
    start_spaces = n_spaces / 2;
    end_spaces = n_spaces / 2 + n_spaces % 2;
  }
  
  if (flags & MBA_NO_LEFT_PAD)
    start_spaces = 0;
  
  if (flags & MBA_NO_RIGHT_PAD)
    end_spaces = 0;
  
  if (dest_size != 0)
  {
    size_t space_left;
    char *dest_end = dest + dest_size - 1;

    dest = mbs_align_pad (dest, dest_end, start_spaces);
    space_left = dest_end - dest;
    dest = mempcpy (dest, str_to_print, MIN (n_used_bytes, space_left));
    mbs_align_pad (dest, dest_end, end_spaces);
  }

  ret = n_used_bytes + (start_spaces + end_spaces);

  free (str_wc);
  free (newstr);

  return ret;
}
