go
func btc_uint32_read(zp *uint32, xp *[]byte, xn *int) int {
   if *xn < 4 {
      return 0
   }

   *zp = (uint32)((*xp)[0]) |
         (uint32)((*xp)[1]) << 8 |
         (uint32)((*xp)[2]) << 16 |
         (uint32)((*xp)[3]) << 24

   *xp = (*xp)[4:]
   *xn -= 4

   return 1
}
