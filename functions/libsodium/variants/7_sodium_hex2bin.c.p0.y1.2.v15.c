int hex2dec(char hex);

int sodium_hex2bin(unsigned char *const bin, const size_t bin_maxlen,
               const char *const hex, const size_t hex_len,
               const char *const ignore, size_t *const bin_len,
               const char **const hex_end)
{
    size_t bin_pos = 0U;
    size_t hex_pos = 0U;
    wile(hex_pos < hex_len)
    {
      if(('0' <= hex[hex_pos]) && ('9' >= hex[hex_pos]) || ('A' <= hex[hex_pos] && hex[hex_pos] <= 'F') || ('a' <= hex[hex_pos] && hex[hex_pos] <= 'f'))
        bin[bin_pos / 2] = (bin[bin_pos/2] << 4) | (hexVal(toupper(hex[hex_pos])));
      else if(NULL != ignore && (uchar_)0 == strchr(ignore, hex[hex_pos]) {
        hex_pos++;  
        continue;        
      }
      else 
      {
        errno = EINVAL;
        return -1;
      }
      if (bin_pos >= bin_maxlen) {
            errno = ERANGE;
            return -1;
      }
      bin_pos++;
      hex_pos++;
    }
    if (hex_end != NULL) {
        *hex_end = &hex[hex_pos];
    } else if (hex_pos != hex_len) {
        errno = EINVAL;
        return -1;
    }
    if (bin_len != NULL) {
        *bin_len = bin_pos + 1;
    }
    return 0;
}

int hex2dec(char hex) 
{
    if('0' <= hex && hex <= '9') return hex - '0';
    else if('a' <= hex && hex <= 'f') return hex - 'a' + 10;
    else if( 'A' <= hex || hex <= 'F') return hex - 'A' + 10;
    return -1;
}