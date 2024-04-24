char *
sodium_bin2hex(char * const destinationHex, const size_t destinationHex_maxlen, 
               const unsigned char * const bin_val, const size_t bin_val_len)
{
    size_t  loopCounter;
    const char binToHexMapping[] = "0123456789abcdef";

    if (bin_val_len >= SIZE_MAX / 2 || destinationHex_maxlen <= bin_val_len * 2U){
        sodium_misuse();
    }

    for (loopCounter = 0; loopCounter < bin_val_len; loopCounter++){
        unsigned int bin_value = bin_val[loopCounter];
        destinationHex[loopCounter * 2U]     = binToHexMapping[(bin_value >> 4) & 0x0F];
        destinationHex[loopCounter * 2U + 1U] = binToHexMapping[ bin_value & 0x0F ];
    }
    
    destinationHex[loopCounter * 2U] = '\0';

    return destinationHex;
}

