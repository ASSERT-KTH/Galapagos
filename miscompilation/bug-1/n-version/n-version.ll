; ModuleID = '/home/javier/Galapagos/miscompilation/bug-1/project/main.bc'
source_filename = "main.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.ucontext_t = type { i64, ptr, %struct.stack_t, %struct.mcontext_t, %struct.__sigset_t, %struct._libc_fpstate, [4 x i64] }
%struct.stack_t = type { ptr, i32, i64 }
%struct.mcontext_t = type { [23 x i64], ptr, [8 x i64] }
%struct.__sigset_t = type { [16 x i64] }
%struct._libc_fpstate = type { i16, i16, i16, i16, i64, i64, i32, i32, [8 x %struct._libc_fpxreg], [16 x %struct._libc_xmmreg], [24 x i32] }
%struct._libc_fpxreg = type { [4 x i16], i16, [3 x i16] }
%struct._libc_xmmreg = type { [4 x i32] }
%struct.sigaction = type { %union.anon.8, %struct.__sigset_t, i32, ptr }
%union.anon.8 = type { ptr }

@a = dso_local global i32 0, align 4
@b = dso_local global i16 5, align 2
@.str = private unnamed_addr constant [12 x i8] c"CAUGHT: %d\0A\00", align 1
@.str.1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@c = dso_local global i16 0, align 2
@stdout = external global ptr, align 8
@.str.2 = private unnamed_addr constant [12 x i8] c"RETURN: %d\0A\00", align 1

; Function Attrs: nounwind uwtable
define dso_local void @sgh(i32 noundef %0, ptr noundef %1, ptr noundef %2) #0 {
  %4 = alloca i32, align 4
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store ptr %1, ptr %5, align 8
  store ptr %2, ptr %6, align 8
  %8 = load i32, ptr %4, align 4
  %9 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %8)
  call void @llvm.lifetime.start.p0(i64 4, ptr %7) #8
  store i32 7, ptr %7, align 4
  %10 = load ptr, ptr %6, align 8
  %11 = getelementptr inbounds %struct.ucontext_t, ptr %10, i32 0, i32 3
  %12 = getelementptr inbounds %struct.mcontext_t, ptr %11, i32 0, i32 0
  %13 = getelementptr inbounds [23 x i64], ptr %12, i64 0, i64 16
  %14 = load i64, ptr %13, align 8
  %15 = add nsw i64 %14, 7
  store i64 %15, ptr %13, align 8
  call void @llvm.lifetime.end.p0(i64 4, ptr %7) #8
  ret void
}

declare i32 @printf(ptr noundef, ...) #1

; Function Attrs: nocallback nofree nosync nounwind willreturn argmemonly
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #2

; Function Attrs: nocallback nofree nosync nounwind willreturn argmemonly
declare void @llvm.lifetime.end.p0(i64 immarg, ptr nocapture) #2

; Function Attrs: noinline nounwind uwtable
define dso_local void @empty() #3 {
  %1 = alloca i32, align 4
  %2 = call i32 (ptr, ...) @printf(ptr noundef @.str.1)
  call void @llvm.lifetime.start.p0(i64 4, ptr %1) #8
  store i32 1, ptr %1, align 4
  call void @llvm.lifetime.end.p0(i64 4, ptr %1) #8
  ret void
}

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @n_version_call() #3 {
entry:
  %0 = call i32 @version_1()
  %1 = call i32 @version_2()
  %2 = call i32 @version_3()
  %3 = call i32 @version_4()
  %4 = call i32 @version_5()
  %5 = call i32 @version_6()
  %6 = call i32 @version_7()
  %7 = call i32 @version_8()
  %8 = call i32 @version_9()
  %9 = call i32 @version_10()
  %10 = call i32 @version_11()
  br label %comparisons

comparisons:                                      ; preds = %entry
  %11 = icmp eq i32 %0, %1
  br i1 %11, label %true, label %error

true:                                             ; preds = %comparisons
  %12 = icmp eq i32 %0, %2
  br i1 %12, label %true1, label %error

true1:                                            ; preds = %true
  %13 = icmp eq i32 %0, %3
  br i1 %13, label %true2, label %error

true2:                                            ; preds = %true1
  %14 = icmp eq i32 %0, %4
  br i1 %14, label %true3, label %error

true3:                                            ; preds = %true2
  %15 = icmp eq i32 %0, %5
  br i1 %15, label %true4, label %error

true4:                                            ; preds = %true3
  %16 = icmp eq i32 %0, %6
  br i1 %16, label %true5, label %error

true5:                                            ; preds = %true4
  %17 = icmp eq i32 %0, %7
  br i1 %17, label %true6, label %error

true6:                                            ; preds = %true5
  %18 = icmp eq i32 %0, %8
  br i1 %18, label %true7, label %error

true7:                                            ; preds = %true6
  %19 = icmp eq i32 %0, %9
  br i1 %19, label %true8, label %error

true8:                                            ; preds = %true7
  %20 = icmp eq i32 %0, %10
  br i1 %20, label %true9, label %error

true9:                                            ; preds = %true8
  ret i32 %0

error:                                            ; preds = %true8, %true7, %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_2() #4 {
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

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_3() #4 {
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

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_4() #4 {
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
  br i1 %21, label %22, label %54

22:                                               ; preds = %13
  %23 = load i64, ptr %5, align 8
  %24 = load i8, ptr %4, align 1
  %25 = sext i8 %24 to i32
  %26 = xor i32 %25, -1
  %27 = load i32, ptr %7, align 4
  %28 = or i32 583, %27
  %29 = or i32 %26, %28
  %30 = zext i32 %29 to i64
  %31 = or i64 %23, %30
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
  %43 = zext i16 %42 to i64
  %44 = sub i64 8, %43
  %45 = udiv i64 22, %44
  %46 = trunc i64 %45 to i16
  store i16 %46, ptr @c, align 2
  %47 = load i16, ptr %3, align 2
  %48 = zext i16 %47 to i32
  %49 = icmp sgt i32 %48, 0
  br i1 %49, label %50, label %53

50:                                               ; preds = %22
  %51 = load ptr, ptr @stdout, align 8
  %52 = call i32 @putc(i32 noundef 0, ptr noundef %51)
  br label %53

53:                                               ; preds = %50, %22
  br label %54

54:                                               ; preds = %53, %13
  %55 = load i64, ptr %5, align 8
  %56 = load i16, ptr @c, align 2
  %57 = sext i16 %56 to i64
  %58 = srem i64 %55, %57
  %59 = trunc i64 %58 to i32
  store i32 %59, ptr %8, align 4
  %60 = load i16, ptr %3, align 2
  %61 = zext i16 %60 to i64
  %62 = xor i64 %61, 5
  %63 = trunc i64 %62 to i16
  store i16 %63, ptr %9, align 2
  %64 = load i16, ptr %9, align 2
  %65 = icmp ne i16 %64, 0
  br i1 %65, label %66, label %68

66:                                               ; preds = %54
  %67 = load i32, ptr %8, align 4
  store i32 %67, ptr @a, align 4
  br label %68

68:                                               ; preds = %66, %54
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

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_5() #4 {
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

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_6() #4 {
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
  br i1 %22, label %23, label %54

23:                                               ; preds = %13
  %24 = load i64, ptr %5, align 8
  %25 = load i16, ptr %6, align 2
  %26 = sext i16 %25 to i32
  %27 = load i32, ptr %7, align 4
  %28 = or i32 583, %27
  %29 = or i32 %26, %28
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
  %43 = zext i16 %42 to i64
  %44 = sub i64 8, %43
  %45 = udiv i64 22, %44
  %46 = trunc i64 %45 to i16
  store i16 %46, ptr @c, align 2
  %47 = load i16, ptr %3, align 2
  %48 = zext i16 %47 to i32
  %49 = icmp sgt i32 %48, 0
  br i1 %49, label %50, label %53

50:                                               ; preds = %23
  %51 = load ptr, ptr @stdout, align 8
  %52 = call i32 @putc(i32 noundef 0, ptr noundef %51)
  br label %53

53:                                               ; preds = %50, %23
  br label %54

54:                                               ; preds = %53, %13
  %55 = load i64, ptr %5, align 8
  %56 = load i16, ptr @c, align 2
  %57 = sext i16 %56 to i64
  %58 = srem i64 %55, %57
  %59 = trunc i64 %58 to i32
  store i32 %59, ptr %8, align 4
  %60 = load i16, ptr %3, align 2
  %61 = zext i16 %60 to i64
  %62 = xor i64 %61, 5
  %63 = trunc i64 %62 to i16
  store i16 %63, ptr %9, align 2
  %64 = load i16, ptr %9, align 2
  %65 = sext i16 %64 to i32
  %66 = icmp ne i32 %65, 0
  br i1 %66, label %67, label %69

67:                                               ; preds = %54
  %68 = load i32, ptr %8, align 4
  store i32 %68, ptr @a, align 4
  br label %69

69:                                               ; preds = %67, %54
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

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_7() #4 {
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

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_8() #4 {
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
  %27 = load i32, ptr %7, align 4
  %28 = or i32 583, %27
  %29 = or i32 %26, %28
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

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_9() #4 {
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
  br i1 %22, label %23, label %54

23:                                               ; preds = %13
  %24 = load i64, ptr %5, align 8
  %25 = load i16, ptr %6, align 2
  %26 = sext i16 %25 to i32
  %27 = load i32, ptr %7, align 4
  %28 = or i32 583, %27
  %29 = or i32 %26, %28
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
  %43 = zext i16 %42 to i64
  %44 = sub i64 8, %43
  %45 = udiv i64 22, %44
  %46 = trunc i64 %45 to i16
  store i16 %46, ptr @c, align 2
  %47 = load i16, ptr %3, align 2
  %48 = zext i16 %47 to i32
  %49 = icmp sgt i32 %48, 0
  br i1 %49, label %50, label %53

50:                                               ; preds = %23
  %51 = load ptr, ptr @stdout, align 8
  %52 = call i32 @putc(i32 noundef 0, ptr noundef %51)
  br label %53

53:                                               ; preds = %50, %23
  br label %54

54:                                               ; preds = %53, %13
  %55 = load i64, ptr %5, align 8
  %56 = load i16, ptr @c, align 2
  %57 = sext i16 %56 to i64
  %58 = srem i64 %55, %57
  %59 = trunc i64 %58 to i32
  store i32 %59, ptr %8, align 4
  %60 = load i16, ptr %3, align 2
  %61 = zext i16 %60 to i64
  %62 = xor i64 %61, 5
  %63 = trunc i64 %62 to i16
  store i16 %63, ptr %9, align 2
  %64 = load i16, ptr %9, align 2
  %65 = sext i16 %64 to i32
  %66 = icmp ne i32 %65, 0
  br i1 %66, label %67, label %69

67:                                               ; preds = %54
  %68 = load i32, ptr %8, align 4
  store i32 %68, ptr @a, align 4
  br label %69

69:                                               ; preds = %67, %54
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

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_10() #4 {
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
  %27 = load i32, ptr %7, align 4
  %28 = or i32 583, %27
  %29 = or i32 %26, %28
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

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_11() #4 {
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

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @version_1() #3 {
  %1 = alloca i32, align 4
  %2 = alloca i16, align 2
  %3 = alloca i16, align 2
  %4 = alloca i8, align 1
  %5 = alloca i64, align 8
  %6 = alloca i16, align 2
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i16, align 2
  %10 = alloca i32, align 4
  call void @llvm.lifetime.start.p0(i64 2, ptr %2) #8
  store i16 -1, ptr %2, align 2
  call void @llvm.lifetime.start.p0(i64 2, ptr %3) #8
  call void @llvm.lifetime.start.p0(i64 1, ptr %4) #8
  store i8 25, ptr %4, align 1
  call void @llvm.lifetime.start.p0(i64 8, ptr %5) #8
  store i64 0, ptr %5, align 8
  %11 = load i32, ptr @a, align 4
  %12 = icmp ne i32 %11, 0
  br i1 %12, label %13, label %14

13:                                               ; preds = %0
  store i64 -1, ptr %5, align 8
  store i8 0, ptr %4, align 1
  br label %14

14:                                               ; preds = %13, %0
  call void @llvm.lifetime.start.p0(i64 2, ptr %6) #8
  %15 = load i8, ptr %4, align 1
  %16 = sext i8 %15 to i32
  %17 = xor i32 %16, -1
  %18 = trunc i32 %17 to i16
  store i16 %18, ptr %6, align 2
  call void @llvm.lifetime.start.p0(i64 4, ptr %7) #8
  %19 = load i8, ptr %4, align 1
  %20 = sext i8 %19 to i32
  store i32 %20, ptr %7, align 4
  %21 = load i16, ptr @b, align 2
  %22 = icmp ne i16 %21, 0
  br i1 %22, label %23, label %56

23:                                               ; preds = %14
  %24 = load i64, ptr %5, align 8
  %25 = load i16, ptr %6, align 2
  %26 = sext i16 %25 to i32
  %27 = load i32, ptr %7, align 4
  %28 = or i32 583, %27
  %29 = or i32 %26, %28
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

56:                                               ; preds = %55, %14
  call void @llvm.lifetime.start.p0(i64 4, ptr %8) #8
  %57 = load i64, ptr %5, align 8
  %58 = load i16, ptr @c, align 2
  %59 = sext i16 %58 to i64
  %60 = srem i64 %57, %59
  %61 = trunc i64 %60 to i32
  store i32 %61, ptr %8, align 4
  call void @llvm.lifetime.start.p0(i64 2, ptr %9) #8
  %62 = load i16, ptr %3, align 2
  %63 = zext i16 %62 to i64
  %64 = xor i64 %63, 5
  %65 = trunc i64 %64 to i16
  store i16 %65, ptr %9, align 2
  %66 = load i16, ptr %9, align 2
  %67 = icmp ne i16 %66, 0
  br i1 %67, label %68, label %70

68:                                               ; preds = %56
  %69 = load i32, ptr %8, align 4
  store i32 %69, ptr @a, align 4
  br label %70

70:                                               ; preds = %68, %56
  %71 = load i32, ptr @a, align 4
  %72 = icmp ne i32 %71, -1
  br i1 %72, label %73, label %74

73:                                               ; preds = %70
  store i32 0, ptr @a, align 4
  store i32 1, ptr %1, align 4
  store i32 1, ptr %10, align 4
  br label %75

74:                                               ; preds = %70
  store i32 0, ptr %1, align 4
  store i32 1, ptr %10, align 4
  br label %75

75:                                               ; preds = %74, %73
  call void @llvm.lifetime.end.p0(i64 2, ptr %9) #8
  call void @llvm.lifetime.end.p0(i64 4, ptr %8) #8
  call void @llvm.lifetime.end.p0(i64 4, ptr %7) #8
  call void @llvm.lifetime.end.p0(i64 2, ptr %6) #8
  call void @llvm.lifetime.end.p0(i64 8, ptr %5) #8
  call void @llvm.lifetime.end.p0(i64 1, ptr %4) #8
  call void @llvm.lifetime.end.p0(i64 2, ptr %3) #8
  call void @llvm.lifetime.end.p0(i64 2, ptr %2) #8
  %76 = load i32, ptr %1, align 4
  ret i32 %76
}

declare i32 @putc(i32 noundef, ptr noundef) #1

; Function Attrs: nounwind uwtable
define dso_local i32 @main() #0 {
  %1 = alloca %struct.sigaction, align 8
  call void @llvm.lifetime.start.p0(i64 152, ptr %1) #8
  call void @llvm.memset.p0.i64(ptr align 8 %1, i8 0, i64 152, i1 false)
  %2 = getelementptr inbounds %struct.sigaction, ptr %1, i32 0, i32 1
  %3 = call i32 @sigemptyset(ptr noundef %2) #8
  %4 = getelementptr inbounds %struct.sigaction, ptr %1, i32 0, i32 0
  store ptr @sgh, ptr %4, align 8
  %5 = getelementptr inbounds %struct.sigaction, ptr %1, i32 0, i32 2
  store i32 4, ptr %5, align 8
  %6 = call i32 @sigaction(i32 noundef 8, ptr noundef %1, ptr noundef null) #8
  %7 = call i32 @n_version_call()
  %8 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %7)
  call void @llvm.lifetime.end.p0(i64 152, ptr %1) #8
  ret i32 0
}

; Function Attrs: nocallback nofree nounwind willreturn argmemonly
declare void @llvm.memset.p0.i64(ptr nocapture writeonly, i8, i64, i1 immarg) #5

; Function Attrs: nounwind
declare i32 @sigemptyset(ptr noundef) #6

; Function Attrs: nounwind
declare i32 @sigaction(i32 noundef, ptr noundef, ptr noundef) #6

; Function Attrs: cold noreturn nounwind
declare void @llvm.trap() #7

attributes #0 = { nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nocallback nofree nosync nounwind willreturn argmemonly }
attributes #3 = { noinline nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { nocallback nofree nounwind willreturn argmemonly }
attributes #6 = { nounwind "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #7 = { cold noreturn nounwind }
attributes #8 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"Ubuntu clang version 15.0.7"}
