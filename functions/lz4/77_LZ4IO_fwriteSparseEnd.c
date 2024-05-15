static void LZ4IO_fwriteSparseEnd(FILE* file, unsigned storedSkips)
{
    if (storedSkips>0) {   /* implies sparseFileSupport>0 */
        const char lastZeroByte[1] = { 0 };
        if (UTIL_fseek(file, storedSkips-1, SEEK_CUR) != 0)
            END_PROCESS(69, "Final skip error (sparse file)\n");
        if (fwrite(lastZeroByte, 1, 1, file) != 1)
            END_PROCESS(69, "Write error : cannot write last zero\n");
    }
}