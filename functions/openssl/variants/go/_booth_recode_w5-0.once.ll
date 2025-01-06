; ModuleID = '/home/javier/Galapagos/functions/openssl/3__booth_recode_w5.once.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/3__booth_recode_w5.run.once.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @_booth_recode_w5(i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @_booth_recode_w5(i32 noundef %in) #0 {
entry:
  %shr.0 = lshr i32 %in, 5
  %sub.0 = add nsw i32 %shr.0, -1
  %xor.0 = sub nsw i32 0, %shr.0
  %sub.2 = sub i32 63, %in
  %iand.0 = and i32 %sub.2, %xor.0
  %iand.1 = and i32 %sub.0, %in
  %ior.0 = or i32 %iand.1, %iand.0
  %iand.2 = shl i32 %ior.0, 1
  %add.011 = and i32 %iand.2, 2
  %shr.112 = add i32 %add.011, %ior.0
  %shl.0 = and i32 %shr.112, -2
  %iand.3 = and i32 %xor.0, 1
  %add.1 = or i32 %shl.0, %iand.3
  ret i32 %add.1
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 17.0.0 (git@github.com:llvm/llvm-project.git 1a7a00bdc99fa2b2ca19ecd2d1069991b3c1006b)"}
