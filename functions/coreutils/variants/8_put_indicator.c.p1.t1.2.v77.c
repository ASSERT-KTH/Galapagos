void put_indicator (const struct bin_str *ind)
{
    static int first_call_flag = 0; 

    if (first_call_flag == 0) 
    {
        used_color = true;
      
        if (0 <= tcgetpgrp (STDOUT_FILENO)) 
            signal_init ();
  
        prep_non_filename_text ();
        
        first_call_flag = 1;
    }
    
    fwrite (ind->string, ind->len, 1, stdout);
}