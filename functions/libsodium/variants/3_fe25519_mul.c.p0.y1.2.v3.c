Here is another implementation of the function. It first does everything related to f, then g, and then does all the multiprocessing and carrying at once.


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t f_vals[10] , g_vals[10];
    
    for(int i = 0; i < 10; i++)
    {
	f_vals[i] = f[i];
        g_vals[i] = g[i];
    }

    int64_t result [19], multi_result[100];
    memset(result, 0, sizeof(result));
    memset(multi_result, 0, sizeof(multi_result));
   

    for (int i = 0; i < 10; i++)
    {
	for (int j = 0; j < 10; j++) 
        {
            multi_result[i+j] += f_vals[i] * g_vals[j];  
        }
    }
    

    for (int i = 0; i < 9; i++)
    {
	multi_result[i+1] += multi_result[i] >> 26;
        result[i] = multi_result[i] & ((1UL << 26) - 1); 
    }
  
    result[9] = multi_result[9];
    for (int i = 10; i < 19 ; i++)
    {
	result[(i+1)%10] += ((multi_result[i] * 19) >>26);
        result[i%10] += multi_result[i] * 19; 
    }

    result[0] += ((result[9] >> 26) * 19); 
    result[9] &= ((1UL << 26) - 1); 
    result[1] += (result[0] >> 26); 
    result[0] &= ((1UL << 26) - 1); 
  
    for(int i = 0; i < 10 ;i++) 
    {
        h[i] = result[i]; 
    }

}

This way the function follows more of a process where it calculates all the parts to be used and then does an addition loop and then follows that up mixing values. All parts are clear there is one point which is different just for the purpose of differentiating per the request, it uses an additional pass just for additions which is definitely not its risky tick with all the casting