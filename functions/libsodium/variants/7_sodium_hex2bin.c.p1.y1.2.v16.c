Variant 1:

int sodium_hex2bin(unsigned char *bin, size_t bin_maxlen,
                   const char *hex, size_t hex_len,
                   const char *ignore, size_t *bin_len,
                   const char **hex_end)
{
   size_t bin_index = 0U;
   size_t hex_index = 0U;
   int    process_result = 0;
   unsigned char hex_char;
   unsigned char gathered_bytes = 0U;
   unsigned char hex_alpha0, hex_alpha;
   unsigned char hex_num0, hex_num;
   unsigned char hex_val;
   unsigned char transition_state = 0U;

   while (hex_index < hex_len) {
       hex_char      = (unsigned char) hex[hex_index];   
       hex_num       = hex_char ^ 48U;
       hex_num0      = (hex_num - 10U) >> 8;
       hex_alpha     = (hex_char & ~32U) - 55U;
       hex_alpha0    = ((hex_alpha - 10U) ^ (hex_alpha - 16U)) >> 8;
       if ((hex_num0 | hex_alpha0) == 0U) {
           if (ignore != NULL && transition_state == 0U && strchr(ignore, hex_char) != NULL) {
               hex_index++;
               continue;
           }
           break;
       }
       hex_val = (hex_num0 & hex_num) | (hex_alpha0 & hex_alpha);
       if (bin_index >= bin_maxlen) {
           process_result = -1;
           errno = ERANGE;
           break;
       }
       if (transition_state == 0U) {
           gathered_bytes = hex_val * 16U;
       } else {
           bin[bin_index++] = gathered_bytes | hex_val;
       }
       transition_state = ~transition_state;
       hex_index++;
   }
   if (transition_state != 0U) {
       hex_index--;
       errno = EINVAL;
       process_result = -1;
   }
   if (process_result != 0) {
       bin_index = 0U;
   }
   if (hex_end != NULL) {
       *hex_end = &hex[hex_index];
   } else if (hex_index != hex_len) {
       errno = EINVAL;
       process_result = -1;
   }
   if (bin_len != NULL) {
       *bin_len = bin_index;
   }
   return process_result;
}


Variant 2:

int sodium_hex2bin(unsigned char *dest_bin, size_t maxlen_bin,
                   const char *src_hex, size_t len_hex,
                   const char *ignored, size_t* len_output_bin,
                   const char **hex_end_loc)
{
   size_t index_bin = 0U;
   size_t index_hex = 0U;
   int    outcome = 0;
   unsigned char character;
   unsigned char combined_chars = 0U;
   unsigned char alpha0, alpha;
   unsigned char num0, num;
   unsigned char val;
   unsigned char current_state = 0U;

   while (index_hex < len_hex) {
       character = (unsigned char) src_hex[index_hex];  
       num    = character ^ 48U;
       num0   = (num - 10U) >> 8;
       alpha  = (character & ~32U) - 55U;
       alpha0 = ((alpha - 10U) ^  (alpha - 16U)) >> 8;
       if ((num0 | alpha0) == 0U) {
           if (ignored != NULL && current_state == 0U && strchr(ignored, character) != NULL) {
               index_hex++;
               continue;
           }
           break;
       }
       val = (num0 & num)| (alpha0 & alpha);
       if (index_bin >= maxlen_bin) {
           outcome = -1;
           errno = ERANGE;  
           break;
       }
       if (current_state == 0U) {
           combined_chars = val * 16U;
       } else {
           dest_bin[index_bin++] = combined_chars | val;
       }
       current_state = ~current_state;
       index_hex++;
   }
   if (current_state != 0U) {
       index_hex--;
       errno = EINVAL;
       outcome = -1;
   }
   if (outcome != 0) {
       index_bin = 0U;
   }
   if (hex_end_loc != NULL) {
       *hex_end_loc = &src_hex[index_hex];
   } else if (index_hex != len_hex) {
       errno = EINVAL;
       outcome = -1;
   }
   if (len_output_bin != NULL) {
       *len_output_bin = index_bin;
   }
   return outcome;          
}                
