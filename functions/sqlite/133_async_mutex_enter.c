static void async_mutex_enter(int eMutex){
  assert( eMutex==0 || eMutex==1 || eMutex==2 );
  assert( eMutex!=2 || (!mutex_held(0) && !mutex_held(1) && !mutex_held(2)) );
  assert( eMutex!=1 || (!mutex_held(0) && !mutex_held(1)) );
  assert( eMutex!=0 || (!mutex_held(0)) );
  pthread_mutex_lock(&primitives.aMutex[eMutex]);
  TESTONLY( primitives.aHolder[eMutex] = pthread_self(); )
}