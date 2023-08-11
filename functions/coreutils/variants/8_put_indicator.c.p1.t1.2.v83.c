void put_indicator_variant(const struct bin_str *ind)
{
    if (! used_color)
    {
        used_color = true;

        if (0 <= tcgetpgrp (STDOUT_FILENO))
        {
            signal_init ();
        }

        prep_non_filename_text ();
    }

    // Newer program variant that buffers the output in data and flushes it out 
    // once all data is ready to be written
    printf("%s", ind->string); 

    /* Older variant uses fwrite which operates at lower-level and may not provide 
    buffering. The newer variant with printf offers more buffering and could potentially 
    ensure quicker executions in case of large data.
    * Note, however, that both variants may behave differently on different platforms and contexts. 
    * Always consider to thoroughly test any change of such nature in your contexts. */ 
}