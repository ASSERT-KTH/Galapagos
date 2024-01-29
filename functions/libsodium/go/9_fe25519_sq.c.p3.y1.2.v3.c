go
func fe25519_sq(h [10]int32, f [10]int32) [10]int32 {
    var f0 int32 = f[0]
    var f1 int32 = f[1]
    var f2 int32 = f[2]
    var f3 int32 = f[3]
    var f4 int32 = f[4]
    var f5 int32 = f[5]
    var f6 int32 = f[6]
    var f7 int32 = f[7]
    var f8 int32 = f[8]
    var f9 int32 = f[9]

    var f0_2  int32 = 2 * f0
    var f1_2  int32 = 2 * f1
    var f2_2  int32 = 2 * f2
    var f3_2  int32 = 2 * f3
    var f4_2  int32 = 2 * f4
    var f5_2  int32 = 2 * f5
    var f6_2  int32 = 2 * f6
    var f7_2  int32 = 2 * f7
    var f5_38 int32 = 38 * f5
    var f6_19 int32 = 19 * f6
    var f7_38 int32 = 38 * f7
    var f8_19 int32 = 19 * f8
    var f9_38 int32 = 38 * f9

    var f0f0    int64 = int64(f0) * int64(f0)
    var f0f1_2  int64 = int64(f0_2) * int64(f1)
    var f0f2_2  int64 = int64(f0_2) * int64(f2)
    var f0f3_2  int64 = int64(f0_2) * int64(f3)
    var f0f4_2  int64 = int64(f0_2) * int64(f4)
    var f0f5_2  int64 = int64(f0_2) * int64(f5)
    var f0f6_2  int64 = int64(f0_2) * int64(f6)
    var f0f7_2  int64 = int64(f0_2) * int64(f7)
    var f0f8_2  int64 = int64(f0_2) * int64(f8)
    var f0f9_2  int64 = int64(f0_2) * int64(f9)
    var f1f1_2  int64 = int64(f1_2) * int64(f1)
    var f1f2_2  int64 = int64(f1_2) * int64(f2)
    var f1f3_4  int64 = int64(f1_2) * int64(f3_2)
    var f1f4_2  int64 = int64(f1_2) * int64(f4)
    var f1f5_4  int64 = int64(f1_2) * int64(f5_2)
    var f1f6_2  int64 = int64(f1_2) * int64(f6)
    var f1f7_4  int64 = int64(f1_2) * int64(f7_2)
    var f1f8_2  int64 = int64(f1_2) * int64(f8)
    var f1f9_76 int64 = int64(f1_2) * int64(f9_38)
    var f2f2    int64 = int64(f2) * int64(f2)
    var f2f3_2  int64 = int64(f2_2) * int64(f3)
    var f2f4_2  int64 = int64(f2_2) * int64(f4)
    var f2f5_2  int64 = int64(f2_2) * int64(f5)
    var f2f6_2  int64 = int64(f2_2) * int64(f6)
    var f2f7_2  int64 = int64(f2_2) * int64(f7)
    var f2f8_38 int64 = int64(f2_2) * int64(f8_19)
    var f2f9_38 int64 = int64(f2) * int64(f9_38)
    var f3f3_2.. .
