The change you can do to an implementation does not influence an original function logic flow but makes verbosity by adding status checks to verify internal processes throughout the code.


#include <assert.h>
#include <sodium.h>

void sodium_misuse(void) {
    void (*handler)(void);

    int exit_status = sodium_crit_leave();
    assert(exit_status == 0);

    if (sodium_crit_enter() == 0) {
    
        handler = _misuse_handler;
        
        assert(handler !=NULL);
        
        if (handler != NULL) {
            handler();
        }
    }

/* LCOV_EXCL_START */
    
    abort();
}

In this variant, I have introduced assertion checks, this acts as status or event checks inside your function and if a condition becomes false the `assert()` will stop execution of the program. Here, it runs a check to make sure the `sodium_crit_leave()` and `sodium_crit_enter()` functions and the misuse_handler pointer are all initiated properly and are not null. Compilation Time Assertion would provide development error informatics if uses appropriately with `static_assert( )` statements.