; ModuleID = '/home/javier/Galapagos/miscompilation/bug-1/function/variants/c/foo_7.bc'
source_filename = "/home/javier/Galapagos/miscompilation/bug-1/function/variants/c/foo_7.c"
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
  br i1 %21, label %22, label %53

22:                                               ; preds = %13
  %23 = load i64, ptr %5, align 8
  %24 = load i16, ptr %6, align 2
  %25 = sext i16 %24 to i32
  %26 = load i32, ptr %7, align 4
  %27 = or i32 %26, 583
  %28 = or i32 %25, %27
  %29 = zext i32 %28 to i64
  %30 = or i64 %23, %29
  %31 = load i8, ptr %4, align 1
  %32 = sext i8 %31 to i64
  %33 = and i64 %32, 5
  %34 = xor i64 %33, -1
  %35 = load i16, ptr %2, align 2
  %36 = sext i16 %35 to i64
  %37 = sdiv i64 %34, %36
  %38 = xor i64 %37, -1
  %39 = xor i64 %30, %38
  %40 = trunc i64 %39 to i16
  store i16 %40, ptr %3, align 2
  %41 = load i16, ptr %3, align 2
  %42 = zext i16 %41 to i64
  %43 = sub i64 8, %42
  %44 = udiv i64 22, %43
  %45 = trunc i64 %44 to i16
  store i16 %45, ptr @c, align 2
  %46 = load i16, ptr %3, align 2
  %47 = zext i16 %46 to i32
  %48 = icmp sgt i32 %47, 0
  br i1 %48, label %49, label %52

49:                                               ; preds = %22
  %50 = load ptr, ptr @stdout, align 8
  %51 = call i32 @putc(i32 noundef 0, ptr noundef %50)
  br label %52

52:                                               ; preds = %49, %22
  br label %53

53:                                               ; preds = %52, %13
  %54 = load i64, ptr %5, align 8
  %55 = load i16, ptr @c, align 2
  %56 = sext i16 %55 to i64
  %57 = srem i64 %54, %56
  %58 = trunc i64 %57 to i32
  store i32 %58, ptr %8, align 4
  %59 = load i16, ptr %3, align 2
  %60 = zext i16 %59 to i64
  %61 = xor i64 %60, 5
  %62 = trunc i64 %61 to i16
  store i16 %62, ptr %9, align 2
  %63 = load i16, ptr %9, align 2
  %64 = sext i16 %63 to i32
  %65 = icmp ne i32 %64, 0
  br i1 %65, label %66, label %68

66:                                               ; preds = %53
  %67 = load i32, ptr %8, align 4
  store i32 %67, ptr @a, align 4
  br label %68

68:                                               ; preds = %66, %53
  %69 = load i32, ptr @a, align 4
  %70 = icmp ne i32 %69, 0
  br i1 %70, label %71, label %72

71:                                               ; preds = %68
  store i32 0, ptr @a, align 4
  store i32 1, ptr %1, align 4
  br label %73

72:                                               ; preds = %68
  store i32 0, ptr %1, align 4
  br label %73

73:                                               ; preds = %72, %71
  %74 = load i32, ptr %1, align 4
  ret i32 %74
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
