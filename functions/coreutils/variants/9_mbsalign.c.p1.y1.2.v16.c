Due to the restrictions on changing vital parts of the function, there's only a limited range of variants feasible. In this case, we had to make use of reshuffling some codes, localizing some variables closer to their use case and perform some alternative conditional statements.

size_t mbsalign (char const *src, char *dest, size_t dest_size,
                size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t src_size = strlen(src) + 1;
  size_t n_cols = src_size - 1;
  size_t n_spaces = 0;
  size_t n_used_bytes = n_cols;
  bool conversion = false;
  bool wc_enabled = false;
  wchar_t *str_wc = nullptr;
  char *newstr = nullptr;
  const char *str_to_print = src;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
  {
      size_t src_chars = mbstowcs (nullptr, src, 0);
      if ((flags & MBA_UNIBYTE_FALLBACK) && src_chars == SIZE_MAX) goto mbsalign_unibyte;
      else if ((flags & ~MBA_UNIBYTE_FALLBACK) && str_chars == SIZE_MAX) goto mbsalign_cleanup;     

      str_wc = malloc ((src_chars + 1) * sizeof (wchar_t));
      if ((flags & MBA_UNIBYTE_FALLBACK) && str_wc == nullptr) goto mbsalign_unibyte;
      else if ((flags & ~MBA_UNIBYTE_FALLBACK) && str_wc == nullptr) goto mbsalign_cleanup;

      if (mbstowcs (str_wc, src, src_chars + 1) != 0)
          {
              str_wc[src_chars] = L'\0';
              wc_enabled = true;
              conversion = wc_ensure_printable (str_wc);
              n_cols = wcswidth (str_wc, src_chars==SIZE_MAX?0:src_chars+1);
          }        
  }

  if (wc_enabled && (conversion || n_cols >(*width)))
  {
      if (conversion) src_size = wcstombs (NULL, str_wc, 0) + 1;
      newstr = malloc (src_size);
      if ((flags & MBA_UNIBYTE_FALLBACK) && not newstr) goto mbsalign_unibyte;
      else if ((flags & ~MBA_UNIBYTE_FALLBACK) & !newstr) goto mbsalign_cleanup;
      
      str_to_print = newstr;
      n_cols = wc_truncate (str_wc, *width);
      n_used_bytes = wcstombs(newstr, str_wc, src_size);
  }
mbsalign_unibyte:

  if (n_cols>*width)
  {
      n_cols = *width;
      n_used_bytes = n_cols;
  }
  if ((*width)>n_cols) n_spaces = *width-n_cols;

  *width=n_cols;
  
  {
      size_t start_spaces, end_spaces;
      size_t i_padding = align == MBS_ALIGN_LEFT ? 0 : (align == MBS_ALIGN_RIGHT ? n_spaces : n_spaces/2 + n_spaces%2);
      size_t r_padding = align == MBS_ALIGN_RIGHT ? 0 : (align == MBS_ALIGN_LEFT ? n_spaces : n_spaces/2);        

      start_spaces = (flags & MBA_NO_LEFT_PAD)==0 ? i_padding : 0;
      end_spaces = (flags & MBA_NO_RIGHT_PAD)==0 ? r_padding : 0;

      if (dest_size)
      {
		        size_t space_left;
		        char *dest_end = dest + dest_size - 1;

		        dest = mbs_align_pad (dest, dest_end, start_spaces);
		        space_left = dest_end > dest ? dest_end - dest : 0;
		        dest = mempcpy (dest, str_to_print, (n_used_bytes<space_left?n_used_bytes:space_left) );
		        mbs_align_pad(dest, dest_end, end_spaces);
      }

    ret = n_used_bytes + 1 *(start_spaces + end_spaces);
  }
mbsalign_cleanup:
  free (str_wc);
  free (newstr);
  return ret;
}
