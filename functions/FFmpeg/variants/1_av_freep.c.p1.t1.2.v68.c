Here is a variant of the original C function. Instead of using memcpy to fetch the content of the argument, it just uses direct assignment. After free, it directly sets the value of the argument to NULL. Assert function usage for extra precaution in case NULL assignment fails.
 

#include <assert.h>

void av_freep(void **arg)
{
    void *val;

    val = *arg;
    *arg = NULL;
    av_free(val);

    assert(*arg == NULL);
}

In this version, it's necessary to change the function argument from "void *" to "void **". Because to directly modify the pointer in C, we need to pass the address of the argument to the function. Please note that "assert" will not alter the functionality but will stop altogether if failed. The output will be only given when the assignments of `NULL` fail.

The original function is also not perfectly safe, it is invoking undefined behavior by creating a tmp object with `&(void *){ NULL }` and use it later after it's technically already out of scope or using memcpy on a non-POD `void *`, which again, is undefined behavior. However, your project requirement or scenario can have an influence over which practice to adopt.
According to the basic principles of C programming, a clean way to free memory and then set it to NULL, you should correct this function to pass-by-pointer option.

Note: Passing "assert" may cause different behavior when to switch among debug or release versions. Beside, it may presumably produce dissimilar outputs based on difference cases as reason above. Therefore, involving "assert" as a principled habit should be performed under considerations and for particular purposes.