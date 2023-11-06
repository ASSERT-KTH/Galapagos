void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fvalues[10];
    int64_t temp[45];

    for(int i=0;i<10;i++){
        fvalues[i] = f[i];
    }

    for(int i=0, k=0;i<10;i++){
        for(int j=i;j<10;j++, k++){
            temp[k] = (i==j)?(int64_t)fvalues[i]*fvalues[i]:(2*(int64_t)fvalues[i]*fvalues[j]);    
        }
    }

    int mulVal[] = {1,19,1,19,2,19,2,19,2,38...};
    int arIndexForh[] = {0,9,7,5,3,1,4,1,6,3,8,5,0,3,6,7,4,1,4,7,2,5,0,5,8,3,6,1,5,0,2,6,8,4,0,7,2,5,8};
    int64_t sumForH[10] = {0};
    for(int idx=0, i=0; idx<38; idx+=3, i++){
      sumForH[arIndexForh[i]] += temp[idx] * mulVal[idx] + temp[idx+1] * mulVal[idx+1] + 
                                  (int64_t)fvalues[(i%5)+5]*mulVal[9-i%5]; 
    }
    for(int64_t carry, i = 0; i<10;i++){
           carry = (sumForH[i] + (int64_t)(1 << (25+ i%2)))>> (26 - i%2);
          sumForH[(i+1)%10] += carry;
          sumForH[i] -= carry << (26 - i%2);
          if(i==9){
            sumForH[0] += 19*carry;
          }
       }
    for(int i = 0;i<10; i++)
      h[i] = (int)sumForH[i];
}