; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/c/4_val_seg_1.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/variants/c/4_val_seg_1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @val_seg(i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @val_seg(i32 noundef %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  %r = alloca i32, align 4
  store i32 %val, ptr %val.addr, align 4
  store i32 1, ptr %r, align 4
  %0 = load i32, ptr %val.addr, align 4
  %shr = ashr i32 %0, 8
  store i32 %shr, ptr %val.addr, align 4
  %1 = load i32, ptr %val.addr, align 4
  %and = and i32 %1, 240
  %tobool = icmp ne i32 %and, 0
  %2 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 4, i32 0
  %3 = load i32, ptr %r, align 4
  %add = add nsw i32 %3, %cond
  store i32 %add, ptr %r, align 4
  %4 = load i32, ptr %val.addr, align 4
  %and1 = and i32 %4, 240
  %tobool2 = icmp ne i32 %and1, 0
  %5 = zext i1 %tobool2 to i64
  %cond3 = select i1 %tobool2, i32 4, i32 0
  %6 = load i32, ptr %val.addr, align 4
  %shr4 = ashr i32 %6, %cond3
  store i32 %shr4, ptr %val.addr, align 4
  %7 = load i32, ptr %val.addr, align 4
  %and5 = and i32 %7, 12
  %tobool6 = icmp ne i32 %and5, 0
  %8 = zext i1 %tobool6 to i64
  %cond7 = select i1 %tobool6, i32 2, i32 0
  %9 = load i32, ptr %r, align 4
  %add8 = add nsw i32 %9, %cond7
  store i32 %add8, ptr %r, align 4
  %10 = load i32, ptr %val.addr, align 4
  %and9 = and i32 %10, 12
  %tobool10 = icmp ne i32 %and9, 0
  %11 = zext i1 %tobool10 to i64
  %cond11 = select i1 %tobool10, i32 2, i32 0
  %12 = load i32, ptr %val.addr, align 4
  %shr12 = ashr i32 %12, %cond11
  store i32 %shr12, ptr %val.addr, align 4
  %13 = load i32, ptr %val.addr, align 4
  %and13 = and i32 %13, 2
  %tobool14 = icmp ne i32 %and13, 0
  %14 = zext i1 %tobool14 to i64
  %cond15 = select i1 %tobool14, i32 1, i32 0
  %15 = load i32, ptr %r, align 4
  %add16 = add nsw i32 %15, %cond15
  store i32 %add16, ptr %r, align 4
  %16 = load i32, ptr %r, align 4
  ret i32 %16
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
