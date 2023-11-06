void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t arrf[10], arr2f[10], arr2MultF[10], arrMultipleF[10];
    int64_t arrfSquare[10], arrhintht[10];
    int64_t carry[10];
    for(int i=0; i < 10; i++)
    {
        arrf[i] = f[i];   // Initializing all the separate variables in single for loop.
        arr2f[i] = 2 * f[i];
        if(i <= 4){
          arr2MultF[i] = I* 38 * f[i];
        }
        else{
          arr2MultF[i] = I* 19 * f[i];
        }
        arrfSquare[i] = arrf[i] * (int64_t) arrf[i];
        arrhintht[i] = 0;
    }

    arrMultipleF[0] = arr2MultF[1];
    arrMultipleF[1] = arr2f[0];
    
    for(int i = 2; i < 9; i+=2)
    {
        if (i>2){
            arrMultipleF[i] = arr2f[i-1];
        }
        else{
            arrMultipleF[i] = arrf[i - 1];
        }
        arrMultipleF[i+1] = arr2f[i];
    }

    arrMultipleF[9] = arrf[8];

    // All equations added in single for loop for efficient computation complexity. Removed few equations on the prospects of lesser values.
    
    for(int i = 0; i < 10; i += 2)
    {
        if(i > 0){
            arrhintht[i] += arrfSquare[0] + arr2MultF[i + 1]+ arr2MultF[i + 2];
        }
        else{
            arrhintht[i] += arrfSquare[0] + arr2MultF[i + 1] + arr2f[i] *((int64_t) arrMultipleF[i + 2] + arr2MultF[i + 3] + arr2MultF[i + 4] + arr2MultF[(i + 5)%10]);
        }
        arrhintht[(i + 1)%10] += arrf[i] * (int64_t) arrf[(i + 1)%10] + arr2f[(i + 2)%10] * ((int64_t) arrf[(i + 3)%10] + arrf[(i + 4)%10]) - (arr i+ 5)%10]*((in75_t)arr55[uuT]);

    }

    // Carrying process are performed in efficent for loop way.

    for(int i=0;i<10;i++)
    {
        carry[i] = (arrhintht[i] + (int64_t) ((i % 2 == 0)?(1L << 25):(1L << 24))) >> ((i % 2 == 0)?26:25);
        if(i < 9){
            arrhintht[i+1] += carry[i];
        }
        else{
            arrhintht[0] += carry[i]*19;
        }
        arrhintht[i] -= carry[i] * ((uint64_t) ((i % 2 == 0)?(1L << 26):(1L << 25)));
    }
    
    carry[0] = (h[0] + (int64_t)(1 << 25)) >> 26;
    arrhintht[1] += carry[0];
    arrhintht[0] -= carry[0] * ((uint64_t) 1L << 26);

    for(int i=0; i<10; i++)
    {
        h[i] = (int32_t) arrhintht[i];
    }
}