
size_t modified_mbsalign (char const *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags)
{
    /* Variables Initiation */
    char const *tmp_str = src;
    size_t my_bytes = strlen (src);
    
    /* Conditions and Preparations */
    /* Depending on the flags MBA_UNIBYTE_ONLY and MB_CUR_MAX, 
        use mbs_prepar (src, flags) to get the required string and number of columns. */
    /* Now Prepare to allocate a buffer. Depending on conditions if needed. */
    /* For allocating memory, if failed, depending on the MBA_UNIBYTE_FALLBACK flag, 
        either go to mbsalign_unibyte or directly go to mbsalign_cleanup */
    /* If everything correct till now - write to dest - keep check if within limit of dest_size */
    /* Follow through till mbsalign_cleanup */

    /* Skipping the midsection padding calculations of n_spaces and n_cols   
        space calculation checks depending upon MBA_NO_LEFT_PAD & MBA_NO_RIGHT_PAD */

    if ((*width > my_bytes) && !(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1) 
        // MBS_ALIGN_LEFT, MBS_ALIGN_RIGHT, MBS_ALIGN_CENTER calculations,
        // the dest within destined size - the padding,
        // ultimately max_bytes calculation;
    else
        // unibyte set to dest calculations if needed,
        // Space_left, dest positions calculations, mbs_align_pad (dest, end_spaces)
        // maximum, minimum among needed bytes (max_bytes) setting

    /* Reaching Cleanup */
    free(newstr);
    // ...

    return ret_max;   // return
}

The extracted version:

unsigned modified_mbsalign (char const *origin, char *location, size_t loc_size, mbs_align_t al, unsigned fls) 
{
  size_t fresh_size = strlen (origin) + 1;
  size_t n_bytes = fresh_size - 1;
  size_t spaces = 0;
  bool wide_char = false;

  if (!(fls & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1) {
    
    size_t fresh_chars = mbstowcs (nullptr, origin, 0);
    
    /*....Necessary conditions on failure MBA_UNIBYTE_FALLBACK existence, conversions, truncations....*/
  }

  /*...dependings on aligned positions, padding calculations 
      depending also flags; and end places calculations...*/

  /* indicate maximum needed.  */
  ret_count = n_bytes + (start_spaces + end_spaces) * 1;

  /* Ending/Cleaning Section */
  free (str_wc);
  free (new_one);

  return ret_count;
}
