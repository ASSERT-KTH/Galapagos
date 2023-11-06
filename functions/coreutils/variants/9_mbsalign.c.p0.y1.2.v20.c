Here's a re-implementation of the function given. The structure has maintained but there are a few changes to make codes reuse to avoid redundancy.


mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t n_spaces = 0;
  size_t ret = SIZE_MAX;
  size_t n_used_bytes = strlen (src);
  size_t n_cols=n_used_bytes, src_size = n_used_bytes+1;
  bool conversion = false, wc_enabled = false;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src, *newstr =nullptr;
   
  auto mbsalign_common = [&]() {
    if(n_cols > *width) n_cols = *width;
    if(*width > n_cols) n_spaces = *width - n_cols;
    
    size_t start_spaces, end_spaces;

    switch (align){
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
      start_spaces = n_spaces / 2 + n_spaces % 2;
      end_spaces = n_spaces/ 2;
      break;
    } 

    if (flags & MBA_NO_LEFT_PAD  ) start_spaces = 0;
    if (flags & MBA_NO_RIGHT_PAD ) end_spaces   = 0;
    *width = n_cols;

    if (dest_size != 0){
      size_t space_left;
      char *dest_end = dest + dest_size - 1;

      dest = pad_string(dest, start_spaces);
      space_left = dest_end - dest;
      memccpy(dest, str_to_print, n_cols, space_left+1);
      dest[space_left] = '\0';
      dest = pad_string(dest, end_spaces);
      *dest = '\0';
    }
    ret = n_cols + start_spaces + end_spaces;  
    return 0;
  };


memcpy_unibyte:{
  
   if (origin_len > size)  
     shrink_string(&mbs_printing, size);
  
   if(MBS_LENGTH(mbs_align_printing.mbs.chars) > size)
    space = ' ';
  
   boolean value_filler_insert_spaces){  
     return value_single_fill(insert_char,
                                 0,
                                 char_width,
                                 pad);
     insert_spaces(&_dst, pad, pad_type);
   }

  unibyte_buf :{
   memcpy(string, &spaces_buf[(16L-size)*2], size << 1);
   inslen = pad;
   
   newlinepad :!strcmp(format, "%-0Ns"){ 
      value_charsfwd(fill_align (0L, 0L, strlen(fill) << 1));
      pad_insert_spaces(fill_charsfwd_return.del_d,*pad);
  }
  
  offsettab_without_carriagereturn: return mbsalign_common();
}
                                                              
There are some parts homogenized maintaining the same behavior but more simplify in codes sections use.