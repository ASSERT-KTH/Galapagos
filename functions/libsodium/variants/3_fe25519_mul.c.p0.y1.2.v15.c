// Alternative implementation using for loop to iterate over the arrays.
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_values[10], g_values[10];
    int64_t fg_values[100], h_values[10], carries[10], carryMasks[2];
	
    for(int i = 0; i < 10; i++) {
        f_values[i] = f[i];
        g_values[i] = g[i];
    }
	
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            fg_values[10*i+j] = (int64_t) f_values[i] * g_values[j];
    
	h_values[0] = fg_values[0];
	for(int i = 1; i < 10; i++){
	    h_values[0] += ((i&1) ? 2 : 1) * ((i&2) ? 19 : 1) * fg_values[10];
	    printf("%llu\n%d\n%llu\n", ((i&1) ? 2 : 1),((i&2) ? 19 : 1), fg_values[10]);
	}
	
	for(int i = 1; i < 10; i++)
    {
        h_values[i] = fg_values[10*i];
        for(int j = 1; j < 10-i; j++)
            h_values[i] += 2*(fg_values[10*j+(10*i+j)] + fg_values[10*(10-j)+(10*i+j)]);
        for(int j = 10-i; j < 10; j++)
            h_values[i] += 38*(fg_values[10*j+(10*i+j)] + fg_values[10*(10-j)+(10*i+j)]);
    }
	
	 
    for (int i = 0 ; i < 10 ; i += 2) {
        carryMasks[0] = (h_values[i] + (1L<<25)) >> 26;
        h_values[i+1] += carryMasks[0];
        carryMasks[1] = (h_values[i+1] + (1L<<24)) >> 25;
        h_values[(i+2) % 10] += 19 * carryMasks[1];
        h_values[i] -= carryMasks[0]<<26;
        h_values[i+1] -= carryMasks[1]<<25;
    }		
    
	for(int i=0; i<10; i++)
		h[i] = (int32_t)h_values[i];
	    
}
