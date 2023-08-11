1. Varied error section output string:

emit_ancillary_info (char const *program)
{
 ...
 
 /* URL for error reporting, modified output message string */
 if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Please report any translation inaccuracies to the following link: "
               "<https://translationproject.org/team/>\n"), stdout);
    }
...
}


2: Replace fputs with printf and added functionality to display name of language code with potential error:


emit_ancillary_info (char const *program)
{
 ...
 
 if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      printf (_("Report translation errors for '%s' at: "
               "<https://translationproject.org/team/>\n"), lc_messages);
    }

...
}


3: Add feedback towards behavior of different shell interpreters towards ["test", "["] strings:


emit_ancillary_info (char const *program)
{
 ...
 
 /* Add differentiation between shell interpreters */
 char const *url_program = (STREQ (program, "[") 
                            ? "test (note that some shell interpreters may handle differently)" 
                            : program);
                            
 ...
}


4: Simplify node assignment:


emit_ancillary_info (char const *program)
{
 ...
 
 /* Simplify node assignment */
 node = (map_prog->node ? map_prog->node : program);
        
 ...   
}
