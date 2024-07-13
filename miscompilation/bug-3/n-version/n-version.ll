; ModuleID = '/home/javier/Galapagos/miscompilation/bug-3/project/main.bc'
source_filename = "main.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@stdout = external global ptr, align 8
@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @n_version_call(ptr noundef %0, i32 noundef %1) #0 {
entry:
  %2 = call i32 @version_1(ptr %0, i32 %1)
  %3 = call i32 @version_2(ptr %0, i32 %1)
  %4 = call i32 @version_3(ptr %0, i32 %1)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %5 = icmp eq i32 %2, %3
  br i1 %5, label %true, label %error

true:                                             ; preds = %comparisons
  %6 = icmp eq i32 %2, %4
  br i1 %6, label %true1, label %error

true1:                                            ; preds = %true
  ret i32 %2

error:                                            ; preds = %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_2(ptr noundef %0, i32 noundef %1) #1 {
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
  br i1 %27, label %16, label %28, !llvm.loop !5

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
  br i1 %46, label %35, label %47, !llvm.loop !7

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
  br label %57, !llvm.loop !8

70:                                               ; preds = %57
  store i32 0, ptr %3, align 4
  br label %71

71:                                               ; preds = %70, %51
  %72 = load i32, ptr %3, align 4
  ret i32 %72
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_3(ptr noundef %0, i32 noundef %1) #1 {
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
  br i1 %27, label %16, label %28, !llvm.loop !9

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
  br i1 %46, label %35, label %47, !llvm.loop !10

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
  br label %57, !llvm.loop !11

70:                                               ; preds = %57
  store i32 0, ptr %3, align 4
  br label %71

71:                                               ; preds = %70, %51
  %72 = load i32, ptr %3, align 4
  ret i32 %72
}

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @version_1(ptr noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca ptr, align 8
  %5 = alloca i32, align 4
  %6 = alloca [7 x i32], align 16
  %7 = alloca i32, align 4
  %8 = alloca i64, align 8
  %9 = alloca i64, align 8
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  store ptr %0, ptr %4, align 8
  store i32 %1, ptr %5, align 4
  call void @llvm.lifetime.start.p0(i64 28, ptr %6) #6
  call void @llvm.lifetime.start.p0(i64 4, ptr %7) #6
  store i32 0, ptr %7, align 4
  %12 = load i32, ptr %5, align 4
  %13 = icmp eq i32 %12, 123
  br i1 %13, label %14, label %33

14:                                               ; preds = %2
  call void @llvm.lifetime.start.p0(i64 8, ptr %8) #6
  %15 = load ptr, ptr %4, align 8
  %16 = load i64, ptr %15, align 8
  store i64 %16, ptr %8, align 8
  br label %17

17:                                               ; preds = %26, %14
  %18 = load i32, ptr %7, align 4
  %19 = add nsw i32 %18, 1
  store i32 %19, ptr %7, align 4
  %20 = sext i32 %18 to i64
  %21 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 %20
  store i32 123, ptr %21, align 4
  %22 = load i64, ptr %8, align 8
  %23 = sub i64 %22, 1
  %24 = load i64, ptr %8, align 8
  %25 = and i64 %24, %23
  store i64 %25, ptr %8, align 8
  br label %26

26:                                               ; preds = %17
  %27 = load i64, ptr %8, align 8
  %28 = icmp ne i64 %27, 0
  br i1 %28, label %17, label %29, !llvm.loop !12

29:                                               ; preds = %26
  %30 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 1
  %31 = load i32, ptr %30, align 4
  %32 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 0
  store i32 %31, ptr %32, align 16
  call void @llvm.lifetime.end.p0(i64 8, ptr %8) #6
  br label %33

33:                                               ; preds = %29, %2
  call void @llvm.lifetime.start.p0(i64 8, ptr %9) #6
  %34 = load ptr, ptr %4, align 8
  %35 = load i64, ptr %34, align 8
  store i64 %35, ptr %9, align 8
  br label %36

36:                                               ; preds = %45, %33
  %37 = load i32, ptr %7, align 4
  %38 = add nsw i32 %37, 1
  store i32 %38, ptr %7, align 4
  %39 = sext i32 %37 to i64
  %40 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 %39
  store i32 123, ptr %40, align 4
  %41 = load i64, ptr %9, align 8
  %42 = sub i64 %41, 1
  %43 = load i64, ptr %9, align 8
  %44 = and i64 %43, %42
  store i64 %44, ptr %9, align 8
  br label %45

45:                                               ; preds = %36
  %46 = load i64, ptr %9, align 8
  %47 = icmp ne i64 %46, 0
  br i1 %47, label %36, label %48, !llvm.loop !13

48:                                               ; preds = %45
  %49 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 0
  %50 = load i32, ptr %49, align 16
  %51 = icmp slt i32 %50, 0
  br i1 %51, label %52, label %57

52:                                               ; preds = %48
  %53 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 0
  %54 = load i32, ptr %53, align 16
  %55 = load ptr, ptr @stdout, align 8
  %56 = call i32 @putc(i32 noundef %54, ptr noundef %55)
  store i32 42, ptr %3, align 4
  store i32 1, ptr %10, align 4
  br label %73

57:                                               ; preds = %48
  call void @llvm.lifetime.start.p0(i64 4, ptr %11) #6
  store i32 0, ptr %11, align 4
  br label %58

58:                                               ; preds = %69, %57
  %59 = load i32, ptr %11, align 4
  %60 = load i32, ptr %7, align 4
  %61 = icmp slt i32 %59, %60
  br i1 %61, label %63, label %62

62:                                               ; preds = %58
  store i32 6, ptr %10, align 4
  call void @llvm.lifetime.end.p0(i64 4, ptr %11) #6
  br label %72

63:                                               ; preds = %58
  %64 = load i32, ptr %11, align 4
  %65 = sext i32 %64 to i64
  %66 = getelementptr inbounds [7 x i32], ptr %6, i64 0, i64 %65
  %67 = load i32, ptr %66, align 4
  %68 = xor i32 %67, 123
  store i32 %68, ptr %66, align 4
  br label %69

69:                                               ; preds = %63
  %70 = load i32, ptr %11, align 4
  %71 = add nsw i32 %70, 1
  store i32 %71, ptr %11, align 4
  br label %58, !llvm.loop !14

72:                                               ; preds = %62
  store i32 0, ptr %3, align 4
  store i32 1, ptr %10, align 4
  br label %73

73:                                               ; preds = %72, %52
  call void @llvm.lifetime.end.p0(i64 8, ptr %9) #6
  call void @llvm.lifetime.end.p0(i64 4, ptr %7) #6
  call void @llvm.lifetime.end.p0(i64 28, ptr %6) #6
  %74 = load i32, ptr %3, align 4
  ret i32 %74
}

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #2

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.end.p0(i64 immarg, ptr nocapture) #2

declare i32 @putc(i32 noundef, ptr noundef) #3

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #4 {
  %3 = alloca i32, align 4
  %4 = alloca ptr, align 8
  %5 = alloca i64, align 8
  %6 = alloca i32, align 4
  store i32 %0, ptr %3, align 4
  store ptr %1, ptr %4, align 8
  call void @llvm.lifetime.start.p0(i64 8, ptr %5) #6
  store i64 131586, ptr %5, align 8
  call void @llvm.lifetime.start.p0(i64 4, ptr %6) #6
  store i32 -12345, ptr %6, align 4
  %7 = load i32, ptr %6, align 4
  %8 = call i32 @n_version_call(ptr noundef %5, i32 noundef %7)
  %9 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %8)
  call void @llvm.lifetime.end.p0(i64 4, ptr %6) #6
  call void @llvm.lifetime.end.p0(i64 8, ptr %5) #6
  ret i32 0
}

declare i32 @printf(ptr noundef, ...) #3

; Function Attrs: cold noreturn nounwind
declare void @llvm.trap() #5

attributes #0 = { noinline nounwind uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="znver4" "target-features"="+adx,+aes,+avx,+avx2,+avx512bf16,+avx512bitalg,+avx512bw,+avx512cd,+avx512dq,+avx512f,+avx512ifma,+avx512vbmi,+avx512vbmi2,+avx512vl,+avx512vnni,+avx512vpopcntdq,+bmi,+bmi2,+clflushopt,+clwb,+clzero,+crc32,+cx16,+cx8,+evex512,+f16c,+fma,+fsgsbase,+fxsr,+gfni,+invpcid,+lzcnt,+mmx,+movbe,+mwaitx,+pclmul,+pku,+popcnt,+prfchw,+rdpid,+rdpru,+rdrnd,+rdseed,+sahf,+sha,+shstk,+sse,+sse2,+sse3,+sse4.1,+sse4.2,+sse4a,+ssse3,+vaes,+vpclmulqdq,+wbnoinvd,+x87,+xsave,+xsavec,+xsaveopt,+xsaves" }
attributes #1 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }
attributes #3 = { "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="znver4" "target-features"="+adx,+aes,+avx,+avx2,+avx512bf16,+avx512bitalg,+avx512bw,+avx512cd,+avx512dq,+avx512f,+avx512ifma,+avx512vbmi,+avx512vbmi2,+avx512vl,+avx512vnni,+avx512vpopcntdq,+bmi,+bmi2,+clflushopt,+clwb,+clzero,+crc32,+cx16,+cx8,+evex512,+f16c,+fma,+fsgsbase,+fxsr,+gfni,+invpcid,+lzcnt,+mmx,+movbe,+mwaitx,+pclmul,+pku,+popcnt,+prfchw,+rdpid,+rdpru,+rdrnd,+rdseed,+sahf,+sha,+shstk,+sse,+sse2,+sse3,+sse4.1,+sse4.2,+sse4a,+ssse3,+vaes,+vpclmulqdq,+wbnoinvd,+x87,+xsave,+xsavec,+xsaveopt,+xsaves" }
attributes #4 = { noinline nounwind optnone uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="znver4" "target-features"="+adx,+aes,+avx,+avx2,+avx512bf16,+avx512bitalg,+avx512bw,+avx512cd,+avx512dq,+avx512f,+avx512ifma,+avx512vbmi,+avx512vbmi2,+avx512vl,+avx512vnni,+avx512vpopcntdq,+bmi,+bmi2,+clflushopt,+clwb,+clzero,+crc32,+cx16,+cx8,+evex512,+f16c,+fma,+fsgsbase,+fxsr,+gfni,+invpcid,+lzcnt,+mmx,+movbe,+mwaitx,+pclmul,+pku,+popcnt,+prfchw,+rdpid,+rdpru,+rdrnd,+rdseed,+sahf,+sha,+shstk,+sse,+sse2,+sse3,+sse4.1,+sse4.2,+sse4a,+ssse3,+vaes,+vpclmulqdq,+wbnoinvd,+x87,+xsave,+xsavec,+xsaveopt,+xsaves" }
attributes #5 = { cold noreturn nounwind }
attributes #6 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"Ubuntu clang version 18.1.3 (1ubuntu1)"}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.mustprogress"}
!7 = distinct !{!7, !6}
!8 = distinct !{!8, !6}
!9 = distinct !{!9, !6}
!10 = distinct !{!10, !6}
!11 = distinct !{!11, !6}
!12 = distinct !{!12, !6}
!13 = distinct !{!13, !6}
!14 = distinct !{!14, !6}
