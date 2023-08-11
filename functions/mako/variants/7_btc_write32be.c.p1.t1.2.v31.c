Here's a variant of the function that maintains its functionality. This version also handles the endianess:


void btc_write32be(uint8_t* zp, uint32_t x) {
    for( int idx = 0 ; idx < sizeof(uint32_t) ; ++idx ) {
        zp[idx] = (uint8_t)(x >> ((3 - idx) * 8));
    }
}
