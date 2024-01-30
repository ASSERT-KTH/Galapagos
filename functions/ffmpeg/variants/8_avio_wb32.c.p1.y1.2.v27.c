1. Loop Based Transformation:


void avio_wb32(AVIOContext *s, unsigned int val)
{
    for(int i=3; i>=0; --i)
    {
        avio_w8(s, (uint8_t)(val >> (8*i)));
    }    
}



2. Swapping the order of the function calls:


void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s, (uint8_t) val);
    avio_w8(s, (uint8_t)(val >> 8 ));
    avio_w8(s, (uint8_t)(val >> 16));
    avio_w8(s, val >> 24 );
}



3. Assigning to variables before calling the function:


void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t w1 = val >> 24;
    uint8_t w2 = (uint8_t)(val >> 16);
    uint8_t w3 = (uint8_t)(val >> 8 );
    uint8_t w4 = (uint8_t) val;

    avio_w8(s, w1);
    avio_w8(s, w2);
    avio_w8(s, w3);
    avio_w8(s, w4);
}


4. Using a do-while loop:
  

void avio_wb32(AVIOContext *s, unsigned int val)
{   
    uint8_t offsetMultiplier = 3;
    do
    {
        avio_w8(s, (uint8_t)(val >> (8*offsetMultiplier--)));
    } 
    while (offsetMultiplier != (uint8_t)(-1));
}
