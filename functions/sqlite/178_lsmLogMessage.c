void lsmLogMessage(lsm_db *pDb, int rc, const char *zFormat, ...){
  if( pDb->xLog ){
    LsmString s;
    va_list ap, ap2;
    lsmStringInit(&s, pDb->pEnv);
    va_start(ap, zFormat);
    va_start(ap2, zFormat);
    lsmStringVAppendf(&s, zFormat, ap, ap2);
    va_end(ap);
    va_end(ap2);
    pDb->xLog(pDb->pLogCtx, rc, s.z);
    lsmStringClear(&s);
  }
}