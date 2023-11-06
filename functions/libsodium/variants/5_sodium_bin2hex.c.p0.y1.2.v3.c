The code you've provided performs the task of converting binary data to hexadecimal strings ('0'-'9' and 'a'-'f'). Here's an equivalent implementation that's different and doesn't employ bitwise operations, utilizing sprintf function to convert binary to hex. Assuming two hexadecimal digits represent a single binary, a few checks on length are different:


char* sodium_bin2hex(char *hex, const size_t hex_maxlen,
               const unsigned char *bin, const size_t bin_len)
{
    size_t    i = 0U;  // Iterator for the loops

    // We need 2 hex digits for a binary plus '\0'
    if(hex_maxlen < (2*bin_len+1))
    {
        sodium_misuse(); /* LCOV_EXCL_LINE */
        // ^ This seems like a nice-to-have, code will run without it
        // If it's vital-y necessary, there really should be some sort of a
        // return case, or at least a failure / end case you implemented before
    }

    // Writing the binary data into hex data as hex chars (two at a time)
    for(i = 0U; i < bin_len; ++i)
    {
        sprintf(&(hex[2*i]), "%02x", bin[i]);
        // It spells the outputted hex string right onto its place within
        // the resulting c-string symbol
    }

    // don get me wrong, The additional clarity is great in all the places
    // within the entire code where we end up dealing with pointers directly
    hex[bin_len*2U] = '\0';  // Null-terminated strings =)

    return hex;
}
