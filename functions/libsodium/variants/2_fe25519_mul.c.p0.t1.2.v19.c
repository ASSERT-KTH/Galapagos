fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], fi[5], f_i_19[4], gi[5];
    uint64_t rii[5], carry;

    for(int i=0;i<5;i++){
        fi[i] = (uint128_t) f[i];
        gi[i] = (uint128_t) g[i];
        if(i<4) 
            f_i_19[i] = 19ULL * fi[i+1];
    }

    r[0] = fi[0]*gi[0] + f_i_19[0]*gi[4] + f_i_19[1]*gi[3] + f_i_19[2]*gi[2] + f_i_19[3]*gi[1];
    r[1] = fi[0]*gi[1] +  fi[1]* gi[0]   + f_i_19[1]*gi[4] + f_i_19[2]*gi[3] + f_i_19[3]*gi[2];
    r[2] = fi[0]*gi[2] +  fi[1]* gi[1]   +     fi[2]* gi[0]+ f_i_19[2]*gi[4] + f_i_19[3]*gi[3];
    r[3] = fi[0]*gi[3] +  fi[1]* gi[2]   +     fi[2]* gi[1]+     fi[3]* gi[0]+ f_i_19[3]*gi[4];
    r[4] = fi[0]*gi[4] +  fi[1]* gi[3]   +     fi[2]* gi[2]+     fi[3]* gi[1]+     fi[4]* gi[0];

    for(int i=0;i<5;i++){
        rii[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        if(i<4)    
            r[i+1]+= carry;
        else{
            rii[0]+=19ULL*carry;
            carry=rii[0]>>51;
            rii[0]&=mask;
            rii[1]+=carry;
            carry=rii[1]>>51;
            rii[1]&=mask; 
            rii[2]+=carry;
        }
    }

    for(int i=0; i<5; i++){
        h[i] = rii[i];
    }

}