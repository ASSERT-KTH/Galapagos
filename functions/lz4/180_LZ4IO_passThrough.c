LZ4IO_passThrough(FILE* finput, FILE* foutput,
                  unsigned char MNstore[MAGICNUMBER_SIZE],
                  int sparseFileSupport)
{
	size_t buffer[PTSIZET];
    size_t readBytes = 1;
    unsigned long long total = MAGICNUMBER_SIZE;
    unsigned storedSkips = 0;

    if (fwrite(MNstore, 1, MAGICNUMBER_SIZE, foutput) != MAGICNUMBER_SIZE) {
        END_PROCESS(50, "Pass-through write error");
    }
    while (readBytes) {
        readBytes = fread(buffer, 1, sizeof(buffer), finput);
        total += readBytes;
        storedSkips = LZ4IO_fwriteSparse(foutput, buffer, readBytes, sparseFileSupport, storedSkips);
    }
    if (ferror(finput)) END_PROCESS(51, "Read Error");

    LZ4IO_fwriteSparseEnd(foutput, storedSkips);
    return total;
}