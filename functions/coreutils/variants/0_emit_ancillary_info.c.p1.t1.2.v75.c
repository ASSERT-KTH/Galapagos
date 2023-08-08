Here is a variant of the program that maintains the original functionality but alters the behavior. In the below variant, every time the function emit_ancillary_info is called, it always checks each item of infomap until it reaches null. As a result, it potentially impacts the performance if the size infomap is very large. Here, an early return has been introduced when a match is found which improves the performance in certain cases.


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

  while (map_prog->program)
  {
    if (!STREQ (program, map_prog->program))
    {
      map_prog++;
    }
    else
    {
      node = map_prog->node;
      printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

      char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
      if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
      {
        fputs (_("Report any translation bugs to "
                  "<https://translationproject.org/team/>\n"), stdout);
      }

      char const *url_program = STREQ (program, "[") ? "test" : program;
      printf (_("Full documentation <%s%s>\n"),
              PACKAGE_URL, url_program);
      printf (_("or available locally via: info '(coreutils) %s%s'\n"),
              node, node == program ? " invocation" : "");

      return;
    }  
  }
}

In this variant, the function will return once it has found a matching program in the infomap array which, at least in some cases, can save a significant amount of time.