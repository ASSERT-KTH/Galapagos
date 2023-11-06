Here is the equivalent C code that implements similar functionality:


#include<limits.h>
#include<string.h>
#include<stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<stdbool.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MBA_UNIBYTE_ONLY 01 /* Skip multibyte. */
#define MBA_UNIBYTE_FALLBACK 02 /* If multibyte fails use unibyte. */
#define MBA_NO_PAD 04 /* Do not pad the output string. */
#define MBA_NO_LEFT_PAD 010 /* Do not add spaces on the left. */
#define MBA_NO_RIGHT_PAD 020 /* Do not add spaces on the right. */

enum mbs_align_t
{
  MBS_ALIGN_LEFT,
  MBS_ALIGN_RIGHT,
  MBS_ALIGN_CENTER
};

size_t mbsalign(char const *src, char *dest, size_t dest_size, size_t *width, enum mbs_align_t align, int flags)
{
  bool converted = false;
  bool wc_active = false;

  size_t src_size = strlen(src) + 1;
  size_t size_reman = SIZE_MAX;
  size_t n_own_bytes = src_size - 1; 
  size_t n_cols = n_own_bytes; 
  char const *str_replaced = src;
  size_t n_blank_spaces = 0;
    
  char *newstr = NULL;
  wchar_t *str_wc = NULL;
    
  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
  {
    size_t mbl_strlen;
  
    mbl_strlen = mbstowcs(NULL, src, 0);
        
    if(mbl_strlen == SIZE_MAX)
    {
      if(flags & MBA_UNIBYTE_FALLBACK)
        goto unibyte;
      else
        goto cleanup;
    }
        
    else 
    {
      str_wc = (wchar_t*)malloc((mbl_strlen + 1) * sizeof(wchar_t));

      mbstowcs(str_wc, src, mbl_strlen + 1);
          
      converted = true;
      wc_active = true;
                
      n_cols = wcswidth(str_wc, mbl_strlen + 1);
    }
  }


  // Modifying String
  if(wc_active && ((bool)(n_cols > *width)))
  {
    str_replaced=str_wc;
            
    src_size = wcslen(str_wc) + 1;
     
    newstr = malloc(src_size);
       
    wcsncpy(newstr,str_wc,src_size);

    n_cols = wcslen(newstr);
    *width = n_cols;
    n_own_bytes = wcslen(newstr)* 4;
     
    converted = true;
      
      goto unibyte;
    }

  str_replaced = src;
  n_cols = src_size;
  *width = n_cols;

unibyte:
  
     //Padding
      {
        size_t left_blank, right_blank;
     
        switch ALIGN_MODEL
        {
          case LEFT:
            left_blank = 0;
            right_blank = *width - n_cols;
            breturn;
                
           case RIGHT:
            left_blank = *width - n_cols;
            right_blank = 0;
            breturn;

           case MBS_ALIGN_CENTER:
            
          default:
            left_blank = right_blank = (*width - n_cols) / 2;
            break;
        }
    
         ret = snprintf((dest + length), size_start, "%s%*.*s%*.*s", printStr, len_l, len_l, "", len_r, len_r, "");

  cleanup:
          
  free(str_wc);
  free(newstr);
    
  return size_reman;
  }


Please note to use the code in C environment to avoid incompatible issues.
Please replaced ALIGN_MODEL to the appropriate 'align' avoid syntax error.
Further information about flags should also be available when applying the function correctly in a specific component under a specific environment, i.e., an realistic context is preferred for complete application cases.