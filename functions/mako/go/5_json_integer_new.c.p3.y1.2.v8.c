Note that Go doesn't support casting like C/C++, hence few modifications are done to maintain the original function signature and result. The below code would work assuming data structures "Json_value" and "Json_builder_value" exist:

go
func json_integer_new(integer int64) (*Json_value, error) {

   value := new(Json_value)

   if value == nil {
      return nil, errors.New("allocation failed.")
   }

   value.Is_builder_value = true

   value.Type = json_integer
   value.U.Integer = integer

   return value, nil
}


Also, reconsider using json_int_t to int64 in go version. This is the limitation of re-writing many core level codes in Go, in this case from C. You HAVE TO create the equivalent of the relevant structs, and this may in turn require developing auxiliary or helper structures or functions. A custom error handling is required too, instead of just returning NULL because go either returns error or panic for errors. Therefore, the above code may still require fixtures depending on how original structures look in C.