void put_indicator (const struct bin_str *ind)
{
    static int lock = 0;
    if (lock == 0)
    {
        lock = 1;
        if (0 <= tcgetpgrp (STDOUT_FILENO))
            signal_init ();

        prep_non_filename_text ();

        lock = 0;
    }

    fwrite (ind->string, ind->len, 1, stdout);
}
   
In this variant, the condition check (! used_color) was replaced by an integer lock mechanism. Creating the lock as a static variable we ensure it is initialized only once and plays a similar role as the used_color variable in the original function. Upon its initialization, lock is 0 (false). The lock is set to 1 (true) when executing the condition within the code block. Later the lock gets reset to 0 after executing. Thus, effectively maintaining it's first trigger / call aspect feature similar to... used_color = true. With this implementation the original functionality including the STDOUT and signal_int is maintained as per original code while utilizing different conditional technique.