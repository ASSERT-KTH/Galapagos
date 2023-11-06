Here's a potential solution:


void check(krb5_error_code code)
{
    if (code != 0) {
        const char *msg;
        msg = krb5_get_error_message(ctx, code);
        fputs(msg, stderr);
        fputc('\n', stderr);
        krb5_free_error_message(ctx, msg);
        exit(EXIT_FAILURE);
    }
}


This version largely behaves the same way as the original -- it fetches a Kerberos 5 error message, prints it to standard error, and then exits the program if the initially tested `code` wasn't zero. Instead of using `fprintf` to print out the error message it uses `fputs` and `fputc` to achieve the same end result. 

Note the usage of `exit(EXIT_FAILURE)` since `assert(expression)` is essentially equivalent to `if(!(expression)) exit(EXIT_FAILURE)` causing program termination when expression evaluates false (0). Both of them kill the process immediately (without executing destructors, flushing buffers etc). Non-zero is just the universal "something went wrong" value. In this context, it's the report code for parent process that the program terminated because a requirement was not met ("assertion failed"/"anomaly, quit"/etc.), if made to capture this kind of info. It's cleaner because this will clear all system resources by the operating system.
