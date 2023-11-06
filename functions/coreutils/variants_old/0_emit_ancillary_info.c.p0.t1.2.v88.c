Here's one alteration that maintains functionality while varying behavior lightly. The variation consists of renaming the matching variable node to pageInfo, for better readability, we also renamed variable map_prog to prog_map that following the consistent programming convention. Here's the transformed version:


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

  char const *pageInfo = program;
  struct infomap const *prog_map = infomap;

  while (prog_map->program && ! STREQ (program, prog_map->program))
    prog_map++;

  if (prog_map->node)
    pageInfo = prog_map->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      /* TRANSLATORS: Note the URL.  */
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;

  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);

  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          pageInfo, pageInfo == program ? " invocation" : "");
}

This variation is straightforward and does not affect original functionality. All references to node are replaced by pageInfo, preserving the function's original behavior. Similarly, all references to map_prog are replaced by prog_map.