Program Transformation 1:
Change the structure initialization within the same function. This slightly alters the code style and eyeflow.


emit_ancillary_info (char const *program)
{
  struct infomap {
    char const *program;
    char const *node;
  };
  
  struct infomap const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };
  
  /* .... rest of original code .... */
}


Program Transformation 2:
Change the location of url_program variable initialization so that it happens after outputting translation bugs. The flow of code slightly changes but functionality is the same:


emit_ancillary_info (char const *program)
{
  /* .... some part of original code .... */

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

}

