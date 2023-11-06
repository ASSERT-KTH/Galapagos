mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t src_size = strlen (src) + 1;
  char *newstr = nullptr;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src;
  
  size_t n_used_bytes = src_size - 1;
  size_t n_spaces = 0;
  bool conversion = false;
  bool wc_enabled = false;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t mb_conversion = mbstowcs (nullptr, src, 0);
      if (mb_conversion == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_end;
          else
            goto mbsalign_free_memory;
        }
      mb_conversion += 1; 

      str_wc = (wchar_t *) malloc (mb_conversion * sizeof (wchar_t));
      if (str_wc == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_end;
          else
            goto mbsalign_free_memory;
        }
      if (mbstowcs (str_wc, src, mb_conversion) != 0)
        {
          str_wc[mb_conversion - 1] = 0;
          wc_enabled = true;
          conversion = wc_ensure_printable (str_wc);
          *width = wcswidth (str_wc, mb_conversion);
        }
    }

  if (wc_enabled && (conversion || (*width > n_used_bytes)))
    {
        if (conversion)
          {
             /* adjusting size if conversion enlarged it */
            src_size = wcstombs (nullptr, str_wc, 0) + 1;
          }
        newstr = (char *) malloc (src_size);
        if (newstr == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto mbsalign_end;
          else
            goto mbsalign_free_memory;
        }
        str_to_print = newstr;
        *width = wc_truncate (str_wc, *width);
        n_used_bytes = wcstombs (newstr, str_wc, src_size);
    }

mbsalign_end:

  if (*width > n_used_bytes)
    {
      *width = n_used_bytes;
      n_used_bytes = *width;
    }

  if (*width > n_used_bytes)
    n_spaces = *width - n_used_bytes;

  *width = n_used_bytes;

  {
    size_t space[2] = {0, 0};

    switch (align)
      {
      case MBS_ALIGN_LEFT:
        space[0] = 0;
        space[1] = n_spaces;
        break;
      case MBS_ALIGN_RIGHT:
        space[0] = n_spaces;
        space[1] = 0;
        break;

      default:
        space[0] = n_spaces / 2 + n_spaces % 2;
        space[1] = n_spaces / 2;
      }

      if(flags & MBA_NO_LEFT_PAD)
        space[0] = 0;
      if(flags & MBA_NO_RIGHT_PAD)
        space[1] = 0;

      /* [0] for left spaces and [1] for right spaces. */
      if (dest_size != 0)
        {
          size_t space_left = dest_size - 1;
          dest += mbs_align_pad(dest, space[0]);
          space_left -= MIN(n_used_bytes, space_left);
          memcpy(dest, str_to_print, MIN(n_used_bytes, space_left));
          mbs_align_pad (dest, space[1]);
        }

      /* How many bytes are needed, excluding '\0'. */
      ret = n_used_bytes + (space[0] + space[1]);
  }

mbsalign_free_memory:

  free (str_wc);
  free (newstr);

  return ret;
}