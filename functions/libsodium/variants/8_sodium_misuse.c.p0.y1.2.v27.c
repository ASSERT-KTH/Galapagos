void sodium_misuse(void)
{
   void (*functionPointer)(void);

   (void) sodium_crit_leave();
   
   if (!sodium_crit_enter()) {
       functionPointer = _misuse_handler;
       if (functionPointer) {
           (*functionPointer)();
       }   
   }
/* LCOV_EXCL_START */
   abort();
}