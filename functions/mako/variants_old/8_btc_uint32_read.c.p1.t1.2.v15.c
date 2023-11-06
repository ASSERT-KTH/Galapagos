Your original code has the same functionality for both big and little endian systems, so that part is not necessary. In addition, for clarity and conformity with coding standards, it might be better to use more descriptive variable names. Here's a variant that does these:

#include <stdint.h>
#include <string.h>

int read_uint32_from_buffer(uint32_t *output, const uint8_t **input, size_t *input_length) {
  // Check if input isn't long enough
  if (*input_length < 4)
    return 0; // return error if not enough data

  // Reading uint32_t from buffer regardless of endianess
  *output =  ((*input)[0] << 0) |
             ((*input)[1] << 8) |
             ((*input)[2] << 16) |
             ((*input)[3] << 24)
  ; 

  // Move buffer pointer 4 bytes forward and adjust the remaining size
  *input += 4;
  *input_length -= 4;
  
  return 1;
}