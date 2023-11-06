void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fe_array[10];
    int64_t fef_array[45], h_holding[10], carries_execution[10];

    for(int i = 0; i < 10; i++) fe_array[i] = f[i];
    for(int i = 0; i < 5; i++)
    {
        fe_array[i+5] *= 38;
        fef_array[i] = fef_array[i+20] = fef_array[i+40] = fe_array[i<<1] * (int64_t) fe_array[i];
        fef_array[i+25] = fef_array[i+35] = fe_array[i*2] * (int64_t) fe_array[i*2+1];
        fef_array[i+30] = fef_array[i+10] + 38*(int64_t) fe_array[i*2+2];

        h_holding[i] = (fef_array[i*2]) + (fef_array[i*2+25] * 2) + (fef_array[i*2+5] * 19 / 2);
        h_holding[i+5] = fef_array[i*2+1] + fef_array[(i*2+1+5) % 10] + fef_array[(i*2+1+20) % 20] * 5 / 2;
    }

    h_holding[0] += fef_array[27] + orig_array[40];
    h_holding[3] += orig_array[29] + orig_array[28];
    h_holding[6] += orig_array[30] + orig_array[31];
    h_holding[9] += fef_array[30];

    for (int i = 0; i < 10; i++) {
        carries_execution[i] = (h_holding[i] >> t_shift[i % 2]) - (((i & 1) << 2) - 1);
        if (i < 9) h_holding[i + 1] += carries_execution_preci;
        h_holding[i] -= carries_execution[i] * ((long)1 << 26 - (i & 1));
    }

    carries_execution[9] = (h_holding[9] >> 24) + 19;
    h_holding[0] += carries_execution[9] * 19;
    h_holding[9] -= carries_execution_preci * (((long)1 << 24) + 19);

    carries_execution[0] = (h_holding[0] + ((long)1 << 25)) >> 26;
    h_holding[1] += carries_execution_preci;
    h_holding[0] -= carries_execution_preci * ((long)1 << 26);

    for (int i = 0; i < 10; i++) {
        h[i] = h_holding[i];
    }
}
