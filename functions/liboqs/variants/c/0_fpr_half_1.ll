; ModuleID = '/home/javier/Galapagos/functions/liboqs/variants/c/0_fpr_half_1.bc'
source_filename = "/home/javier/Galapagos/functions/liboqs/variants/c/0_fpr_half_1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i64 @fpr_half(i64 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @fpr_half(i64 noundef %x) #0 {
entry:
  %x.addr = alloca i64, align 8
  %mask = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  %0 = load i64, ptr %x.addr, align 8
  %tobool = icmp ne i64 %0, 0
  %1 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i64 -1, i64 0
  store i64 %cond, ptr %mask, align 8
  %2 = load i64, ptr %mask, align 8
  %and = and i64 %2, 4503599627370496
  %3 = load i64, ptr %x.addr, align 8
  %sub = sub i64 %3, %and
  store i64 %sub, ptr %x.addr, align 8
  %4 = load i64, ptr %x.addr, align 8
  %shr = lshr i64 %4, 52
  %conv = trunc i64 %shr to i32
  %and1 = and i32 %conv, 2047
  %add = add i32 %and1, 1
  %shr2 = lshr i32 %add, 11
  %conv3 = zext i32 %shr2 to i64
  store i64 %conv3, ptr %mask, align 8
  %5 = load i64, ptr %mask, align 8
  %sub4 = sub i64 %5, 1
  %6 = load i64, ptr %x.addr, align 8
  %and5 = and i64 %6, %sub4
  store i64 %and5, ptr %x.addr, align 8
  %7 = load i64, ptr %x.addr, align 8
  ret i64 %7
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