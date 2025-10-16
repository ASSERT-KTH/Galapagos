; ModuleID = '../functions/openssl/BitDeinterleave.bc'
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
  %call = call i32 @clock_gettime(i32 noundef 4, ptr noundef %start) #4
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %0, 2000000
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %call1 = call i64 @BitDeinterleave(i64 noundef 0)
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %1 = load i32, ptr %i, align 4
  %inc = add nsw i32 %1, 1
  store i32 %inc, ptr %i, align 4
  br label %for.cond, !llvm.loop !6

for.end:                                          ; preds = %for.cond
  %call2 = call i32 @clock_gettime(i32 noundef 4, ptr noundef %end) #4
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
define internal i64 @BitDeinterleave(i64 noundef %Ai) #0 {
entry:
  %icmp.0 = icmp ugt i64 %Ai, 10
  br i1 %icmp.0, label %then.0, label %fallthrough.0

then.0:                                           ; preds = %entry
  %shr.0 = lshr i64 %Ai, 32
  %trunc.0 = trunc i64 %shr.0 to i32
  %trunc.1 = trunc i64 %Ai to i32
  %iand.0 = and i32 %trunc.1, 65535
  %shl.0 = shl nuw nsw i32 %iand.0, 8
  %ior.0 = or i32 %shl.0, %iand.0
  %iand.1 = and i32 %ior.0, 16711935
  %shl.1 = shl nuw nsw i32 %iand.1, 4
  %ior.1 = or i32 %shl.1, %iand.1
  %iand.2 = and i32 %ior.1, 252645135
  %shl.2 = shl nuw nsw i32 %iand.2, 2
  %ior.2 = or i32 %shl.2, %iand.2
  %iand.3 = and i32 %ior.2, 858993459
  %shl.3 = shl nuw nsw i32 %iand.3, 1
  %ior.3 = or i32 %shl.3, %iand.3
  %iand.4 = and i32 %ior.3, 1431655765
  %shl.4 = shl i32 %trunc.0, 16
  %shr.1 = lshr exact i32 %shl.4, 8
  %ior.4 = or i32 %shr.1, %shl.4
  %iand.5 = and i32 %ior.4, -16711936
  %shr.2 = lshr exact i32 %iand.5, 4
  %ior.5 = or i32 %shr.2, %iand.5
  %iand.6 = and i32 %ior.5, -252645136
  %shr.3 = lshr exact i32 %iand.6, 2
  %ior.6 = or i32 %shr.3, %iand.6
  %iand.7 = and i32 %ior.6, -858993460
  %shr.4 = lshr exact i32 %iand.7, 1
  %ior.7 = or i32 %shr.4, %iand.7
  %iand.8 = and i32 %ior.7, -1431655766
  %shr.5 = lshr i32 %trunc.1, 16
  %shl.5 = shl nuw nsw i32 %shr.5, 8
  %ior.8 = or i32 %shl.5, %shr.5
  %iand.9 = and i32 %ior.8, 16711935
  %shl.6 = shl nuw nsw i32 %iand.9, 4
  %ior.9 = or i32 %shl.6, %iand.9
  %iand.10 = and i32 %ior.9, 252645135
  %shl.7 = shl nuw nsw i32 %iand.10, 2
  %ior.10 = or i32 %shl.7, %iand.10
  %iand.11 = and i32 %ior.10, 858993459
  %shl.8 = shl nuw nsw i32 %iand.11, 1
  %ior.11 = or i32 %shl.8, %iand.11
  %iand.12 = and i32 %ior.11, 1431655765
  %iand.13 = and i32 %trunc.0, -65536
  %shr.6 = lshr exact i32 %iand.13, 8
  %ior.12 = or i32 %shr.6, %iand.13
  %iand.14 = and i32 %ior.12, -16711936
  %shr.7 = lshr exact i32 %iand.14, 4
  %ior.13 = or i32 %shr.7, %iand.14
  %iand.15 = and i32 %ior.13, -252645136
  %shr.8 = lshr exact i32 %iand.15, 2
  %ior.14 = or i32 %shr.8, %iand.15
  %iand.16 = and i32 %ior.14, -858993460
  %shr.9 = lshr exact i32 %iand.16, 1
  %ior.15 = or i32 %shr.9, %iand.16
  %iand.17 = and i32 %ior.15, -1431655766
  %ior.16 = or i32 %iand.17, %iand.12
  %zext.0 = zext i32 %ior.16 to i64
  %shl.9 = shl nuw i64 %zext.0, 32
  %ior.17 = or i32 %iand.8, %iand.4
  %zext.1 = zext i32 %ior.17 to i64
  %ior.18 = or i64 %shl.9, %zext.1
  br label %fallthrough.0

fallthrough.0:                                    ; preds = %then.0, %entry
  %Ai.addr.0 = phi i64 [ %ior.18, %then.0 ], [ %Ai, %entry ]
  ret i64 %Ai.addr.0
}

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare double @llvm.fmuladd.f64(double, double, double) #2

declare i32 @printf(ptr noundef, ...) #3

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #3 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind }

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
