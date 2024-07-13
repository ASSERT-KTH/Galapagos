; ModuleID = '/home/javier/Galapagos/miscompilation/bug-3/function/variants/c/foo_1.bc'
source_filename = "/home/javier/Galapagos/miscompilation/bug-3/function/variants/c/foo_1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@b = dso_local global i16 5, align 2
@stdout = external global ptr, align 8
@a = dso_local global i32 0, align 4
@c = dso_local global i16 0, align 2
@l = dso_local global i16 0, align 2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @foo(ptr noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca ptr, align 8
  %5 = alloca i32, align 4
  %6 = alloca [7 x i32], align 16
  %7 = alloca i32, align 4
  %8 = alloca i64, align 8
  %9 = alloca i64, align 8
  %10 = alloca i32, align 4
  store ptr %0, ptr %4, align 8
  store i32 %1, ptr %5, align 4
  store i32 0, ptr %7, align 4
  %11 = load i32, ptr %5, align 4
  %12 = icmp eq i32 %11, 123
  br i1 %12, label %13, label %33

13:                                               ; preds = %2
  %14 = load ptr, ptr %4, align 8
  %15 = load i64, ptr %14, align 8
  store i64 %15, ptr %8, align 8
  br label %16

16:                                               ; preds = %24, %13
  %17 = load i64, ptr %8, align 8
  %18 = icmp ne i64 %17, 0
  br i1 %18, label %19, label %29

19:                                               ; preds = %16
  %20 = load i32, ptr %7, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, ptr %7, align 4
  %22 = sext i32 %20 to i64
  %23 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 %22
  store i32 123, ptr %23, align 4
  br label %24

24:                                               ; preds = %19
  %25 = load i64, ptr %8, align 8
  %26 = sub i64 %25, 1
  %27 = load i64, ptr %8, align 8
  %28 = and i64 %27, %26
  store i64 %28, ptr %8, align 8
  br label %16, !llvm.loop !6

29:                                               ; preds = %16
  %30 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 1
  %31 = load i32, ptr %30, align 4
  %32 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 0
  store i32 %31, ptr %32, align 16
  br label %33

33:                                               ; preds = %29, %2
  %34 = load ptr, ptr %4, align 8
  %35 = load i64, ptr %34, align 8
  store i64 %35, ptr %9, align 8
  br label %36

36:                                               ; preds = %44, %33
  %37 = load i64, ptr %9, align 8
  %38 = icmp ne i64 %37, 0
  br i1 %38, label %39, label %49

39:                                               ; preds = %36
  %40 = load i32, ptr %7, align 4
  %41 = add nsw i32 %40, 1
  store i32 %41, ptr %7, align 4
  %42 = sext i32 %40 to i64
  %43 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 %42
  store i32 123, ptr %43, align 4
  br label %44

44:                                               ; preds = %39
  %45 = load i64, ptr %9, align 8
  %46 = sub i64 %45, 1
  %47 = load i64, ptr %9, align 8
  %48 = and i64 %47, %46
  store i64 %48, ptr %9, align 8
  br label %36, !llvm.loop !8

49:                                               ; preds = %36
  %50 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 0
  %51 = load i32, ptr %50, align 16
  %52 = icmp slt i32 %51, 0
  br i1 %52, label %53, label %58

53:                                               ; preds = %49
  %54 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 0
  %55 = load i32, ptr %54, align 16
  %56 = load ptr, ptr @stdout, align 8
  %57 = call i32 @putc(i32 noundef %55, ptr noundef %56)
  store i32 42, ptr %3, align 4
  br label %73

58:                                               ; preds = %49
  store i32 0, ptr %10, align 4
  br label %59

59:                                               ; preds = %69, %58
  %60 = load i32, ptr %10, align 4
  %61 = load i32, ptr %7, align 4
  %62 = icmp slt i32 %60, %61
  br i1 %62, label %63, label %72

63:                                               ; preds = %59
  %64 = load i32, ptr %10, align 4
  %65 = sext i32 %64 to i64
  %66 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 %65
  %67 = load i32, ptr %66, align 4
  %68 = xor i32 %67, 123
  store i32 %68, ptr %66, align 4
  br label %69

69:                                               ; preds = %63
  %70 = load i32, ptr %10, align 4
  %71 = add nsw i32 %70, 1
  store i32 %71, ptr %10, align 4
  br label %59, !llvm.loop !9

72:                                               ; preds = %59
  store i32 0, ptr %3, align 4
  br label %73

73:                                               ; preds = %72, %53
  %74 = load i32, ptr %3, align 4
  ret i32 %74
}

declare i32 @putc(i32 noundef, ptr noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i64, align 8
  store i64 131586, ptr %1, align 8
  %2 = call i32 @foo(ptr noundef %1, i32 noundef 0)
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
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}
