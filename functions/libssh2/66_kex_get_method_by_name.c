kex_get_method_by_name(const char *name, size_t name_len,
                       const LIBSSH2_COMMON_METHOD ** methodlist)
{
    while(*methodlist) {
        if((strlen((*methodlist)->name) == name_len) &&
            (strncmp((*methodlist)->name, name, name_len) == 0)) {
            return *methodlist;
        }
        methodlist++;
    }
    return NULL;
}