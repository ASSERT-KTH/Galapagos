void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int byte1, byte2, byte3, byte4;
    
    byte1 = val & 0xFF;         
    byte2 = (val >> 8) & 0xFF;    
    byte3 = (val >> 16) & 0xFF;  
    byte4 = (val >> 24) & 0xFF;   

    avio_w8(s, byte4);
    avio_w8(s, byte3);
    avio_w8(s, byte2);
    avio_w8(s, byte1);
}