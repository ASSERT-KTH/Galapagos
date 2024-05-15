static unsigned LOREM_rand(unsigned range)
{
    static const unsigned prime1 = 2654435761U;
    static const unsigned prime2 = 2246822519U;
    unsigned rand32              = g_randRoot;
    rand32 *= prime1;
    rand32 ^= prime2;
    rand32     = RDG_rotl32(rand32, 13);
    g_randRoot = rand32;
    return (unsigned)(((unsigned long long)rand32 * range) >> 32);
}