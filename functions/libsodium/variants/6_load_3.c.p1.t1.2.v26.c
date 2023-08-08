Here is the same function implemented differently but maintaining the same function signature and exact behavior:


load_3(const unsigned char *in)
{
    uint64_t result = 0;

    for (int i = 0; i < 3; i++)
    {
        result |= ((uint64_t) in[i]) << (8 * i);
    }

    return result;
}

The function now uses a loop, but it's behaviour and output remain the same. It creates result from the first three bytes in the input array, each shifted over 8 times the current loop index. Maintainability is improved since the number of expressions is reduced while functionality remains identical.