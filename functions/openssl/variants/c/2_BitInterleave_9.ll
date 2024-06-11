; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/c/2_BitInterleave_9.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/variants/c/2_BitInterleave_9.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i64 @BitInterleave(i64 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @BitInterleave(i64 noundef %Ai) #0 {
entry:
  %Ai.addr = alloca i64, align 8
  %x = alloca i64, align 8
  %mask = alloca i64, align 8
  store i64 %Ai, ptr %Ai.addr, align 8
  %0 = load i64, ptr %Ai.addr, align 8
  store i64 %0, ptr %x, align 8
  store i64 6148914691236517205, ptr %mask, align 8
  %1 = load i64, ptr %x, align 8
  %2 = load i64, ptr %x, align 8
  %shl = shl i64 %2, 16
  %or = or i64 %1, %shl
  %3 = load i64, ptr %mask, align 8
  %and = and i64 %or, %3
  store i64 %and, ptr %x, align 8
  %4 = load i64, ptr %x, align 8
  %5 = load i64, ptr %x, align 8
  %shl1 = shl i64 %5, 8
  %or2 = or i64 %4, %shl1
  %and3 = and i64 %or2, 71777214294589695
  store i64 %and3, ptr %x, align 8
  %6 = load i64, ptr %x, align 8
  %7 = load i64, ptr %x, align 8
  %shl4 = shl i64 %7, 4
  %or5 = or i64 %6, %shl4
  %and6 = and i64 %or5, 1085102592571150095
  store i64 %and6, ptr %x, align 8
  %8 = load i64, ptr %x, align 8
  %9 = load i64, ptr %x, align 8
  %shl7 = shl i64 %9, 2
  %or8 = or i64 %8, %shl7
  %and9 = and i64 %or8, 3689348814741910323
  store i64 %and9, ptr %x, align 8
  %10 = load i64, ptr %x, align 8
  %11 = load i64, ptr %x, align 8
  %shl10 = shl i64 %11, 1
  %or11 = or i64 %10, %shl10
  %and12 = and i64 %or11, 6148914691236517205
  store i64 %and12, ptr %x, align 8
  %12 = load i64, ptr %x, align 8
  %13 = load i64, ptr %x, align 8
  %shl13 = shl i64 %13, 1
  %or14 = or i64 %12, %shl13
  ret i64 %or14
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
