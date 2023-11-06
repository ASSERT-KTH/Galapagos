fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t a = f[0];
    int32_t b = f[1];
    int32_t c = f[2];
    int32_t d = f[3];
    int32_t e = f[4];
    int32_t j = f[5];
    int32_t k = f[6];
    int32_t l = f[7];
    int32_t m = f[8];
    int32_t n = f[9];

    int32_t a_2  = 2 * a;
    int32_t b_2  = 2 * b;
    int32_t c_2  = 2 * c;
    int32_t d_2  = 2 * d;
    int32_t e_2  = 2 * e;
    int32_t j_2  = 2 * j;
    int32_t k_2  = 2 * k;
    int32_t l_2  = 2 * l;
    int32_t j_38 = 19 * j;
    int32_t k_38 = 19 * k; 
    int32_t l_38 = 19 * l; 
    int32_t m_38 = 19 * m; 
    int32_t n_38 = 19 * n; 

    int64_t a_a    = a * (int64_t) a;
    int64_t a_b_2  = a_2 * (int64_t) b;
    int64_t a_c_2  = a_2 * (int64_t) c;
    int64_t a_d_2  = a_2 * (int64_t) d;
    int64_t a_e_2  = a_2 * (int64_t) e;
    int64_t a_j_2  = a_2 * (int64_t) j;
    int64_t a_k_2  = a_2 * (int64_t) k;
    int64_t a_l_2  = a_2 * (int64_t) l;
    int64_t a_m_2  = a_2 * (int64_t) m;
    int64_t a_n_2  = a_2 * (int64_t) n;
    int64_t b_b_2  = b_2 * (int64_t) b;
    int64_t b_c_2  = b_2 * (int64_t) c;
    int64_t b_d_4  = b_2 * (int64_t) d_2;
    int64_t b_e_2  = b_2 * (int64_t) e;
    int64_t b_j_2  = b_2 * (int64_t) j_2;
    int64_t b_k_2  = b_2 * (int64_t) k;
    int64_t b_l_4  = b_2 * (int64_t) l_2;
    int64_t b_m_2  = b_2 * (int64_t) m;
    int64_t b_n_4  = b_2 * (int64_t) n_38;
    int64_t c_c    = c * (int64_t) c;
    int64_t c_d_2  = c_2 * (int64_t) d;
    int64_t c_e_2  = c_2 * (int64_t) e;
    int64_t c_j_2  = c_2 * (int64_t) j;
    int64_t c_k_38 = c_2 * (int64_t) k_38;
    int64_t c_l_38 = c * (int64_t) l_38;
    int64_t d_d_2  = d_2 * (int64_t) d;
    int64_t d_e_2  = d_2 * (int64_t) e;
    int64_t d_j_2  = d_2 * (int64_t) j_2;
    int64_t d_k_2  = d_2 * (int64_t) k;
    int64_t d_l_38 = d_2 * (int64_t) l_38;
    int64_t d_m_38 = d_2 * (int64_t) m_38;
    int64_t d_n_38 = d_2 * (int64_t) n_38;
    int64_t e_e    = e * (int64_t) e;
    int64_t e_j_2  = e_2 * (int64_t) j;
    int64_t e_k_2  = e_2 * (int64_t) k_38;
    int64_t e_l_38 = e * (int64_t) l_38;
    int64_t e_m_38 = e_2 * (int64_t) m_38;
    int64_t e_n_38 = e * (int64_t) n_38;
    int64_t j_j_38 = j * (int64_t) j_38;
    int64_t j_k_38 = j_2 * (int64_t) k_38;
    int64_t j_l_76 = j_2 * (int64_t) l_38;
    int64_t j_m_38 = j_2 * (int64_t) m_38;
    int64_t j_n_76 = j_2 * (int64_t) n_38;
    int64_t k_k_38 = k * (int64_t) k_38;
    int64_t k_l_38 = k * (int64_t) l_38;
    int64_t k_m_38 = k_2 * (int64_t) m_38;
    int64_t k_n_38 = k * (int64_t) n_38;
    int64_t l_l_38 = l * (int64_t) l_38;
    int64_t l_m_38 = l_2 * (int64_t) m_38;
    int64_t l_n_38 = l_2 * (int64_t) n_38;
    int64_t m_m_38 = m * (int64_t) m_38;
    int64_t m_n_38 = m * (int64_t) n_38;
    int64_t n_n_38 = n * (int64_t) n_38;

    int64_t t0 = a_a + b_n_4 + c_m_38 + d_l_38 + e_k_2 + j_j_38;
    int64_t t1 = a_b_2 + c_n_38 + d_m_38 + e_l_38 + j_k_2;
    int64_t t2 = a_c_2 + b_b_2 + d_n_4 + e_m_38 + j_l_38 + k_k_38;
    int64_t t3 = a_d_2 + b_c_2 + e_n_38 + j_m_38 + k_l_38;
    int64_t t4 = a_e_2 + b_d_4 + c_c + j_n_4 + k_m_38 + l_l_38;
    int64_t t5 = a_j_2 + b_e_2 + c_d_2 + k_n_38 + l_m_38;
    int64_t t6 = a_k_2 + b_j_2 + c_e_2 + d_d_2 + l_n_38 + m_m_38;
    int64_t t7 = a_l_2 + b_k_2 + c_j_2 + d_e_2 + m_n_38;
    int64_t t8 = a_m_2 + b_l_4 + c_k_2 + d_j_2 + e_e + n_n_38;
    int64_t t9 = a_n_2 + b_m_2 + c_l_2 + d_k_2 + e_j_2;

    int64_t carry[10];

    carry[0] = (t0 + (int64_t) (1<<25)) >> 26;
    t1 += carry[0];
    t0 -= carry[0] << 26;
    carry[4] = (t4 + (int64_t) (1<<25)) >> 26;
    t5 += carry[4];
    t4 -= carry[4] << 26;

    carry[1] = (t1 + (int64_t) (1<<24)) >> 25;
    t2 += carry[1];
    t1 -= carry[1] << 25;
    carry[5] = (t5 + (int64_t) (1<<24)) >> 25;
    t6 += carry[5];
    t5 -= carry[5] << 25;

    carry[2] = (t2 + (int64_t) (1<<25)) >> 26;
    t3 += carry[2];
    t2 -= carry[2] << 26;
    carry[6] = (t6 + (int64_t) (1<<25)) >> 26;
    t7 += carry[6];
    t6 -= carry[6] << 26;

    carry[3] = (t3 + (int64_t) (1<<24)) >> 25;
    t4 += carry[3];
    t3 -= carry[3] << 25;
    carry[7] = (t7 + (int64_t) (1<<24)) >> 25;
    t8 += carry[7];
    t7 -= carry[7] << 25;

    carry[4] = (t4 + (int64_t) (1<<25)) >> 26;
    t5 += carry[4];
    t4 -= carry[4] << 26;
    carry[8] = (t8 + (int64_t) (1<<25)) >> 26;
    t9 += carry[8];
    t8 -= carry[8] << 26;

    carry[9] = (t9 + (int64_t) (1<<24)) >> 25;
    t0 += carry[9] * 19;
    t9 -= carry[9] << 25;
    
    carry[0] = (t0 + (int64_t) (1<<25)) >> 26;
    t1 += carry[0];
    t0 -= carry[0] << 26;
    
    h[0] = (int32_t) t0;
    h[1] = (int32_t) t1;
    h[2] = (int32_t) t2;
    h[3] = (int32_t) t3;
    h[4] = (int32_t) t4;
    h[5] = (int32_t) t5;
    h[6] = (int32_t) t6;
    h[7] = (int32_t) t7;
    h[8] = (int32_t) t8;
    h[9] = (int32_t) t9;
}