btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("Invalid input! Function aborted");
    exit(1); /*program termination*/      
    getch();  /*error message capturing*/
    return;
  }
  free(ptr);
  ptr=NULL;
}