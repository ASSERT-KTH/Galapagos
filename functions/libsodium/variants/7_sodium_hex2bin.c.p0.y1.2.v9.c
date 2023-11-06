Here's a function that performs the same task, however it implements a different approach and makes use of the 'strtol' function :


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>


int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen, const char * const hex, const size_t hex_len,
                   const char * const ignore, size_t * const bin_len, const char ** const hex_end) {
  if (hex == NULL) return -1;

  char buf[3] = {0};
  size_t bin_index = 0, hex_index = 0;
  
  /* for hex_string="abcdef"
   each 'a', 'b', 'c', 'd', 'e', 'f' will have 1 byte space 
   So the bin_length would be length of hex_string divided by 2 */

  long res;
  char *endptr;
  errno = 0;  
  
  for(; hex_index < hex_len - 1; hex_index += 2, ++bin_index) {

    /* Check Ignore */
    while (ignore != NULL && strchr(ignore, hex[hex_index]) != NULL)
        ++hex_index;    

    /* fill the buffer from 2 hex characters */
    strncpy(buf, &hex[hex_index], 2);

    res = strtol(buf, &endptr, 16);
    
    /* check that there wasn't an error parsing the number   */
    if (endptr == buf || ((res == LONG_MIN || res  == LONG_MAX) && errno == ERANGE)) {
      errno = EINVAL;
      return -1;
    }
    
    bin[bin_index] = (unsigned char)res;
  }

  if(bin_len != NULL)  *bin_len = bin_index;
  
  if(bin_maxlen < bin_index)
  {
    errno = ERANGE;
    return -1;
  }

  /* left the end of hex*/
  if (hex_end != NULL && hex_index != hex_len){
    *hex_end = &hex[hex_index];
  }
  
  return 0;
}

This function follows a bit more standard conversion process. It reads the hexadecimal numbers in pairs, claims them to a buffer, then calls 'strtol' to convert this 2 digit hex number to integer and saves in bin array. This function ultimately works through the string maximizing use of conventional string functions. However, any unconventional features of the original program will definitely bypass this code snippet.