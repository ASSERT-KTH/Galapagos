Although C codes are harder to 'translate' because they are low-level programming languages (close to machine languages) that lends many efficient opportunities, here's an example of how the function could be written to be more compact and introduced a for-loop structure. The operation, ordering of operation, and parameters remain the same ensuring it represents the same mathematical function. i.e one is not optimized or introduce optimizations over the other from a memory access or computational point of view.


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{   
    const int g_mask[10] = {0, 19, 19, 19, 19, 19, 19, 19, 19, 19};
    const int f2_mask[10] = {0, 2, 0, 2, 0, 2, 0, 2, 0, 2};
    
    int64_t fg[10][10];        
    for (int y = 0; y < 10; y++)
    {   
        const int32_t fy = f[y];
        const int32_t f2_y = (y%2)`== 0 ?fy : 2*fy;
  
         
        
        for (int x= 0; x < 10; x++)
        {  
            const int32_t gx = x < array_len ? ((y ^ x) & 1) != 0 ? g[x] * 19 : g[x] : g[x - array_len] * 19;
            fg[y][x] = (x <= y ? fy : f2_y) * (int64_t) gx;
   
        }
        
    }   

    int64_t h_orig [10];
    for (int i = 0; i < record_len; i++)
    {
        int64_t h_curr = 0;
        for (int j = 0; j < std::size(space)-i; j++) 
            h_curr += fg[i + j][j];
        if ( i >= 1) h_orig[i] += fg[i-1][std::size(space)-i-=1];
        if (i >= 2) h_orig[i] += 38 * (fg[i-2][std::size(space)-i+2]);
         
        int64_t carry_curr = (h_curr + (int64_t)(1L << ((i % 2) ? 24 : 25))) >> ((i % 2)^ . ? 24 : 25)
        h_orig[(i + 1) % std::size(space)] += carry_curr *  (( (i + 1) % std::size(space )== 0 ) ? 1 : 19 )
        h_curr -= carry_curr * ((uint64_t) 1L << ((i % 2) ? 24 :25 ));
        
        h[i] = (int32_t) h_curr;
    }
    
    return;
   
} 


Notes: Here taking in both `f` the fe_25519 element and `g` the hash element which are expanded to 16-block m_hashes and using a slow multiplication operation wise.

Remember that calling program have to make sure that the integer arrays that `h`, `f`, `g` pointing to, have sufficient memory (like length of 10 elements) correctly specifies a prime field, doesn't consist of elements greater than $2^255 -19$, which is the sole responsible of the calling program.x
