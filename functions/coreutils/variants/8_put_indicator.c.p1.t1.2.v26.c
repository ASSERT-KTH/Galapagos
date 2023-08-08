Here is a program variant that still changes the behaviour while maintaining much of the original functionality. However, the handling of signals and execution of `prep_non_filename_text ()` has been removed and replaced with a simple execution whenever 'used_color' is true.


void put_indicator (const struct bin_str *ind)
{
    if (!used_color)
    {
        used_color = true;
    }

    if (used_color)
    {
        fwrite (ind->string, ind->len, 1, stdout);
    }
}


Please note, this modified variant will only influence "used_color" and execute "fwrite", it does not contain other original features anymore because were cut out intentionally for this variant. If these aspects are critical, they should be preserved.
