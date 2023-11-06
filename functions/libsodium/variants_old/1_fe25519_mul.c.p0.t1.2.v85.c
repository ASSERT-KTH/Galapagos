fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fi[10];
    int32_t gi[10];

    for (int i = 0; i<10; i++) {
        fi[i] = f[i]
        gi[i] = g[i]);
    }

    int32_t gi19[10] = {0};
    int32_t fi2[10] = {0};

    for (int v = 0; v < 10; v+=2)
    {
       gi19[v+1] = 19*gi[v];
       fi2[v]  = 2*fi[v+1];
    }

    int64_t theseProductResults[2*10]= {0} ; 

    for (int u = 0; u < 10; u++)
    {
       for (int k=0; k<=u + 1; k++)
       {
           if(!(k == u+1 && u%2 == 1))
           {
	           theseProductResults[u]+= fi[k]* (int64_t)((k%2 == 1) ? gi19 [u-k]: gi[u-k] );
           }
           if(!(k == 0 && u%2 == 1))
           {
             theseProductResults[u]+= fi[9 - k]* (int64_t)((k%2 == 0) ? gi19 [9-u+k]: gi[9-u+k] );
           }
       }
    }

   for (int v=10; v < 20; v++)
   {
       theseProductResults[v ] = fi[v -10]* (int64_t) (( (v-10)%2 == 0)? gi19[20 - v]: gi[20 -v]);
   }

    int64_t summations[10]={0};

   for(int z = 9; z >= 1; z-- )
   {
      summations[z] = theseProductResults[z-1] - ((z != 9) ? theseProductResults[z+1]*38 : 0)  + theseProductResults[z+10-1]* (z==9?38: 19)
                      + ((z!=9) ? theseProductResults[z+11]*19: 0);
      if(z <= 5)
      {
         summations[z] = summations[z] + theseProductResults[10 - z] +   ((z<5) ? theseProductResults[9 -z] *2 : 0);
      }
   }

   summations[0] = theseProductResults[4]*19*2 + theseProductResults[5]*38 + theseProductResults[6]*19 + theseProductResults[7]*38;

   for(int z=4;z>=0;z--)
   {
       summations[0] = summations[0] + theseProductResults[z] + ((9 == z)? theseProductResults[z]: theseProductResults[z+1]*38); 
   } 

   int64_t hCarries[10];

   
           calcul_carry_and_reduce(summations,hCarries)

   for(int z=0;z<=10;z++) h[z]  = (int32_t) summations[z]

         
}