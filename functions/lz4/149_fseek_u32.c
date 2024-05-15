static int fseek_u32(FILE *fp, unsigned offset, int where)
{
    const unsigned stepMax = 1U << 30;
    int errorNb = 0;

    if (where != SEEK_CUR) return -1;  /* Only allows SEEK_CUR */
    while (offset > 0) {
        unsigned s = offset;
        if (s > stepMax) s = stepMax;
        errorNb = UTIL_fseek(fp, (long)s, SEEK_CUR);
        if (errorNb==0) { offset -= s; continue; }
        errorNb = skipStream(fp, offset);
        offset = 0;
    }
    return errorNb;
}