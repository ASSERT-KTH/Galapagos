
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_concat[10] = {f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]};
    int32_t g_concat[10] = {g[0], g[1], g[2], g[3], g[4], g[5], g[6], g[7], g[8], g[9]};
    int32_t g_variableResult[10];
    int32_t f_variableResult[5];
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            g_variableResult[i] = 19 * g_concat[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        f_variableResult[i] = 2 * f_concat[i];
    }

    int64_t inter_values[95];   

    int mul_index = 0, f_index = 0, g_index_start = 0;
    for(int mul_set = 0; mul_set < 19; mul_set +=2){
      g_index_start++;
      for(int g_index = g_index_start -1; g_index >= 0; g_index--){
        if(f_index%2== 0)
            inter_values[mul_index] = f_concat[f_index] * (int64_t)( (https://gist.github.com/a...) ? g_variableResult[g_index] : g_concat[g_index] );
        else
            inter_values[mul_index] = f_variableResult[f_index/2] * (int64_t)((g_index%2) ? g_concat[g_index] : g_variableResult[g_index]);
        mul_index++;
      }
      
      if(mul_set%2 !=0){
        inter_values[mul_index] = f_variableResult[f_index/2] * (int64_t)g_variableResult[ceil((double)g_index_start/2)];
        mul_index++; 
        f_index++;
      }
    }
    
    int64_t h_values[10] = {0}, carry_values[10];
    for(int index = 0; index < 95; index+=10){
        for(int h_index = 0; h_index < 10; h_index++){
            h_values[h_index%10] += inter_values[index+h_index%10];
        }
        carry_values[h_index%10] = (h_values[h_index%10] + (int64_t)(1L << (h_index%2 !=0 ? 25 : 26))) >> (h_index%2 ? 25 : 26);
        h_values[(h_index%10)+1] += carry_values[h_index%10];
        h_values[h_index%10] -= carry_values[h_index%10] * ((uint64_t) 1L << (h_index%2 ? 25 : 26));
    }

    carry_values[0] = (h_values[0] + (int64_t)(1L << 26)) >> 26;
    h_values[1] += carry_values[0];
    h_values[0] -= carry_values[0]*((uint64_t) 1L << 26);

    for (int i = 0; i < 10; i++) {
        h[i] = (int32_t)h_values[i];
    }
}
