void put_indicator (const struct bin_str *ind)
{
    static bool isInitialized = false; 

    if (! isInitialized)
    {
        isInitialized = true;

        if (0 <= tcgetpgrp (STDOUT_FILENO))
            signal_init ();

        prep_non_filename_text ();
    }

   fwrite (ind->string, ind->len, 1, stdout);
}