The code provided is quite complex and already would seem to cover its concerns rather well--it's not immediately apparent that a fundamentally different yet equivalent approach is available. However, edits could be implemented including variable renaming for a clearer structure and reducing branching scenarios based on the indent style, but the original features of the handling multi-byte and uni-byte strings would be maintained.

Here is a modified version:


mbsalign (char const *in, char *out, size_t out_size,
          size_t *width_ref, mbs_align_t align_type, int param)
{
  size_t return_val = SIZE_MAX;
  size_t in_size = strlen (in) + 1;
  char *altered_str = nullptr;
  wchar_t *wc_str = nullptr;
  char const *string_to_process = in;
  size_t num_columns = in_size - 1;
  size_t used_bytes = num_columns; /* not considering null terminator */
  size_t num_spaces = 0;
  bool unicode_used = false;
  bool multi_byte_to_wc_successful = false;

  if (!(param & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t in_wchars = mbstowcs (nullptr, in, 0);
      if (in_wchars  == SIZE_MAX)
       goto to_fallback_or_cleanup_based_on_param;
      in_wchars++;
      wc_str = malloc (in_wchars * sizeof (wchar_t));
      if (wc_str == nullptr)
        goto to_fallback_or_cleanup_based_on_param;
      if (mbstowcs (wc_str, in, in_wchars ) == in_wchars - 1)
        {
          wc_str[in_wchars - 1] = L'\0';
          multi_byte_to_wc_successful = true;
          unicode_used = wc_ensure_printable (wc_str);
          num_columns = wcswidth (wc_str, in_wchars);
        }
    }

  if (multi_byte_to_wc_successful && (unicode_used || (num_columns > *width_ref)))
    {
       to_unibyte_block: /* added for better code flow */
        if (unicode_used)
           in_size = wcstombs (nullptr, wc_str, 0) + 1;
        altered_str = malloc (in_size);
        if (altered_str == nullptr)
            goto to_fallback_or_cleanup_based_on_param;
        string_to_process = altered_str;
        num_columns = wc_truncate (wc_str, *width_ref);
        used_bytes = wcstombs (altered_str, wc_str, in_size);
    }

  if (num_columns > *width_ref)
    {
      num_columns = *width_ref;
      used_bytes = num_columns;
    }

  num_spaces = (num_columns> *width_ref)?0:(*width_ref-num_columns);
  *width_ref = num_columns;
  size_t leading_spaces, trailing_spaces;
         
  if(param & MBA_NO_LEFT_PAD) leading_spaces=trailing_spaces=(param & MBA_NO_RIGHT_PAD)?0:(num_spaces/2 + (align_type == MBS_ALIGN_CENTER && num_spaces%2));
  else{
      leading_spaces=(align_type!=MBS_ALIGN_LEFT)?(align_type==MBS_ALIGN_RIGHT)?num_spaces:(num_spaces/2):0;
      trailing_spaces=(align_type == MBS_ALIGN_CENTER)?num_spaces/2:num_spaces-leading_spaces;
  }

  if (out_size)
    {
        char *end = out+out_size-1;
        out=mbs_align_pad(out, end, leading_spaces);
        out=mempcpy(out,string_to_process,MIN(used_bytes,end-out));
        mbs_align_pad(out, end, trailing_spaces);
    }

  return_val=used_bytes+(leading_spaces + trailing_spaces );
  if(wc_str!=nullptr) free(wc_str);
  if(altered_str!=nullptr) free (altered_str);

  return return_val;


to_fallback_or_cleanup_based_on_param:
  if(wc_str!=nullptr) { free(wc_str); wc_str=nullptr;} 
  if(param & MBA_UNIBYTE_FALLBACK)
    goto to_unibyte_block;
  else{
      if(altered_str!=nullptr) free (altered_str);
      return return_val;
  }
}
