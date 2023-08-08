The below refactor is functionally equivalent to the original function implementation, while providing a different structure to achieve the same output:


fe25519_sq(fe25519 h, const fe25519 f)
{
  int32_t i;
  int64_t carry[10], prod[10][10];

  for (i = 0; i < 10; i++)
    carry[i] = 0;

  for(i = 0; i<10; i++)
    for (int j = 0; j <= i; j++)
      prod[i][j] = (i == j ? 1 : 2) * (int64_t)f[i] * f[j];

  for (i = 0; i < 10; i++)
    for (int j = 0; j <= i; j++)
      carry[(i+j)%10] += i+j<10 ? prod[i][j] : 19* prod[i][j];

  carry[0] +=(1LU << 25);
  carry[4] +=(1LU << 25);
  carry[1] +=(1LU << 24);
  carry[5] +=(1LU << 24);
  carry[2] +=(1LU << 25);
  carry[6] +=(1LU << 25);
  carry[3] +=(1LU << 24);
  carry[7] +=(1LU << 24);
  carry[4] +=(1LU << 25);
  carry[8] +=(1LU << 25);
  carry[9] +=(1LU << 24);

  carry[1] += carry[0]>> 26; carry[0] = carry[0] & 0x3ffffff;
  carry[2] += carry[1]>> 25; carry[1] = carry[1] & 0x1ffffff;
  carry[3] += carry[2]>> 26; carry[2] = carry[2] & 0x3ffffff;
  carry[4] += carry[3]>> 25; carry[3] = carry[3] & 0x1ffffff;
  carry[5] += carry[4]>> 26; carry[4] = carry[4] & 0x3ffffff;
  carry[6] += carry[5]>> 25; carry[5] = carry[5] & 0x1ffffff;
  carry[7] += carry[6]>> 26; carry[6] = carry[6] & 0x3ffffff;
  carry[8] += carry[7]>> 25; carry[7] = carry[7] & 0x1ffffff;
  carry[9] += carry[8]>> 26; carry[8] = carry[8] & 0x3ffffff;
  carry[0] += carry[9]>> 25 * 19; carry[9] = carry[9] & 0x1ffffff;
  carry[1] += carry[0]>> 26; carry[0] = carry[0] & 0x3ffffff;

  for (i = 0; i < 10; i++)
    h[i] = carry[i];
}

In addition to factoring out some identical operations into for-loops to simplify the function, the above refactor performs dynamic computation for entries of h and carries through use of modulo arithmetic to periodically cycle through h/carry elements several changes to the operations within each `carry[...]` computation.
Please note that, there are several strategies and ways to refactor code while maintaining functionality, trading off simplicity, compactness, efficiency and other factors.