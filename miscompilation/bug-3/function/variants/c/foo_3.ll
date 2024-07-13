; ModuleID = '/home/javier/Galapagos/miscompilation/bug-3/function/variants/c/foo_3.bc'
source_filename = "/home/javier/Galapagos/miscompilation/bug-3/function/variants/c/foo_3.c"
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
  br i1 %12, label %13, label %32

13:                                               ; preds = %2
  %14 = load ptr, ptr %4, align 8
  %15 = load i64, ptr %14, align 8
  store i64 %15, ptr %8, align 8
  br label %16

16:                                               ; preds = %25, %13
  %17 = load i32, ptr %7, align 4
  %18 = add nsw i32 %17, 1
  store i32 %18, ptr %7, align 4
  %19 = sext i32 %17 to i64
  %20 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 %19
  store i32 123, ptr %20, align 4
  %21 = load i64, ptr %8, align 8
  %22 = sub i64 %21, 1
  %23 = load i64, ptr %8, align 8
  %24 = and i64 %23, %22
  store i64 %24, ptr %8, align 8
  br label %25

25:                                               ; preds = %16
  %26 = load i64, ptr %8, align 8
  %27 = icmp ne i64 %26, 0
  br i1 %27, label %16, label %28, !llvm.loop !6

28:                                               ; preds = %25
  %29 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 1
  %30 = load i32, ptr %29, align 4
  %31 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 0
  store i32 %30, ptr %31, align 16
  br label %32

32:                                               ; preds = %28, %2
  %33 = load ptr, ptr %4, align 8
  %34 = load i64, ptr %33, align 8
  store i64 %34, ptr %9, align 8
  br label %35

35:                                               ; preds = %44, %32
  %36 = load i32, ptr %7, align 4
  %37 = add nsw i32 %36, 1
  store i32 %37, ptr %7, align 4
  %38 = sext i32 %36 to i64
  %39 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 %38
  store i32 123, ptr %39, align 4
  %40 = load i64, ptr %9, align 8
  %41 = sub i64 %40, 1
  %42 = load i64, ptr %9, align 8
  %43 = and i64 %42, %41
  store i64 %43, ptr %9, align 8
  br label %44

44:                                               ; preds = %35
  %45 = load i64, ptr %9, align 8
  %46 = icmp ne i64 %45, 0
  br i1 %46, label %35, label %47, !llvm.loop !8

47:                                               ; preds = %44
  %48 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 0
  %49 = load i32, ptr %48, align 16
  %50 = icmp slt i32 %49, 0
  br i1 %50, label %51, label %56

51:                                               ; preds = %47
  %52 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 0
  %53 = load i32, ptr %52, align 16
  %54 = load ptr, ptr @stdout, align 8
  %55 = call i32 @putc(i32 noundef %53, ptr noundef %54)
  store i32 42, ptr %3, align 4
  br label %71

56:                                               ; preds = %47
  store i32 0, ptr %10, align 4
  br label %57

57:                                               ; preds = %67, %56
  %58 = load i32, ptr %10, align 4
  %59 = load i32, ptr %7, align 4
  %60 = icmp slt i32 %58, %59
  br i1 %60, label %61, label %70

61:                                               ; preds = %57
  %62 = load i32, ptr %10, align 4
  %63 = sext i32 %62 to i64
  %64 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 %63
  %65 = load i32, ptr %64, align 4
  %66 = xor i32 %65, 123
  store i32 %66, ptr %64, align 4
  br label %67

67:                                               ; preds = %61
  %68 = load i32, ptr %10, align 4
  %69 = add nsw i32 %68, 1
  store i32 %69, ptr %10, align 4
  br label %57, !llvm.loop !9

70:                                               ; preds = %57
  store i32 0, ptr %3, align 4
  br label %71

71:                                               ; preds = %70, %51
  %72 = load i32, ptr %3, align 4
  ret i32 %72
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
