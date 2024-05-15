UTIL_STATIC int UTIL_sameString(const char* a, const char* b)
{
    assert(a != NULL || b != NULL);  /* unsupported scenario */
    if (a==NULL) return 0;
    if (b==NULL) return 0;
    return !strcmp(a,b);
}