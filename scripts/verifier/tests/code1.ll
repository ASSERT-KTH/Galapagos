define i32 @f(i32 %a, i32 %b) {
  %add = add nsw i32 %b, %a
  ret i32 %add
}