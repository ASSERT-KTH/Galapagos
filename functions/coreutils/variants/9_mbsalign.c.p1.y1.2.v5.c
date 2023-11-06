1. Reverse the checks for wide character support and unibyte-only flag:


mbsalign (char const *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags)
{
  // Definitions...)

  if (flags & MBA_UNIBYTE_ONLY || !(MB_CUR_MAX > 1))
    goto mbsalign_unibyte;

  // 'Multi-byte' operations...

mbsalign_unibyte:

  // 'Unibyte' operations...

mbsalign_cleanup:

  // Cleanup operations...

  return ret;
}


2. Introduce reverse string chopping parts result in converting wide characters:


mbsalign (char const *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags)
{
  // Definitions...)

  /* 'Direct' variant of unibyte checkation. */
  if (flags & MBA_UNIBYTE_ONLY | !(MB_CUR_MAX > 1))
    goto mbsalign_unibyte_direct;

  // 'Multi-byte' operations...

mbsalign_unibyte_direct:

  if (*width < src_size)
    str_to_print = strncpy(dest, src, *width);

  // Padding calculations...

  // 'Truncate and Display' operations with nused_bytes...
  
mbsalign_cleanup:

  // Cleanup operations...

  return ret;
}


3. Swapping the order of conditionals in padding calculations:


mbsalign (char const *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags)
{
  // Definitions...)

  // Multibyte conversion...

  // 'Multi-byte' swappping...

  // Unibyte truncation...

  // Padding checking...

  switch (align)
  {
  case MBS_ALIGN_RIGHT:
    start_spaces = n_spaces;
    end_spaces = 0;
    break;
  case MBS_ALIGN_LEFT:
    start_spaces = 0;
    end_spaces = n_spaces;
    break;
  case MBS_ALIGN_CENTER:
    default:
    start_spaces = n_spaces / 2 + n_spaces % 2;
    end_spaces = n_spaces / 2;
    break;

  }

  // Rest of the function...
}


4. Merge two `if` checks into a single condition


mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  // Definitions...

  if(
      (flags & MBA_UNIBYTE_ONLY) || 
     (!(MB_CUR_MAX > 1) || mbstowcs (nullptr, src, 0) == SIZE_MAX)
   )
  {
    goto mbsalign_cleanup;
  }

  // Rest of the function body...
}
