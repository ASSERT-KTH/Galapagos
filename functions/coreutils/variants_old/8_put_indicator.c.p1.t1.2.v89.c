void put_indicator (const struct bin_str *ind)
{
    if (! used_color)
    {
        used_color = 1;
     
        if (0 <= tcgetpgrp (1))
            signal_init ();
        
        prep_non_filename_text ();
    }

    int counter = ind->len;
    char* temp_string = ind->string;
 
    /* Writing the string character by character to the stdout. 
       Segmenting fwrite into byte-sized outputs achieves the same 
       functionality of writing to stdout, while changing how its done */
    while (counter > 0)
    {
       fwrite(temp_string, 1, 1, stdout);
       temp_string++; //Increment pointer.
       counter--;
    }
}