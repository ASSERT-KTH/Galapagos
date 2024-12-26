; ModuleID = '/home/javier/Galapagos/functions/openssl/2_BitInterleave.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/2_BitInterleave.run.c"
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
  %call1 = call i64 @n_version_call(i64 noundef 42)
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
define internal i64 @n_version_call(i64 noundef %0) #0 {
entry:
  %1 = call i64 @version_1(i64 %0)
  %2 = call i64 @version_2(i64 %0)
  %3 = call i64 @version_3(i64 %0)
  %4 = call i64 @version_4(i64 %0)
  %5 = call i64 @version_5(i64 %0)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %6 = icmp eq i64 %1, %2
  br i1 %6, label %true, label %error

true:                                             ; preds = %comparisons
  %7 = icmp eq i64 %1, %3
  br i1 %7, label %true1, label %error

true1:                                            ; preds = %true
  %8 = icmp eq i64 %1, %4
  br i1 %8, label %true2, label %error

true2:                                            ; preds = %true1
  %9 = icmp eq i64 %1, %5
  br i1 %9, label %true3, label %error

true3:                                            ; preds = %true2
  ret i64 %1

error:                                            ; preds = %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_2(i64 noundef %Ai) #0 {
entry:
  %Ai.addr = alloca i64, align 8
  %result = alloca i64, align 8
  %mask1 = alloca i64, align 8
  %i = alloca i32, align 4
  store i64 %Ai, ptr %Ai.addr, align 8
  store i64 0, ptr %result, align 8
  store i64 6148914691236517205, ptr %mask1, align 8
  %0 = load i64, ptr %Ai.addr, align 8
  %1 = load i64, ptr %Ai.addr, align 8
  %shl = shl i64 %1, 16
  %or = or i64 %0, %shl
  %and = and i64 %or, 281470681808895
  store i64 %and, ptr %Ai.addr, align 8
  %2 = load i64, ptr %Ai.addr, align 8
  %3 = load i64, ptr %Ai.addr, align 8
  %shl1 = shl i64 %3, 8
  %or2 = or i64 %2, %shl1
  %and3 = and i64 %or2, 71777214294589695
  store i64 %and3, ptr %Ai.addr, align 8
  %4 = load i64, ptr %Ai.addr, align 8
  %5 = load i64, ptr %Ai.addr, align 8
  %shl4 = shl i64 %5, 4
  %or5 = or i64 %4, %shl4
  %and6 = and i64 %or5, 1085102592571150095
  store i64 %and6, ptr %Ai.addr, align 8
  %6 = load i64, ptr %Ai.addr, align 8
  %7 = load i64, ptr %Ai.addr, align 8
  %shl7 = shl i64 %7, 2
  %or8 = or i64 %6, %shl7
  %and9 = and i64 %or8, 3689348814741910323
  store i64 %and9, ptr %Ai.addr, align 8
  %8 = load i64, ptr %Ai.addr, align 8
  %9 = load i64, ptr %Ai.addr, align 8
  %shl10 = shl i64 %9, 1
  %or11 = or i64 %8, %shl10
  %and12 = and i64 %or11, 6148914691236517205
  store i64 %and12, ptr %Ai.addr, align 8
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %10 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %10, 64
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %11 = load i64, ptr %Ai.addr, align 8
  %12 = load i64, ptr %mask1, align 8
  %and13 = and i64 %11, %12
  %13 = load i32, ptr %i, align 4
  %sh_prom = zext i32 %13 to i64
  %shl14 = shl i64 %and13, %sh_prom
  %14 = load i64, ptr %result, align 8
  %or15 = or i64 %14, %shl14
  store i64 %or15, ptr %result, align 8
  %15 = load i64, ptr %Ai.addr, align 8
  %shr = lshr i64 %15, 1
  %16 = load i64, ptr %mask1, align 8
  %and16 = and i64 %shr, %16
  %17 = load i32, ptr %i, align 4
  %add = add nsw i32 %17, 1
  %sh_prom17 = zext i32 %add to i64
  %shl18 = shl i64 %and16, %sh_prom17
  %18 = load i64, ptr %result, align 8
  %or19 = or i64 %18, %shl18
  store i64 %or19, ptr %result, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %19 = load i32, ptr %i, align 4
  %add20 = add nsw i32 %19, 2
  store i32 %add20, ptr %i, align 4
  br label %for.cond, !llvm.loop !8

for.end:                                          ; preds = %for.cond
  %20 = load i64, ptr %result, align 8
  ret i64 %20
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_3(i64 noundef %Ai) #0 {
entry:
  %Ai.addr = alloca i64, align 8
  %result = alloca i64, align 8
  %i = alloca i32, align 4
  store i64 %Ai, ptr %Ai.addr, align 8
  store i64 0, ptr %result, align 8
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %0, 64
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %1 = load i64, ptr %Ai.addr, align 8
  %2 = load i32, ptr %i, align 4
  %div = sdiv i32 %2, 2
  %sh_prom = zext i32 %div to i64
  %shr = lshr i64 %1, %sh_prom
  %and = and i64 %shr, 1
  %3 = load i32, ptr %i, align 4
  %sh_prom1 = zext i32 %3 to i64
  %shl = shl i64 %and, %sh_prom1
  %4 = load i64, ptr %result, align 8
  %or = or i64 %4, %shl
  store i64 %or, ptr %result, align 8
  %5 = load i64, ptr %Ai.addr, align 8
  %6 = load i32, ptr %i, align 4
  %div2 = sdiv i32 %6, 2
  %add = add nsw i32 %div2, 32
  %sh_prom3 = zext i32 %add to i64
  %shr4 = lshr i64 %5, %sh_prom3
  %and5 = and i64 %shr4, 1
  %7 = load i32, ptr %i, align 4
  %add6 = add nsw i32 %7, 1
  %sh_prom7 = zext i32 %add6 to i64
  %shl8 = shl i64 %and5, %sh_prom7
  %8 = load i64, ptr %result, align 8
  %or9 = or i64 %8, %shl8
  store i64 %or9, ptr %result, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %9 = load i32, ptr %i, align 4
  %add10 = add nsw i32 %9, 2
  store i32 %add10, ptr %i, align 4
  br label %for.cond, !llvm.loop !9

for.end:                                          ; preds = %for.cond
  %10 = load i64, ptr %result, align 8
  ret i64 %10
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_4(i64 noundef %Ai) #0 {
entry:
  %Ai.addr = alloca i64, align 8
  %interleaved = alloca i64, align 8
  %i = alloca i32, align 4
  store i64 %Ai, ptr %Ai.addr, align 8
  store i64 0, ptr %interleaved, align 8
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %0, 32
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %1 = load i64, ptr %Ai.addr, align 8
  %2 = load i32, ptr %i, align 4
  %mul = mul nsw i32 2, %2
  %sh_prom = zext i32 %mul to i64
  %shr = lshr i64 %1, %sh_prom
  %and = and i64 %shr, 1
  %3 = load i32, ptr %i, align 4
  %sh_prom1 = zext i32 %3 to i64
  %shl = shl i64 %and, %sh_prom1
  %4 = load i64, ptr %interleaved, align 8
  %or = or i64 %4, %shl
  store i64 %or, ptr %interleaved, align 8
  %5 = load i64, ptr %Ai.addr, align 8
  %6 = load i32, ptr %i, align 4
  %mul2 = mul nsw i32 2, %6
  %add = add nsw i32 %mul2, 1
  %sh_prom3 = zext i32 %add to i64
  %shr4 = lshr i64 %5, %sh_prom3
  %and5 = and i64 %shr4, 1
  %7 = load i32, ptr %i, align 4
  %add6 = add nsw i32 32, %7
  %sh_prom7 = zext i32 %add6 to i64
  %shl8 = shl i64 %and5, %sh_prom7
  %8 = load i64, ptr %interleaved, align 8
  %or9 = or i64 %8, %shl8
  store i64 %or9, ptr %interleaved, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %9 = load i32, ptr %i, align 4
  %inc = add nsw i32 %9, 1
  store i32 %inc, ptr %i, align 4
  br label %for.cond, !llvm.loop !10

for.end:                                          ; preds = %for.cond
  %10 = load i64, ptr %interleaved, align 8
  ret i64 %10
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_5(i64 noundef %Ai) #0 {
entry:
  %Ai.addr = alloca i64, align 8
  %result = alloca i64, align 8
  %i = alloca i32, align 4
  store i64 %Ai, ptr %Ai.addr, align 8
  store i64 0, ptr %result, align 8
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %0, 32
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %1 = load i64, ptr %Ai.addr, align 8
  %2 = load i32, ptr %i, align 4
  %sh_prom = zext i32 %2 to i64
  %shr = lshr i64 %1, %sh_prom
  %and = and i64 %shr, 1
  %3 = load i32, ptr %i, align 4
  %mul = mul nsw i32 2, %3
  %sh_prom1 = zext i32 %mul to i64
  %shl = shl i64 %and, %sh_prom1
  %4 = load i64, ptr %result, align 8
  %or = or i64 %4, %shl
  store i64 %or, ptr %result, align 8
  %5 = load i64, ptr %Ai.addr, align 8
  %6 = load i32, ptr %i, align 4
  %add = add nsw i32 %6, 32
  %sh_prom2 = zext i32 %add to i64
  %shr3 = lshr i64 %5, %sh_prom2
  %and4 = and i64 %shr3, 1
  %7 = load i32, ptr %i, align 4
  %mul5 = mul nsw i32 2, %7
  %add6 = add nsw i32 %mul5, 1
  %sh_prom7 = zext i32 %add6 to i64
  %shl8 = shl i64 %and4, %sh_prom7
  %8 = load i64, ptr %result, align 8
  %or9 = or i64 %8, %shl8
  store i64 %or9, ptr %result, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %9 = load i32, ptr %i, align 4
  %inc = add nsw i32 %9, 1
  store i32 %inc, ptr %i, align 4
  br label %for.cond, !llvm.loop !11

for.end:                                          ; preds = %for.cond
  %10 = load i64, ptr %result, align 8
  ret i64 %10
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_1(i64 noundef %Ai) #0 {
entry:
  %Ai.addr = alloca i64, align 8
  store i64 %Ai, ptr %Ai.addr, align 8
  %0 = load i64, ptr %Ai.addr, align 8
  ret i64 %0
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
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}
!10 = distinct !{!10, !7}
!11 = distinct !{!11, !7}
