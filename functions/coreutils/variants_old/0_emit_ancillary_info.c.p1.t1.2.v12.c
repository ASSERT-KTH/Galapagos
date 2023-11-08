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

  for (; map_prog->program; map_prog++)
  {
    if(STREQ (program, map_prog->program))
    {
      node = map_prog->node;
      break;
    }
  }

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && !STRNCMP_LIT (lc_messages, "en_"))
  {
    fputs (_("Report any translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_program = STRCASEEQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
} 

Out of the differences, I used a for loop instead of
++    
while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;
 
 method to search through the program node.
 
 I have used changed the comparison function STREQ to STRCASEEQ which considers the case sensitivity while the previous does not in comparing the program name in char const *url_program = STREQ (program, "[") ? "test" : program; line Providing an extra bit of functionality while maintaining original function behavior.+