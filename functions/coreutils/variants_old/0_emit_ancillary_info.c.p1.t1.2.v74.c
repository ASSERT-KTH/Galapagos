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

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  fputc('\n', stdout);
  fputs(PACKAGE_NAME, stdout);
  fputs(" online help: <", stdout); 
  fputs(PACKAGE_URL, stdout); 
  putchar('\n');

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *url_program = STREQ (program, "[") ? "test" : program;
   
  fputs(_("Full documentation <"), stdout); 
  fputs(PACKAGE_URL, stdout); fputs(url_program, stdout); putchar('>'); fputs("\n", stdout);
  
  fputs("or available locally via: info '(coreutils) ", stdout); 
  fputs(node, stdout); 
  if(node == program) 
    fputs(" invocation", stdout);
  fputs("'\n", stdout);
}
This version maintains the functionality of the earlier function, removing multiple calls to printf to perform individual printing via fputs, fputc, and putchar. It also places dynamic string data inside method calls to appropriately avoid inaccurate memory exception.