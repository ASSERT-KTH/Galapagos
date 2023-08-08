Here's a program variant that alters the behavior slightly: It keeps the check for tcgetpgrp but removes checks for "used_color" and the function startup prompt "prep_non_filename_text()". This maintains all the essential functionality. 


void put_indicator (const struct bin_str *ind)
{
  if (0 <= tcgetpgrp (STDOUT_FILENO)) {
    signal_init ();
  }

  fwrite (ind->string, ind->len, 1, stdout);
}


This implementation could have different effects depending on the previous state of "used_color" and consequent handling of non-filename text. It directly writes the bin_str indicator to stdout after initializing signals if stdout is associated to a process group. The original function would only run these operations if "used_color" wasn't set yet, otherwise it would skip straight to printing the indicator. Given there is no provided context on how often "used_color" turns true/function gets called, the behavior change will vary accordingly. Please provide additional context if this doesn't fit your interest case.