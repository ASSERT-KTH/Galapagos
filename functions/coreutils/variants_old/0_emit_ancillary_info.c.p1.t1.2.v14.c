emit_ancillary_info (char const *program)
{
  int loc_flag = 0;
  const char *_loc = setlocale(LC_ALL, "");
  if (_loc != NULL) {
    if (strcmp("C", _loc) != 0 || strcmp("POSIX", _loc) != 0)
      loc_flag = 1;
  }  
    
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  const char *node = program;
  const struct infomap *pInfomap = infomap;
  
  while (pInfomap->program && strcmp(program, pInfomap->program) != 0)
    pInfomap++;
  
  if (pInfomap->node)
    node = pInfomap->node;

  if(loc_flag)
    printf ("\n%s (We do not currently expect users with location not set to English)\n   online help: <%s> \n", PACKAGE_NAME, PACKAGE_URL);
  else
    printf ("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

  if(chunk2(_loc, "en_")){
      fputs("Report any translation bugs to <https://translationproject.org/team/>\n", stdout);
  }

  const char *url_program = strncmp(program, "[", 1) ? program : "test";    
  
  printf("Full documentation <%s%s>\n", PACKAGE_URL, url_program);
  printf ("or available locally via: info '(%s) %s%s'\n", PACKAGE_NAME, node, strcmp(node, program) ? "" : " invocation");
}

int chunk2(const char *str, const char *sub) {
  if(str == NULL || sub == NULL) return 0;
  char *pos = strstr(str, sub);
  if(pos == str) return 1;
  
  while(pos) {
    if(*(pos - 1) == ' ' ){
      return 1;
    }
    pos = strstr(pos + 1, sub);
  }
  
  return 0;
}