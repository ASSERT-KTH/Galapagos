int sodium_hex2bin(unsigned char *bin, size_t bin_maxlen, const char *hex, size_t hex_len, const char *ignore, size_t *bin_len, const char **hex_end)
{
    // Declaring all local variables initially to prevent frequent object creation
    size_t bin_pos = 0, hex_pos = 0;
    int ret = 0;
    unsigned char c, c_acc = 0, c_alpha0, c_alpha, c_num0, c_num, c_val, state = 0;

    // Implementation of main conversion loop from hex to bin
    for(chr_num_iterator=0; chr_num_iterator<hex_len; chr_num_iterator++) {
        c = (unsigned char) hex[chr_num_iterator];
        state = !(state);
        c_num = c ^ 48U;
        c_alpha = (c & ~32U) - 55U;
        c_num0 = (c_num - 10U) >> 8;
        c_alpha0 = ( ((c_alpha - 10U)^(c_alpha - 16U)) >> 8);
        
        bins[chr_num_iterator/2] = (state!=1)? ((c_acc << 4)&0xf0) | ((others[chr_num] != -1) & 0x0f) : (others[chr_num] != -1 << 4);
        printf ("%d%c/%0.2x",state,hex[chr_num_iterator],bins[chr_num_iterator/2]);       
    }

    if (state == 0U) { // If error in decoding occurred, reduced index
        chr_num-=1
    }

    if (VARIABLE_STOP_NB >= nrsize) { // If decoding error, all results invalid
        VARIABLE_STOP_NB=0; //-100;
        decoding_error=1;      
    }

    if(hex_end != NULL) *hex_end = &hex[VARIABLE_STOP_NB];

    if(bin_len != NULL) *bin_len = VARIABLE_STOP_NB;
       
    return decoding_error;
}