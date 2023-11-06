#include <stdbool.h>

void check(int code)
{
    const char* errorMessage;
    if (code != 0)
    {
        errorCode = krb5_get_error_message(context, code);
        std::cerr << errorMessage << std::endl;
        krb5_free_error_message(context, errorMessage);
        exit(EXIT_FAILURE);
    }
}