; ModuleID = '/home/javier/Galapagos/functions/openssl/3__booth_recode_w5.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/3__booth_recode_w5.run.c"
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
define dso_local i32 @version_2(i32 noundef %in) #0 {
entry:
  %shr.0 = lshr i32 %in, 5
  %sub.0 = add nsw i32 %shr.0, -1
  %xor.0 = sub nsw i32 0, %shr.0
  %sub.2 = sub i32 63, %in
  %iand.0 = and i32 %sub.2, %xor.0
  %iand.1 = and i32 %sub.0, %in
  %ior.0 = or i32 %iand.1, %iand.0
  %iand.2 = shl i32 %ior.0, 1
  %add.011 = and i32 %iand.2, 2
  %shr.112 = add i32 %add.011, %ior.0
  %shl.0 = and i32 %shr.112, -2
  %iand.3 = and i32 %xor.0, 1
  %add.1 = or i32 %shl.0, %iand.3
  ret i32 %add.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_3(i32 noundef %in) #0 {
entry:
  %shr.0 = lshr i32 %in, 5
  %sub.0 = add nsw i32 %shr.0, -1
  %xor.0 = sub nsw i32 0, %shr.0
  %sub.1 = sub i32 63, %in
  %iand.0 = and i32 %sub.1, %xor.0
  %iand.1 = and i32 %sub.0, %in
  %ior.0 = or i32 %iand.1, %iand.0
  %iand.2 = shl i32 %ior.0, 1
  %add.011 = and i32 %iand.2, 2
  %shr.112 = add i32 %add.011, %ior.0
  %shl.0 = and i32 %shr.112, -2
  %iand.3 = and i32 %xor.0, 1
  %add.1 = or i32 %shl.0, %iand.3
  ret i32 %add.1
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_1(i32 noundef %in) #0 {
entry:
  %in.addr = alloca i32, align 4
  %s = alloca i32, align 4
  %d = alloca i32, align 4
  store i32 %in, ptr %in.addr, align 4
  %0 = load i32, ptr %in.addr, align 4
  %shr = lshr i32 %0, 5
  %sub = sub i32 %shr, 1
  %not = xor i32 %sub, -1
  store i32 %not, ptr %s, align 4
  %1 = load i32, ptr %in.addr, align 4
  %sub1 = sub i32 64, %1
  %sub2 = sub i32 %sub1, 1
  store i32 %sub2, ptr %d, align 4
  %2 = load i32, ptr %d, align 4
  %3 = load i32, ptr %s, align 4
  %and = and i32 %2, %3
  %4 = load i32, ptr %in.addr, align 4
  %5 = load i32, ptr %s, align 4
  %not3 = xor i32 %5, -1
  %and4 = and i32 %4, %not3
  %or = or i32 %and, %and4
  store i32 %or, ptr %d, align 4
  %6 = load i32, ptr %d, align 4
  %shr5 = lshr i32 %6, 1
  %7 = load i32, ptr %d, align 4
  %and6 = and i32 %7, 1
  %add = add i32 %shr5, %and6
  store i32 %add, ptr %d, align 4
  %8 = load i32, ptr %d, align 4
  %shl = shl i32 %8, 1
  %9 = load i32, ptr %s, align 4
  %and7 = and i32 %9, 1
  %add8 = add i32 %shl, %and7
  ret i32 %add8
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
