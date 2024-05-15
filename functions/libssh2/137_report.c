report(uint32_t data[], uint16_t len)
{
    int i;
    for(i = 0; i < len; i += 2)
        printf("Block %d: 0x%08lx 0x%08lx.\n",
               i / 2, (unsigned long)data[i], (unsigned long)data[i + 1]);
}