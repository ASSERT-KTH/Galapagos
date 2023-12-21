Version 1: Inline binary shifting

void avio_wb32(AVIOContext *s, unsigned int val) 
{
    avio_w8(s, val >> 24 & 0xFF);
    avio_w8(s, val >> 16 & 0xFF);
    avio_w8(s, val >> 8  & 0xFF);
    avio_w8(s, val       & 0xFF);
}


Version 2: Iterative inline writing

void avio_wb32(AVIOContext *s, unsigned int val) {
    for (unsigned int i = 0; i < 4; i++) {
        avio_w8(s, (val >> ((3-i) * 8)) & 0xFF);
    }
}


Version 3: Unrolled for loop (value updating)

void avio_wb32(AVIOContext *s, unsigned int val) {
    avio_w8(s, val);
    val = (val << 8) & 0xFFFFFF;
    avio_w8(s, val);
    val = (val << 8) & 0xFFFFFF;
    avio_w8(s, val);
    val = (val << 8) & 0xFFFFFF;
    avio_w8(s,val);
}


Version 4: Array based, iterative index updating

void avio_wb32(AVIOContext *s, unsigned int val) {
    uint8_t arr[4] = {val >> 24, val >> 16, val >> 8, val};
    for(int i = 0; i < 4; i++) {
        avio_w8(s, arr[i]);
    }
}


Version 5: Recursive calls

void avio_wb32(AVIOContext *s, unsigned int val) {
    if (val > 0xFF) {
        avio_wb32(s, val >> 8);
    }
    avio_w8(s, val & 0xFF)
}
