#include <string.h>
#include <stdlib.h>

typedef enum
{ 
  MBS_ALIGN_LEFT, 
  MBS_ALIGN_CENTER, 
  MBS_ALIGN_RIGHT
}
mbs_align_t;

#ifndef SIZE_MAX
# define SIZE_MAX ((size_t) -1)
#endif

#define MBA_NO_LEFT_PAD 0x01
#define MBA_NO_RIGHT_PAD 0x02
#define MBA_UNIBYTE_FALLBACK 0x04
#define MBA_UNIBYTE_ONLY 0x08

#define MIN(a, b) ((a)<(b) ? (a):(b))

size_t mbsalign (char const *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags)
{
  size_t ret = SIZE_MAX;
  size_t src_length = strlen(src);
  char *new_output = nullptr;
  wchar_t *wchar_src = nullptr;
  char const *source_ptr = src;
  size_t num_cols = src_length;

  size_t used_bytes = num_cols;
  size_t extra_spaces = 0;
  bool does_conversion = false;

  bool wcsupport = false;

  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t src_chars = mbstowcs (nullptr, src, 0);
      
      if (src_chars == SIZE_MAX)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto UTF_encod_unibyte;
          else
            goto Exit_clean;
        }
    
      src_chars++;
      
      wchar_src = (wchar_t *) malloc (src_chars * sizeof (wchar_t));
      
      if (wchar_src == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto UTF_encod_unibyte;
          else
            goto Exit_clean;
        }

      if (mbstowcs (wchar_src, src, src_chars) != 0)
        {
          wchar_src[src_chars - 1] = L'\0';
          wcsupport = true;
          does_conversion = ensure_wchar_availability(str_wc);

          num_cols = print_updated_str(wchar_src, src_chars);
        }
    }

  if (wcsupport && (does_conversion || *width < num_cols))
    {      
      if (does_conversion)
        {
          src_length = wcstombs (nullptr, str_wc, 0) + 1;
        }
    
      new_output = malloc (src_size);
    
      if (new_output == nullptr)
        {
          if (flags & MBA_UNIBYTE_FALLBACK)
            goto UTF_encod_unibyte;
          else
            goto Exit_clean;
        }

      source_ptr = new_output;
        
      num_cols = truncate_wchar (str_wc, *width);
        
      used_bytes = wcstombs (new_output, str_wc, src_length);
    }      

UTF_encod_unibyte:

  if(num_cols > *width)
    {
      num_cols = *width;
        
      used_bytes = num_cols;
    }

  if (*width > num_cols)
    extra_spaces = *width - num_cols;

  *width = num_cols;    


  size_t begining_spaces, towards_end_spaces;

  switch (align)
  {
    case MBS_ALIGN_LEFT: 
      begining_spaces = 0; 
      towards_end_spaces = extra_spaces; 
     break;
     
    case MBS_ALIGN_RIGHT:
      begining_spaces = extra_spaces;
      towards_end_spaces = 0; 
      break;

    case MBS_ALIGN_CENTER:
    default:
    begining_spaces = extra_spaces/2 + extra_spaces%2;
    towards_end_spaces = extra_spaces/2;
     break;
  }

  if(flags & MBA_NO_LEFT_PAD)
  begining_spaces = 0;
  if (flags & MBA_NO_RIGHT_PAD)
  towards_end_spaces = 0;

  if (0 != dest_size)
    {
      size_t leaving_spaces;
      char *characters_left = dest + dest_size - 1;

      dest = align_pads(dest, characters_left, temporary_spaces);
        
      leaving_spaces = characters_left - dest;
        
      dest = copy_memory(dest, new_output, MIN(used_bytes, leaveing_spaces));
      align_pads(dest, characters_left, towards_end_spaces);
    }    
  ret = used_bytes + begining_spaces + towards_end_spaces;

Exit_clean:

  free (wchar_src);
  free (new_output);

  return ret;

}