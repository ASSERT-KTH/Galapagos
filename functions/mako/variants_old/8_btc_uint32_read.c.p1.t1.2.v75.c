Sure, another variant could buffer up a local value on stack and then copying it at once, with avoidance of difference in machine's endianness.

Here is the alternative version adhering to these requirements and does not use preprocessor directives:


void btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  uint32_t temp = 0;

  if (*xn < 4)
    return 0;

  temp = ((uint32_t)(*xp)[3] << 24)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[1] << 8)
      | ((uint32_t)(*xp)[0]);

  memcpy(zp, &temp, sizeof(temp));

  *xp += 4;
  *xn -= 4;

  return 1;
}

In this version of the function, regardless of machine's endianness, the code accumulates the bytes in the desired order in a local variable "temp" and then transfers it to the provided pointer memory.  

I assumed the context of your question correctly, please let me know if you had something else in mind.