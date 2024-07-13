; ModuleID = '/home/javier/Galapagos/miscompilation/bug-1/function/variants/c/foo_2.bc'
source_filename = "/home/javier/Galapagos/miscompilation/bug-1/function/variants/c/foo_2.c"
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
  %21 = sext i16 %20 to i32
  %22 = icmp ne i32 %21, 0
  br i1 %22, label %23, label %56

23:                                               ; preds = %13
  %24 = load i64, ptr %5, align 8
  %25 = load i16, ptr %6, align 2
  %26 = sext i16 %25 to i32
  %27 = or i32 %26, 583
  %28 = load i32, ptr %7, align 4
  %29 = or i32 %27, %28
  %30 = zext i32 %29 to i64
  %31 = or i64 %24, %30
  %32 = load i8, ptr %4, align 1
  %33 = sext i8 %32 to i64
  %34 = and i64 %33, 5
  %35 = xor i64 %34, -1
  %36 = load i16, ptr %2, align 2
  %37 = sext i16 %36 to i64
  %38 = sdiv i64 %35, %37
  %39 = xor i64 %38, -1
  %40 = xor i64 %31, %39
  %41 = trunc i64 %40 to i16
  store i16 %41, ptr %3, align 2
  %42 = load i16, ptr %3, align 2
  %43 = zext i16 %42 to i32
  %44 = sub nsw i32 %43, 0
  %45 = sext i32 %44 to i64
  %46 = sub i64 8, %45
  %47 = udiv i64 22, %46
  %48 = trunc i64 %47 to i16
  store i16 %48, ptr @c, align 2
  %49 = load i16, ptr %3, align 2
  %50 = zext i16 %49 to i32
  %51 = icmp sgt i32 %50, 0
  br i1 %51, label %52, label %55

52:                                               ; preds = %23
  %53 = load ptr, ptr @stdout, align 8
  %54 = call i32 @putc(i32 noundef 0, ptr noundef %53)
  br label %55

55:                                               ; preds = %52, %23
  br label %56

56:                                               ; preds = %55, %13
  %57 = load i64, ptr %5, align 8
  %58 = load i16, ptr @c, align 2
  %59 = sext i16 %58 to i64
  %60 = srem i64 %57, %59
  %61 = trunc i64 %60 to i32
  store i32 %61, ptr %8, align 4
  %62 = load i16, ptr %3, align 2
  %63 = zext i16 %62 to i64
  %64 = xor i64 %63, 5
  %65 = trunc i64 %64 to i16
  store i16 %65, ptr %9, align 2
  %66 = load i16, ptr %9, align 2
  %67 = sext i16 %66 to i32
  %68 = icmp ne i32 %67, 0
  br i1 %68, label %69, label %71

69:                                               ; preds = %56
  %70 = load i32, ptr %8, align 4
  store i32 %70, ptr @a, align 4
  br label %71

71:                                               ; preds = %69, %56
  %72 = load i32, ptr @a, align 4
  %73 = icmp ne i32 %72, 0
  br i1 %73, label %74, label %75

74:                                               ; preds = %71
  store i32 0, ptr @a, align 4
  store i32 1, ptr %1, align 4
  br label %76

75:                                               ; preds = %71
  store i32 0, ptr %1, align 4
  br label %76

76:                                               ; preds = %75, %74
  %77 = load i32, ptr %1, align 4
  ret i32 %77
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
