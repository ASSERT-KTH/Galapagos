
void fe25519_sq(fe25519 h, const fe25519 f)
{
    int i, j, carry0, carry4, carry1, carry5, carry2, carry6, carry3, carry7, carry4b, carry8, carry9;
    int fi, fj;
    int64_t product, h_main[10], h_aux[10];

    for(i = 0; i < 10; i++)
    {
        fi = (i<5) ? f[i] : (i<8) ? 38*f[i] : 19*f[i];
        for(j = 0; j <= i; j++)
        {
            fj = (j<5) ? f[i-j] : (j<8) ? 38*f[i-j] : 19*f[i-j];
            product = (i<=j<<1) ? fi*(int64_t)fj : (int64_t)((fi<<1)*fj);
            h_main[(i+j)%10] += product;
            h_aux[(i+j+1)%10] += product >> ((i+j)%2 ? 25 : 26);
        }
    }

    for(i = 0; i < 10; i++)
    {
        h_main [ i      ] +=     19 * h_aux[(i+9)%10];
        h_main [(i+1)%10] += h_main[i]>>26;
        h_main [ i      ] -= (h_main[i]>>26) <<26;
    }

    carry9 = h_main[9] >> 25; h_main[9] &= 0x1FFFFFF;
    carry0 = h_main[0] + 19 * carry9; 

    h[ 0] = (int32_t)(h_main[0] = ((carry0 =  h_main[0] + carry9 * 19)              & 0x3FFFFFF));
    h[ 1] = (int32_t)(h_main[1] = ((carry1 = (h_main[1] + (carry0 >> 26))           & 0x1FFFFFF)));
    h[ 2] = (int32_t)(h_main[2] = ((carry2 =  h_main[2] + ((h_main[1] = carry1) >> 25))  & 0x3FFFFFF));
    h[ 3] = (int32_t)(h_main[3] = ((carry3 = (h_main[3] + (carry2 >> 26))           & 0x1FFFFFF)));
    h[ 4] = (int32_t)(h_main[4] = ((carry4 =  h_main[4] + ((h_main[3] = carry3) >> 25))  & 0x3FFFFFF));
    h[ 5] = (int32_t)(h_main[5] = ((carry5 = (h_main[5] + (carry4 >> 26))           & 0x1FFFFFF)));
    h[ 6] = (int32_t)(h_main[6] = ((carry6 =  h_main[6] + ((h_main[5] = carry5) >> 25))  & 0x3FFFFFF));
    h[ 7] = (int32_t)(h_main[7] = ((carry7 = (h_main[7] + (carry6 >> 26))           & 0x1FFFFFF)));
    h[ 8] = (int32_t)(h_main[8] = ((carry8 =  h_main[8] + ((h_main[7] = carry7) >> 25))  & 0x3FFFFFF));
    h[ 9] = (int32_t)(h_main[9] =    h_main[9] + (carry8 >> 26));
}
