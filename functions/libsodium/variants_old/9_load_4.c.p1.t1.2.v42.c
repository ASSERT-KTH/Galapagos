Here is a program variant of the function that maintains the original functionality:


uint64_t load_4(const unsigned char *in)
{
    uint64_t result = 0;

    for (int i = 0; i < 4; i++) {
        result |= ((uint64_t) in[i]) << (i*8);
    }

    return result;
}


The above function is a simpler alternative that accomplishes the same thing as the original load_4. In a sense, it is 'cleaner' because it doesn't have as many explicit lines of different types of shift operations. Instead of individually accessing and shifting each 8-bit block `{in[0], in[1], in[2], in[3]}`, it iterates through them with a loop. Each iteration it left-shifts by `8*i` bits, which equals the necessary amount `{0, 8, 16, 24}`.