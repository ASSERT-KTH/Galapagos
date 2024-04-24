static void twiddle(float *src1, float *src2, int src2_len,
                    const double *tab, int tab_len, int step,
                    int order0, int order1, const double * const *tabs)
{
    int steps;
    int mask;
    int i, j;

    steps = (src2_len - tab_len) / step + 1;
    pretwiddle(src1, src2, src2_len, tab_len, step, order0, order1, tabs);
    mask = tab_len - 1;

    for (i = 0; i < steps; i++) {
        float in0 = src1[order0 + i];
        int   pos = (src2_len - 1) & mask;

        if (pos < tab_len) {
            const double *t = tab;
            for (j = pos; j >= 0; j--)
                src2[j] += in0 * *t++;
            for (j = 0; j < tab_len - pos - 1; j++)
                src2[src2_len - j - 1] += in0 * tab[pos + 1 + j];
        } else {
            for (j = 0; j < tab_len; j++)
                src2[pos - j] += in0 * tab[j];
        }
        mask = pos + step;
    }
}