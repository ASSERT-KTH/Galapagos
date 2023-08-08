A variant of the function that changes its behavior albeit keeping the original functionality is given below. On top of the original existence check, the variant function checks length of 'program' argument before iterating through 'infomap' array and then performs a full string comparison instead of strncmp(). 


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

  unsigned long program_length = strlen(program);
    
  while (map_prog->program && ! (strlen(map_prog->program) == program_length && !strcmp (program, map_prog->program)))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  
  if (lc_messages && strcmp (lc_messages, "en") && strcmp(lc_messages, "C"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = !strcmp (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, !strcmp(node, program) ? " invocation" : "");
}

This variant changes how iterations over 'infomap' are carried out to find matching program string and checks on "not English" local setup. These changes keeps the original functionality while inflicting new behavior according to the amendment requirement.