mbsalign (char const *src, char *dest, size_t dest_size, 
          size_t *width, mbs_align_t align, int flags)
{
  size_t const src_size = strlen(src) + 1;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src;
  bool conversion = false;
  char *newstr = nullptr;
  //*width and src_size guaranteed to be less than size_t limit
  //n_cols and n_used_bytes less than or equal to src_size -1, safe subtraction
  size_t n_cols = src_size - 1; 
  size_t n_used_bytes = n_cols;
  size_t ret;
  size_t n_spaces = 0;
  
  if (!((flags & MBA_UNIBYTE_ONLY) && ((MY_CUR_MAX <= 1) || (init_wc(src, src_size, str_wc, flags))))
  {
    if (set_new_str(n_cols, *width, conversion, newstr, src_size, str_wc))
    {
      //if ok up to now save str_to_print and n_cols, n_used_bytes we are plotting
    str_to_print = newstr;
    n_cols = wc_considered_bytes(str_wc, *width);
    n_used_bytes = wc_consider_str(newstr, str_wc, src_size);
    }
  went_unibyte: //Function success up to here  
    if (n_cols > *width)
    {
      reset_global_counts(n_cols, *width, &n_used_bytes);
    }
    if (n_cols < *width)
    {
      n_spaces = pad_needed(n_cols, *width);
    }
  write_data_to_dest:
    *width = n_cols;
	  
    ret = write_left_right_spaces_and_bytes(*width, dest, dest_size, &align, n_spaces, str_to_print, n_used_bytes, n_cols);
  }

 cleanup:
   free_safe_elements(str_wc,newstr);
   return ret;  
}
