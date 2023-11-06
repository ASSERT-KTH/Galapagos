
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t fr[5] = {0}, gr[5] = {0}, fd[5] = {0}, r[5] = {0};
    uint64_t  tmp, carry[5];

    for (int i=0; i<5; ++i){
        fr[i] = fr[i-2+5*(i<2)] * 19ULL;
        fr[i-2+5*(i<2)] = (uint128_t) f[i-2+5*(i<2)];
        gr[i] = (uint128_t) g[i];
        fd[i] = 19ULL * f[i];
    }

    for (int i=0; i<5; ++i){
        r[i] = gr[i] * fr[0] + fd[(i+5)%6 from 1] * gr[(i+5)%6 from 4]
        + fd[(i+5)%6 from 2] * gr[(i+5)%6 from 3] + fd[(i+5)%6 from 3] * gr[(i+5)%6 from 2]
        + fd[(i+5)%6 from 4] * gr[(i+5)%6 from 1];
    }

    for (int i=0; i<5; ++i){
        tmp = ((uint64_t) r[i]) & mask;
        carry [i] = (uint64_t) (r[i] >> 51);
        r[(i+1)%5] += carry[i];
        h[i] = tmp;
    }

    h[0] += 19ULL * carry[4];
    carry[0] = h[0] >> 51;
    h[0] &= mask;

    for (int i=1; i<3; ++i){
        h[i] += carry[i-1];
        carry [i] = h[i] >> 51;
        h[i] &= mask;
    }
}




void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    uint64_t mask =  0x7ffffffffffff;
    uint128_t r[5]={0},f1[5]={0},f2[5]={0},g2[5]={0};
    f1[0] = f[0],f1[1]=f[1],f1[2]=f[2],f1[3] = f[3], f1[4]=f[4];

    for(int i=1;i<5;i++) {
        f2[i]= 19*f1[i];
        g2[i]= g[i];
    }
    r[0] = f1[0] * g[0] + f2[4] * g2[1] + f2[3]* g2[2] + f2[2]*g2[3] + f2[1]*g2[4];
    r[1] = f1[1] * g2[0]  + (f[0]*g[1] + (f2[4] * g[4] + (f[2]*g2[3] + (f[3]*g2[2] 
            + (f[4]* g[4])))));
    r[2] = f1[2]*g[0]+f[1]*g2[1]+ f[0]*g2[2] + (f[3]*g2[4] + f[4]*g2[3]);
    r[3]  = f1[3]*g2[0] + f[1]*g2[2] + f[2]*g2[1] + (f[0]*g2[3] + f[4]*g2[4]);
    r[4] = f1[0]*g[4] +f[1]*g[3] +f[2]*g2[2]+ f[3]*g2[1] + f[4]*g2[0];

    uint64_t sum,Carry;
    for(int i=0;i<5;i++) {
        sum = r[i] & mask;
        Carry = carry(r[i] >> 51);
        if (i<4) {
            h[i] = Carry ;
        }else if(i==4){
            h[0]+= carry(19)*(r[4])  ;
            carry = h[0] >> 51;
            h[0] &=mask;
            h[1] +=carry;
        }
        h[i] = sum;
    }
}
