Here is a variant that extends the functionality by also matching uppercase program names while, to the best of our understanding based on what's given, still maintaining the original functionality for lowercase program names:


void emit_ancillary_info (char const *program)
{

  struct infomap_upper { char const *program_upper; char const *node; } const infomap_upper[] = {
    { "[", "test invocation" },
    { "COREUTILS", "Multi-call invocation" },
    { "SHA224SUM", "sha2 utilities" },
    { "SHA256SUM", "sha2 utilities" },
    { "SHA384SUM", "sha2 utilities" },
    { "SHA512SUM", "sha2 utilities" },
    { nullptr, nullptr }
};

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;
    
  if (!map_prog->program) {
    struct infomap_upper const *map_prog_upper = infomap_upper;
    while (map_prog_upper->program_upper && ! STREQ_UPPER (program, map_prog_upper->program_upper))
      map_prog_upper++;
       
    if (map_prog_upper->node)
      node = map_prog_upper->node;        
  } 
   
  else if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  /* Don't output this redundant message for English locales.
     Note we still output for 'C' so that it gets included in the man page.  */
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}

In this variant, we added a case-insensitive function STREQ_UPPER to check if the program name matches with the corresponding value in the struct infomap_upper (which contains the uppercase equivalents of the program names). We made these changes assuming that you have the comparable capacity to check case insensitive Equality just as STREQ does for case sensitive. Otherwise, a helper function must be created away from the scope of this question assumptions. 

Please note any omitted auxiliary function like STREQ_UPPER fall out the scope defined by the problem's assumptions. If it does not exist in the original environment where this code would run, this solution might imply the creation of such auxiliary functions for adequate operation.