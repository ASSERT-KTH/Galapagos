Code transformation 1: Inline transformation


void avio_wb32(AVIOContext *s, unsigned int val){
    s->pb[s->size++] = (uint8_t)(val >> 24);
    s->pb[s->size++] = (uint8_t)(val >> 16);
    s->pb[s->size++] = (uint8_t)(val >> 8 );
    s->pb[s->size++] = (uint8_t) val;  
}


Code transformation 2: Loop transformation


void avio_wb32(AVIOContext *s, unsigned int val){
    int shift;
    for (shift = 24; shift >= 0; shift -= 8)
    {
        avio_w8(s, (uint8_t) (val >> shift));
    }
}


Note: These transformations presume that behavior of not covered methods and struct remained unchanged. "s->pb[s->size++]" for example was assumed to have same functionality as "avio_w8". Similarly, presumed that we are running uchar (uint8_t) on a little endian machine. This information might determine whether we use xor or not. If these presumptions do not meet your case, recommendation would be to treat above transformation carefully and as pseudo code and apply details of your case yourself manually.