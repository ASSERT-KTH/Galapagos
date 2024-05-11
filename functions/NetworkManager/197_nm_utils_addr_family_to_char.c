nm_utils_addr_family_to_char(int addr_family)
{
    switch (addr_family) {
    case NM_AF_UNSPEC:
        return 'X';
    case NM_AF_INET:
        return '4';
    case NM_AF_INET6:
        return '6';
    }
    nm_assert_not_reached();
    return '?';
}