; ModuleID = '/home/javier/Galapagos/miscompilation/bug-2/function/variants/c/foo_6.bc'
source_filename = "/home/javier/Galapagos/miscompilation/bug-2/function/variants/c/foo_6.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@b = dso_local global i16 5, align 2
@a = dso_local global i32 0, align 4
@c = dso_local global i16 0, align 2
@l = dso_local global i16 0, align 2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @foo(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  %6 = load i32, ptr %4, align 4
  %7 = load i32, ptr %5, align 4
  %8 = sub nsw i32 %6, %7
  %9 = icmp sge i32 %8, 10000
  br i1 %9, label %10, label %16

10:                                               ; preds = %2
  %11 = load i32, ptr %4, align 4
  %12 = load i32, ptr %4, align 4
  %13 = sub nsw i32 0, %12
  %14 = srem i32 1, %13
  %15 = add nsw i32 %11, %14
  store i32 %15, ptr %3, align 4
  br label %18

16:                                               ; preds = %2
  %17 = load i32, ptr %4, align 4
  store i32 %17, ptr %3, align 4
  br label %18

18:                                               ; preds = %16, %10
  %19 = load i32, ptr %3, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = call i32 @foo(i32 noundef 0, i32 noundef 0)
  ret i32 0
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 15.0.7"}
