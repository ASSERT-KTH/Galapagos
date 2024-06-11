; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/c/2_BitInterleave_6.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/variants/c/2_BitInterleave_6.c"
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
  %hi = alloca i64, align 8
  %lo = alloca i64, align 8
  store i64 %Ai, ptr %Ai.addr, align 8
  %0 = load i64, ptr %Ai.addr, align 8
  %shr = lshr i64 %0, 32
  %and = and i64 %shr, 4294967295
  store i64 %and, ptr %hi, align 8
  %1 = load i64, ptr %Ai.addr, align 8
  %and1 = and i64 %1, 4294967295
  store i64 %and1, ptr %lo, align 8
  %2 = load i64, ptr %hi, align 8
  %3 = load i64, ptr %hi, align 8
  %shl = shl i64 %3, 16
  %or = or i64 %2, %shl
  %and2 = and i64 %or, 281470681808895
  store i64 %and2, ptr %hi, align 8
  %4 = load i64, ptr %hi, align 8
  %5 = load i64, ptr %hi, align 8
  %shl3 = shl i64 %5, 8
  %or4 = or i64 %4, %shl3
  %and5 = and i64 %or4, 71777214294589695
  store i64 %and5, ptr %hi, align 8
  %6 = load i64, ptr %hi, align 8
  %7 = load i64, ptr %hi, align 8
  %shl6 = shl i64 %7, 4
  %or7 = or i64 %6, %shl6
  %and8 = and i64 %or7, 1085102592571150095
  store i64 %and8, ptr %hi, align 8
  %8 = load i64, ptr %hi, align 8
  %9 = load i64, ptr %hi, align 8
  %shl9 = shl i64 %9, 2
  %or10 = or i64 %8, %shl9
  %and11 = and i64 %or10, 3689348814741910323
  store i64 %and11, ptr %hi, align 8
  %10 = load i64, ptr %hi, align 8
  %11 = load i64, ptr %hi, align 8
  %shl12 = shl i64 %11, 1
  %or13 = or i64 %10, %shl12
  %and14 = and i64 %or13, 6148914691236517205
  store i64 %and14, ptr %hi, align 8
  %12 = load i64, ptr %lo, align 8
  %13 = load i64, ptr %lo, align 8
  %shl15 = shl i64 %13, 16
  %or16 = or i64 %12, %shl15
  %and17 = and i64 %or16, 281470681808895
  store i64 %and17, ptr %lo, align 8
  %14 = load i64, ptr %lo, align 8
  %15 = load i64, ptr %lo, align 8
  %shl18 = shl i64 %15, 8
  %or19 = or i64 %14, %shl18
  %and20 = and i64 %or19, 71777214294589695
  store i64 %and20, ptr %lo, align 8
  %16 = load i64, ptr %lo, align 8
  %17 = load i64, ptr %lo, align 8
  %shl21 = shl i64 %17, 4
  %or22 = or i64 %16, %shl21
  %and23 = and i64 %or22, 1085102592571150095
  store i64 %and23, ptr %lo, align 8
  %18 = load i64, ptr %lo, align 8
  %19 = load i64, ptr %lo, align 8
  %shl24 = shl i64 %19, 2
  %or25 = or i64 %18, %shl24
  %and26 = and i64 %or25, 3689348814741910323
  store i64 %and26, ptr %lo, align 8
  %20 = load i64, ptr %lo, align 8
  %21 = load i64, ptr %lo, align 8
  %shl27 = shl i64 %21, 1
  %or28 = or i64 %20, %shl27
  %and29 = and i64 %or28, 6148914691236517205
  store i64 %and29, ptr %lo, align 8
  %22 = load i64, ptr %hi, align 8
  %shl30 = shl i64 %22, 1
  %23 = load i64, ptr %lo, align 8
  %or31 = or i64 %shl30, %23
  ret i64 %or31
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
