The following variant of the function maintains the functionality of the original by grouping similar actions into loops:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fi[10], gi[10];

    for(int i=0; i<10; i++){
        fi[i] = f[i];
        gi[i] = (i % 2) ? g[i]*19 : g[i];
    }

    int64_t fijg[100];

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            fijg[10*i+j] = fi[i]*((i+j)%2 ? (int64_t)2*g[j] : (int64_t)gi[j]);
        }
    }

    int64_t hj[10];
    
    for(int i=0; i<10; i++){
        hj[i] = 0;
        for(int j=0; j<=i; j++){
            if((i-j)>9){
                continue;
            }
            hj[i] += fijg[10*j+(i-j)];
        }
        for(int j=i+1; j<10; j++){
            hj[i] += 38*fijg[10*j+(i+10-j)];
        }
    }

    int64_t carry;
    
    for(int i=0; i<9; i++){
        carry = (hj[i]+(int64_t)(1L<<((26 - (i%2)) - 1))) >> (26 - i%2);
        hj[i+1] += carry;
        hj[i] -= carry*((uint64_t)1L<<(26 - (i%2)));
    }

    carry = (hj[9] + (int64_t)(1L << 24)) >> 25;
    hj[0] += 19 * carry;
    hj[9] -= carry * ((int64_t) 1L << 25);
    carry = (hj[0] + (int64_t)(1L << 25)) >> 26;
    hj[1] += carry;
    hj[0] -= carry*((uint64_t)1L << 26);

    for(int i=0; i<10; i++){
        h[i] = hj[i];
    }
}

Note: This solution assumes that the array type `fe25519` is 10 elements long and simplifies the assignment of the `fi` and `gi` values as well as group all of them in a single loop. The computation of the 10`hj` variables are also simplified into a single loop. Carry propagation is still done in a loop rather point-wise to make the code less redundant.