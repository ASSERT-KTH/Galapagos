static void vlogLogPrint(
  VLogLog *pLog,                 /* The log file to write into */
  sqlite3_int64 tStart,            /* Start time of system call */
  sqlite3_int64 tElapse,           /* Elapse time of system call */
  const char *zOp,                 /* Type of system call */
  sqlite3_int64 iArg1,             /* First argument */
  sqlite3_int64 iArg2,             /* Second argument */
  const char *zArg3,               /* Third argument */
  int iRes                         /* Result */
){
  char z1[40], z2[40], z3[2000];
  if( pLog==0 ) return;
  if( iArg1>=0 ){
    sqlite3_snprintf(sizeof(z1), z1, "%lld", iArg1);
  }else{
    z1[0] = 0;
  }
  if( iArg2>=0 ){
    sqlite3_snprintf(sizeof(z2), z2, "%lld", iArg2);
  }else{
    z2[0] = 0;
  }
  if( zArg3 ){
    sqlite3_snprintf(sizeof(z3), z3, "\"%.*w\"", sizeof(z3)-4, zArg3);
  }else{
    z3[0] = 0;
  }
  fprintf(pLog->out,"%lld,%lld,%s,%d,%s,%s,%s,%d\n",
      tStart, tElapse, zOp, pLog->zFilename==0, z1, z2, z3, iRes);
}