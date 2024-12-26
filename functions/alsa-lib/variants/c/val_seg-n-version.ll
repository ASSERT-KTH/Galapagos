; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/4_val_seg.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/4_val_seg.run.c"
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
  %call1 = call i32 @n_version_call(i32 noundef 0)
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
define internal i32 @n_version_call(i32 noundef %0) #0 {
entry:
  %1 = call i32 @version_1(i32 %0)
  %2 = call i32 @version_2(i32 %0)
  %3 = call i32 @version_3(i32 %0)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %4 = icmp eq i32 %1, %2
  br i1 %4, label %true, label %error

true:                                             ; preds = %comparisons
  %5 = icmp eq i32 %1, %3
  br i1 %5, label %true1, label %error

true1:                                            ; preds = %true
  ret i32 %1

error:                                            ; preds = %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_2(i32 noundef %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  %r = alloca i32, align 4
  store i32 %val, ptr %val.addr, align 4
  store i32 1, ptr %r, align 4
  %0 = load i32, ptr %val.addr, align 4
  %shr = ashr i32 %0, 8
  store i32 %shr, ptr %val.addr, align 4
  %1 = load i32, ptr %val.addr, align 4
  %and = and i32 %1, 240
  %tobool = icmp ne i32 %and, 0
  %2 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 4, i32 0
  %3 = load i32, ptr %r, align 4
  %add = add nsw i32 %3, %cond
  store i32 %add, ptr %r, align 4
  %4 = load i32, ptr %val.addr, align 4
  %and1 = and i32 %4, 240
  %tobool2 = icmp ne i32 %and1, 0
  %5 = zext i1 %tobool2 to i64
  %cond3 = select i1 %tobool2, i32 4, i32 0
  %6 = load i32, ptr %val.addr, align 4
  %shr4 = ashr i32 %6, %cond3
  store i32 %shr4, ptr %val.addr, align 4
  %7 = load i32, ptr %val.addr, align 4
  %and5 = and i32 %7, 12
  %tobool6 = icmp ne i32 %and5, 0
  %8 = zext i1 %tobool6 to i64
  %cond7 = select i1 %tobool6, i32 2, i32 0
  %9 = load i32, ptr %r, align 4
  %add8 = add nsw i32 %9, %cond7
  store i32 %add8, ptr %r, align 4
  %10 = load i32, ptr %val.addr, align 4
  %and9 = and i32 %10, 12
  %tobool10 = icmp ne i32 %and9, 0
  %11 = zext i1 %tobool10 to i64
  %cond11 = select i1 %tobool10, i32 2, i32 0
  %12 = load i32, ptr %val.addr, align 4
  %shr12 = ashr i32 %12, %cond11
  store i32 %shr12, ptr %val.addr, align 4
  %13 = load i32, ptr %val.addr, align 4
  %and13 = and i32 %13, 2
  %tobool14 = icmp ne i32 %and13, 0
  %14 = zext i1 %tobool14 to i64
  %cond15 = select i1 %tobool14, i32 1, i32 0
  %15 = load i32, ptr %r, align 4
  %add16 = add nsw i32 %15, %cond15
  store i32 %add16, ptr %r, align 4
  %16 = load i32, ptr %r, align 4
  ret i32 %16
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_3(i32 noundef %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  %r = alloca i32, align 4
  store i32 %val, ptr %val.addr, align 4
  store i32 1, ptr %r, align 4
  %0 = load i32, ptr %val.addr, align 4
  %shr = ashr i32 %0, 8
  store i32 %shr, ptr %val.addr, align 4
  %1 = load i32, ptr %val.addr, align 4
  %and = and i32 %1, 240
  %tobool = icmp ne i32 %and, 0
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %r, align 4
  %add = add nsw i32 %2, 4
  store i32 %add, ptr %r, align 4
  %3 = load i32, ptr %val.addr, align 4
  %shr1 = ashr i32 %3, 4
  store i32 %shr1, ptr %val.addr, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %4 = load i32, ptr %val.addr, align 4
  %and2 = and i32 %4, 12
  %tobool3 = icmp ne i32 %and2, 0
  br i1 %tobool3, label %if.then4, label %if.end7

if.then4:                                         ; preds = %if.end
  %5 = load i32, ptr %r, align 4
  %add5 = add nsw i32 %5, 2
  store i32 %add5, ptr %r, align 4
  %6 = load i32, ptr %val.addr, align 4
  %shr6 = ashr i32 %6, 2
  store i32 %shr6, ptr %val.addr, align 4
  br label %if.end7

if.end7:                                          ; preds = %if.then4, %if.end
  %7 = load i32, ptr %val.addr, align 4
  %and8 = and i32 %7, 2
  %tobool9 = icmp ne i32 %and8, 0
  br i1 %tobool9, label %if.then10, label %if.end12

if.then10:                                        ; preds = %if.end7
  %8 = load i32, ptr %r, align 4
  %add11 = add nsw i32 %8, 1
  store i32 %add11, ptr %r, align 4
  br label %if.end12

if.end12:                                         ; preds = %if.then10, %if.end7
  %9 = load i32, ptr %r, align 4
  ret i32 %9
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_1(i32 noundef %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  %r = alloca i32, align 4
  store i32 %val, ptr %val.addr, align 4
  store i32 1, ptr %r, align 4
  %0 = load i32, ptr %val.addr, align 4
  %shr = ashr i32 %0, 8
  store i32 %shr, ptr %val.addr, align 4
  %1 = load i32, ptr %val.addr, align 4
  %and = and i32 %1, 240
  %tobool = icmp ne i32 %and, 0
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %val.addr, align 4
  %shr1 = ashr i32 %2, 4
  store i32 %shr1, ptr %val.addr, align 4
  %3 = load i32, ptr %r, align 4
  %add = add nsw i32 %3, 4
  store i32 %add, ptr %r, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %4 = load i32, ptr %val.addr, align 4
  %and2 = and i32 %4, 12
  %tobool3 = icmp ne i32 %and2, 0
  br i1 %tobool3, label %if.then4, label %if.end7

if.then4:                                         ; preds = %if.end
  %5 = load i32, ptr %val.addr, align 4
  %shr5 = ashr i32 %5, 2
  store i32 %shr5, ptr %val.addr, align 4
  %6 = load i32, ptr %r, align 4
  %add6 = add nsw i32 %6, 2
  store i32 %add6, ptr %r, align 4
  br label %if.end7

if.end7:                                          ; preds = %if.then4, %if.end
  %7 = load i32, ptr %val.addr, align 4
  %and8 = and i32 %7, 2
  %tobool9 = icmp ne i32 %and8, 0
  br i1 %tobool9, label %if.then10, label %if.end12

if.then10:                                        ; preds = %if.end7
  %8 = load i32, ptr %r, align 4
  %add11 = add nsw i32 %8, 1
  store i32 %add11, ptr %r, align 4
  br label %if.end12

if.end12:                                         ; preds = %if.then10, %if.end7
  %9 = load i32, ptr %r, align 4
  ret i32 %9
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
