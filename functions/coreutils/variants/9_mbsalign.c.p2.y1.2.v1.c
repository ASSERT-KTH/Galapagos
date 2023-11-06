mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
   /* Initial values */
   size_t ret = SIZE_MAX;
   size_t src_size = strlen (src) + 1;
   char *newstr = nullptr;
   wchar_t *str_wc = nullptr;
   char const *str_to_print = src;
   size_t n_used_bytes = src_size - 1;
   size_t n_cols = src_size - 1;
   size_t n_spaces = 0;
   bool conversion = false;
   bool wc_enabled = false;

   /* Check flag condition. If it returns true proceed with conversion */
   if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
   {
      size_t src_chars = mbstowcs (nullptr, src, 0);
      if (src_chars != SIZE_MAX)
      {
        str_wc = malloc ((src_chars + 1) * sizeof(wchar_t));
        if (str_wc)
        {
          str_wc[++src_chars - 1] = L'\0';
          wc_enabled = mbstowcs (str_wc, src, src_chars) ? true : false;
          if (wc_enabled) 
          {
            conversion = wc_ensure_printable (str_wc);
            n_cols = wcswidth (str_wc, src_chars); 
          }
        }
      }
   }

   if (wc_enabled && (conversion || (n_cols > *width))) 
   {
     src_size = conversion ? wcsrtombs (nullptr, &str_wc, 0) + 1 : src_size;
     newstr = malloc (src_size);
     if (newstr) 
     {
        str_to_print = newstr;
        n_cols = wc_truncate (str_wc, *width);
        n_used_bytes = wcsrtombs(newstr, &str_wc, src_size);
     }
     else if (!(flags & MBA_UNIBYTE_FALLBACK))
        goto mbsalign_cleanup; 
   }

   n_spaces = *width > n_cols ? *width - n_cols : n_spaces;
   *width = n_cols;
   size_t start_spaces = 0, end_spaces = 0;
   if (align == MBS_ALIGN_RIGHT) 
     end_spaces = start_spaces = n_spaces;
   else if (align == MBS_ALIGN_LEFT)
     end_spaces = n_spaces;
   else 
     { start_spaces = n_spaces / 2 + n_spaces %2; end_spaces=n_spaces/2; }

   if (flags & MBA_NO_LEFT_PAD)
     start_spaces = 0;  
   if (flags & MBA_NO_RIGHT_PAD)
     end_spaces = 0;

   /* Write as much NULL terminated output as DEST as possible */
   if (dest_size) 
   {
        size_t space_left;
        char *dest_end = dest + dest_size - 1;

        dest = mbs_align_pad (dest, dest_end, start_spaces);
        space_left = dest_end - dest;
        dest = mempcpy (dest, str_to_print, n_used_bytes < space_left ? n_used_bytes : space_left);
        mbs_align_pad (dest, dest_end, end_spaces);
   }
   ret = n_used_bytes + (start_spaces + end_spaces);

mbsalign_cleanup:
  free (str_wc);
  free (newstr);

  return ret;
}