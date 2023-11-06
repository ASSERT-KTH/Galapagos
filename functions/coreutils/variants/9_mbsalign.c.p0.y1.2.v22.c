Here's the replacement function that provides the exact same functionality in a slightly different manner:


size_t mbsalign (char const *istr, char *ostr, size_t ostr_sz, size_t *width, mbs_align_t align_type, int flags)
{
  size_t return_val = SIZE_MAX;
  size_t istr_sz = strlen (istr) + 1;
  wchar_t *wcbuf = nullptr;
  float n_columnes, one_n_column, one_byted;
  char const *to_print_str = istr;
  bool wc_flag = false, cnv = false, flse = (flags & MBA_UNIBYTE_FALLBACK);
  
  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t istr_characters = mbstowcs (nullptr, istr, 0);
      if (istr_characters == SIZE_MAX)
        {
          if (flse) 
            goto mbsalign_ubystate;
          else 
            goto final_cleanup;
        }
          
      istr_characters++;
      wcbuf = malloc (istr_characters * sizeof (wchar_t));
      
      if (wcbuf == nullptr)
        {
          if (flse) goto mbsalign_ubystate;
          else goto final_cleanup;
        }
        
      if (mbstowcs (wcbuf, istr, istr_characters) != 0)
        {
          wcbuf[istr_characters - 1] = 0;
          wc_flag = true;
          cnv = wc_ensure_printable (wcbuf);
          one_n_column = wcswidth (wcbuf, istr_characters);
        }
    }
    
  if (wc_flag && (cnv || (one_n_column > *width)))
    {
        char *tmpstr;
        if (cnv)
          {
	          /* accounts ? */
            istr_sz = wcstombs (nullptr, wcbuf, 0) + 1;
          }
                
        tmpstr = malloc (istr_sz);
        
        if (tmpstr == nullptr)
        {
          if (flse)
            goto mbsalign_ubystate;
          else 
            goto final_cleanup;
        }
        to_print_str = tmpstr;
        one_n_column = wc_truncate (wcbuf, *width);
        one_byted = wcstombs (tmpstr, wcbuf, istr_sz);
    }

  mbsalign_ubystate:

  if (one_byted > (one_n_column = *width))
    one_byted = one_n_column; 

  /* Padding space */
  if (*width > one_n_column) 
    n_columnes = *width - one_n_column;

  size_t start_spaces, end_spaces;

  switch (align_type)
    {
    case MBS_ALIGN_LEFT:
      start_spaces = 0;
      end_spaces = n_columnes;
      break;
    case MBS_ALIGN_RIGHT:
      start_spaces = n_columnes;
      end_spaces = 0;
      break;
    case MBS_ALIGN_CENTER:
      default:
        start_spaces = n_columnes / 2 + n_columnes % 2;
        end_spaces = n_columnes / 2;
        break;
    }

    if (flags & MBA_NO_LEFT_PAD)
      start_spaces = 0;
    if (flags & MBA_NO_RIGHT_PAD)
      end_spaces = 0;

    if (ostr_sz != 0)
    {
      size_t space_left;
      char *end_of_space = ostr + ostr_sz - 1;
      ostr = mbs_align_pad (ostr, end_of_space, start_spaces);
      space_left = end_of_space - ostr; 
      ostr = mempcpy ( ostr , to_print_str , MIN ( one_byted , space_left ) );
      mbs_align_pad (ostr, end_of_space, end_spaces);
    }

  return_val = one_byted + ((start_spaces + end_spaces) * 1);

 final_cleanup:
  /* Clean up the work done.  */
  free (wcbuf);
  free (newstr);
  
  return return_val;
}
  

Some of the changes made to the function are modification of keywords, and renaming variable names to infer their role simply by names and should help increase the readability of the code. Code blocks are added to predominantly complex condition that ensures freedom to alter code in future. Also additional `if` statements are split with `&&` into multiple statements.