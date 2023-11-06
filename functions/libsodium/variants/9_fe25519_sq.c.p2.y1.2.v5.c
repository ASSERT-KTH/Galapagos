void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t numbers[10];
    int64_t temp[10];
    for(int i=0; i<10; i++){
       numbers[i]=f[i];
    }

    for(int i=0; i<10; i++){
       if(i<5) //multiplying by 2 for i less than 5
           numbers[i]*=2;
    }

    numbers[5]*=38; numbers[6]*=19; numbers[7]*=38; numbers[8]*=19; numbers[9]*=38;

    for(int i=0; i<10; i++){
        for(int j=i; j<10; j++){
            if(j==i)
                temp[i] = numbers[i]*numbers[i];
            else
                temp[i]= numbers[i]*numbers[j];
        }
    }

    int64_t h_new[10]; 
    h_new[0] = temp[0]+temp[9]*19+temp[8]*2+temp[7]*38+temp[6]*19+(numbers[0]*numbers[0]);
    h_new[1] = temp[0]+temp[9]*19+temp[8]+temp[7]*38+ temp[6]*2;
    h_new[2] = temp[0]*2 + temp[1]*2 + temp[9]*38 + temp[8] + temp[7]*38 + temp[6];
    h_new[3] = temp[0]*2 + temp[1]*2 + temp[9]*19 + temp[8] + temp[6]*38;
    h_new[4] = temp[0]*2 + temp[1]*2 + temp[2] + temp[5]*38 + temp[6]*19 + (numbers[7]*numbers[7]);
    h_new[5] = temp[0]*2 + temp[1]*2 + temp[2]*2 + temp[6]*19 + temp[7]*38;
    h_new[6] = temp[0]*2 + temp[1]+temp[2]*2 + temp[3]*2 + temp[5]*38+ temp[8]*19;
    h_new[7] = temp[0]*2 + temp[1]*2 + temp[2]*2 + temp[3]*2 + temp[8]*19;
    h_new[8] = temp[0]*2 + temp[1]*2 + temp[2]*2 + temp[3]/2 +(numbers[4]*numbers[4]) + temp[9]*38;
    h_new[9] = temp[0]*2 +temp[1]*2 +temp[2]+temp[3]/2 +temp[4]*2;

    int64_t carrying[10] = {};

    for(int i=0; i<9; i++){
        carrying[i] = (h_new[i]+(1L<<((i%2==1)?25:26))) >> ((i%2==1)?25:26);
        if (i < 8) {
            h_new[i+1] += carrying[i];
            h_new[i] -= carrying[i]* (1L << ((i%2==1)?25:26));
        }
        
    }
    h_new[0] += carrying[9]*19;
    h_new[9] -= carrying[9] * (1L << 25);

    carrying[0] = (h_new[0] + (1L << 25)) >> 26;
    h_new[1] += carrying[0];
    h_new[0] -= carrying[0] * (1L << 26);

    for(int i=0;i<10;++i)
        h[i] = h_new[i];
}
