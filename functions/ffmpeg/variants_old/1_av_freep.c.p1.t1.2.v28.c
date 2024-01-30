Sure, here's an example:


#include <stdlib.h>
#include <string.h>

void av_freep(void **arg)
{
    void *val = *arg;
    *arg = NULL;
    free(val);
}


In this variant, `arg` is declared as a double pointer to void, this allows us to overwrite the original pointer with NULL once the memory it points to has been deallocated. In both implementations we deallocate memory pointed to by pointer in `arg` and also make sure that former pointer don't "dangle", i.e. always points to valid memory or is NULL. But please note, that in the first function, the content that the pointer is pointing to is copied to `void *val` and overwritten with NULL in the same code block, which could potentially cause errors or misconceptions. The variant reduces this risk by dealing with the pointer and automatic variable (`val`) more Ndirectly.`;yet ` also avoids using the possibly confusing **compound literal**, `{NULL}`, to transport the null value. Generally speaking original function better works with characters or bytes, and variant - with chunks of memory as objects. Both implementations, though, maintain the same predicate meaning and could serve as a plain 'free and nullify' function. Different usage patterns depend on the enter hook logic.