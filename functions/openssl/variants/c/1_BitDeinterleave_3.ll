; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/c/1_BitDeinterleave_3.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/variants/c/1_BitDeinterleave_3.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i64 @BitDeinterleave(i64 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @BitDeinterleave(i64 noundef %Ai) #0 {
entry:
  %Ai.addr = alloca i64, align 8
  %lo = alloca i64, align 8
  %hi = alloca i64, align 8
  store i64 %Ai, ptr %Ai.addr, align 8
  %0 = load i64, ptr %Ai.addr, align 8
  %and = and i64 %0, 6148914691236517205
  store i64 %and, ptr %lo, align 8
  %1 = load i64, ptr %Ai.addr, align 8
  %shr = lshr i64 %1, 1
  %and1 = and i64 %shr, 6148914691236517205
  store i64 %and1, ptr %hi, align 8
  %2 = load i64, ptr %lo, align 8
  %3 = load i64, ptr %lo, align 8
  %shr2 = lshr i64 %3, 1
  %or = or i64 %2, %shr2
  %and3 = and i64 %or, 3689348814741910323
  store i64 %and3, ptr %lo, align 8
  %4 = load i64, ptr %lo, align 8
  %5 = load i64, ptr %lo, align 8
  %shr4 = lshr i64 %5, 2
  %or5 = or i64 %4, %shr4
  %and6 = and i64 %or5, 1085102592571150095
  store i64 %and6, ptr %lo, align 8
  %6 = load i64, ptr %lo, align 8
  %7 = load i64, ptr %lo, align 8
  %shr7 = lshr i64 %7, 4
  %or8 = or i64 %6, %shr7
  %and9 = and i64 %or8, 71777214294589695
  store i64 %and9, ptr %lo, align 8
  %8 = load i64, ptr %lo, align 8
  %9 = load i64, ptr %lo, align 8
  %shr10 = lshr i64 %9, 8
  %or11 = or i64 %8, %shr10
  %and12 = and i64 %or11, 281470681808895
  store i64 %and12, ptr %lo, align 8
  %10 = load i64, ptr %lo, align 8
  %11 = load i64, ptr %lo, align 8
  %shr13 = lshr i64 %11, 16
  %or14 = or i64 %10, %shr13
  %and15 = and i64 %or14, 4294967295
  store i64 %and15, ptr %lo, align 8
  %12 = load i64, ptr %hi, align 8
  %13 = load i64, ptr %hi, align 8
  %shr16 = lshr i64 %13, 1
  %or17 = or i64 %12, %shr16
  %and18 = and i64 %or17, 3689348814741910323
  store i64 %and18, ptr %hi, align 8
  %14 = load i64, ptr %hi, align 8
  %15 = load i64, ptr %hi, align 8
  %shr19 = lshr i64 %15, 2
  %or20 = or i64 %14, %shr19
  %and21 = and i64 %or20, 1085102592571150095
  store i64 %and21, ptr %hi, align 8
  %16 = load i64, ptr %hi, align 8
  %17 = load i64, ptr %hi, align 8
  %shr22 = lshr i64 %17, 4
  %or23 = or i64 %16, %shr22
  %and24 = and i64 %or23, 71777214294589695
  store i64 %and24, ptr %hi, align 8
  %18 = load i64, ptr %hi, align 8
  %19 = load i64, ptr %hi, align 8
  %shr25 = lshr i64 %19, 8
  %or26 = or i64 %18, %shr25
  %and27 = and i64 %or26, 281470681808895
  store i64 %and27, ptr %hi, align 8
  %20 = load i64, ptr %hi, align 8
  %21 = load i64, ptr %hi, align 8
  %shr28 = lshr i64 %21, 16
  %or29 = or i64 %20, %shr28
  %and30 = and i64 %or29, 4294967295
  store i64 %and30, ptr %hi, align 8
  %22 = load i64, ptr %hi, align 8
  %shl = shl i64 %22, 32
  %23 = load i64, ptr %lo, align 8
  %or31 = or i64 %shl, %23
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
