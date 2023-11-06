nextarg(char const *str){
  if (!(*args))
        return false;

    if(!strcmp(*args, str)){
        *args += 1;
        return true;
    } else{
        return false;
    }
}