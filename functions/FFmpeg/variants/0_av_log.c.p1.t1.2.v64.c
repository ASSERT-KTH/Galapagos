If the function behavior can be changed to include recording or logging of messages, this version involves an additional step - it will write the same log message to a disk file.


#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);

    char *filename = "log.txt"; 
    FILE *file = fopen(filename, "a"); 
    if (file == NULL)
    {
        return;
    }
    
    va_start(vl, fmt);
    vfprintf(file, fmt, vl);
    va_end(vl);  

    fclose(file);
}


Before implementing this example outside a quiz or training context, keep in mind that opening and closing a file every time you log could carry a significant performance penalty. A truly robust logging mechanism should address this issue. In a serious use case, a more appropriate strategy might be to open the file only once and close it when your application quits. Alternatively, use rotating log files or a dedicated lightweight logger process.