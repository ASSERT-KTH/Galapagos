; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/0_barrett_reduce.bc'
source_filename = "/home/javier/Galapagos/functions/libgcrypt/0_barrett_reduce.run.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.timespec = type { i64, i64 }

@.str = private unnamed_addr constant [6 x i8] c"%.4f\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @n_version_call(i16 noundef signext %0) #0 {
entry:
  %1 = call i16 @version_1(i16 %0)
  %2 = call i16 @version_2(i16 %0)
  %3 = call i16 @version_3(i16 %0)
  %4 = call i16 @version_4(i16 %0)
  %5 = call i16 @version_5(i16 %0)
  %6 = call i16 @version_6(i16 %0)
  %7 = call i16 @version_7(i16 %0)
  %8 = call i16 @version_8(i16 %0)
  %9 = call i16 @version_9(i16 %0)
  %10 = call i16 @version_10(i16 %0)
  %11 = call i16 @version_11(i16 %0)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %12 = icmp eq i16 %1, %2
  br i1 %12, label %true, label %error

true:                                             ; preds = %comparisons
  %13 = icmp eq i16 %1, %3
  br i1 %13, label %true1, label %error

true1:                                            ; preds = %true
  %14 = icmp eq i16 %1, %4
  br i1 %14, label %true2, label %error

true2:                                            ; preds = %true1
  %15 = icmp eq i16 %1, %5
  br i1 %15, label %true3, label %error

true3:                                            ; preds = %true2
  %16 = icmp eq i16 %1, %6
  br i1 %16, label %true4, label %error

true4:                                            ; preds = %true3
  %17 = icmp eq i16 %1, %7
  br i1 %17, label %true5, label %error

true5:                                            ; preds = %true4
  %18 = icmp eq i16 %1, %8
  br i1 %18, label %true6, label %error

true6:                                            ; preds = %true5
  %19 = icmp eq i16 %1, %9
  br i1 %19, label %true7, label %error

true7:                                            ; preds = %true6
  %20 = icmp eq i16 %1, %10
  br i1 %20, label %true8, label %error

true8:                                            ; preds = %true7
  %21 = icmp eq i16 %1, %11
  br i1 %21, label %true9, label %error

true9:                                            ; preds = %true8
  ret i16 %1

error:                                            ; preds = %true8, %true7, %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @version_2(i16 noundef signext %a) #0 {
entry:
  %sext.0 = sext i16 %a to i32
  %mul.0 = mul nsw i32 %sext.0, 20159
  %add.0 = add nsw i32 %mul.0, 33554432
  %shr.0 = ashr i32 %add.0, 26
  %0 = trunc i32 %shr.0 to i16
  %trunc.1.neg = mul i16 %0, -3329
  %sub.0 = add i16 %trunc.1.neg, %a
  ret i16 %sub.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @version_3(i16 noundef signext %a) #0 {
entry:
  %sext.0 = sext i16 %a to i32
  %mul.0 = mul nsw i32 %sext.0, 20159
  %add.0 = add nsw i32 %mul.0, 33554432
  %shr.0 = ashr i32 %add.0, 26
  %0 = trunc i32 %shr.0 to i16
  %1 = mul i16 %0, -3329
  %trunc.1 = add i16 %1, %a
  ret i16 %trunc.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @version_4(i16 noundef signext %a) #0 {
entry:
  %sext.0 = sext i16 %a to i32
  %mul.0 = mul nsw i32 %sext.0, 20159
  %add.0 = add nsw i32 %mul.0, 33554432
  %shr.0 = ashr i32 %add.0, 26
  %0 = trunc i32 %shr.0 to i16
  %1 = mul i16 %0, -3329
  %trunc.1 = add i16 %1, %a
  ret i16 %trunc.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @version_5(i16 noundef signext %a) #0 {
entry:
  %sext.0 = sext i16 %a to i32
  %mul.0 = mul nsw i32 %sext.0, 20159
  %add.0 = add nsw i32 %mul.0, 33554432
  %shr.0 = ashr i32 %add.0, 26
  %0 = trunc i32 %shr.0 to i16
  %1 = mul i16 %0, -3329
  %trunc.1 = add i16 %1, %a
  ret i16 %trunc.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @version_6(i16 noundef signext %a) #0 {
entry:
  %sext.0 = sext i16 %a to i32
  %mul.0 = mul nsw i32 %sext.0, 20159
  %add.0 = add nsw i32 %mul.0, 33554432
  %shr.0 = ashr i32 %add.0, 26
  %0 = trunc i32 %shr.0 to i16
  %trunc.1.neg = mul i16 %0, -3329
  %sub.0 = add i16 %trunc.1.neg, %a
  ret i16 %sub.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @version_7(i16 noundef signext %a) #0 {
entry:
  %sext.0 = sext i16 %a to i32
  %mul.0 = mul nsw i32 %sext.0, 20159
  %add.0 = add nsw i32 %mul.0, 33554432
  %shr.0 = ashr i32 %add.0, 26
  %0 = trunc i32 %shr.0 to i16
  %trunc.1.neg = mul i16 %0, -3329
  %sub.0 = add i16 %trunc.1.neg, %a
  ret i16 %sub.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @version_8(i16 noundef signext %a) #0 {
entry:
  %sext.0 = sext i16 %a to i32
  %mul.0 = mul nsw i32 %sext.0, 20159
  %add.0 = add nsw i32 %mul.0, 33554432
  %shr.0 = ashr i32 %add.0, 26
  %0 = trunc i32 %shr.0 to i16
  %1 = mul i16 %0, -3329
  %trunc.1 = add i16 %1, %a
  ret i16 %trunc.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @version_9(i16 noundef signext %a) #0 {
entry:
  %sext.0 = sext i16 %a to i32
  %mul.0 = mul nsw i32 %sext.0, 20159
  %add.0 = add nsw i32 %mul.0, 33554432
  %shr.0 = ashr i32 %add.0, 26
  %0 = trunc i32 %shr.0 to i16
  %trunc.1.neg = mul i16 %0, -3329
  %sub.0 = add i16 %trunc.1.neg, %a
  ret i16 %sub.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @version_10(i16 noundef signext %a) #0 {
entry:
  %sext.0 = sext i16 %a to i32
  %mul.0 = mul nsw i32 %sext.0, 20159
  %add.0 = add nsw i32 %mul.0, 33554432
  %shr.0 = ashr i32 %add.0, 26
  %0 = trunc i32 %shr.0 to i16
  %trunc.1.neg = mul i16 %0, -3329
  %sub.0 = add i16 %trunc.1.neg, %a
  ret i16 %sub.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @version_11(i16 noundef signext %a) #0 {
entry:
  %sext.0 = sext i16 %a to i32
  %mul.0 = mul nsw i32 %sext.0, 20159
  %add.0 = add nsw i32 %mul.0, 33554432
  %shr.0 = ashr i32 %add.0, 26
  %0 = trunc i32 %shr.0 to i16
  %trunc.1.neg = mul i16 %0, -3329
  %sub.0 = add i16 %trunc.1.neg, %a
  ret i16 %sub.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @version_1(i16 noundef signext %a) #0 {
entry:
  %a.addr = alloca i16, align 2
  %t = alloca i16, align 2
  %v = alloca i16, align 2
  store i16 %a, ptr %a.addr, align 2
  store i16 20159, ptr %v, align 2
  %0 = load i16, ptr %a.addr, align 2
  %conv = sext i16 %0 to i32
  %mul = mul nsw i32 20159, %conv
  %add = add nsw i32 %mul, 33554432
  %shr = ashr i32 %add, 26
  %conv1 = trunc i32 %shr to i16
  store i16 %conv1, ptr %t, align 2
  %1 = load i16, ptr %t, align 2
  %conv2 = sext i16 %1 to i32
  %mul3 = mul nsw i32 %conv2, 3329
  %conv4 = trunc i32 %mul3 to i16
  store i16 %conv4, ptr %t, align 2
  %2 = load i16, ptr %a.addr, align 2
  %conv5 = sext i16 %2 to i32
  %3 = load i16, ptr %t, align 2
  %conv6 = sext i16 %3 to i32
  %sub = sub nsw i32 %conv5, %conv6
  %conv7 = trunc i32 %sub to i16
  ret i16 %conv7
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %iterations = alloca i32, align 4
  %start = alloca %struct.timespec, align 8
  %end = alloca %struct.timespec, align 8
  %total_time = alloca double, align 8
  %i = alloca i32, align 4
  store i32 0, ptr %retval, align 4
  store i32 2000000, ptr %iterations, align 4
  store double 0.000000e+00, ptr %total_time, align 8
  %call = call i32 @clock_gettime(i32 noundef 4, ptr noundef %start) #5
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %0, 2000000
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %call1 = call signext i16 @n_version_call(i16 noundef signext 0)
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %1 = load i32, ptr %i, align 4
  %inc = add nsw i32 %1, 1
  store i32 %inc, ptr %i, align 4
  br label %for.cond, !llvm.loop !6

for.end:                                          ; preds = %for.cond
  %call2 = call i32 @clock_gettime(i32 noundef 4, ptr noundef %end) #5
  %tv_sec = getelementptr inbounds %struct.timespec, ptr %end, i32 0, i32 0
  %2 = load i64, ptr %tv_sec, align 8
  %tv_sec3 = getelementptr inbounds %struct.timespec, ptr %start, i32 0, i32 0
  %3 = load i64, ptr %tv_sec3, align 8
  %sub = sub nsw i64 %2, %3
  %conv = sitofp i64 %sub to double
  %tv_nsec = getelementptr inbounds %struct.timespec, ptr %end, i32 0, i32 1
  %4 = load i64, ptr %tv_nsec, align 8
  %tv_nsec4 = getelementptr inbounds %struct.timespec, ptr %start, i32 0, i32 1
  %5 = load i64, ptr %tv_nsec4, align 8
  %sub5 = sub nsw i64 %4, %5
  %conv6 = sitofp i64 %sub5 to double
  %6 = call double @llvm.fmuladd.f64(double %conv, double 1.000000e+09, double %conv6)
  store double %6, ptr %total_time, align 8
  %7 = load double, ptr %total_time, align 8
  %call7 = call i32 (ptr, ...) @printf(ptr noundef @.str, double noundef %7)
  %8 = load i32, ptr %retval, align 4
  ret i32 %8
}

; Function Attrs: nounwind
declare i32 @clock_gettime(i32 noundef, ptr noundef) #1

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare double @llvm.fmuladd.f64(double, double, double) #2

declare i32 @printf(ptr noundef, ...) #3

; Function Attrs: cold noreturn nounwind
declare void @llvm.trap() #4

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #3 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { cold noreturn nounwind }
attributes #5 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 17.0.0 (git@github.com:llvm/llvm-project.git 1a7a00bdc99fa2b2ca19ecd2d1069991b3c1006b)"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
