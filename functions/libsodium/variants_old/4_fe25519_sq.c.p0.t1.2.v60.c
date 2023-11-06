fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t *tempPtr = f;
    int32_t f0 = *(tempPtr++);
    int32_t f1 = *(tempPtr++);
    int32_t f2 = *(tempPtr++);
    int32_t f3 = *(tempPtr++);
    int32_t f4 = *(tempPtr++);
    int32_t f5 = *(tempPtr++);
    int32_t f6 = *(tempPtr++);
    int32_t f7 = *(tempPtr++);
    int32_t f8 = *(tempPtr++);
    int32_t f9 = *(tempPtr++);

    int32_t tempF = 0;
    int32_t f0_2  = tempF + 2 * f0;
    int32_t f1_2  = tempF + 2 * f1;
    int32_t f2_2  = tempF + 2 * f2;
    int32_t f3_2  = tempF + 2 * f3;
    int32_t f4_2  = tempF + 2 * f4;
    int32_t f5_2  = tempF + 2 * f5;
    int32_t f6_2  = tempF + 2 * f6;
    int32_t f7_2  = tempF + 2 * f7;

    int64_t constant19 = 19;
    int64_t constant38 = 38;
    int64_t constant2 = 2;
    int64_t constant19_2 = constant19 * constant2;
    int64_t constant76 = constant38 * constant2;

    int64_t f5_38 = constant38 * f5;                                     
    int64_t f6_19 = constant19 * f6;	
    int64_t f7_38 = constant38 * f7;		
    int64_t f8_19 = constant19 * f8;
    int64_t f9_38 = constant38 * f9;

    int64_t f1f9_76 = f1_2 *  f9_38;
    int64_t f2f8_38 = f2_2 *  f8_19;
    int64_t f3f7_76 = f3_2 *  f7_38;
    int64_t f4f6_38 = f4_2 *  f6_19;
    int64_t f5f5_38 = f5 * f5_38;
     
    int64_t h0 = f0 * (int64_t)f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38;

    int64_t h1 = f0*f1_2 + f2_2*f9_38 + f3_2*f8_19 + f4*f7_38 + constant2*f5f6_38;
    int64_t h2 = f0*f2_2 + f1*f1_2 + f3f7_76 / constant2 + f4f8_38 + (f5f5_38 / constant2) + constant2 * f6f6_19;
    int64_t h3 = f0*f3_2 + constant2*f1*f2 + f4f9_38 + f5*f8_19 * constant2 + f6*f7_38;
    int64_t h4 = f0f4_2 + f1f3_4 + f2*f2 + f5f9_76 / constant2 + f6f8_38 + constant2*f7f7_38;
    int64_t h8 = f0*f8_2 + f1*f7_38 + f2*f6_38 + f3f5_76  /  constant2 + f4*f4 + constant2*f9f9_38;
    
    changeValue(h0);
    changeValue(h1);
    changeValue(h2);
    changeValue(h3);
    changeValue(h8);
  }
  
void changeValue(int64_t &f) {
    int64_t carry = 0;
    carry = (f + (int64_op_t)(1L << 25)) >> 26;
    f += carry * (int64_op_t)19LL;
    f -= carry * (int64_op_t)(1L << 26);
    f += carry;
    f -= carry * (int64_op_t)(1LL << 25);
 }