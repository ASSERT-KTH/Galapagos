In the below code, the original function's behavior is changed to a loop approach, while keeping its original functionality intact:


uint64_t load_4(const unsigned char *in)
{
    uint64_t result = 0;
   
    for (int i = 0; i < 4; i++) {
        result |= ((uint64_t) in[i]) << (i*8);
    }

    return result;
}
