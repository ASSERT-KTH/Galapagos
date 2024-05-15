static void fatalError(const char *zFormat, ...){
  va_list ap;
  if( g.zTestName[0] ){
    fprintf(stderr, "%s (%s): ", g.zArgv0, g.zTestName);
  }else{
    fprintf(stderr, "%s: ", g.zArgv0);
  }
  va_start(ap, zFormat);
  vfprintf(stderr, zFormat, ap);
  va_end(ap);
  fprintf(stderr, "\n");
  exit(1);
}