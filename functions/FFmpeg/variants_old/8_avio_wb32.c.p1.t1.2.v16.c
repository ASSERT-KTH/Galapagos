void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char arr[4];
    arr[0] = (unsigned char)(val >> 24);
    arr[1] = (unsigned char)(val >> 16);
    arr[2] = (unsigned char)(val >> 8);
    arr[3] = (unsigned char) val;

    for(int i=0; i<4; i++){
        avio_w8(s, arr[i]);
    }
}