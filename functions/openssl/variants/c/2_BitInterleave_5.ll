; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/c/2_BitInterleave_5.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/variants/c/2_BitInterleave_5.c"
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
  %evenBits = alloca i64, align 8
  %oddBits = alloca i64, align 8
  store i64 %Ai, ptr %Ai.addr, align 8
  %0 = load i64, ptr %Ai.addr, align 8
  %and = and i64 %0, 6148914691236517205
  store i64 %and, ptr %evenBits, align 8
  %1 = load i64, ptr %Ai.addr, align 8
  %shr = lshr i64 %1, 1
  %and1 = and i64 %shr, 6148914691236517205
  store i64 %and1, ptr %oddBits, align 8
  %2 = load i64, ptr %evenBits, align 8
  %shr2 = lshr i64 %2, 1
  %3 = load i64, ptr %evenBits, align 8
  %or = or i64 %3, %shr2
  store i64 %or, ptr %evenBits, align 8
  %4 = load i64, ptr %evenBits, align 8
  %and3 = and i64 %4, 3689348814741910323
  store i64 %and3, ptr %evenBits, align 8
  %5 = load i64, ptr %evenBits, align 8
  %shr4 = lshr i64 %5, 2
  %6 = load i64, ptr %evenBits, align 8
  %or5 = or i64 %6, %shr4
  store i64 %or5, ptr %evenBits, align 8
  %7 = load i64, ptr %evenBits, align 8
  %and6 = and i64 %7, 1085102592571150095
  store i64 %and6, ptr %evenBits, align 8
  %8 = load i64, ptr %evenBits, align 8
  %shr7 = lshr i64 %8, 4
  %9 = load i64, ptr %evenBits, align 8
  %or8 = or i64 %9, %shr7
  store i64 %or8, ptr %evenBits, align 8
  %10 = load i64, ptr %evenBits, align 8
  %and9 = and i64 %10, 71777214294589695
  store i64 %and9, ptr %evenBits, align 8
  %11 = load i64, ptr %evenBits, align 8
  %shr10 = lshr i64 %11, 8
  %12 = load i64, ptr %evenBits, align 8
  %or11 = or i64 %12, %shr10
  store i64 %or11, ptr %evenBits, align 8
  %13 = load i64, ptr %evenBits, align 8
  %and12 = and i64 %13, 281470681808895
  store i64 %and12, ptr %evenBits, align 8
  %14 = load i64, ptr %oddBits, align 8
  %shr13 = lshr i64 %14, 1
  %15 = load i64, ptr %oddBits, align 8
  %or14 = or i64 %15, %shr13
  store i64 %or14, ptr %oddBits, align 8
  %16 = load i64, ptr %oddBits, align 8
  %and15 = and i64 %16, 3689348814741910323
  store i64 %and15, ptr %oddBits, align 8
  %17 = load i64, ptr %oddBits, align 8
  %shr16 = lshr i64 %17, 2
  %18 = load i64, ptr %oddBits, align 8
  %or17 = or i64 %18, %shr16
  store i64 %or17, ptr %oddBits, align 8
  %19 = load i64, ptr %oddBits, align 8
  %and18 = and i64 %19, 1085102592571150095
  store i64 %and18, ptr %oddBits, align 8
  %20 = load i64, ptr %oddBits, align 8
  %shr19 = lshr i64 %20, 4
  %21 = load i64, ptr %oddBits, align 8
  %or20 = or i64 %21, %shr19
  store i64 %or20, ptr %oddBits, align 8
  %22 = load i64, ptr %oddBits, align 8
  %and21 = and i64 %22, 71777214294589695
  store i64 %and21, ptr %oddBits, align 8
  %23 = load i64, ptr %oddBits, align 8
  %shr22 = lshr i64 %23, 8
  %24 = load i64, ptr %oddBits, align 8
  %or23 = or i64 %24, %shr22
  store i64 %or23, ptr %oddBits, align 8
  %25 = load i64, ptr %oddBits, align 8
  %and24 = and i64 %25, 281470681808895
  store i64 %and24, ptr %oddBits, align 8
  %26 = load i64, ptr %oddBits, align 8
  %shl = shl i64 %26, 16
  store i64 %shl, ptr %oddBits, align 8
  %27 = load i64, ptr %evenBits, align 8
  %shl25 = shl i64 %27, 16
  %28 = load i64, ptr %oddBits, align 8
  %or26 = or i64 %shl25, %28
  ret i64 %or26
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
