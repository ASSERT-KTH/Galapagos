; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/0_flac_get_max_frame_size.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/0_flac_get_max_frame_size.run.c"
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
  %call1 = call i32 @n_version_call(i32 noundef 0, i32 noundef 0, i32 noundef 0)
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
define internal i32 @n_version_call(i32 noundef %0, i32 noundef %1, i32 noundef %2) #0 {
entry:
  %3 = call i32 @version_1(i32 %0, i32 %1, i32 %2)
  %4 = call i32 @version_2(i32 %0, i32 %1, i32 %2)
  %5 = call i32 @version_3(i32 %0, i32 %1, i32 %2)
  %6 = call i32 @version_4(i32 %0, i32 %1, i32 %2)
  %7 = call i32 @version_5(i32 %0, i32 %1, i32 %2)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %8 = icmp eq i32 %3, %4
  br i1 %8, label %true, label %error

true:                                             ; preds = %comparisons
  %9 = icmp eq i32 %3, %5
  br i1 %9, label %true1, label %error

true1:                                            ; preds = %true
  %10 = icmp eq i32 %3, %6
  br i1 %10, label %true2, label %error

true2:                                            ; preds = %true1
  %11 = icmp eq i32 %3, %7
  br i1 %11, label %true3, label %error

true3:                                            ; preds = %true2
  ret i32 %3

error:                                            ; preds = %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_2(i32 noundef %blocksize, i32 noundef %ch, i32 noundef %bps) #0 {
entry:
  %blocksize.addr = alloca i32, align 4
  %ch.addr = alloca i32, align 4
  %bps.addr = alloca i32, align 4
  %count = alloca i32, align 4
  %frame_payload = alloca i32, align 4
  store i32 %blocksize, ptr %blocksize.addr, align 4
  store i32 %ch, ptr %ch.addr, align 4
  store i32 %bps, ptr %bps.addr, align 4
  store i32 16, ptr %count, align 4
  %0 = load i32, ptr %ch.addr, align 4
  %1 = load i32, ptr %bps.addr, align 4
  %add = add nsw i32 7, %1
  %add1 = add nsw i32 %add, 7
  %div = sdiv i32 %add1, 8
  %mul = mul nsw i32 %0, %div
  %2 = load i32, ptr %count, align 4
  %add2 = add nsw i32 %2, %mul
  store i32 %add2, ptr %count, align 4
  %3 = load i32, ptr %ch.addr, align 4
  %cmp = icmp eq i32 %3, 2
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %4 = load i32, ptr %bps.addr, align 4
  %mul3 = mul nsw i32 2, %4
  %add4 = add nsw i32 %mul3, 1
  %5 = load i32, ptr %blocksize.addr, align 4
  %mul5 = mul nsw i32 %add4, %5
  %add6 = add nsw i32 %mul5, 7
  %div7 = sdiv i32 %add6, 8
  br label %cond.end

cond.false:                                       ; preds = %entry
  %6 = load i32, ptr %ch.addr, align 4
  %7 = load i32, ptr %bps.addr, align 4
  %mul8 = mul nsw i32 %6, %7
  %8 = load i32, ptr %blocksize.addr, align 4
  %mul9 = mul nsw i32 %mul8, %8
  %add10 = add nsw i32 %mul9, 7
  %div11 = sdiv i32 %add10, 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %div7, %cond.true ], [ %div11, %cond.false ]
  store i32 %cond, ptr %frame_payload, align 4
  %9 = load i32, ptr %frame_payload, align 4
  %10 = load i32, ptr %count, align 4
  %add12 = add nsw i32 %10, %9
  store i32 %add12, ptr %count, align 4
  %11 = load i32, ptr %count, align 4
  %add13 = add nsw i32 %11, 2
  store i32 %add13, ptr %count, align 4
  %12 = load i32, ptr %count, align 4
  ret i32 %12
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_3(i32 noundef %blocksize, i32 noundef %ch, i32 noundef %bps) #0 {
entry:
  %blocksize.addr = alloca i32, align 4
  %ch.addr = alloca i32, align 4
  %bps.addr = alloca i32, align 4
  %count = alloca i32, align 4
  %size = alloca i32, align 4
  store i32 %blocksize, ptr %blocksize.addr, align 4
  store i32 %ch, ptr %ch.addr, align 4
  store i32 %bps, ptr %bps.addr, align 4
  store i32 16, ptr %count, align 4
  %0 = load i32, ptr %ch.addr, align 4
  %1 = load i32, ptr %bps.addr, align 4
  %add = add nsw i32 7, %1
  %add1 = add nsw i32 %add, 7
  %div = sdiv i32 %add1, 8
  %mul = mul nsw i32 %0, %div
  %2 = load i32, ptr %count, align 4
  %add2 = add nsw i32 %2, %mul
  store i32 %add2, ptr %count, align 4
  %3 = load i32, ptr %ch.addr, align 4
  %cmp = icmp eq i32 %3, 2
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %4 = load i32, ptr %bps.addr, align 4
  %mul3 = mul nsw i32 2, %4
  %add4 = add nsw i32 %mul3, 1
  %5 = load i32, ptr %blocksize.addr, align 4
  %mul5 = mul nsw i32 %add4, %5
  %add6 = add nsw i32 %mul5, 7
  %div7 = sdiv i32 %add6, 8
  br label %cond.end

cond.false:                                       ; preds = %entry
  %6 = load i32, ptr %ch.addr, align 4
  %7 = load i32, ptr %bps.addr, align 4
  %mul8 = mul nsw i32 %6, %7
  %8 = load i32, ptr %blocksize.addr, align 4
  %mul9 = mul nsw i32 %mul8, %8
  %add10 = add nsw i32 %mul9, 7
  %div11 = sdiv i32 %add10, 8
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %div7, %cond.true ], [ %div11, %cond.false ]
  store i32 %cond, ptr %size, align 4
  %9 = load i32, ptr %size, align 4
  %10 = load i32, ptr %count, align 4
  %add12 = add nsw i32 %10, %9
  store i32 %add12, ptr %count, align 4
  %11 = load i32, ptr %count, align 4
  %add13 = add nsw i32 %11, 2
  store i32 %add13, ptr %count, align 4
  %12 = load i32, ptr %count, align 4
  ret i32 %12
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_4(i32 noundef %blocksize, i32 noundef %ch, i32 noundef %bps) #0 {
entry:
  %blocksize.addr = alloca i32, align 4
  %ch.addr = alloca i32, align 4
  %bps.addr = alloca i32, align 4
  %count = alloca i32, align 4
  store i32 %blocksize, ptr %blocksize.addr, align 4
  store i32 %ch, ptr %ch.addr, align 4
  store i32 %bps, ptr %bps.addr, align 4
  %0 = load i32, ptr %ch.addr, align 4
  %1 = load i32, ptr %bps.addr, align 4
  %add = add nsw i32 %1, 14
  %div = sdiv i32 %add, 8
  %mul = mul nsw i32 %0, %div
  %add1 = add nsw i32 16, %mul
  store i32 %add1, ptr %count, align 4
  %2 = load i32, ptr %ch.addr, align 4
  %cmp = icmp eq i32 %2, 2
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %3 = load i32, ptr %bps.addr, align 4
  %mul2 = mul nsw i32 2, %3
  %add3 = add nsw i32 %mul2, 1
  %4 = load i32, ptr %blocksize.addr, align 4
  %mul4 = mul nsw i32 %add3, %4
  %add5 = add nsw i32 %mul4, 7
  %div6 = sdiv i32 %add5, 8
  %5 = load i32, ptr %count, align 4
  %add7 = add nsw i32 %5, %div6
  store i32 %add7, ptr %count, align 4
  br label %if.end

if.else:                                          ; preds = %entry
  %6 = load i32, ptr %ch.addr, align 4
  %7 = load i32, ptr %bps.addr, align 4
  %mul8 = mul nsw i32 %6, %7
  %8 = load i32, ptr %blocksize.addr, align 4
  %mul9 = mul nsw i32 %mul8, %8
  %add10 = add nsw i32 %mul9, 7
  %div11 = sdiv i32 %add10, 8
  %9 = load i32, ptr %count, align 4
  %add12 = add nsw i32 %9, %div11
  store i32 %add12, ptr %count, align 4
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  %10 = load i32, ptr %count, align 4
  %add13 = add nsw i32 %10, 2
  store i32 %add13, ptr %count, align 4
  %11 = load i32, ptr %count, align 4
  ret i32 %11
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_5(i32 noundef %blocksize, i32 noundef %ch, i32 noundef %bps) #0 {
entry:
  %blocksize.addr = alloca i32, align 4
  %ch.addr = alloca i32, align 4
  %bps.addr = alloca i32, align 4
  %count = alloca i32, align 4
  %overhead = alloca i32, align 4
  store i32 %blocksize, ptr %blocksize.addr, align 4
  store i32 %ch, ptr %ch.addr, align 4
  store i32 %bps, ptr %bps.addr, align 4
  store i32 16, ptr %count, align 4
  %0 = load i32, ptr %bps.addr, align 4
  %add = add nsw i32 7, %0
  %add1 = add nsw i32 %add, 7
  %div = sdiv i32 %add1, 8
  store i32 %div, ptr %overhead, align 4
  %1 = load i32, ptr %ch.addr, align 4
  %2 = load i32, ptr %overhead, align 4
  %mul = mul nsw i32 %1, %2
  %3 = load i32, ptr %count, align 4
  %add2 = add nsw i32 %3, %mul
  store i32 %add2, ptr %count, align 4
  %4 = load i32, ptr %ch.addr, align 4
  %cmp = icmp eq i32 %4, 2
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %5 = load i32, ptr %bps.addr, align 4
  %mul3 = mul nsw i32 2, %5
  %add4 = add nsw i32 %mul3, 1
  %6 = load i32, ptr %blocksize.addr, align 4
  %mul5 = mul nsw i32 %add4, %6
  %add6 = add nsw i32 %mul5, 7
  %div7 = sdiv i32 %add6, 8
  %7 = load i32, ptr %count, align 4
  %add8 = add nsw i32 %7, %div7
  store i32 %add8, ptr %count, align 4
  br label %if.end

if.else:                                          ; preds = %entry
  %8 = load i32, ptr %ch.addr, align 4
  %9 = load i32, ptr %bps.addr, align 4
  %mul9 = mul nsw i32 %8, %9
  %10 = load i32, ptr %blocksize.addr, align 4
  %mul10 = mul nsw i32 %mul9, %10
  %add11 = add nsw i32 %mul10, 7
  %div12 = sdiv i32 %add11, 8
  %11 = load i32, ptr %count, align 4
  %add13 = add nsw i32 %11, %div12
  store i32 %add13, ptr %count, align 4
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  %12 = load i32, ptr %count, align 4
  %add14 = add nsw i32 %12, 2
  store i32 %add14, ptr %count, align 4
  %13 = load i32, ptr %count, align 4
  ret i32 %13
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_1(i32 noundef %blocksize, i32 noundef %ch, i32 noundef %bps) #0 {
entry:
  %blocksize.addr = alloca i32, align 4
  %ch.addr = alloca i32, align 4
  %bps.addr = alloca i32, align 4
  %count = alloca i32, align 4
  store i32 %blocksize, ptr %blocksize.addr, align 4
  store i32 %ch, ptr %ch.addr, align 4
  store i32 %bps, ptr %bps.addr, align 4
  store i32 16, ptr %count, align 4
  %0 = load i32, ptr %ch.addr, align 4
  %1 = load i32, ptr %bps.addr, align 4
  %add = add nsw i32 7, %1
  %add1 = add nsw i32 %add, 7
  %div = sdiv i32 %add1, 8
  %mul = mul nsw i32 %0, %div
  %2 = load i32, ptr %count, align 4
  %add2 = add nsw i32 %2, %mul
  store i32 %add2, ptr %count, align 4
  %3 = load i32, ptr %ch.addr, align 4
  %cmp = icmp eq i32 %3, 2
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %4 = load i32, ptr %bps.addr, align 4
  %mul3 = mul nsw i32 2, %4
  %add4 = add nsw i32 %mul3, 1
  %5 = load i32, ptr %blocksize.addr, align 4
  %mul5 = mul nsw i32 %add4, %5
  %add6 = add nsw i32 %mul5, 7
  %div7 = sdiv i32 %add6, 8
  %6 = load i32, ptr %count, align 4
  %add8 = add nsw i32 %6, %div7
  store i32 %add8, ptr %count, align 4
  br label %if.end

if.else:                                          ; preds = %entry
  %7 = load i32, ptr %ch.addr, align 4
  %8 = load i32, ptr %bps.addr, align 4
  %mul9 = mul nsw i32 %7, %8
  %9 = load i32, ptr %blocksize.addr, align 4
  %mul10 = mul nsw i32 %mul9, %9
  %add11 = add nsw i32 %mul10, 7
  %div12 = sdiv i32 %add11, 8
  %10 = load i32, ptr %count, align 4
  %add13 = add nsw i32 %10, %div12
  store i32 %add13, ptr %count, align 4
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  %11 = load i32, ptr %count, align 4
  %add14 = add nsw i32 %11, 2
  store i32 %add14, ptr %count, align 4
  %12 = load i32, ptr %count, align 4
  ret i32 %12
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
