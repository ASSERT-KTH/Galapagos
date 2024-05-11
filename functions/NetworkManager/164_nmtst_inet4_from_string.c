nmtst_inet4_from_string(const char *str)
{
    in_addr_t addr;
    int       success;

    if (!str)
        return 0;

    success = inet_pton(AF_INET, str, &addr);

    g_assert(success == 1);

    return addr;
}