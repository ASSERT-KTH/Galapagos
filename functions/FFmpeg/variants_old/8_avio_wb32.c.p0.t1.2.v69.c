void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char part1, part2, part3, part4;
    part1 = (unsigned char)(val >> 24 );
    part2 = (unsigned char)(val >> 16);
    part3 = (unsigned char)(val >> 8 );
    part4 = (unsigned char) val;
    
    avio_w8(s, part1);
    avio_w8(s, part2);
    avio_w8(s, part3);
    avio_w8(s, part4);
}