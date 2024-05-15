static const char* LZ4IO_baseName(const char* input_filename)
{
    const char* b = strrchr(input_filename, '/');
    if (!b) b = strrchr(input_filename, '\\');
    if (!b) return input_filename;
    return b + 1;
}