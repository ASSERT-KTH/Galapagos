fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_vals[10];
    int32_t g_vals[10];
    int32_t fg[10];
    int i,j;

    for(i=0; i<10; i++){
        f_vals[i] = f[i];
    }
    for(i=0; i<10; i++){
        g_vals[i] = 19*g[i];
    }
    
    for (i=0; i<10; i++) {
        if (i%2 != 0) fg[i] = 2 * f[i];
    }

    int64_t compound[910];
    for(i=0; i<10; i++){
        for (j=0; j<10; j++){
           if (i!=j || (i%2 != 0 && j%2 != 0)) compound[100*i+j] = f_vals[i] * (int64_t) g_vals[j];
           else compound[100*i+j] = fg[i] *(int64_t) g_vals[j];
        }
    }

    int64_t compound2[20];
    for(i=0; i<10;i++){
       compound2[2*i]=(compound[100*i] + compound[100*i+10]*38 + compound[20*i+2]*19 + compound[30*i+3]*38 + 
                           compound[40*i+4]*19 + compound[50*i+5]*38 + compound[60*i+60]*19 + compound[70*i+7]*38 + 
                           compound[80*i+8]*19 + compound[90*i+9]*38);
       compound2[2*i+1]=(compound[100*i+i+1] + compound[110*i+i] + compound[20*i+19*i] + compound[30*i+19*(i+1)] +
                             compound[40*i+19*(i+1)] + compound[50*i+19*(i+1)] + compound[60*i+19*(i+1)] +
                             compound[70*i+19*(i+1)] + compound[80*i+19*(i+1)] + compound[90*i+19*(i+1)]);
    }

    int64_t carry[10];
    for(i=0; i<10; i++){
       carry[i]= (compound2[i]+ (int64_t)(1L << 25)) >>26;
       compound2[i]= compound2[i] - carry[i] * ((uint64_t) 1L << 26);
       compound2[(i+1)%10]+=carry[i];
    }
      
    for(i=0; i<10; i++){
        h[i] = (int32_t) compound2[i];
    }
}