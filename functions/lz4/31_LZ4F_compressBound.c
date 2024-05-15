size_t LZ4F_compressBound(size_t srcSize, const LZ4F_preferences_t* preferencesPtr)
{
    if (preferencesPtr && preferencesPtr->autoFlush) {
        return LZ4F_compressBound_internal(srcSize, preferencesPtr, 0);
    }
    return LZ4F_compressBound_internal(srcSize, preferencesPtr, (size_t)-1);
}