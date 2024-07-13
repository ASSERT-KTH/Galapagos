; ModuleID = '/home/javier/Galapagos/miscompilation/bug-2/function/variants/c/foo_4.bc'
source_filename = "/home/javier/Galapagos/miscompilation/bug-2/function/variants/c/foo_4.c"
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
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  %8 = load i32, ptr %4, align 4
  %9 = load i32, ptr %5, align 4
  %10 = sub nsw i32 %8, %9
  store i32 %10, ptr %6, align 4
  %11 = load i32, ptr %6, align 4
  %12 = icmp slt i32 %11, 10000
  br i1 %12, label %13, label %15

13:                                               ; preds = %2
  %14 = load i32, ptr %4, align 4
  store i32 %14, ptr %3, align 4
  br label %22

15:                                               ; preds = %2
  %16 = load i32, ptr %4, align 4
  %17 = load i32, ptr %4, align 4
  %18 = sub nsw i32 0, %17
  %19 = srem i32 1, %18
  %20 = add nsw i32 %16, %19
  store i32 %20, ptr %7, align 4
  %21 = load i32, ptr %7, align 4
  store i32 %21, ptr %3, align 4
  br label %22

22:                                               ; preds = %15, %13
  %23 = load i32, ptr %3, align 4
  ret i32 %23
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
