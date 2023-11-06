Variant 1:
This variant introduces the usage of the vfprintf function and it takes away part of the functionality from global variables


#include <stdio.h>
#include <stdarg.h>

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    fprintf(stderr, "%s: ", whoami);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}


Variant 2:
This variant introduces the usage of variable packages utilized inside another structure allowing essentially the same funcationality with a difference in how this functionality is framed

#include <stdarg.h>

typedef struct _err_pack {
    const char* whoami;
    errcode_t code;
    va_list ap;
} err_pack;

void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    err_pack pack;

    va_start(pack.ap, fmt);
    pack.whoami = whoami;
    pack.code = code;
    com_err_va(pack.whoami, pack.code, fmt, pack.ap);
    va_end(pack.ap);
}


Variant 3:
This variant introduces passing of reused arguement reference updates by controlling its state inside the function
   

#include <stdarg.h>

void KRB5_CALLCONV_C com_err(const char *whoami,
                        errcode_t code,
                        const char *fmt, ...)
{
    va_list ap, aq;

    // initialize arg pointer ap
    va_start(ap, fmt);

    // copy aq from the state of ap
    va_copy(aq, ap);

    // call com_err_va with aq and then end the list 
    // before setting it equal to ap which can be used again 
    com_err_va(whoami, code, fmt, aq);
    va_end(aq); 
    com_err_va(whoami, code, fmt, ap);
    
    va_end(ap);
}
