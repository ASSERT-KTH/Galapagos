void emit_ancillary_info (char const *program)
{
  struct infomap_elem { char const *prognm; char const *nodenm; };
  static struct infomap_elem const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { NULL, NULL }
  };

  char const *node = program;
  struct infomap_elem const *infomap_ptr = infomap;

  while (infomap_ptr->prognm && strcmp (program, infomap_ptr->prognm) != 0)
    infomap_ptr++;

  if (infomap_ptr->nodenm != NULL)
    node = infomap_ptr->nodenm;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_msg = setlocale (LC_MESSAGES, NULL);
  if (lc_msg && strncmp (lc_msg, "en_", 3) != 0)
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_abbreviated_program = strcmp (program, "[") == 0 ? "test" : program;
  printf (_("Complete documentation <%s%s>\n"),
           PACKAGE_URL, url_abbreviated_program);
  printf (_("or obtainable offline via: info '(coreutils) %s%s'\n"),
          node, node != program ? "" : " invocation");
}