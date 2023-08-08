Here's a variant of the function that maintains the original functionality but changes some minor aspects of the function, such as early return and inverse their condition when calling "prep_non_filename_text()":


void put_indicator(const struct bin_str* ind) {
     // Early return in case the color has already been used
    if(used_color) {
      fwrite(ind->string, ind->len, 1, stdout);
      return;
    }
    
    used_color = true;

    if(tcgetpgrp(STDOUT_FILENO) < 0) {
        /* If the standard output is a controlling terminal, watch out"
               for signals, so that the colors can be restored to the
               default state if "ls" is suspended or interrupted." */
        signal_init();
    } 
    else {
        prep_non_filename_text();
     }

    fwrite(ind->string, ind->len, 1, stdout);
}
