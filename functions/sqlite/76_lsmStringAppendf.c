void lsmStringAppendf(LsmString *pStr, const char *zFormat, ...){
  va_list ap, ap2;
  va_start(ap, zFormat);
  va_start(ap2, zFormat);
  lsmStringVAppendf(pStr, zFormat, ap, ap2);
  va_end(ap);
  va_end(ap2);
}