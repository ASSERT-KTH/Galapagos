Blowfish_stream2word(const uint8_t *data, uint16_t databytes,
                     uint16_t *current)
{
    uint8_t i;
    uint16_t j;
    uint32_t temp;

    temp = 0x00000000;
    j = *current;

    for(i = 0; i < 4; i++, j++) {
        if(j >= databytes)
            j = 0;
        temp = (temp << 8) | data[j];
    }

    *current = j;
    return temp;
}