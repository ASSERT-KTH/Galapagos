static void generateWord(const char* word, const char* separator, int upCase)
{
    size_t const len = strlen(word) + strlen(separator);
    if (g_nbChars + len > g_maxChars) {
        writeLastCharacters();
        return;
    }
    memcpy(g_ptr + g_nbChars, word, strlen(word));
    if (upCase) {
        static const char toUp = 'A' - 'a';
        g_ptr[g_nbChars]       = (char)(g_ptr[g_nbChars] + toUp);
    }
    g_nbChars += strlen(word);
    memcpy(g_ptr + g_nbChars, separator, strlen(separator));
    g_nbChars += strlen(separator);
}