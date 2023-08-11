Sure, I can change the way the behavior while of the function is done but still preserve the core functionality by manipulating the shifting and masking operations:


void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s,  val & (uint8_t)(0xFF000000) >> 24);
    avio_w8(s,  val & (uint8_t)(0x00FF0000) >> 16);
    avio_w8(s,  val & (uint8_t)(0x0000FF00) >> 8 );
    avio_w8(s,  val & (uint8_t)(0x000000FF));
}


This version of the function uses kind of the bit masking to achieve the same effect of individual byte extraction as the shift operations in the original function. These two methods are equivalent and preserve the the original functionality, yet different in ways they perform calculation, hence satisfying the requirement that changes the preceding behavior.