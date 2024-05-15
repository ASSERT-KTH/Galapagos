int sqlite3_strglob(const char *zGlobPattern, const char *zString){
  if( zString==0 ){
    return zGlobPattern!=0;
  }else if( zGlobPattern==0 ){
    return 1;
  }else {
    return patternCompare((u8*)zGlobPattern, (u8*)zString, &globInfo, '[');
  }
}