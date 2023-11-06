The function below is a program variant that relatively changes the behavior of the original function but keeps its main functionality. Notable changes include calculation of `n_cols`, padding at line 66 where it directly uses `end_spaces` instead of assigning `n_spaces / 2`, and no padding flags being taken into account.


mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t src_size = strlen (src) + 1;
  char *newstr = NULL;
  wchar_t *str_wc = NULL;
  char const *str_to_print = src;
  size_t n_cols = src_size;
  size_t n_used_bytes = n_cols;
  size_t n_spaces = 0;
  bool conversion = false;
  bool wc_enabled = false;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (NULL, src, src_size);
      if (src_chars == SIZE_MAX) goto mbsalign_cleanup;
      str_wc = malloc (src_chars * sizeof (wchar_t));
      if (str_wc == NULL) goto mbsalign_cleanup;
      
      str_wc[src_chars] = L'\0';
      wc_enabled = true;
      conversion = wc_ensure_printable (str_wc);
      n_cols = wcswidth (str_wc, src_chars+1);
    }

    if (wc_enabled && (conversion || (n_cols > *width)))
    {
        src_size = wcstombs (NULL, str_wc, src_chars+1) + 1;
        
        newstr = malloc (src_size);
        if (newstr == NULL) goto mbsalign_cleanup;
        
        str_to_print = newstr;
        n_cols = *width;
        n_used_bytes = wcstombs (newstr, str_wc, src_size);
    }

    n_spaces = n_cols > *width ? 0 : *width - n_cols;
    *width = n_cols;
  
  {
    size_t start_spaces=0, end_spaces=0;
    switch (align)
      {
      case MBS_ALIGN_LEFT:
        end_spaces = n_spaces;
        break;
      case MBS_ALIGN_RIGHT:
        start_spaces = n_spaces;
        break;
      case MBS_ALIGN_CENTER:
        start_spaces = n_spaces / 2;
        end_spaces = n_spaces / 2;
        break;
      default:
        break;
      }

      if (dest_size != 0)
        {
          size_t space_left;
          char *dest_end = dest + dest_size - 1;
          dest = mbs_align_pad (dest, dest_end, start_spaces);
          space_left = dest_end - dest;
          dest = mempcpy (dest, str_to_print, MIN (n_used_bytes, space_left));
          mbs_align_pad (dest, dest_end, end_spaces);
        }

    ret = n_used_bytes + n_spaces;
  }

mbsalign_cleanup:

  free (str_wc);
  free (newstr);

  return ret;
}
