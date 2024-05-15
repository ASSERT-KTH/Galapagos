LOREM_genBlock(void* buffer, size_t size, unsigned seed, int first, int fill)
{
    g_ptr = (char*)buffer;
    assert(size < INT_MAX);
    g_maxChars = size;
    g_nbChars  = 0;
    g_randRoot = seed;
    if (g_distribCount == 0) {
        init_word_distrib(kWords, kNbWords, kWeights, kNbWeights);
    }

    if (first) {
        generateFirstSentence();
    }
    while (g_nbChars < g_maxChars) {
        int sentencePerParagraph = about(7);
        generateParagraph(sentencePerParagraph);
        if (!fill)
            break; /* only generate one paragraph in not-fill mode */
    }
    g_ptr = NULL;
    return g_nbChars;
}