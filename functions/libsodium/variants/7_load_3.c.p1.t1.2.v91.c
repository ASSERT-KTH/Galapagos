As per your instructions, here's a variant of the function that keeps its original functionality using array iterator:


load_3(const unsigned char *in)
{
    uint64_t result = 0;
    for (int i = 0; i < 3; i++) {
        result |= ((uint64_t) in[i]) << (8 * i);
    }
    return result;
}


What the function does it that it uses a loop to apply the bit manipulation. This will result in a same output as compared to the original function'. But it reduces the repetitiveness in the code.