; ModuleID = 'main.bc'
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

@b = dso_local global i16 5, align 2
@.str = private unnamed_addr constant [12 x i8] c"CAUGHT: %d\0A\00", align 1
@a = dso_local global i32 0, align 4
@.str.1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@c = dso_local global i16 0, align 2
@l = dso_local global i16 0, align 2
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
  store i32 42, ptr @a, align 4
  call void @llvm.lifetime.start.p0(i64 4, ptr %7) #7
  store i32 8, ptr %7, align 4
  %10 = load ptr, ptr %6, align 8
  %11 = getelementptr inbounds %struct.ucontext_t, ptr %10, i32 0, i32 3
  %12 = getelementptr inbounds %struct.mcontext_t, ptr %11, i32 0, i32 0
  %13 = getelementptr inbounds [23 x i64], ptr %12, i64 0, i64 16
  %14 = load i64, ptr %13, align 8
  %15 = add nsw i64 %14, 8
  store i64 %15, ptr %13, align 8
  call void @llvm.lifetime.end.p0(i64 4, ptr %7) #7
  ret void
}

declare i32 @printf(ptr noundef, ...) #1

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #2

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.end.p0(i64 immarg, ptr nocapture) #2

; Function Attrs: noinline nounwind uwtable
define dso_local void @empty() #3 {
  %1 = alloca i32, align 4
  %2 = call i32 (ptr, ...) @printf(ptr noundef @.str.1)
  call void @llvm.lifetime.start.p0(i64 4, ptr %1) #7
  store i32 1, ptr %1, align 4
  call void @llvm.lifetime.end.p0(i64 4, ptr %1) #7
  ret void
}

; Function Attrs: nounwind uwtable
define dso_local i32 @foo() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i16, align 2
  %3 = alloca i16, align 2
  %4 = alloca i8, align 1
  %5 = alloca i64, align 8
  %6 = alloca i16, align 2
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  call void @llvm.lifetime.start.p0(i64 2, ptr %2) #7
  store i16 -1, ptr %2, align 2
  call void @llvm.lifetime.start.p0(i64 2, ptr %3) #7
  call void @llvm.lifetime.start.p0(i64 1, ptr %4) #7
  store i8 25, ptr %4, align 1
  call void @llvm.lifetime.start.p0(i64 8, ptr %5) #7
  store i64 0, ptr %5, align 8
  %10 = load i32, ptr @a, align 4
  %11 = icmp ne i32 %10, 0
  br i1 %11, label %12, label %13

12:                                               ; preds = %0
  store i64 -1, ptr %5, align 8
  store i8 0, ptr %4, align 1
  br label %13

13:                                               ; preds = %12, %0
  call void @llvm.lifetime.start.p0(i64 2, ptr %6) #7
  %14 = load i8, ptr %4, align 1
  %15 = sext i8 %14 to i32
  %16 = xor i32 %15, -1
  %17 = trunc i32 %16 to i16
  store i16 %17, ptr %6, align 2
  call void @llvm.lifetime.start.p0(i64 4, ptr %7) #7
  %18 = load i8, ptr %4, align 1
  %19 = sext i8 %18 to i32
  store i32 %19, ptr %7, align 4
  %20 = load i16, ptr @b, align 2
  %21 = icmp ne i16 %20, 0
  br i1 %21, label %22, label %56

22:                                               ; preds = %13
  %23 = load i64, ptr %5, align 8
  %24 = load i16, ptr %6, align 2
  %25 = sext i16 %24 to i32
  %26 = load i32, ptr %7, align 4
  %27 = or i32 583, %26
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
  %42 = zext i16 %41 to i32
  %43 = sub nsw i32 %42, 0
  %44 = sext i32 %43 to i64
  %45 = sub i64 8, %44
  %46 = udiv i64 22, %45
  %47 = trunc i64 %46 to i16
  store i16 %47, ptr @c, align 2
  %48 = load i16, ptr %3, align 2
  %49 = zext i16 %48 to i32
  %50 = icmp sgt i32 %49, 0
  br i1 %50, label %51, label %55

51:                                               ; preds = %22
  %52 = load i16, ptr %3, align 2
  %53 = zext i16 %52 to i32
  %54 = call i32 @ffs(i32 noundef %53) #8
  br label %55

55:                                               ; preds = %51, %22
  br label %56

56:                                               ; preds = %55, %13
  call void @llvm.lifetime.start.p0(i64 4, ptr %8) #7
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
  store i16 %65, ptr @l, align 2
  %66 = load i16, ptr @l, align 2
  %67 = icmp ne i16 %66, 0
  br i1 %67, label %68, label %70

68:                                               ; preds = %56
  %69 = load i32, ptr %8, align 4
  store i32 %69, ptr @a, align 4
  br label %70

70:                                               ; preds = %68, %56
  %71 = load i32, ptr @a, align 4
  %72 = icmp ne i32 %71, 0
  br i1 %72, label %73, label %74

73:                                               ; preds = %70
  store i32 1, ptr %1, align 4
  store i32 1, ptr %9, align 4
  br label %75

74:                                               ; preds = %70
  store i32 0, ptr %1, align 4
  store i32 1, ptr %9, align 4
  br label %75

75:                                               ; preds = %74, %73
  call void @llvm.lifetime.end.p0(i64 4, ptr %8) #7
  call void @llvm.lifetime.end.p0(i64 4, ptr %7) #7
  call void @llvm.lifetime.end.p0(i64 2, ptr %6) #7
  call void @llvm.lifetime.end.p0(i64 8, ptr %5) #7
  call void @llvm.lifetime.end.p0(i64 1, ptr %4) #7
  call void @llvm.lifetime.end.p0(i64 2, ptr %3) #7
  call void @llvm.lifetime.end.p0(i64 2, ptr %2) #7
  %76 = load i32, ptr %1, align 4
  ret i32 %76
}

; Function Attrs: nounwind willreturn memory(none)
declare i32 @ffs(i32 noundef) #4

; Function Attrs: nounwind uwtable
define dso_local i32 @main() #0 {
  %1 = alloca %struct.sigaction, align 8
  call void @llvm.lifetime.start.p0(i64 152, ptr %1) #7
  call void @llvm.memset.p0.i64(ptr align 8 %1, i8 0, i64 152, i1 false)
  %2 = getelementptr inbounds %struct.sigaction, ptr %1, i32 0, i32 1
  %3 = call i32 @sigemptyset(ptr noundef %2) #7
  %4 = getelementptr inbounds %struct.sigaction, ptr %1, i32 0, i32 0
  store ptr @sgh, ptr %4, align 8
  %5 = getelementptr inbounds %struct.sigaction, ptr %1, i32 0, i32 2
  store i32 4, ptr %5, align 8
  %6 = call i32 @sigaction(i32 noundef 8, ptr noundef %1, ptr noundef null) #7
  %7 = call i32 @foo()
  %8 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %7)
  call void @llvm.lifetime.end.p0(i64 152, ptr %1) #7
  ret i32 0
}

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: write)
declare void @llvm.memset.p0.i64(ptr nocapture writeonly, i8, i64, i1 immarg) #5

; Function Attrs: nounwind
declare i32 @sigemptyset(ptr noundef) #6

; Function Attrs: nounwind
declare i32 @sigaction(i32 noundef, ptr noundef, ptr noundef) #6

attributes #0 = { nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }
attributes #3 = { noinline nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind willreturn memory(none) "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { nocallback nofree nounwind willreturn memory(argmem: write) }
attributes #6 = { nounwind "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #7 = { nounwind }
attributes #8 = { nounwind willreturn memory(none) }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"Ubuntu clang version 15.0.7"}
