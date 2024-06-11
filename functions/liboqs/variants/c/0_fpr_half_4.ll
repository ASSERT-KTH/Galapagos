; ModuleID = '/home/javier/Galapagos/functions/liboqs/variants/c/0_fpr_half_4.bc'
source_filename = "/home/javier/Galapagos/functions/liboqs/variants/c/0_fpr_half_4.c"
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
  %shift = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  %0 = load i64, ptr %x.addr, align 8
  %cmp = icmp eq i64 %0, 0
  %1 = zext i1 %cmp to i64
  %cond = select i1 %cmp, i32 0, i32 52
  %conv = sext i32 %cond to i64
  store i64 %conv, ptr %shift, align 8
  %2 = load i64, ptr %x.addr, align 8
  %3 = load i64, ptr %shift, align 8
  %shl = shl i64 1, %3
  %sub = sub i64 %2, %shl
  %4 = load i64, ptr %x.addr, align 8
  %and = and i64 %4, 2047
  %shl1 = shl i64 %and, 52
  %cmp2 = icmp ne i64 %shl1, 0
  %conv3 = zext i1 %cmp2 to i32
  %conv4 = sext i32 %conv3 to i64
  %sub5 = sub i64 %conv4, 1
  %and6 = and i64 %sub, %sub5
  ret i64 %and6
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
