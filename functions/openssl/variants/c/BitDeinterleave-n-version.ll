; ModuleID = '/home/javier/Galapagos/functions/openssl/1_BitDeinterleave.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/1_BitDeinterleave.run.c"
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
  br label %comparisons

comparisons:                                      ; preds = %entry
  %5 = icmp eq i64 %1, %2
  br i1 %5, label %true, label %error

true:                                             ; preds = %comparisons
  %6 = icmp eq i64 %1, %3
  br i1 %6, label %true1, label %error

true1:                                            ; preds = %true
  %7 = icmp eq i64 %1, %4
  br i1 %7, label %true2, label %error

true2:                                            ; preds = %true1
  ret i64 %1

error:                                            ; preds = %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_2(i64 noundef %Ai) #0 {
entry:
  %Ai.addr = alloca i64, align 8
  %even = alloca i64, align 8
  %odd = alloca i64, align 8
  %i = alloca i32, align 4
  store i64 %Ai, ptr %Ai.addr, align 8
  store i64 0, ptr %even, align 8
  store i64 0, ptr %odd, align 8
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
  %4 = load i64, ptr %even, align 8
  %or = or i64 %4, %shl
  store i64 %or, ptr %even, align 8
  %5 = load i64, ptr %Ai.addr, align 8
  %6 = load i32, ptr %i, align 4
  %mul2 = mul nsw i32 2, %6
  %add = add nsw i32 %mul2, 1
  %sh_prom3 = zext i32 %add to i64
  %shr4 = lshr i64 %5, %sh_prom3
  %and5 = and i64 %shr4, 1
  %7 = load i32, ptr %i, align 4
  %sh_prom6 = zext i32 %7 to i64
  %shl7 = shl i64 %and5, %sh_prom6
  %8 = load i64, ptr %odd, align 8
  %or8 = or i64 %8, %shl7
  store i64 %or8, ptr %odd, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %9 = load i32, ptr %i, align 4
  %inc = add nsw i32 %9, 1
  store i32 %inc, ptr %i, align 4
  br label %for.cond, !llvm.loop !8

for.end:                                          ; preds = %for.cond
  %10 = load i64, ptr %odd, align 8
  %shl9 = shl i64 %10, 32
  %11 = load i64, ptr %even, align 8
  %or10 = or i64 %shl9, %11
  ret i64 %or10
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_3(i64 noundef %Ai) #0 {
entry:
  %Ai.addr = alloca i64, align 8
  %deinterleaved = alloca i64, align 8
  %i = alloca i32, align 4
  store i64 %Ai, ptr %Ai.addr, align 8
  store i64 0, ptr %deinterleaved, align 8
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
  %4 = load i64, ptr %deinterleaved, align 8
  %or = or i64 %4, %shl
  store i64 %or, ptr %deinterleaved, align 8
  %5 = load i64, ptr %Ai.addr, align 8
  %6 = load i32, ptr %i, align 4
  %mul2 = mul nsw i32 2, %6
  %add = add nsw i32 %mul2, 1
  %sh_prom3 = zext i32 %add to i64
  %shr4 = lshr i64 %5, %sh_prom3
  %and5 = and i64 %shr4, 1
  %7 = load i32, ptr %i, align 4
  %add6 = add nsw i32 %7, 32
  %sh_prom7 = zext i32 %add6 to i64
  %shl8 = shl i64 %and5, %sh_prom7
  %8 = load i64, ptr %deinterleaved, align 8
  %or9 = or i64 %8, %shl8
  store i64 %or9, ptr %deinterleaved, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %9 = load i32, ptr %i, align 4
  %inc = add nsw i32 %9, 1
  store i32 %inc, ptr %i, align 4
  br label %for.cond, !llvm.loop !9

for.end:                                          ; preds = %for.cond
  %10 = load i64, ptr %deinterleaved, align 8
  ret i64 %10
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_4(i64 noundef %Ai) #0 {
entry:
  %Ai.addr = alloca i64, align 8
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %z = alloca i32, align 4
  %w = alloca i32, align 4
  %i = alloca i32, align 4
  store i64 %Ai, ptr %Ai.addr, align 8
  %0 = load i64, ptr %Ai.addr, align 8
  %and = and i64 %0, 4294967295
  %conv = trunc i64 %and to i32
  store i32 %conv, ptr %x, align 4
  %1 = load i64, ptr %Ai.addr, align 8
  %shr = lshr i64 %1, 32
  %conv1 = trunc i64 %shr to i32
  store i32 %conv1, ptr %y, align 4
  store i32 0, ptr %z, align 4
  store i32 0, ptr %w, align 4
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %2 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %2, 16
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %3 = load i32, ptr %x, align 4
  %4 = load i32, ptr %i, align 4
  %mul = mul nsw i32 2, %4
  %shl = shl i32 1, %mul
  %and3 = and i32 %3, %shl
  %5 = load i32, ptr %i, align 4
  %shr4 = lshr i32 %and3, %5
  %6 = load i32, ptr %z, align 4
  %or = or i32 %6, %shr4
  store i32 %or, ptr %z, align 4
  %7 = load i32, ptr %y, align 4
  %8 = load i32, ptr %i, align 4
  %mul5 = mul nsw i32 2, %8
  %shl6 = shl i32 1, %mul5
  %and7 = and i32 %7, %shl6
  %9 = load i32, ptr %i, align 4
  %sub = sub nsw i32 %9, 16
  %shr8 = lshr i32 %and7, %sub
  %10 = load i32, ptr %z, align 4
  %or9 = or i32 %10, %shr8
  store i32 %or9, ptr %z, align 4
  %11 = load i32, ptr %x, align 4
  %12 = load i32, ptr %i, align 4
  %mul10 = mul nsw i32 2, %12
  %add = add nsw i32 %mul10, 1
  %shl11 = shl i32 1, %add
  %and12 = and i32 %11, %shl11
  %13 = load i32, ptr %i, align 4
  %add13 = add nsw i32 %13, 1
  %shr14 = lshr i32 %and12, %add13
  %14 = load i32, ptr %w, align 4
  %or15 = or i32 %14, %shr14
  store i32 %or15, ptr %w, align 4
  %15 = load i32, ptr %y, align 4
  %16 = load i32, ptr %i, align 4
  %mul16 = mul nsw i32 2, %16
  %add17 = add nsw i32 %mul16, 1
  %shl18 = shl i32 1, %add17
  %and19 = and i32 %15, %shl18
  %17 = load i32, ptr %i, align 4
  %sub20 = sub nsw i32 %17, 15
  %shr21 = lshr i32 %and19, %sub20
  %18 = load i32, ptr %w, align 4
  %or22 = or i32 %18, %shr21
  store i32 %or22, ptr %w, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %19 = load i32, ptr %i, align 4
  %inc = add nsw i32 %19, 1
  store i32 %inc, ptr %i, align 4
  br label %for.cond, !llvm.loop !10

for.end:                                          ; preds = %for.cond
  %20 = load i32, ptr %w, align 4
  %conv23 = zext i32 %20 to i64
  %shl24 = shl i64 %conv23, 32
  %21 = load i32, ptr %z, align 4
  %conv25 = zext i32 %21 to i64
  %or26 = or i64 %shl24, %conv25
  ret i64 %or26
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
