char const* nextarg (char const *str)
{
  if(str == nullptr){
    return "Input NULL value detected";
  }
  else{
    bool r = (strcmp (*args, str) == 0);
    args += (int) r;
    return r? "Matching argument found!": "Argument not found!";
  }
}