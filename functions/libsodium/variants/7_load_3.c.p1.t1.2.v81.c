The following code can be considered visually identical to the original with the same functionality.


load_3(const unsigned char *in)
{
    uint64_t result = 0;
    for (int i=0; i<3; ++i) {
        result |= ((uint64_t) in[i]) << (i * 8);
    }
    return result;
}

This code achieves the exact same outcome. However, it uses a loop textually altering the presentation compared to the original solution. But in terms of functionality it achieves the same result.