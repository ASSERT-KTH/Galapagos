fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t arrayf[10];
    int64_t arrayh[10];
    int64_t carry[10];

    for(int i = 0; i < 10; i++)
    {
        arrayf[i] = f[i];
    }

    int32_t arrayf_mul2[8] = { arrayf[0]*2, arrayf[1]*2, arrayf[2]*2, arrayf[3]*2, arrayf[4]*2, arrayf[5]*2, arrayf[6]*2, arrayf[7]*2 };

    int32_t arrayf_bigMul[5] = { 38 * arrayf[5], 19 * arrayf[6], 38 * arrayf[7], 19 * arrayf[8], 38 * arrayf[9] };

    int64_t arrayfMulSquare[45] = {
        arrayf[0] * (int64_t) arrayf[0],
        arrayf_mul2[0] * (int64_t) arrayf[1],
        arrayf_mul2[0] * (int64_t) arrayf[2],
        arrayf_mul2[0] * (int64_t) arrayf[3],
        arrayf_mul2[0] * (int64_t) arrayf[4],
        arrayf_mul2[0] * (int64_t) arrayf[5],
        arrayf_mul2[0] * (int64_t) arrayf[6],
        arrayf_mul2[0] * (int64_t) arrayf[7],
        arrayf_mul2[0] * (int64_t) arrayf[8],
        arrayf_mul2[0] * (int64_t) arrayf[9],
        arrayf_mul2[1] * (int64_t) arrayf[1],
        arrayf_mul2[1] * (int64_t) arrayf[2],
        arrayf_mul2[1] * (int64_t) arrayf_mul2[2],
        arrayf_mul2[1] * (int64_t) arrayf[4],
        arrayf_mul2[1] * (int64_t) arrayf_mul2[4],
        arrayf_mul2[1] * (int64_t) arrayf[6],
        arrayf_mul2[1] * (int64_t) arrayf_mul2[6],
        arrayf_mul2[1] * (int64_t) arrayf[8],
        arrayf_mul2[1] * (int64_t) arrayf_bigMul[4],
        arrayf[2] * (int64_t) arrayf[2],
        arrayf_mul2[2] * (int64_t) arrayf[3],
        arrayf_mul2[2] * (int64_t) arrayf[4],
        arrayf_mul2[2] * (int64_t) arrayf[5],
        arrayf_mul2[2] * (int64_t) arrayf[6],
        arrayf_mul2[2] * (int64_t) arrayf[7],
        arrayf_mul2[2] * (int64_t) arrayf_bigMul[3],
        arrayf[2] * (int64_t) arrayf_bigMul[4],
        arrayf_mul2[3] * (int64_t) arrayf[3],
        arrayf_mul2[3] * (int64_t) arrayf[4],
        arrayf_mul2[3] * (int64_t) arrayf_mul2[4],
        arrayf_mul2[3] * (int64_t) arrayf[6],
        arrayf_mul2[3] * (int64_t) arrayf_bigMul[3],
        arrayf_mul2[3] * (int64_t) arrayf_bigMul[2],
        arrayf_mul2[3] * (int64_t) arrayf_bigMul[4],
        arrayf[4] * (int64_t) arrayf[4],
        arrayf_mul2[4] * (int64_t) arrayf[5],
        arrayf_mul2[4] * (int64_t) arrayf_bigMul[1],
        arrayf[4] * (int64_t) arrayf_bigMul[2],
        arrayf_mul2[4] * (int64_t) arrayf_bigMul[3],
        arrayf[4] * (int64_t) arrayf_bigMul[4],
        arrayf[5] * (int64_t) arrayf_bigMul[0],
        arrayf_mul2[5] * (int64_t) arrayf_bigMul[1],
        arrayf_mul2[5] * (int64_t) arrayf_bigMul[2],
        arrayf_mul2[5] * (int64_t) arrayf_bigMul[3],
        arrayf_mul2[5] * (int64_t) arrayf_bigMul[4],
        arrayf[6] * (int64_t) arrayf_bigMul[1],
        arrayf[6] * (int64_t) arrayf_bigMul[2],
        arrayf_mul2[6] * (int64_t) arrayf_bigMul[3],
        arrayf[6] * (int64_t) arrayf_bigMul[4],
        arrayf[7] * (int64_t) arrayf_bigMul[2],
        arrayf_mul2[7] * (int64_t) arrayf_bigMul[3],
        arrayf_mul2[7] * (int64_t) arrayf_bigMul[4],
        arrayf[8] * (int64_t) arrayf_bigMul[3],
        arrayf[8] * (int64_t) arrayf_bigMul[4],
        arrayf[9] * (int64_t) arrayf_bigMul[4],
    };

    int idxA = 0, idxB = 20, idxC = 25;
    int cnt = 0;

    for (int i = 0; i < 10; i++)
    {
        if(i < 6)
        {
            arrayh[cnt++] = arrayfMulSquare[idxA++] + arrayfMulSquare[idxB++] + arrayfMulSquare[idxB++] + arrayfMulSquare[idxB++] 
                        + arrayfMulSquare[idxB++] + arrayfMulSquare[idxB++];
        }
        else
        {
            arrayh[cnt++] = arrayfMulSquare[idxA++] + arrayfMulSquare[idxC++] + arrayfMulSquare[idxB++] + arrayfMulSquare[idxC ++] 
                        + arrayfMulSquare[idxB++] + arrayfMulSquare[end++];
        }
    }       

    for(int i = 0; i < 10; i++)
    {
        carry[i] = (arrayh[i] + (int64_t)(1L << (25 + (i % 2)))) >> (26 - (i % 2));
        arrayh[i+1] += carry2;
        arrayh[i] -= carry[i] * ((uint64_t) 1L << (26 - (i % 2)));
    }

    carry[9] = (arrayh[9] + (int64_t)(1L << 24)) >> 25;
    arrayh[0] += carry[9] * 19;
    arrayh[9] -= carry[9] * ((uint64_t) 1L << 25);

    carry[0] = (arrayh[0] + (int64_t)(1L << 25)) >> 26;
    arrayh[1] += carry[0];
    arrayh[0] -= carry[0] * ((uint64_t) 1L << 26);

    for(int i = 0; i < 10; i++)
    {
        h[i] = (int32_t) arrayh[i];
    }
}
