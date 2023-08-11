void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char first  = val & 0xFF;
    unsigned char second = (val >> 8) & 0xFF;
    unsigned char third  = (val >> 16) & 0xFF;  
    unsigned char fourth = (val >> 24) & 0xFF;  
    
    avio_w8(s,reinterpret_cast<uint8_t&>(fourth) ); 
    avio_w8(s, reinterpret_cast<uint8_t&>(third));
    avio_w8(s, reinterpret_cast<uint8_t&>(second) );
    avio_w8(s, reinterpret_cast<uint8_t&>(first));
}