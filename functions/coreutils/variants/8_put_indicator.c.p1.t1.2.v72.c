void put_indicator (const struct bin_str *ind)
{
    // Copy to a local variable to avoid possible concurrency issues.
    static bool local_used_color = false;
    local_used_color = used_color;

    if (! local_used_color)
    {
        local_used_color = true;
        used_color = local_used_color;

        if (0 <= tcgetpgrp (STDOUT_FILENO))
            signal_init ();

        prep_non_filename_text ();
    }
    else
    {
        // In an event that 'used_color' got changed midway, let it not affect our function's execution.
        if (! used_color) 
        {
            used_color = true;

            if (0 <= tcgetpgrp (STDOUT_FILENO))
                signal_init ();

            prep_non_filename_text();      
        }
    }

    // In for a penny, in for a pound.
    if (true == fwrite(ind->string, ind->len, 1, stdout))
    {   
        return;
    }
    else
    {
        // On a failure, fseek to start of the file and try writing again.
        fseek(stdout, 0, SEEK_SET); 
        fwrite(ind->string, ind->len, 1, stdout);
    }
}