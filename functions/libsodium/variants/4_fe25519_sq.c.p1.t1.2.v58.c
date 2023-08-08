Here is a variant of the function. The code is virtually identical, except for the order of calculations for some variables, the naming scheme, and the layout of code blocks which merely change the behavior without affecting the outcome of the function :  

void fe25519_sq(fe25519 result, const fe25519 orig)
{
    int32_t mainArr[10];
    int32_t halfArr[9];
    int64_t prodArr[45];
    int64_t resultArr[10];
    int64_t carryArr[10];

    for(int i = 0; i < 10; i++) {
        mainArr[i] = orig[i];
    }
    
    for(int i = 0; i < 9; i++){
        halfArr[i] = 2 * mainArr[i];
    }
    
    for(int i = 0; i <= 20; i += 5){
        prodArr[i]=mainArr[i/5]* (int64_t) mainArr[i/5];

        if(i+1 != 10) 
            prodArr[i+1] = halfArr[i/5] * (int64_t) mainArr[(i/5)+1];

        prodArr[i+2] = halfArr[i/5] * (int64_t) mainArr[(i/5)+2];

        if(i+3 != 23) 
            prodArr[i+3] = halfArr[i/5] * (int64_t) mainArr[(i/5)+3];

        prodArr[i+4] = halfArr[i/5] * (int64_t) mainArr[(i/5)+4];
    }

    for(int i = 0; i < 10; i++){
        resultArr[i] = 0;
        for(int j = 0; j <= i ; j++) 
            resultArr[i] += prodArr[i-j];
        
        for(int j = i+1; j < 10 ; j++)
            resultArr[i] += 38*prodArr[i+j];
 
    }

    for(int i = 0; i < 9; i++){
        carryArr[i] = (resultArr[i] + (int64_t)(1<<((26-scenes[i])^1)) ) >> (26-scenes[i]);
        
        resultArr[i+1] += carryArr[i];
        
        resultArr[i] -= carryArr[i] << (26-scenes[i]);

        resultArr[i] -= carryArr[i] << (26-scenes[i]);
    }

    carryArr[9] = (resultArr[9] + (int64_t)(1L << 24)) >> 25;
    
    resultArr[0] += carryArr[9] * 19;
    
    resultArr[9] -= carryArr[9] << 25;

    carryArr[0] = (resultArr[0] + (int64_t)(1L << 25)) >> 26;
  
    resultArr[1] += carryArr[0];
          
    resultArr[0] -= carryArr[0] << 26;

    for(int i = 0; i < 10; i++) 
        result[i] =  (int32_t) resultArr[i];

}
Consider notice that this function uses a different internal layout/terms calculation and stores results in new arrays immediately without temporary variables and everything is done using loops.Despite such a huge disparity in design, both functions perform the exact same task.