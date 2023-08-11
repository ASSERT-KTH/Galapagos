Here is a program variant that changes the behavior of original function while maintaining its original functionality:


void av_freep(void **arg)
{
    if(arg && *arg){
       void* temp = *arg;
       *arg = NULL; 
       av_free(temp);
    }
}


This version has some caution to not cause null pointer dereferences but overall, it behaves somewhat similar to original version. This also uses **arg, this variant could avoid memory copy action because it changes the pointer, not the pointee. It assumes that av_free() function is forgiving of null, trying to free a null pointer does not result an error. This makes overall code shorter, easier to read and potentially more efficient.  

Note: every function counts on `av_free` having particular behavior upon passing it `NULL`.