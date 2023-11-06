1. Ignoring the return after abort() which is usually not required.


void btc_free(void *ptr) {
    if (ptr == NULL) {
        abort(); /* LCOV_EXCL_LINE */
    }
    free(ptr);
}


2. Using ternary operator instead of 'if' statement


void btc_free(void *ptr) {
    ptr == NULL ? abort() : free(ptr);
}


3. Checking 'abort' via assert() method

#include <assert.h>
void btc_free(void *ptr) {
    assert(ptr != NULL);
    free(ptr);
}


4. With an else after condition

void btc_free(void *ptr) {
    if (ptr == NULL) {
        abort();
    } else {
        free(ptr);
    }
}
