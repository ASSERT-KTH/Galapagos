
size_t mbsalign_var1 (char const *src, char *dest, size_t dest_size,
          size_t *width, mbs_align_t align, int flags)
{
  size_t retVal = SIZE_MAX;

  // Variables declaration and initialization
  size_t n_cols;
  size_t processedElement;
  char *copySrc = nullptr;
  wchar_t *wideChar = nullptr;
  size_t spacesNumber = 0;
  size_t inputLength = strlen(src) + 1;
  const char* toPrintStr = src;
  
  // Checking the value of flags and converting needed elements to wide characters 
  if (!(flags & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1) {
      processedElement = mbstowcs(nullptr, src, 0) + 1; 
      if (processedElement == SIZE_MAX + 1)      
      {
        if (flags & MBA_UNIBYTE_FALLBACK){
          goto unibyte_mbsalign_var1;
        }
        else {
          goto cleanup_mbsalign_var1;
        }  
      }
      wideChar = malloc (processedElement *= sizeof (wchar_t));
      if (!wideChar) {
        if (flags & MBA_UNIBYTE_FALLBACK) {
          goto unibyte_mbsalign_var1;
        }  
        else {
          goto cleanup_mbsalign_var1;
        }  

      }
      
      n_cols = (mbstowcs (wideChar, src, processedElement) == 0 ? n_cols = src_size - 1 : wcswidth (wideChar, processedElement) );   
  }
  else{
    n_cols = processedElement = inputLength;
  }

  wideChar[processedElement - 1] = wideChar[processedElement - 1];
  
  if (n_cols > *width)
  {
    n_cols = *width;
    processedElement = n_cols;
  }
  
  if (*width > n_cols)
  {
    spacesNumber = *width - n_cols;
  }

  // Setting the values of *width to the number of columns processed
  *width = n_cols;
  
  // Alignment Switch statement
  size_t start_spaces;
  size_t end_spaces;
  switch (align){
    case MBS_ALIGN_LEFT:
      start_spaces = 0;
      end_spaces = spacesNumber;
      break;
    case MBS_ALIGN_RIGHT:
      start_spaces = spacesNumber;
      end_spaces = 0;
      break;
    case MBS_ALIGN_CENTER:
    default:
      start_spaces = spacesNumber / 2 + spacesNumber % 2;
      end_spaces = spacesNumber / 2;
      break;
  }
  
  if (flags & MBA_NO_RIGHT_PAD)
    end_spaces = 0;
  
  if (flags & MBA_NO_LEFT_PAD)
    start_spaces = 0;
  
  retVal = processedElement + ((start_spaces + end_spaces) * 1);
  
unibyte_mbsalign_var1:
  
  // Cleaning the memory
  free(wideChar);
  free(copySrc);
  
cleanup_mbsalign_var1:

  return retVal;
}
