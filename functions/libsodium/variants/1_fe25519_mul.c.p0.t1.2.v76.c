fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g){   
  int32_t f_[10], g_[10];
  int64_t temp_h[10];

  // Loop Unrolling f,g arrays
  for(unsigned int i=0; i<10; i++){
      f_[i] = f[i];
      g_[i] = g[i];
  }

  f_[1] *= 2;
  f_[3] *= 2;
  f_[5] *= 2;
  f_[7] *= 2;
  f_[9] *= 2;

  g_[1] *= 19;
  g_[2] *= 19;
  g_[3] *= 19;
  g_[4] *= 19;
  g_[5] *= 19;
  g_[6] *= 19;
  g_[7] *= 19;
  g_[8] *= 19;
  g_[9] *= 19;

  
  for(unsigned int i=0; i<10; i++){
    for(unsigned int j=0; j<10; j++){
      temp_h[(i+j)%10] += f_[i] * (int64_t)  g_[j];
    }
  }

  temp_h[1] += temp_h[0] >> 26; temp_h[0] = temp_h[0] & 0x3ffffff;
  temp_h[2] += temp_h[1] >> 25; temp_h[1] = temp_h[1] & 0x1ffffff;
  temp_h[3] += temp_h[2] >> 26; temp_h[2] = temp_h[2] & 0x3ffffff;
  temp_h[4] += temp_h[3] >> 25; temp_h[3] = temp_h[3] & 0x1ffffff;
  temp_h[5] += temp_h[4] >> 26; temp_h[4] = temp_h[4] & 0x3ffffff;
  temp_h[6] += temp_h[5] >> 25; temp_h[5] = temp_h[5] & 0x1ffffff;
  temp_h[7] += temp_h[6] >> 26; temp_h[6] = temp_h[6] & 0x3ffffff; 
  temp_h[8] += temp_h[7] >> 25; temp_h[7] = temp_h[7] & 0x1ffffff;
  temp_h[9] += temp_h[8] >> 26; temp_h[8] = temp_h[8] & 0x3ffffff; 
  temp_h[0] += 19 * (temp_h[9] >> 25); temp_h[9] = temp_h[9] & 0x1ffffff;
  temp_h[1] += temp_h[0] >> 26; temp_h[0] = temp_h[0] & 0x3ffffff;

  // start again
  for(unsigned int u_i=0; u_i<10; u_i++){
      h[u_i] = temp_h[u_i];
  }
}