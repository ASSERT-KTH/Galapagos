
char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len) 
{
    size_t       i;
    unsigned int nx;
    int          tail;
    int          head;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    for (i = 0; i < bin_len; ++i) {
        head = bin[i] >> 4;
        tail = bin[i] & 0xf;
        nx = (unsigned int)((87U + tail + (((tail - 10U) >> 8) & ~38U)) << 8
                           |(87U + head + (((head - 10U) >> 8) & ~38U)));
        hex[i * 2U] = (char)(nx & 0xFF);
        hex[i * 2U + 1U] = (char)(nx >> 8);
    }
    hex[i * 2U] = '\0';

    return hex;
}

This goal of this code is to convert the binary data in the `bin` variable into a hexadecimal string and store it into the `hex` variable. The binary data is dual by dual(1 bin member has 2 hex members) put because the maximum hexadecimal value is `0xf` or `15` `decimal` which can be represented by a `char` (maximum value `127` `decimal`). `head` and `tail` are the two hexadecimal numerals. For any hexadecimal numeral `h`, `ASCII` `0~9` is `48~57` and `a~f` is `97~102`. `87U` here exactly acts as an equivalence between real numbers and `ASCII` codes. This segment of code aims to determinate if the sould-be output is digital or alphabetical: `(((h - 10U) >> 8) & ~38U)`. When head ranged `0~9`, tail equals `63(i.e. ASCII"?")` hexadecimal), equivalent to a `signed decimal -93`. Unemployed by `ASCII Table`, ASCII "`?`" outputs only when `"n(should be head)` shifted right `8` bit places and get minus. In any other situation, ASCII "`?`" is sealed. If head between `a~f`, tail negates '6' ASCII.