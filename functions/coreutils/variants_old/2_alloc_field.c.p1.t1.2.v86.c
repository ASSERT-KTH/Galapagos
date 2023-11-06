Here's a function variant that checks if the c pointer is set or not before memory reallocation, terminates an application if the input value is out of range and checks if the required field is already used or not prior to that allocation. Thus these additions offer better safety and functionality.


void alloc_field(int f, char const *c) {
  if (c == nullptr) {
    fprintf(stderr,"Quit: Unset pointer*\n");
    exit(1);
  }

  if(f < 0 || f >= sizeof(field_data)/sizeof(field_data[0])) {
    fprintf(stderr, "Quit: Input value is out of range\n");
    exit(2);
  }

  if(field_data[f].used == true) {
    fprintf(stderr, "Quit: Field is already in use\n");
    exit(3);
  }
        
  ncolumns++;
  columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  columns[ncolumns - 1]->caption = c;

  field_data[f].used = true;
}
