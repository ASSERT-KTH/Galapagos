Here is a program variant that changes the behaviour of the original function while maintaining its original functionality. A condition checking is being added to check if `"["` link program is present in the infomap array. This enhanced version makes sure the final webpage is referencing `"test"` only when there exists an info node for it in the infomap.


void emit_ancillary_info (char const *program)
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

  bool link_present = false;

  while (map_prog->program)
  {
    if (STREQ (program, map_prog->program))
    {
      node = map_prog->node;
      if (STREQ (program, "["))
        link_present = true;
    }
    map_prog++;
  }
    
 
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
    fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
  }
   
  char const *url_program = (STREQ (program, "[") && link_present) ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");

}
 

This variant looks for a specific value "[" in the infomap array during its process. 
If found, it notes it so later once the program names are output to the webpage URL, the produced webpage steers towards "test", which does provide additional insight on the "[" command in documentation. 
This added behavior adds clarity to users relying on it for information. It only happens if infomap contains "test invocation" as the node info for program "[", adhering to the redundancy rule in website mapping.