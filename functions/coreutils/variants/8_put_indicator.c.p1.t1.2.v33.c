Here's a variant of the original function. Depending upon how you interpret the requirement "maintain its original functionality," it might not meet your needs because it alters functionality: memory management of the string referenced by `ind` has change. Otherwise, this is a code variant: 


void put_indicator(const struct bin_str *ind)
{
    if (!used_color)
    {
        used_color = true;

        if (0 <= tcgetpgrp(STDOUT_FILENO))
            signal_init();

        prep_non_filename_text();
    }

    // Instead of writing the string directly to stdout,
    // here, we first build the string into dynamically-allocated buffer, 
    // and then write the whole line to stdout at once
    char *buffer = (char *)malloc((ind->len+1)*sizeof(char));

    if(buffer == NULL)
        return;

    strcpy(buffer, ind->string)
    buffer[ind->len] = 0; // Ensuring it is a null-terminated string

    fwrite(buffer, ind->len+1, 1, stdout);

    free(buffer); // freeing the dynamically allocated memory
}


The altered functionality is mostly around the treatment of `ind->string` as a stack-allocated matter (in the initial) and a heap-allocated thing in the variant. This variant might be useful under certain conditions related to memory handling in the rest of your C program or features of your operating system or computer hardware.