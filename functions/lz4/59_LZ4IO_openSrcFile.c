static FILE* LZ4IO_openSrcFile(const char* srcFileName)
{
    FILE* f;

    if (LZ4IO_isStdin(srcFileName)) {
        DISPLAYLEVEL(4,"Using stdin for input \n");
        f = stdin;
        SET_BINARY_MODE(stdin);
        return f;
    }

    if (UTIL_isDirectory(srcFileName)) {
        DISPLAYLEVEL(1, "lz4: %s is a directory -- ignored \n", srcFileName);
        return NULL;
    }

    f = fopen(srcFileName, "rb");
    if (f==NULL) DISPLAYLEVEL(1, "%s: %s \n", srcFileName, strerror(errno));
    return f;
}