Assuming your original functionality is to print a formatted error message to stderr, here's a variant that logs the message in a file as well as maintaining its original functionality:


#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <error.h>

void diagnose (int errnum, char const *fmt, ...) {
    if (0 < progress_len){
        fputc ('\n', stderr);
        progress_len = 0;
    }

    va_list ap;
    va_start (ap, fmt);

    FILE *logFile;
    logFile = fopen("logFile.txt","a");
    if(logFile == NULL){
        fprintf(stderr,"Opening logFile.txt failed.\n");
        return;
    }

    vfprintf(logFile, fmt, ap);
    fprintf(logFile,"\n");
    fclose(logFile);
  
    verror (0, errnum, fmt, ap);
    va_end (ap);
}

This variant will additionally log the same message into a file (named `logFile.txt`) in the current directory, along with sending the message to stderr. Do include needed libraries, the modified function returns nothing and takes an integer error number along with a list of other, - format specifier, - variable number of parameters to specify the error.