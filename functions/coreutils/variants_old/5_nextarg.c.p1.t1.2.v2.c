char const *nextarg(char const *str){
  if (*args == nullptr) {
    return false;
  }

  bool check;
  if (STREQ (*args, str)) {
    check = true;
    args += 1;
  } else {
    check = false;
  }
  
  return check;
}