void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t temp, r[5]={0}, fx[5]={0}, gx[5]={0}, f_mul19[4];
    uint64_t carry,out[5]={0};

    //setting initial values
    for(int i=0;i<5;i++){
        fx[i]=(uint128_t)f[i];
        gx[i]=(uint128_t)g[i];
        if(i<4)
            f_mul19[i] = 19ULL * fx[i+1];  // multiplication by 19
    }

    //computations that do not involve carrying
    for(int i=0; i<5; i++) {
        for(int j=0; j<=i; j++)
            r[i] += fx[j]*gx[i-j];
        if(i<4){
            for(int j=0; j<4-i; j++)
                r[i] += f_mul19[j]*gx[4-j];
        }
    }

    //managing carrying bits
    for(int i=0;i<5;i++) {
        out[i]=((uint64_t)r[i])&mask;    //extracting lower bits
        if(i<4){
            temp = r[i]>> 51;   //extracting higher bits
            r[i+1]+=temp;
        }
        else{
            //for the last computation considering constant 19
            temp = r[i]>> 51;
            out[0]+=19*temp;
            carry=out[0]>>51;
        }
    }

    for(int i=0; i<5;i++){
        out[i]&=mask;
        if (i<4)  //checking next carry
            out[i + 1] += carry;
    }

    //writing collection results to h-array
    for(int i=0; i<5; i++)
        h[i]=out[i];
}