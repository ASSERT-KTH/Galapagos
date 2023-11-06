Variant 1: 
Apply transformation through renaming the variables of the given function differently yet still make it readable and understandable.


mbsalign (char const *primary, char *target, size_t target_size,
          size_t *size, mbs_align_t align_style, int flag)
{
  size_t result = SIZE_MAX;
  size_t primary_size = strlen (primary) + 1;
  char *modified_string = nullptr;
  wchar_t *wcharacter_string = nullptr;
  char const *str_print = primary;
  size_t str_cols = primary_size - 1;
  size_t bytes_used = str_cols;
  size_t spacing_count = 0;
  bool converted = false;
  bool wc_successful= false;

  if (!(flag & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t source_char = mbstowcs (nullptr, primary, 0);
      if (source_char == SIZE_MAX)
        {
          if(flag & MBA_UNIBYTE_FALLBACK)
            goto align_unibyte;
          else
            goto align_cleanup;
        }
      source_char += 1;
      wcharacter_string = malloc (source_char * sizeof (wchar_t));
      if (wcharacter_string == nullptr)
        {
          if(flag & MBA_UNIBYTE_FALLBACK)
            goto align_unibyte;
          else
            goto align_cleanup;
        }
      if (mbstowcs (wcharacter_string, primary, source_char) != 0)
        {
          wcharacter_string[source_char - 1] = L'\0';
          wc_successful= true;
          converted = wc_ensure_printable (wcharacter_string);
          str_cols = wcswidth (wcharacter_string, source_char);
        }
    }
  if (wc_successful && (converted || (str_cols > *size)))
  {
      if (converted)
            primary_size = wcstombs (nullptr, wcharacter_string, 0) + 1;
      modified_string = malloc (primary_size);
      if (modified_string == nullptr)
      {
          if(flag & MBA_UNIBYTE_FALLBACK)
            goto align_unibyte;
          else
            goto align_cleanup;
        }
      str_print = modified_string;
      str_cols = wc_truncate (wcharacter_string, *size);
      bytes_used = wcstombs (modified_string, wcharacter_string, primary_size);
  }

align_unibyte:

  if (str_cols > *size)
    {
      str_cols = *size;
      bytes_used = str_cols;
    }
  if (*size > str_cols)
    spacing_count = *size - str_cols;
  *size = str_cols;

  {
    size_t start_positions, end_positions;
    switch(align_style)
     {
      case MBS_ALIGN_LEFT: 
        start_positions = 0;
        end_positions = spacing_count;
        break;
      case MBS_ALIGN_RIGHT:
        start_positions = spacing_count;
        end_positions = 0;
        break;
      case MBS_ALIGN_CENTER:
      default:
        start_positions = spacing_count / 2 + spacing_count % 2;
        end_positions = spacing_count / 2;
        break;
     }
     
     if (flag & MBA_NO_LEFT_PAD) 
        start_positions = 0;
     if (flag & MBA_NO_RIGHT_PAD)
        end_positions = 0;

    if (target_size != 0)
      {
        size_t left_space;
        char *end_target = target + target_size - 1;
        target = mbs_align_pad (target, end_target, start_positions);
        left_space = end_target - target;
        target = mempcpy (target, str_print, MIN (bytes_used, left_space));
        mbs_align_pad (target, end_target, end_positions);
      }

    result = bytes_used + ((start_positions + end_positions) * 1);
  }

align_cleanup:

  free (wcharacter_string);
  free (modified_string);

  return result;
 }


Variant 2: 
Apply the transformation by reordering the block implementations, and the logic will stay the same because the control flow is not affected by this transformation.


mbsalign (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  char *newstr = nullptr;
  wchar_t *str_wc = nullptr;
  char const *str_to_print = src;
  bool conversion = false;
  bool wc_enabled = false;
  size_t src_size = strlen (src) + 1;
  size_t n_cols = src_size - 1;
  size_t n_spaces = 0;
  size_t n_used_bytes = n_cols; //code reorder starts from hcere
 

                   
mbsalign_unibyte:

  if (n_cols > *width) //More code reodering from this line
    n_cols = *width; 
    n_used_bytes = n_cols;
   

  if (*width > n_cols)
    
    if(!(flags & MBA_UNIBYTE_ONLY)&&MB_CUR_MAX >1 )
      {
        size_t src_chars = mbstowcs (nullptr, src, 0);
       
        if (src_chars==SIZE_MAX)
          if (flags & MBA_UNIBYTE_FALLBACK)
            {
            goto mbsalign_unibyte;
            }
            else
            {
              goto mbsalign_cleanup;
            }
            
        src_chars += 1; //For the NUL   
    
    if(tb_response_size = wcstombs(nullptr, str_wc, 0) +1;)
    
        str_wc = malloc ( src_chars*sizeof(wchar_t));

      size_t start_spaces, end_spaces;
      n_spaces = *width  -n_cols;
   

	//PAD BLOCK wrap up the block
        //align block - more reorder
   
  *width = n_cols;
  
  free(str_wc)
  free(str_wc)
  
  return ret;
}

  
