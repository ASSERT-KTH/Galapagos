; ModuleID = '/home/javier/Galapagos/miscompilation/bug-1/function/variants/c/foo_9.bc'
source_filename = "/home/javier/Galapagos/miscompilation/bug-1/function/variants/c/foo_9.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@b = dso_local global i16 5, align 2
@a = dso_local global i32 0, align 4
@c = dso_local global i16 0, align 2
@stdout = external global ptr, align 8
@l = dso_local global i16 0, align 2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @foo() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i16, align 2
  %3 = alloca i16, align 2
  %4 = alloca i8, align 1
  %5 = alloca i64, align 8
  %6 = alloca i16, align 2
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i16, align 2
  store i16 -1, ptr %2, align 2
  store i8 25, ptr %4, align 1
  store i64 0, ptr %5, align 8
  %10 = load i32, ptr @a, align 4
  %11 = icmp ne i32 %10, 0
  br i1 %11, label %12, label %13

12:                                               ; preds = %0
  store i64 -1, ptr %5, align 8
  store i8 0, ptr %4, align 1
  br label %13

13:                                               ; preds = %12, %0
  %14 = load i8, ptr %4, align 1
  %15 = sext i8 %14 to i32
  %16 = xor i32 %15, -1
  %17 = trunc i32 %16 to i16
  store i16 %17, ptr %6, align 2
  %18 = load i8, ptr %4, align 1
  %19 = sext i8 %18 to i32
  store i32 %19, ptr %7, align 4
  %20 = load i16, ptr @b, align 2
  %21 = icmp ne i16 %20, 0
  br i1 %21, label %22, label %55

22:                                               ; preds = %13
  %23 = load i64, ptr %5, align 8
  %24 = load i8, ptr %4, align 1
  %25 = sext i8 %24 to i32
  %26 = sub nsw i32 0, %25
  %27 = sext i32 %26 to i64
  %28 = or i64 %23, %27
  %29 = or i64 %28, 583
  %30 = load i32, ptr %7, align 4
  %31 = zext i32 %30 to i64
  %32 = or i64 %29, %31
  %33 = load i8, ptr %4, align 1
  %34 = sext i8 %33 to i64
  %35 = and i64 %34, 5
  %36 = xor i64 %35, -1
  %37 = load i16, ptr %2, align 2
  %38 = sext i16 %37 to i64
  %39 = sdiv i64 %36, %38
  %40 = xor i64 %39, -1
  %41 = xor i64 %32, %40
  %42 = trunc i64 %41 to i16
  store i16 %42, ptr %3, align 2
  %43 = load i16, ptr %3, align 2
  %44 = zext i16 %43 to i64
  %45 = sub i64 8, %44
  %46 = udiv i64 22, %45
  %47 = trunc i64 %46 to i16
  store i16 %47, ptr @c, align 2
  %48 = load i16, ptr %3, align 2
  %49 = zext i16 %48 to i32
  %50 = icmp sgt i32 %49, 0
  br i1 %50, label %51, label %54

51:                                               ; preds = %22
  %52 = load ptr, ptr @stdout, align 8
  %53 = call i32 @putc(i32 noundef 0, ptr noundef %52)
  br label %54

54:                                               ; preds = %51, %22
  br label %55

55:                                               ; preds = %54, %13
  %56 = load i64, ptr %5, align 8
  %57 = load i16, ptr @c, align 2
  %58 = sext i16 %57 to i64
  %59 = srem i64 %56, %58
  %60 = trunc i64 %59 to i32
  store i32 %60, ptr %8, align 4
  %61 = load i16, ptr %3, align 2
  %62 = zext i16 %61 to i64
  %63 = xor i64 %62, 5
  %64 = trunc i64 %63 to i16
  store i16 %64, ptr %9, align 2
  %65 = load i16, ptr %9, align 2
  %66 = icmp ne i16 %65, 0
  br i1 %66, label %67, label %69

67:                                               ; preds = %55
  %68 = load i32, ptr %8, align 4
  store i32 %68, ptr @a, align 4
  br label %69

69:                                               ; preds = %67, %55
  %70 = load i32, ptr @a, align 4
  %71 = icmp ne i32 %70, 0
  br i1 %71, label %72, label %73

72:                                               ; preds = %69
  store i32 0, ptr @a, align 4
  store i32 1, ptr %1, align 4
  br label %74

73:                                               ; preds = %69
  store i32 0, ptr %1, align 4
  br label %74

74:                                               ; preds = %73, %72
  %75 = load i32, ptr %1, align 4
  ret i32 %75
}

declare i32 @putc(i32 noundef, ptr noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = call i32 @foo()
  ret i32 0
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 15.0.7"}
