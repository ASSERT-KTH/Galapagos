void fe25519_sq(fe25519 h, const fe25519 f)
{
    static const int two = 2;
    static const int ninenteen = 19;
    static const int thirty_eight = 38;
    
    int32_t farr[10];
    int64_t iResult[10];
    int32_t carryarr[10];
    int64_t multArray[45];


    for(int i=0;i<10;++i)  {
        farr[i] = f[i];
    }
    
    farr[0]*=two;
    farr[1]*=two;
    farr[2]*=two;
    farr[3]*=two;
    farr[4]*=two;
    farr[5]*=two;
    farr[6]*=two;
    farr[7]*=two;
  
    farr[5]=f[5]*thirty_eight;
    farr[6]=f[6]*ninenteen;
    farr[7]=f[7]*thirty_eight;
    farr[8]=f[8]*ninenteen;
    farr[9]=f[9]*thirty_eight;

    for(int i=0;i<10;++i){
        for(int j=0;j<=i;++j){
            if(i==j)
              multArray[i*(i+1)/2+j] = farr[i/2]*f[j];
            else
              multArray[i*(i+1)/2+j] = farr[i/2]*farr[j/2];
        }
    }

    farr[1] = farr[1]/two;
    farr[3] = farr[3]/two;
    farr[5] = farr[5]/two;
    farr[7] = farr[7]/two;

    iResult[0] = multArray[0] + multArray[37] + multArray[28] + multArray[2] + multArray[15] + multArray[7];
    iResult[1] = multArray[1] + multArray[38] + multArray[33] + multArray[30] + multArray[27];
    iResult[2] = multArray[3] + multArray[9] + multArray[4] + multArray[2]+multArray[36] + multArray[39] + multArray[22];

    for(int i=0;i<9;++i){
        carryarr[i]=(iResult[i] + ((uint64_t)1<<(24 + (i % 2)))) >> (25 + (i % 2));
        iResult[i] -= carryarr[i]*((uint64_t)1U << (25 + (i % 2)));
        iResult[i+1]+=carryarr[i];

        if(i == 8){
            iResult[0] += carryarr[i]*ninenteen;
        }
    }
    carryarr[9] = (iResult[9] + ((uint64_t)1<<24)) >> 25;
    iResult[9]-=carryarr[9] * ((uint64_t)1<<25);
    iResult[0] += carryarr[9]*ninenteen;
    
    carryarr[0] = (iResult[0] +  ((uint64_t)1<<25)) >> 26; iResult[0] -= carryarr[0]*((uint64_t)1<<26);

    iResult[1] += carryarr[0];
    
    for(int i=0;i<10;++i){
        h[i] = iResult[i];
    }
}