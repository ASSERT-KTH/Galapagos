void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t byte_arr[4]; 
    
    byte_arr[0] = (val >> 24) & 0xFF;
    byte_arr[1] = (val >> 16) & 0xFF;
    byte_arr[2] = (val >> 8)  & 0xFF;
    byte_arr[3] =  val & 0xFF;

    for(int i=0; i<4; i++){
        avio_w8(s, byte_arr[i]);
    }
}