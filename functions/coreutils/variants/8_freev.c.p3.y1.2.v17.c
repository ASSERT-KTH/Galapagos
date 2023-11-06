As Go language has garbage collector, you generally don't need to explicitly free memory. However, semantically-equivalent version of the function in Go could look like this:

go
func freev(v *Value) {
  if v.Type == "string" {
    // In Go, we don't need to free strings explicitly.
    v.US = ""
  } else {
    // Clear function for big number.
    v.UI = new(big.Int)
  }
  // In Go, we don't need to free structs explicitly.
  v = nil
}

Again, please note that Go cleans up memory automatically, so worrying about freeing memory is not necessary nor advisable in most cases. Go just doesn't give you the fine-grained control over memory that you have in C. If you adopt idiomatic Go practices and avoid creating memory challenges in the first place, you'll typically find that the garbage collector does a great job.