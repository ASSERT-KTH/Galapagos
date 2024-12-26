; ModuleID = '/home/javier/Galapagos/functions/liboqs/4_int16_nonzero_mask.bc'
source_filename = "/home/javier/Galapagos/functions/liboqs/4_int16_nonzero_mask.run.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.timespec = type { i64, i64 }

@.str = private unnamed_addr constant [6 x i8] c"%.4f\0A\00", align 1

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
  %call1 = call i32 @n_version_call(i16 noundef signext 0)
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

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @n_version_call(i16 noundef signext %0) #0 {
entry:
  %1 = call i32 @version_1(i16 %0)
  %2 = call i32 @version_2(i16 %0)
  %3 = call i32 @version_3(i16 %0)
  %4 = call i32 @version_4(i16 %0)
  %5 = call i32 @version_5(i16 %0)
  %6 = call i32 @version_6(i16 %0)
  %7 = call i32 @version_7(i16 %0)
  %8 = call i32 @version_8(i16 %0)
  %9 = call i32 @version_9(i16 %0)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %10 = icmp eq i32 %1, %2
  br i1 %10, label %true, label %error

true:                                             ; preds = %comparisons
  %11 = icmp eq i32 %1, %3
  br i1 %11, label %true1, label %error

true1:                                            ; preds = %true
  %12 = icmp eq i32 %1, %4
  br i1 %12, label %true2, label %error

true2:                                            ; preds = %true1
  %13 = icmp eq i32 %1, %5
  br i1 %13, label %true3, label %error

true3:                                            ; preds = %true2
  %14 = icmp eq i32 %1, %6
  br i1 %14, label %true4, label %error

true4:                                            ; preds = %true3
  %15 = icmp eq i32 %1, %7
  br i1 %15, label %true5, label %error

true5:                                            ; preds = %true4
  %16 = icmp eq i32 %1, %8
  br i1 %16, label %true6, label %error

true6:                                            ; preds = %true5
  %17 = icmp eq i32 %1, %9
  br i1 %17, label %true7, label %error

true7:                                            ; preds = %true6
  ret i32 %1

error:                                            ; preds = %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_2(i16 noundef signext %x) #0 {
entry:
  %0 = icmp ne i16 %x, 0
  %shr.0.neg = sext i1 %0 to i32
  ret i32 %shr.0.neg
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_3(i16 noundef signext %x) #0 {
entry:
  %icmp.0.not = icmp ne i16 %x, 0
  %. = sext i1 %icmp.0.not to i32
  ret i32 %.
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_4(i16 noundef signext %x) #0 {
entry:
  %0 = icmp ne i16 %x, 0
  %shr.0.neg = sext i1 %0 to i32
  ret i32 %shr.0.neg
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_5(i16 noundef signext %x) #0 {
entry:
  %icmp.0.not = icmp ne i16 %x, 0
  %. = sext i1 %icmp.0.not to i32
  ret i32 %.
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_6(i16 noundef signext %x) #0 {
entry:
  %icmp.0 = icmp ne i16 %x, 0
  %. = sext i1 %icmp.0 to i32
  ret i32 %.
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_7(i16 noundef signext %x) #0 {
entry:
  %icmp.0 = icmp ne i16 %x, 0
  %. = sext i1 %icmp.0 to i32
  ret i32 %.
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_8(i16 noundef signext %x) #0 {
entry:
  %icmp.0 = icmp ne i16 %x, 0
  %. = sext i1 %icmp.0 to i32
  ret i32 %.
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_9(i16 noundef signext %x) #0 {
entry:
  %icmp.0 = icmp ne i16 %x, 0
  %. = sext i1 %icmp.0 to i32
  ret i32 %.
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_1(i16 noundef signext %x) #0 {
entry:
  %x.addr = alloca i16, align 2
  %u = alloca i16, align 2
  %v = alloca i32, align 4
  store i16 %x, ptr %x.addr, align 2
  %0 = load i16, ptr %x.addr, align 2
  store i16 %0, ptr %u, align 2
  %1 = load i16, ptr %u, align 2
  %conv = zext i16 %1 to i32
  store i32 %conv, ptr %v, align 4
  %2 = load i32, ptr %v, align 4
  %not = xor i32 %2, -1
  %add = add i32 %not, 1
  store i32 %add, ptr %v, align 4
  %3 = load i32, ptr %v, align 4
  %shr = lshr i32 %3, 31
  store i32 %shr, ptr %v, align 4
  %4 = load i32, ptr %v, align 4
  %sub = sub nsw i32 0, %4
  ret i32 %sub
}

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
