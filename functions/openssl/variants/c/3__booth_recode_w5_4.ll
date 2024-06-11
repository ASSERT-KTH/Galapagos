; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/c/3__booth_recode_w5_4.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/variants/c/3__booth_recode_w5_4.c"
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
  %in.addr = alloca i32, align 4
  %s = alloca i32, align 4
  %d = alloca i32, align 4
  store i32 %in, ptr %in.addr, align 4
  %0 = load i32, ptr %in.addr, align 4
  %shr = lshr i32 %0, 5
  %not = xor i32 %shr, -1
  store i32 %not, ptr %s, align 4
  %1 = load i32, ptr %s, align 4
  %add = add i32 %1, 1
  store i32 %add, ptr %s, align 4
  %2 = load i32, ptr %in.addr, align 4
  %sub = sub i32 62, %2
  store i32 %sub, ptr %d, align 4
  %3 = load i32, ptr %d, align 4
  %or = or i32 %3, 32
  store i32 %or, ptr %d, align 4
  %4 = load i32, ptr %d, align 4
  %5 = load i32, ptr %s, align 4
  %and = and i32 %4, %5
  %6 = load i32, ptr %in.addr, align 4
  %7 = load i32, ptr %s, align 4
  %not1 = xor i32 %7, -1
  %and2 = and i32 %6, %not1
  %or3 = or i32 %and, %and2
  store i32 %or3, ptr %d, align 4
  %8 = load i32, ptr %d, align 4
  %shr4 = lshr i32 %8, 1
  %9 = load i32, ptr %d, align 4
  %and5 = and i32 %9, 1
  %or6 = or i32 %shr4, %and5
  store i32 %or6, ptr %d, align 4
  %10 = load i32, ptr %d, align 4
  %shl = shl i32 %10, 1
  %11 = load i32, ptr %s, align 4
  %and7 = and i32 %11, 1
  %or8 = or i32 %shl, %and7
  ret i32 %or8
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
