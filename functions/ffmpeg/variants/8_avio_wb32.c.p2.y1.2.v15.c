void avio_wb32(AVIOContext *s, unsigned int val)
{
    //Transforming the sequence and adding parentheses to highlight precedence Also, removed explicit casting since implicit casting is sufficient
    avio_w8(s, val             );
    avio_w8(s, (val >> 8)  & 0xFF);
    avio_w8(s, (val >> 16) & 0xFF);
    avio_w8(s, (val >> 24) );
}