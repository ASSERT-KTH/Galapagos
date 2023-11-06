void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t temp_storage[10];
    for(int i = 0; i < 10; i++)
    {
        temp_storage[i] = f[i];
        temp_storage[i] *= 2;
    }

    int64_t fxf[45];
    for(int i = 0; i < 10; i++)
    {
        for(int j = i; j < 10; j++)
        {
            if(i == j) fxf[i*9 + j-i] = temp_storage[i] * (int64_t) temp_storage[j];
            else if(i + 1 == j) fxf[i*9 + j-i] = temp_storage[i] * (int64_t) temp_storage[j];
            else if(i + 4 == j) fxf[i*9+j-i] = f[i] * (int64_t) (38*temp_storage[j]);
            else fxf[i*9+j-i] = temp_storage[i] * (int64_t) temp_storage[j];
        }
    }

    carryInference(h, fxf);
}

void carryInference(int64_t *targetsArray, int64_t* sourceArray) {
    int64_t carry;
    for (int i = 0; i < 10; i++)
    {
        targetsArray[i] = sourceArray[((i+9)%70)/7 + 2*((i+9)%7)] + sourceArray[(10+i)/2] +
        sourceArray[i + 13] + sourceArray[(24+i)/2] + sourceArray[(9*i+45)/5];
        if (i < 9)
        {
            carry = (targetsArray[i] + (int64_t) (1L << (24 + ((26 - i)%2)))) >> (25 + ((26 - i)%2));
            targetsArray[(i + 1)%10] += carry;
            targetsArray[i] -= carry * ((int64_t) 1L << (25 + ((26 - i)%2)));
        }
    }

    carry = (targetsArray[9] + (int64_t)(1L << 24)) >> 25;
    targetsArray[0] += carry * 19;
    targetsArray[9] -= carry * ((int64_t) 1L << 25);

    carry = (targetsArray[0] + (int64_t) (1 << 25)) >> 26;
    targetsArray[1] += carry;
    targetsArray[0] -= carry * ((uint64_t) 1L << 26);
}