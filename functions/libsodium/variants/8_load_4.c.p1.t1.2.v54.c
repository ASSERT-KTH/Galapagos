Here is the requested program variant:


uint64_t load_4(const unsigned char *in)
{
    uint64_t result = 0;

    for(int i = 0; i < 4; i++)
    {
        result |= ((uint64_t) in[i]) << (i * 8);
    }

    return result;
}

Overall, this version does the same thing as the original program, but it uses a for loop to automate the process, instead of typing out essentially the same operation four times. This not only shortens the code but also makes it easier to scale up or down to similar tasks that would require loading more or less than exactly 4 bytes from memory.