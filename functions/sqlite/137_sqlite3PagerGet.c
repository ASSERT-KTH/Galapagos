int sqlite3PagerGet(
  Pager *pPager,      /* The pager open on the database file */
  Pgno pgno,          /* Page number to fetch */
  DbPage **ppPage,    /* Write a pointer to the page here */
  int flags           /* PAGER_GET_XXX flags */
){
#if 0   /* Trace page fetch by setting to 1 */
  int rc;
  printf("PAGE %u\n", pgno);
  fflush(stdout);
  rc = pPager->xGet(pPager, pgno, ppPage, flags);
  if( rc ){ 
    printf("PAGE %u failed with 0x%02x\n", pgno, rc);
    fflush(stdout);
  }
  return rc;
#else
  /* Normal, high-speed version of sqlite3PagerGet() */
  return pPager->xGet(pPager, pgno, ppPage, flags);
#endif
}