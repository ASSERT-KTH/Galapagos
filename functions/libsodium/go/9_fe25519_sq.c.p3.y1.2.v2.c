Here is the semantically equivalent function of the provided C-function in Go:

go
func fe25519_sq(h *[10]int32, f *[10]int32) {

    f0, f1, f2, f3, f4, f5,f6, f7, f8, f9:=f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9];

    f0_2,  f1_2,  f2_2,  f3_2,  f4_2:=2*f0 ,2*f1 ,2*f2 ,2*f3 ,2*f4;
    f5_2,  f6_2,  f7_2,  f5_38:=2*f5 ,2*f6 ,2*f7 ,38*f5;
    f6_19,  f7_38,  f8_19,  f9_38:=19*f6 ,38*f7 ,19*f8 ,38*f9;

    f0f0,f0f1_2,f0f2_2 ,f0f3_2 ,f0f4_2 :=f0*int64(f0),f0_2*int64(f1),f0_2*int64(f2),f0_2*int64(f3),f0_2*int64(f4);
    f0f5_2,f0f6_2,f0f7_2 ,f0f8_2 ,f0f9_2 :=f0_2*int64(f5),f0_2*int64(f6),f0_2*int64(f7),f0_2*int64(f8),f0_2*int64(f9);
    f1f1_2,f1f2_2,f1f3_4 := f1_2*int64(f1),f1_2*int64(f2),f1_2*int64(f3_2);
    f1f4_2,f1f5_4,f1f6_2 := f1_2*int64(f4),f1_2*int64(f5_2),f1_2*int64(f6);
    f1f7_4,  f1f8_2  ,f1f9_76  :=f1_2*int64(f7_2),f1_2*int64(f8),f1_2*int64(f9_38);
    f2f2   :=f2*int64(f2);
    const1:=int64(1<<25)
    const2:=uint64(1<<26)
    inner0:=int64(const1)
    inner4 :=int64(const1)
  
    carry9 := (h9 + inner1) >> 25; h0 += carry9 * 19; h9 -=  carry9 << 25;
    carry0 := (h0 + inner0) >> 26; h1 += int32(carry0); h0 -= int32(carry0 << 26);
    
  
    for i,_:=range h[:]{
        h[i]=[]int32{h0,h1,h2,h3,h4,h5,h6,h7,h8,h9}[i]
    } 
}
