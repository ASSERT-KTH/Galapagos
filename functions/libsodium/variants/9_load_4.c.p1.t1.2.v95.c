Here's a different implementation that maintains the original content and functionality while tweaking the behavior on its process:


load_4(const unsigned char *in)
{
    uint64_t result = 0;
    for (int i = 0; i < 4; i++)
    {
        result += ((uint64_t) in[i]) << (i * 8);
    }
    return result;
}

This implementation does the same thing as the original implementation, but it computes four bytes using a loop, allowing the program to introduce changes to each operation should further modifications be added.