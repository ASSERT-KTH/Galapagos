; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/c/1_mix_1.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/variants/c/1_mix_1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @mix(i32 noundef 0, i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @mix(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %c0.addr = alloca i32, align 4
  %c1.addr = alloca i32, align 4
  %blue = alloca i32, align 4
  %green = alloca i32, align 4
  %red = alloca i32, align 4
  store i32 %c0, ptr %c0.addr, align 4
  store i32 %c1, ptr %c1.addr, align 4
  %0 = load i32, ptr %c0.addr, align 4
  %and = and i32 %0, 31
  %1 = load i32, ptr %c0.addr, align 4
  %and1 = and i32 %1, 31
  %add = add nsw i32 1, %and1
  %shl = shl i32 %and, %add
  %2 = load i32, ptr %c1.addr, align 4
  %and2 = and i32 %2, 31
  %add3 = add nsw i32 1, %and2
  %shr = ashr i32 %shl, %add3
  store i32 %shr, ptr %blue, align 4
  %3 = load i32, ptr %c0.addr, align 4
  %and4 = and i32 %3, 992
  %4 = load i32, ptr %c0.addr, align 4
  %and5 = and i32 %4, 992
  %add6 = add nsw i32 1, %and5
  %shl7 = shl i32 %and4, %add6
  %5 = load i32, ptr %c1.addr, align 4
  %and8 = and i32 %5, 992
  %add9 = add nsw i32 1, %and8
  %shr10 = ashr i32 %shl7, %add9
  %shr11 = ashr i32 %shr10, 5
  store i32 %shr11, ptr %green, align 4
  %6 = load i32, ptr %c0.addr, align 4
  %shr12 = ashr i32 %6, 10
  %7 = load i32, ptr %c0.addr, align 4
  %shr13 = ashr i32 %7, 10
  %add14 = add nsw i32 1, %shr13
  %8 = load i32, ptr %c0.addr, align 4
  %shr15 = ashr i32 %8, 11
  %add16 = add nsw i32 %add14, %shr15
  %9 = load i32, ptr %c1.addr, align 4
  %shr17 = ashr i32 %9, 10
  %add18 = add nsw i32 %add16, %shr17
  %shl19 = shl i32 %shr12, %add18
  store i32 %shl19, ptr %red, align 4
  %10 = load i32, ptr %red, align 4
  %div = sdiv i32 %10, 3
  %mul = mul nsw i32 %div, 1024
  %11 = load i32, ptr %green, align 4
  %div20 = sdiv i32 %11, 3
  %mul21 = mul nsw i32 %div20, 32
  %add22 = add nsw i32 %mul, %mul21
  %12 = load i32, ptr %blue, align 4
  %div23 = sdiv i32 %12, 3
  %add24 = add nsw i32 %add22, %div23
  ret i32 %add24
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
