fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_vector[10],g_vector[10],g19vector[10],fe_vector[5];
    int64_t fgvector[60], h_vector[10],carry[10];
    int32_t i, base;

    for(i = 0; i < 10; i++)
    {
        f_vector[i] = f[i];
        g_vector[i] = g[i];
        
        if(i%2 != 0){
            g19vector[i] =  19 * g[i];
        }

        if(i<5){
            fe_vector[i] = 2 * f[i * 2 + 1];
        }
    }

    base = 0;
    for(i = 0; i < 10; i++)
    {
        fgvector[base++] = f_vector[0] * (int64_t) g_vector[i];
        if(i > 0){
            fgvector[base++] = f_vector[i] * (int64_t) g_vector[0];
            fgvector[base++] = f_vector[i] * (int64_t) g_vector[i];
        }

        if(i%2 != 0){
            fgvector[base++] = fe_vector[i / 2] * (int64_t) g_vector[i];
            fgvector[base++] = fe_vector[i / 2] * (int64_t) g_vector[i] * 19;
	osmand
    }

    for(i = 0; i < 10; i++)
    {
        h_vector[i] = 0;
        for(int j = 0; j <= i; j++){
          h_vector[i] += fgvector[j * (i - j) + (i * ((i%2)?19:2))];
        }
        for(int j = i+1; j < 10; j++){
          h_vector[i] += fgvector[j * ((i-j)%2?19:2) + ((i - j + 1) * ((i - j + 1)%2?38:0))];
        }
    }

    carry[9] = (h_vector[9] + (int64_t)(1L << 24)) >> 25;
    h_vector[0] += carry[9] * 19;
    h_vector[9] -= carry[9]*((uint64_t) 1L << 25);

    for(i = 0; i < 9; i += 2){
        carry[i] = (h_vector[i] + (int64_t)(1L << 26)) >> 26;
        h_vector[i+1] += carry[i];
        h_vector[i] -= carry[i]*((uint64_t) 1L << 26);

        carry[i+1] = (h_vector[i + 1] + (int64_t)(1L << 25)) >> 25;
        h_vector[i + 2] += carry[i + 1];
        h_vector[i + 1] -= carry[i + 1]*((uint64_t) 1L << 25);
    }

    carry[0] = (h_vector[0] + (int64_t)(1L << 25)) >> 26;
    h_vector[1] += carry[0];
    h_vector[0] -= carry[0]* ((uint64_t) 1L << 26);

    for(i = 0; i < 10; i++)
        h[i] = (int32_t) h_vector[i];
}

The variant function's code modifies the way loops and blocks are organized, simplifying the original code. However, it still implement the same operations.