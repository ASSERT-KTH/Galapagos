void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; };
  
  struct infomap info_map[] = 
  {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { NULL, NULL }
  };

  char const *node_text = program;
  
  struct infomap const *program_map = info_map;
  while (program_map->program && strcmp (program, program_map->program) != 0)
  {
    program_map++;
  }

  if (program_map->node)
  {
    node_text = program_map->node;
  }
  
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
    
  char const *lc_message = setlocale (LC_MESSAGES, NULL);
  if (lc_message && strncmp (lc_message, "en_", 3))
  {
    fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
  }
  
  char const *updated_program = strcmp (program, "[") == 0 ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, updated_program);
  
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node_text, (node_text==program)?" invocation":"");
}