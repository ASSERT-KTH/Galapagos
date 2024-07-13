; ModuleID = '/home/javier/Galapagos/miscompilation/bug-1/function/variants/c/foo_5.bc'
source_filename = "/home/javier/Galapagos/miscompilation/bug-1/function/variants/c/foo_5.c"
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
  %3 = alloca i8, align 1
  %4 = alloca i64, align 8
  %5 = alloca i16, align 2
  %6 = alloca i32, align 4
  %7 = alloca i16, align 2
  %8 = alloca i32, align 4
  %9 = alloca i16, align 2
  store i16 -1, ptr %2, align 2
  store i8 25, ptr %3, align 1
  %10 = load i32, ptr @a, align 4
  %11 = icmp ne i32 %10, 0
  %12 = zext i1 %11 to i64
  %13 = select i1 %11, i32 -1, i32 0
  %14 = sext i32 %13 to i64
  store i64 %14, ptr %4, align 8
  %15 = load i32, ptr @a, align 4
  %16 = icmp ne i32 %15, 0
  br i1 %16, label %17, label %18

17:                                               ; preds = %0
  store i8 0, ptr %3, align 1
  br label %18

18:                                               ; preds = %17, %0
  %19 = load i8, ptr %3, align 1
  %20 = sext i8 %19 to i32
  %21 = xor i32 %20, -1
  %22 = trunc i32 %21 to i16
  store i16 %22, ptr %5, align 2
  %23 = load i8, ptr %3, align 1
  %24 = sext i8 %23 to i32
  store i32 %24, ptr %6, align 4
  %25 = load i16, ptr @b, align 2
  %26 = icmp ne i16 %25, 0
  br i1 %26, label %27, label %58

27:                                               ; preds = %18
  %28 = load i64, ptr %4, align 8
  %29 = load i16, ptr %5, align 2
  %30 = sext i16 %29 to i32
  %31 = load i32, ptr %6, align 4
  %32 = or i32 583, %31
  %33 = or i32 %30, %32
  %34 = zext i32 %33 to i64
  %35 = or i64 %28, %34
  %36 = load i8, ptr %3, align 1
  %37 = sext i8 %36 to i64
  %38 = and i64 %37, 5
  %39 = xor i64 %38, -1
  %40 = load i16, ptr %2, align 2
  %41 = sext i16 %40 to i64
  %42 = sdiv i64 %39, %41
  %43 = xor i64 %42, -1
  %44 = xor i64 %35, %43
  %45 = trunc i64 %44 to i16
  store i16 %45, ptr %7, align 2
  %46 = load i16, ptr %7, align 2
  %47 = zext i16 %46 to i64
  %48 = sub i64 8, %47
  %49 = udiv i64 22, %48
  %50 = trunc i64 %49 to i16
  store i16 %50, ptr @c, align 2
  %51 = load i16, ptr %7, align 2
  %52 = zext i16 %51 to i32
  %53 = icmp sgt i32 %52, 0
  br i1 %53, label %54, label %57

54:                                               ; preds = %27
  %55 = load ptr, ptr @stdout, align 8
  %56 = call i32 @putc(i32 noundef 0, ptr noundef %55)
  br label %57

57:                                               ; preds = %54, %27
  br label %58

58:                                               ; preds = %57, %18
  %59 = load i64, ptr %4, align 8
  %60 = load i16, ptr @c, align 2
  %61 = sext i16 %60 to i64
  %62 = srem i64 %59, %61
  %63 = trunc i64 %62 to i32
  store i32 %63, ptr %8, align 4
  %64 = load i16, ptr %7, align 2
  %65 = zext i16 %64 to i64
  %66 = xor i64 %65, 5
  %67 = trunc i64 %66 to i16
  store i16 %67, ptr %9, align 2
  %68 = load i16, ptr %9, align 2
  %69 = icmp ne i16 %68, 0
  br i1 %69, label %70, label %72

70:                                               ; preds = %58
  %71 = load i32, ptr %8, align 4
  store i32 %71, ptr @a, align 4
  br label %72

72:                                               ; preds = %70, %58
  %73 = load i32, ptr @a, align 4
  %74 = icmp ne i32 %73, 0
  br i1 %74, label %75, label %76

75:                                               ; preds = %72
  store i32 0, ptr @a, align 4
  store i32 1, ptr %1, align 4
  br label %77

76:                                               ; preds = %72
  store i32 0, ptr %1, align 4
  br label %77

77:                                               ; preds = %76, %75
  %78 = load i32, ptr %1, align 4
  ret i32 %78
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
