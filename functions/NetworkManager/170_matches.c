matches(const char *cmd, const char *pattern)
{
    size_t len = strlen(cmd);
    if (!len || len > strlen(pattern))
        return FALSE;
    return memcmp(pattern, cmd, len) == 0;
}