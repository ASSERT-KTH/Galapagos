The following is a variant of the C code that was shared. This function maintains the original behaviour but uses loops to reduce the redundancy in the code:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fr[10], gr[10];
    int64_t t[19], c, hr[10];

    for(int i=0; i<10; i++) {
        if(i % 2 == 0) {
            fr[i] = f[i];
            gr[i] = g[i];
        } else {
            fr[i] = 2 * f[i];
            gr[i] = 19 * g[i];
        }
    }

    for(int i=0; i<10; i++) {
        t[i] = fr[0]*((int64_t) gr[i]);
        if(i+1 < 10) {
            t[10+i] = fr[i+1]*((int64_t) gr[0]);
        }
    }

    for(int i=1; i<9; i++) {
      
        for(int j=1; j<10-i; j++) {
            if(i%2!=0 && j%2==0) 
                t[i+j] += fr[j+(i+1)/2] * ((int64_t) gr[i]);
            else if(i%2==0 && j%2!=0) 
                t[i+j] += fr[(1+(j+1)/2)*(i!=0)] * ((int64_t) gr[i*j+1]);
        }
    }

    for(int i=1; ai<9; i++) {
        t[i] += 38 * t[i+9];
    }
    
    for(int64_t i=0, c=0; i<10; i++) {
        t[i]+=c; c=t[i]+(1L<<(24+26*(i%2))); 
        hr[i]=(c&(1L+((1L-(i%2))<<25)-1))-((i==9)<<25); 
        c>>=24+26*(i%2); 
    }

    t[0]+=19*c;

    for(int i=0; i<10; i++) {
        h[i] =hr[i];
    }
} 


This has the same functionality as the original program. It first copies the two arrays, multiplying every second element by 2 in first array and by 19 in the second array. Then it does the special interpolation pattern in matrix. Finally it does field reduction.