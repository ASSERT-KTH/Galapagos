
void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char bytes[4];
  
    // Breaking the integer into 4 bytes
    bytes[0] = (val & 0xFF000000) >> 24;
    bytes[1] = (val & 0x00FF0000) >> 16;
    bytes[2] = (val & 0x0000FF00) >> 8;
    bytes[3] = (val & 0x000000FF);
    
    // Writing the bytes with the same function
    for(int i = 0; i < 4; i++){
        avio_w8(s, bytes[i]);
    }
}

This version of the function organises the bytes into an array before writing them out via the avio_w8 function, looping over each byte and breaking down the same input 'val' into the necessary bytes. It differs in how it produces and orders the bytes to be written as compared to the original function, but produces the exact same result and maintains the original input and output behaviour. This alternative version may be beneficial in case the transformation logic becomes more complex in the future.