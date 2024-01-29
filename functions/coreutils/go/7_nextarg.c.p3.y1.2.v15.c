func nextarg(str string, args *string) bool {
     if args == nil {
         return false
     } else {
         r := (*args == str)
         if r {
           *args = (*args)[len((*args))+1:]
         }

         return r
     }
 }