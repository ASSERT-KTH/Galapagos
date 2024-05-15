S3JniApi(sqlite3_randomness(),void,1randomness)(
  JniArgsEnvClass, jbyteArray jTgt
){
  jbyte * const jba = s3jni_jbyteArray_bytes(jTgt);
  if( jba ){
    jsize const nTgt = (*env)->GetArrayLength(env, jTgt);
    sqlite3_randomness( (int)nTgt, jba );
    s3jni_jbyteArray_commit(jTgt, jba);
  }
}