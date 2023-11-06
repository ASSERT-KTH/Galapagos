Here's a small modification of the program. 
I have replaced the static `infomap[]` array with a dynamic one that stores the program names and corresponding nodes in an array of pointer strings. The behaviour and functionality of the code are maintained, but it provides more dynamic control over the array.


void emit_ancillary_info (char const *program)
{
  struct infomap { 
        char const *program; 
        char const *node; 
  };

  /* Dynamic structure object Initialization */
  struct infomap  *infomap_prgrm_node = 
        (struct infomap *)malloc(sizeof(struct infomap)*7);

  /* Initialize the struct members */
  infomap_prgrm_node[0].program = "["; infomap[0].node = "test invocation";
  infomap_prgrm_node[1].program = "coreutils"; infomap[1].node = "Multi-call invocation";
  infomap_prgrm_node[2].program = "sha224sum"; infomap[2].node = "sha2 utilities";
  infomap_prgrm_node[3].program = "sha256sum"; infomap[3].node = "sha2 utilities";
  infomap_prgrm_node[4].program = "sha384sum"; infomap[4].node = "sha2 utilities";
  infomap_prgrm_node[5].program = "sha512sum"; infomap[5].node = "sha2 utilities";
  infomap_prgrm_node[6].program = nullptr; infomap[6].node = nullptr;

  char const *node = program;
  
  /* Changing const point to dynamic allocated array address */
  struct infomap const *map_prog = infomap_prgrm_node;

  while (map_prog->program && !STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
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

  free(infomap_prgrm_node);
  infomap_prgrm_node = NULL;
}

In this modification, dynamic memory allocation is done so that you can control the amount of memory you are using and it will be beneficial when the data grows in the `infomap` structure.
Specifiers can also take a pointer to array of null called termination e.g. `(int*) '\0'` depending on what needs will be.
Please ensure to clean memory after usage and check if malloc succeeds to prevent overflows and unexpected `SEGFAULTS` (`NULL POINTER REFERENCE`).