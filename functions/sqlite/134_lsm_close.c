int lsm_close(lsm_db *pDb){
  int rc = LSM_OK;
  if( pDb ){
    assert_db_state(pDb);
    if( pDb->pCsr || pDb->nTransOpen ){
      rc = LSM_MISUSE_BKPT;
    }else{
      lsmMCursorFreeCache(pDb);
      lsmFreeSnapshot(pDb->pEnv, pDb->pClient);
      pDb->pClient = 0;

      assertRwclientLockValue(pDb);

      lsmDbDatabaseRelease(pDb);
      lsmLogClose(pDb);
      lsmFsClose(pDb->pFS);
      /* assert( pDb->mLock==0 ); */
      
      /* Invoke any destructors registered for the compression or 
      ** compression factory callbacks.  */
      if( pDb->factory.xFree ) pDb->factory.xFree(pDb->factory.pCtx);
      if( pDb->compress.xFree ) pDb->compress.xFree(pDb->compress.pCtx);

      lsmFree(pDb->pEnv, pDb->rollback.aArray);
      lsmFree(pDb->pEnv, pDb->aTrans);
      lsmFree(pDb->pEnv, pDb->apShm);
      lsmFree(pDb->pEnv, pDb);
    }
  }
  return rc;
}