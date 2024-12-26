; ModuleID = '/home/javier/Galapagos/functions/liboqs/1_fpr_lt.bc'
source_filename = "/home/javier/Galapagos/functions/liboqs/1_fpr_lt.run.c"
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
  %call1 = call i32 @n_version_call(i64 noundef 0, i64 noundef 0)
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
define internal i32 @n_version_call(i64 noundef %0, i64 noundef %1) #0 {
entry:
  %2 = call i32 @version_1(i64 %0, i64 %1)
  %3 = call i32 @version_2(i64 %0, i64 %1)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %4 = icmp eq i32 %2, %3
  br i1 %4, label %true, label %error

true:                                             ; preds = %comparisons
  ret i32 %2

error:                                            ; preds = %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_2(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %icmp.0 = icmp slt i64 %x, 0
  %x.lobit = lshr i64 %x, 63
  %0 = trunc i64 %x.lobit to i8
  %y.lobit24 = lshr i64 %y, 63
  %1 = trunc i64 %y.lobit24 to i8
  %tmpv.0.0 = select i1 %icmp.0, i8 %1, i8 %0
  %trunc.5.not = icmp eq i8 %tmpv.0.0, 0
  br i1 %trunc.5.not, label %else.1, label %then.1

common.ret:                                       ; preds = %else.1, %then.1
  %common.ret.op.in.in = phi i64 [ %sub.0, %then.1 ], [ %spec.select, %else.1 ]
  %common.ret.op.in = lshr i64 %common.ret.op.in.in, 63
  %common.ret.op = trunc i64 %common.ret.op.in to i32
  ret i32 %common.ret.op

then.1:                                           ; preds = %entry
  %sub.0 = sub i64 %y, %x
  br label %common.ret

else.1:                                           ; preds = %entry
  %tmpv.2.0 = select i1 %icmp.0, i8 %0, i8 %1
  %trunc.4.not = icmp eq i8 %tmpv.2.0, 0
  %sub.1 = select i1 %trunc.4.not, i64 %y, i64 0
  %spec.select = sub i64 %x, %sub.1
  br label %common.ret
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_1(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  %cc0 = alloca i32, align 4
  %cc1 = alloca i32, align 4
  %sx = alloca i64, align 8
  %sy = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  %0 = load i64, ptr %x.addr, align 8
  store i64 %0, ptr %sx, align 8
  %1 = load i64, ptr %y.addr, align 8
  store i64 %1, ptr %sy, align 8
  %2 = load i64, ptr %sx, align 8
  %3 = load i64, ptr %sy, align 8
  %xor = xor i64 %2, %3
  %shr = ashr i64 %xor, 63
  %not = xor i64 %shr, -1
  %4 = load i64, ptr %sy, align 8
  %and = and i64 %4, %not
  store i64 %and, ptr %sy, align 8
  %5 = load i64, ptr %sx, align 8
  %6 = load i64, ptr %sy, align 8
  %sub = sub nsw i64 %5, %6
  %shr1 = ashr i64 %sub, 63
  %conv = trunc i64 %shr1 to i32
  %and2 = and i32 %conv, 1
  store i32 %and2, ptr %cc0, align 4
  %7 = load i64, ptr %sy, align 8
  %8 = load i64, ptr %sx, align 8
  %sub3 = sub nsw i64 %7, %8
  %shr4 = ashr i64 %sub3, 63
  %conv5 = trunc i64 %shr4 to i32
  %and6 = and i32 %conv5, 1
  store i32 %and6, ptr %cc1, align 4
  %9 = load i32, ptr %cc0, align 4
  %10 = load i32, ptr %cc0, align 4
  %11 = load i32, ptr %cc1, align 4
  %xor7 = xor i32 %10, %11
  %12 = load i64, ptr %x.addr, align 8
  %13 = load i64, ptr %y.addr, align 8
  %and8 = and i64 %12, %13
  %shr9 = lshr i64 %and8, 63
  %conv10 = trunc i64 %shr9 to i32
  %and11 = and i32 %xor7, %conv10
  %xor12 = xor i32 %9, %and11
  ret i32 %xor12
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
