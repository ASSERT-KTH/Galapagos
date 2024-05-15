static int BMK_syntheticTest(int cLevel, int cLevelLast,
                             const char* dictBuf, int dictSize)
{
    int benchError = 0;
    size_t const benchedSize = 10000000;
    void* const srcBuffer = malloc(benchedSize);

    /* Memory allocation */
    if (!srcBuffer) END_PROCESS(21, "not enough memory");

    /* Fill input buffer */
    LOREM_genBuffer(srcBuffer, benchedSize, 0);

    /* Bench */
    benchError = BMK_benchCLevel(srcBuffer, benchedSize,
                    "Lorem ipsum",
                    cLevel, cLevelLast,
                    &benchedSize,
                    1,
                    dictBuf, dictSize);

    /* clean up */
    free(srcBuffer);

    return benchError;
}