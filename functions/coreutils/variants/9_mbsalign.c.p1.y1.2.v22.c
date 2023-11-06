1. Renaming variables and some changes:


mbsalign (char const *inp, char *out, size_t out_length,
          size_t *horizontal, mbs_align_t layout, int indicators)
{
    size_t outcome = SIZE_MAX;
    size_t inp_length = strlen (inp) + 1;
    char *altered = nullptr;
    wchar_t *wc_inp = nullptr;
    char const *inp_to_print = inp;
    size_t cols_total = inp_length - 1;
    size_t use_length = cols_total; 
    size_t padding = 0;
    bool did_conversion = false;
    bool wc_option = false;

    if (!(indicators & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (nullptr, inp, 0);
      if (src_chars == SIZE_MAX)
      {
        if (indicators & MBA_UNIBYTE_FALLBACK) 
          goto unibyte_transform;
        else
          goto cleanup_section;
      }
      src_chars += 1; 
      wc_inp = malloc (src_chars * sizeof (wchar_t));
      if(wc_inp == nullptr)
      {
        if(indicators & MBA_UNIBYTE_FALLBACK) 
           goto unibyte_transform;
        else
           goto cleanup_section;
      }      
      if (mbstowcs (wc_inp, inp, src_chars) != 0)
      {
        wc_inp[src_chars - 1] = L'\0';
        wc_option = true;
        did_conversion = wc_ensure_printable (wc_inp);
        cols_total = wcswidth (wc_inp, src_chars);
      }
    }

    if (wc_option && (did_conversion || (cols_total > *horizontal)))
    {
        if (did_conversion)
            inp_length = wcstombs (nullptr, wc_inp, 0) + 1;
        altered = malloc (inp_length);
        if(altered == nullptr)
        { 
          if(indicators & MBA_UNIBYTE_FALLBACK)
             goto unibyte_transform;
          else
             goto cleanup_section;
        }
        inp_to_print = altered;
        cols_total = wc_truncate (wc_inp, *horizontal);
        use_length = wcstombs (altered, wc_inp, inp_length);
    }
unibyte_transform:
  
     if (cols_total > *horizontal)
     {
         cols_total = *horizontal;
         use_length = cols_total;
     }  

    if (*horizontal > cols_total)
         padding = *horizontal - cols_total; 

    *horizontal = cols_total;  

      {
        size_t padding_start, padding_end;

        switch (layout)
        {
          case MBS_ALIGN_LEFT:
               padding_start = 0;
               padding_end = padding;
               break;
          case MBS_ALIGN_RIGHT:
               padding_start = padding;
               padding_end = 0;
               break;
          case MBS_ALIGN_CENTER:
          default:
               padding_start = padding / 2 + padding % 2;
               padding_end = padding / 2;
               break; 
        } 

       if (indicators & MBA_NO_LEFT_PAD) 
            padding_start = 0;  
       if (indicators & MBA_NO_RIGHT_PAD) 
            padding_end = 0;

      if (out_length != 0)
        {
          size_t space_remaining;
          char *out_top = out + out_length - 1;
          out = mbs_align_pad (out, out_top, padding_start);
          space_remaining = out_top - out;
          out = mempcpy (out, inp_to_print, MIN (use_length, space_remaining));
          mbs_align_pad (out, out_top, padding_end);
        }

        outcome = use_length + ((padding_start + padding_end) * 1);
     }

cleanup_section:
     free (wc_inp);
     free (altered);
     return outcome;
}


2. Rearranging the statements:


mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
    size_t ret = SIZE_MAX;
    bool wc_enabled = false;
    bool conversion = false;
    size_t src_size = strlen (src) + 1;
    size_t n_used_bytes = src_size - 1;
    size_t n_cols = n_used_bytes;
    size_t n_spaces = 0;
    
    char const *str_to_print = src;
    wchar_t *str_wc = nullptr;
    char *newstr = nullptr;
...
...


These transformation produced variants does not change the functionality and semantics of original one. Thay all work in exactly the same way as original one do under identical conditions and inputs. Anything modified in them is purely on the surface. I.e the changes being made are essentially 'orthogonal' to how the function's code works.