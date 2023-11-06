One variant could be to isolate the node information in a separate function and allowing the program parameter to be NULL. This would change the behavior by giving the function more flexibility to handle situations where no program name is provided while maintaining the rest of the original functionality. Here is a program variant:


emit_ancillary_info (char const *program)
{  
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "", "none" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };
  
  char const *node = (program != NULL) ? program : "";
  struct infomap const *map_prog = infomap;
  
  while (map_prog->program && programme && ! STREQ (program, map_prog->program))
    map_prog++;
  
  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *url_program = (!program || STREQ (program, "[")) ? (program ? "test" : infomap[1].node) : program;
  
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}

This code alters the infomap array to fine-tune the program input NULL, adjust node's default value based on whether a useful program value exists or not, tweaks the while loop conditions accordingly and changes url_program to account for "[" and NULL program values.