Sure, the functionality can also be achieved by the following function variant. I have rearranged the code, used ternary operators and anonymous namespace instead of static inline: the functionality is unaffected.

namespace {

unsigned int get_bits1(GetBitContext *s) {

  unsigned int index = s->index; // save original s->index
  uint8_t result = s->buffer[index >> 3]; // get target byte from buffer

#ifdef BITSTREAM_READER_LE
   
  result = (result >> (index & 7)) & 1; //extract bit

#else
   
  result = (result << (index & 7)) >> (8 - 1); //shake bits until return value is 1

#endif

   
#if !UNCHECKED_BITSTREAM_READER
   
  // this prevents reading beyond the requested bitstream
  index = (s->index < s->size_in_bits_plus8) ? index+1 : index;

#else
   
  index++; 

#endif

  s->index = index; //update index

  return result;
}

} //anonymous namespace