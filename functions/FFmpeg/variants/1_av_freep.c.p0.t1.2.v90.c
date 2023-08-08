void av_freep(void *arg)
{
   void *val;

   memcpy(&val, arg, sizeof(val));
   if(val != NULL)
   {
       memcpy(arg, &(void*){ NULL }, sizeof(val));
       av_free(val);
   }
}