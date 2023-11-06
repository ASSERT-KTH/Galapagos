Variant 1: Inline condition checks.

void emit_ancillary_info (char const *program)
{
  char const *node = program;
  struct infomap const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };
  struct infomap const *map_prog = infomap;

  while (map_prog->program && !STREQ (program, map_prog->program))
    map_prog++;

  if ((map_prog->node) ? node = map_prog->node: node = program);

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && (STRNCMP_LIT (lc_messages, "en_") ? true: false))
     fputs (_("Report any translation bugs to "
                "<https://translationproject.org/team/>\n"), stdout);

   char const *url_program = (STREQ (program, "[") ? "test" : program),
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), 
          node, (node == program ? " invocation" : ""));
}

Variant 2: Remove struct in favor of array element conditional evaluations.
Note: This variant assumes that the array infomap[] elements can be accessed directly by a running numerical index, which fully replicates the mapping of the original 'struct infomap'.

void emit_ancillary_info (char const *program)
{
  char const *node = program;
  char const *infomap[] = {"[", "test invocation", 
                          "coreutils", "Multi-call invocation",
                          "sha224sum", "sha2 utilities", 
                          "sha256sum", "sha2 utilities", 
                          "sha384sum", "sha2 utilities",
                          "sha512sum", "sha2 utilities", 
                           nullptr, nullptr };
  int i = 0; 

 while (infomap[i] && !STREQ (program, infomap[i])) 
	i += 2;// 2 because struct is replaced by array

 if ((infomap[i+1]) ? node = infomap[i+1]: node = program);
  
 printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
 char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
 if(lc_messages && STRNCMP_LIT (lc_messages, "en_"))
   fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
  
 char const *url_program = (STREQ (program, "[") ? "test" : program);
 printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
 printf (_("or available locally via: info '(coreutils) %s%s'\n"),
		 node, (node == program ? " invocation" : ""));
}
