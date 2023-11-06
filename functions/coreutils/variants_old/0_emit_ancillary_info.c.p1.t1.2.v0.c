The updated function retains all the original functionality while adding one small piece of additional functionality. 

I have added an additional condition in the loop where it compares 'program' with 'map_prog->program' by converting both to lower case. This enables the function to also recognise inputs where they are matching but case is differing. 

This variation maintains the output format, only checks differently.
We cannot directly take the tolower function or perform the complete map_prog earlier before the program runs. Hence in this example the tolower is applied during the comparison check under a loop which under the scenario performs the same job while string comparison and hence not taking additional Buffer in the memory.

Here, note that we've used the tolower() method which will convert all of inputs passed in a string to lowercase and will then compare the both strings. Hence even if the case differs for the two values, as long as the string name is same, recognizing will be done correctly.


emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && !(!strcasecmp (program, map_prog->program)))
    map_prog++;
  
  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    fputs (_("Report any translation bugs to <https://translationproject.org/team/>\n"), stdout);
    
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}

Here, with ``strcasecmp ()` instead of `STREQ` - it will also make string comparison by converting inputs to lowercase as per conditions. The small performance sacrifice is negligible in consideration of data accuracy.