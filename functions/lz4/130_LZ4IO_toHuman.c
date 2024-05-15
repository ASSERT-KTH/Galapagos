static const char* LZ4IO_toHuman(long double size, char* buf)
{
    const char units[] = {"\0KMGTPEZY"};
    size_t i = 0;
    for (; size >= 1024; i++) size /= 1024;
    sprintf(buf, "%.2Lf%c", size, units[i]);
    return buf;
}