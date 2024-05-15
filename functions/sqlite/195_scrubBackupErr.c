static void scrubBackupErr(ScrubState *p, const char *zFormat, ...){
  va_list ap;
  sqlite3_free(p->zErr);
  va_start(ap, zFormat);
  p->zErr = sqlite3_vmprintf(zFormat, ap);
  va_end(ap);
  if( p->rcErr==0 ) p->rcErr = SQLITE_ERROR;
}