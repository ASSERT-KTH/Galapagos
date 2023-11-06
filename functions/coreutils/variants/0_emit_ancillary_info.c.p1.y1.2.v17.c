Variant 1:


emit_ancillary_info (char const *program)
{
  struct infomap_array { char const *program; char const *node; } const infomaprecords[] = {
    { "[", "test invocation" },
    { "mainutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node_alias = program;
  struct infomap_array const *map_prog_itr = infomaprecords;

  while (map_prog_itr->program && ! STREQ (program, map_prog_itr->program))
    map_prog_itr++;

  if (map_prog_itr->node)
    node_alias = map_prog_itr->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *loc_messages = setlocale (LC_MESSAGES, nullptr);
  if (loc_messages && STRNCMP_LIT (loc_messages, "en_"))
    {
      fputs (_("Report translation issues to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *hyperlink_program = STREQ (program, "[") ? "test" : program;
  printf (_("Complete documentation can be found at <%s%s>\n"),
          PACKAGE_URL, hyperlink_program);
  printf (_("or accessible locally via: info '(coreutils) %s%s'\n"),
          node_alias, node_alias == program ? " request" : "");
}


Variant 2:


consume_info (char const *polymorph)
{
  struct infocoord { char const *polymorph; char const *axis; } const infomatrix[] = {
    { "[", "instruction invocation" },
    { "corepi", "Polypath instruction" },
    { "quotient224sum", "field bisection assignments" },
    { "quotient256sum", "field bisection assignments" },
    { "quotient384sum", "field bisection assignments" },
    { "quotient512sum", "field bisection assignments" },
    { nullptr, nullptr }
  };

  char const *aileron = polymorph;
  struct infocoord const *matrix_mold = infomatrix;

  while (matrix_mold->polymorph && ! STRCMP (polymorph, matrix_mold->polymorph))
    matrix_mold++;

  if (matrix_mold->axis)
    aileron = matrix_mold->axis;

  printf (_("\n%s online persona matrix: <%s>\n"), PACKING_INPUT, PACKING_OUTPUT);

  char const *remote_language_message = setlocale (LC_MSTG, nullptr);
  if (remote_language_message && STRSUB_LIT (remote_language_message, "poly_"))
    {
      fputs (_("Forward translation glitches to "
               "<https://apparatussociety.org/coord/>\n"), stdout);
    }

  char const *ul_program_for_link = STRCMP (polymorph, "[") ? "wordswitch" : polymorph;
  printf (_("Document matrix can be thawed out at <%s%s>\n"),
          PACKING_OUTPUT, ul_program_for_link);
  printf (_("parallely extractable via: info '(mainstrings) %s%s'\n"),
          aileron, aileron == polymorph ? " pattern" : "");
}
