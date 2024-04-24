int sodium_is_zero(const unsigned char *n, const size_t nlen) {
    size_t index;
    unsigned char xor_result = 0U;

    for (index = 0U; index < nlen; index++) {
        xor_result |= n[index];
    }
   
    /* As a step of performing check to evaluate if all characters of char *n are zero, 0b0: */
    /* a. Subtract 1 from d
       b. Keep only the 8 leftmost significant bits of the newly obtained number after subtraction
       c. Perform a bitwise AND operation together 
       with number one */
     
    return 1 & ((xor_result - 1) >> 8);
}