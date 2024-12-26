; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/1_iec958_parity.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/1_iec958_parity.run.c"
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
  %4 = call i32 @version_4(i32 %0)
  %5 = call i32 @version_5(i32 %0)
  %6 = call i32 @version_6(i32 %0)
  %7 = call i32 @version_7(i32 %0)
  %8 = call i32 @version_8(i32 %0)
  %9 = call i32 @version_9(i32 %0)
  %10 = call i32 @version_10(i32 %0)
  %11 = call i32 @version_11(i32 %0)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %12 = icmp eq i32 %1, %2
  br i1 %12, label %true, label %error

true:                                             ; preds = %comparisons
  %13 = icmp eq i32 %1, %3
  br i1 %13, label %true1, label %error

true1:                                            ; preds = %true
  %14 = icmp eq i32 %1, %4
  br i1 %14, label %true2, label %error

true2:                                            ; preds = %true1
  %15 = icmp eq i32 %1, %5
  br i1 %15, label %true3, label %error

true3:                                            ; preds = %true2
  %16 = icmp eq i32 %1, %6
  br i1 %16, label %true4, label %error

true4:                                            ; preds = %true3
  %17 = icmp eq i32 %1, %7
  br i1 %17, label %true5, label %error

true5:                                            ; preds = %true4
  %18 = icmp eq i32 %1, %8
  br i1 %18, label %true6, label %error

true6:                                            ; preds = %true5
  %19 = icmp eq i32 %1, %9
  br i1 %19, label %true7, label %error

true7:                                            ; preds = %true6
  %20 = icmp eq i32 %1, %10
  br i1 %20, label %true8, label %error

true8:                                            ; preds = %true7
  %21 = icmp eq i32 %1, %11
  br i1 %21, label %true9, label %error

true9:                                            ; preds = %true8
  ret i32 %1

error:                                            ; preds = %true8, %true7, %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_2(i32 noundef %data) #0 {
entry:
  %shr.0 = lshr i32 %data, 4
  %iand.0 = and i32 %shr.0, 1
  %shr.1 = lshr i32 %data, 5
  %iand.0.1 = and i32 %shr.1, 1
  %narrow = add nuw nsw i32 %iand.0, %iand.0.1
  %shr.1.1 = lshr i32 %data, 6
  %iand.0.2 = and i32 %shr.1.1, 1
  %narrow11 = add nuw nsw i32 %narrow, %iand.0.2
  %shr.1.2 = lshr i32 %data, 7
  %iand.0.3 = and i32 %shr.1.2, 1
  %narrow12 = add nuw nsw i32 %narrow11, %iand.0.3
  %shr.1.3 = lshr i32 %data, 8
  %iand.0.4 = and i32 %shr.1.3, 1
  %narrow13 = add nuw nsw i32 %narrow12, %iand.0.4
  %shr.1.4 = lshr i32 %data, 9
  %iand.0.5 = and i32 %shr.1.4, 1
  %narrow14 = add nuw nsw i32 %narrow13, %iand.0.5
  %shr.1.5 = lshr i32 %data, 10
  %iand.0.6 = and i32 %shr.1.5, 1
  %narrow15 = add nuw nsw i32 %narrow14, %iand.0.6
  %shr.1.6 = lshr i32 %data, 11
  %0 = and i32 %shr.1.6, 1
  %parity.1.7 = add i32 %0, %narrow15
  %shr.1.7 = lshr i32 %data, 12
  %1 = and i32 %shr.1.7, 1
  %parity.1.8 = add i32 %parity.1.7, %1
  %shr.1.8 = lshr i32 %data, 13
  %2 = and i32 %shr.1.8, 1
  %parity.1.9 = add i32 %parity.1.8, %2
  %shr.1.9 = lshr i32 %data, 14
  %3 = and i32 %shr.1.9, 1
  %parity.1.10 = add i32 %parity.1.9, %3
  %shr.1.10 = lshr i32 %data, 15
  %4 = and i32 %shr.1.10, 1
  %parity.1.11 = add i32 %parity.1.10, %4
  %shr.1.11 = lshr i32 %data, 16
  %5 = and i32 %shr.1.11, 1
  %parity.1.12 = add i32 %parity.1.11, %5
  %shr.1.12 = lshr i32 %data, 17
  %6 = and i32 %shr.1.12, 1
  %parity.1.13 = add i32 %parity.1.12, %6
  %shr.1.13 = lshr i32 %data, 18
  %7 = and i32 %shr.1.13, 1
  %parity.1.14 = add i32 %parity.1.13, %7
  %shr.1.14 = lshr i32 %data, 19
  %8 = and i32 %shr.1.14, 1
  %parity.1.15 = add i32 %parity.1.14, %8
  %shr.1.15 = lshr i32 %data, 20
  %9 = and i32 %shr.1.15, 1
  %parity.1.16 = add i32 %parity.1.15, %9
  %shr.1.16 = lshr i32 %data, 21
  %10 = and i32 %shr.1.16, 1
  %parity.1.17 = add i32 %parity.1.16, %10
  %shr.1.17 = lshr i32 %data, 22
  %11 = and i32 %shr.1.17, 1
  %parity.1.18 = add i32 %parity.1.17, %11
  %shr.1.18 = lshr i32 %data, 23
  %12 = and i32 %shr.1.18, 1
  %parity.1.19 = add i32 %parity.1.18, %12
  %shr.1.19 = lshr i32 %data, 24
  %13 = and i32 %shr.1.19, 1
  %parity.1.20 = add i32 %parity.1.19, %13
  %shr.1.20 = lshr i32 %data, 25
  %14 = and i32 %shr.1.20, 1
  %parity.1.21 = add i32 %parity.1.20, %14
  %shr.1.21 = lshr i32 %data, 26
  %15 = and i32 %shr.1.21, 1
  %parity.1.22 = add i32 %parity.1.21, %15
  %shr.1.22 = lshr i32 %data, 27
  %parity.1.23 = add i32 %parity.1.22, %shr.1.22
  %shr.1.23 = lshr i32 %data, 28
  %parity.1.24 = add i32 %parity.1.23, %shr.1.23
  %shr.1.24 = lshr i32 %data, 29
  %parity.1.25 = add i32 %parity.1.24, %shr.1.24
  %shr.1.25 = lshr i32 %data, 30
  %parity.1.26 = add i32 %parity.1.25, %shr.1.25
  %mod.01617 = and i32 %parity.1.26, 1
  ret i32 %mod.01617
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_3(i32 noundef %data) #0 {
entry:
  %shr.0 = lshr i32 %data, 4
  %iand.0 = and i32 %shr.0, 1
  %shr.1 = lshr i32 %data, 5
  %iand.0.1 = and i32 %shr.1, 1
  %narrow = add nuw nsw i32 %iand.0, %iand.0.1
  %shr.1.1 = lshr i32 %data, 6
  %iand.0.2 = and i32 %shr.1.1, 1
  %narrow11 = add nuw nsw i32 %narrow, %iand.0.2
  %shr.1.2 = lshr i32 %data, 7
  %iand.0.3 = and i32 %shr.1.2, 1
  %narrow12 = add nuw nsw i32 %narrow11, %iand.0.3
  %shr.1.3 = lshr i32 %data, 8
  %iand.0.4 = and i32 %shr.1.3, 1
  %narrow13 = add nuw nsw i32 %narrow12, %iand.0.4
  %shr.1.4 = lshr i32 %data, 9
  %iand.0.5 = and i32 %shr.1.4, 1
  %narrow14 = add nuw nsw i32 %narrow13, %iand.0.5
  %shr.1.5 = lshr i32 %data, 10
  %iand.0.6 = and i32 %shr.1.5, 1
  %narrow15 = add nuw nsw i32 %narrow14, %iand.0.6
  %shr.1.6 = lshr i32 %data, 11
  %zext.0.7 = and i32 %shr.1.6, 1
  %add.0.7 = add i32 %zext.0.7, %narrow15
  %shr.1.7 = lshr i32 %data, 12
  %zext.0.8 = and i32 %shr.1.7, 1
  %add.0.8 = add i32 %add.0.7, %zext.0.8
  %shr.1.8 = lshr i32 %data, 13
  %zext.0.9 = and i32 %shr.1.8, 1
  %add.0.9 = add i32 %add.0.8, %zext.0.9
  %shr.1.9 = lshr i32 %data, 14
  %zext.0.10 = and i32 %shr.1.9, 1
  %add.0.10 = add i32 %add.0.9, %zext.0.10
  %shr.1.10 = lshr i32 %data, 15
  %zext.0.11 = and i32 %shr.1.10, 1
  %add.0.11 = add i32 %add.0.10, %zext.0.11
  %shr.1.11 = lshr i32 %data, 16
  %zext.0.12 = and i32 %shr.1.11, 1
  %add.0.12 = add i32 %add.0.11, %zext.0.12
  %shr.1.12 = lshr i32 %data, 17
  %zext.0.13 = and i32 %shr.1.12, 1
  %add.0.13 = add i32 %add.0.12, %zext.0.13
  %shr.1.13 = lshr i32 %data, 18
  %zext.0.14 = and i32 %shr.1.13, 1
  %add.0.14 = add i32 %add.0.13, %zext.0.14
  %shr.1.14 = lshr i32 %data, 19
  %zext.0.15 = and i32 %shr.1.14, 1
  %add.0.15 = add i32 %add.0.14, %zext.0.15
  %shr.1.15 = lshr i32 %data, 20
  %zext.0.16 = and i32 %shr.1.15, 1
  %add.0.16 = add i32 %add.0.15, %zext.0.16
  %shr.1.16 = lshr i32 %data, 21
  %zext.0.17 = and i32 %shr.1.16, 1
  %add.0.17 = add i32 %add.0.16, %zext.0.17
  %shr.1.17 = lshr i32 %data, 22
  %zext.0.18 = and i32 %shr.1.17, 1
  %add.0.18 = add i32 %add.0.17, %zext.0.18
  %shr.1.18 = lshr i32 %data, 23
  %zext.0.19 = and i32 %shr.1.18, 1
  %add.0.19 = add i32 %add.0.18, %zext.0.19
  %shr.1.19 = lshr i32 %data, 24
  %zext.0.20 = and i32 %shr.1.19, 1
  %add.0.20 = add i32 %add.0.19, %zext.0.20
  %shr.1.20 = lshr i32 %data, 25
  %zext.0.21 = and i32 %shr.1.20, 1
  %add.0.21 = add i32 %add.0.20, %zext.0.21
  %shr.1.21 = lshr i32 %data, 26
  %zext.0.22 = and i32 %shr.1.21, 1
  %add.0.22 = add i32 %add.0.21, %zext.0.22
  %shr.1.22 = lshr i32 %data, 27
  %add.0.23 = add i32 %add.0.22, %shr.1.22
  %shr.1.23 = lshr i32 %data, 28
  %add.0.24 = add i32 %add.0.23, %shr.1.23
  %shr.1.24 = lshr i32 %data, 29
  %add.0.25 = add i32 %add.0.24, %shr.1.24
  %shr.1.25 = lshr i32 %data, 30
  %add.0.26 = add i32 %add.0.25, %shr.1.25
  %mod.01617 = and i32 %add.0.26, 1
  ret i32 %mod.01617
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_4(i32 noundef %data) #0 {
entry:
  %icmp.0.not7 = icmp ult i32 %data, 16
  br i1 %icmp.0.not7, label %else.0, label %then.0.preheader

then.0.preheader:                                 ; preds = %entry
  %shr.0 = lshr i32 %data, 4
  br label %then.0

then.0:                                           ; preds = %then.0, %then.0.preheader
  %parity.09 = phi i64 [ %add.0, %then.0 ], [ 0, %then.0.preheader ]
  %data.addr.08 = phi i32 [ %shr.1, %then.0 ], [ %shr.0, %then.0.preheader ]
  %iand.0 = and i32 %data.addr.08, 1
  %zext.0 = zext i32 %iand.0 to i64
  %add.0 = add i64 %parity.09, %zext.0
  %shr.1 = lshr i32 %data.addr.08, 1
  %icmp.0.not = icmp ult i32 %data.addr.08, 2
  br i1 %icmp.0.not, label %else.0.loopexit, label %then.0

else.0.loopexit:                                  ; preds = %then.0
  %phi.cast = trunc i64 %add.0 to i32
  %phi.bo = and i32 %phi.cast, 1
  br label %else.0

else.0:                                           ; preds = %else.0.loopexit, %entry
  %parity.0.lcssa = phi i32 [ 0, %entry ], [ %phi.bo, %else.0.loopexit ]
  ret i32 %parity.0.lcssa
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_5(i32 noundef %data) #0 {
entry:
  %shr.0 = lshr i32 %data, 4
  %iand.0 = and i32 %shr.0, 1
  %shr.1 = lshr i32 %data, 5
  %iand.0.1 = and i32 %shr.1, 1
  %add.0.1 = add nuw nsw i32 %iand.0, %iand.0.1
  %shr.1.1 = lshr i32 %data, 6
  %iand.0.2 = and i32 %shr.1.1, 1
  %add.0.2 = add nuw nsw i32 %add.0.1, %iand.0.2
  %shr.1.2 = lshr i32 %data, 7
  %iand.0.3 = and i32 %shr.1.2, 1
  %add.0.3 = add nuw nsw i32 %add.0.2, %iand.0.3
  %shr.1.3 = lshr i32 %data, 8
  %iand.0.4 = and i32 %shr.1.3, 1
  %add.0.4 = add nuw nsw i32 %add.0.3, %iand.0.4
  %shr.1.4 = lshr i32 %data, 9
  %iand.0.5 = and i32 %shr.1.4, 1
  %add.0.5 = add nuw nsw i32 %add.0.4, %iand.0.5
  %shr.1.5 = lshr i32 %data, 10
  %iand.0.6 = and i32 %shr.1.5, 1
  %add.0.6 = add nuw nsw i32 %add.0.5, %iand.0.6
  %shr.1.6 = lshr i32 %data, 11
  %iand.0.7 = and i32 %shr.1.6, 1
  %add.0.7 = add nuw nsw i32 %add.0.6, %iand.0.7
  %shr.1.7 = lshr i32 %data, 12
  %iand.0.8 = and i32 %shr.1.7, 1
  %add.0.8 = add nuw nsw i32 %add.0.7, %iand.0.8
  %shr.1.8 = lshr i32 %data, 13
  %iand.0.9 = and i32 %shr.1.8, 1
  %add.0.9 = add nuw nsw i32 %add.0.8, %iand.0.9
  %shr.1.9 = lshr i32 %data, 14
  %iand.0.10 = and i32 %shr.1.9, 1
  %add.0.10 = add nuw nsw i32 %add.0.9, %iand.0.10
  %shr.1.10 = lshr i32 %data, 15
  %iand.0.11 = and i32 %shr.1.10, 1
  %add.0.11 = add nuw nsw i32 %add.0.10, %iand.0.11
  %shr.1.11 = lshr i32 %data, 16
  %iand.0.12 = and i32 %shr.1.11, 1
  %add.0.12 = add nuw nsw i32 %add.0.11, %iand.0.12
  %shr.1.12 = lshr i32 %data, 17
  %iand.0.13 = and i32 %shr.1.12, 1
  %add.0.13 = add nuw nsw i32 %add.0.12, %iand.0.13
  %shr.1.13 = lshr i32 %data, 18
  %iand.0.14 = and i32 %shr.1.13, 1
  %add.0.14 = add nuw nsw i32 %add.0.13, %iand.0.14
  %shr.1.14 = lshr i32 %data, 19
  %iand.0.15 = and i32 %shr.1.14, 1
  %add.0.15 = add nuw nsw i32 %add.0.14, %iand.0.15
  %shr.1.15 = lshr i32 %data, 20
  %iand.0.16 = and i32 %shr.1.15, 1
  %add.0.16 = add nuw nsw i32 %add.0.15, %iand.0.16
  %shr.1.16 = lshr i32 %data, 21
  %iand.0.17 = and i32 %shr.1.16, 1
  %add.0.17 = add nuw nsw i32 %add.0.16, %iand.0.17
  %shr.1.17 = lshr i32 %data, 22
  %iand.0.18 = and i32 %shr.1.17, 1
  %add.0.18 = add nuw nsw i32 %add.0.17, %iand.0.18
  %shr.1.18 = lshr i32 %data, 23
  %iand.0.19 = and i32 %shr.1.18, 1
  %add.0.19 = add nuw nsw i32 %add.0.18, %iand.0.19
  %shr.1.19 = lshr i32 %data, 24
  %iand.0.20 = and i32 %shr.1.19, 1
  %add.0.20 = add nuw nsw i32 %add.0.19, %iand.0.20
  %shr.1.20 = lshr i32 %data, 25
  %iand.0.21 = and i32 %shr.1.20, 1
  %add.0.21 = add nuw nsw i32 %add.0.20, %iand.0.21
  %shr.1.21 = lshr i32 %data, 26
  %iand.0.22 = and i32 %shr.1.21, 1
  %add.0.22 = add nuw nsw i32 %add.0.21, %iand.0.22
  %shr.1.22 = lshr i32 %data, 27
  %add.0.23 = add nuw nsw i32 %add.0.22, %shr.1.22
  %shr.1.23 = lshr i32 %data, 28
  %add.0.24 = add nuw nsw i32 %add.0.23, %shr.1.23
  %shr.1.24 = lshr i32 %data, 29
  %add.0.25 = add nuw nsw i32 %add.0.24, %shr.1.24
  %shr.1.25 = lshr i32 %data, 30
  %add.0.26 = add nuw nsw i32 %add.0.25, %shr.1.25
  %iand.1 = and i32 %add.0.26, 1
  ret i32 %iand.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_6(i32 noundef %data) #0 {
entry:
  %shr.0 = lshr i32 %data, 4
  %iand.0 = and i32 %shr.0, 1
  %shr.1 = lshr i32 %data, 5
  %iand.0.1 = and i32 %shr.1, 1
  %add.0.1 = add nuw nsw i32 %iand.0, %iand.0.1
  %shr.1.1 = lshr i32 %data, 6
  %iand.0.2 = and i32 %shr.1.1, 1
  %add.0.2 = add nuw nsw i32 %add.0.1, %iand.0.2
  %shr.1.2 = lshr i32 %data, 7
  %iand.0.3 = and i32 %shr.1.2, 1
  %add.0.3 = add nuw nsw i32 %add.0.2, %iand.0.3
  %shr.1.3 = lshr i32 %data, 8
  %iand.0.4 = and i32 %shr.1.3, 1
  %add.0.4 = add nuw nsw i32 %add.0.3, %iand.0.4
  %shr.1.4 = lshr i32 %data, 9
  %iand.0.5 = and i32 %shr.1.4, 1
  %add.0.5 = add nuw nsw i32 %add.0.4, %iand.0.5
  %shr.1.5 = lshr i32 %data, 10
  %iand.0.6 = and i32 %shr.1.5, 1
  %add.0.6 = add nuw nsw i32 %add.0.5, %iand.0.6
  %shr.1.6 = lshr i32 %data, 11
  %iand.0.7 = and i32 %shr.1.6, 1
  %add.0.7 = add nuw nsw i32 %add.0.6, %iand.0.7
  %shr.1.7 = lshr i32 %data, 12
  %iand.0.8 = and i32 %shr.1.7, 1
  %add.0.8 = add nuw nsw i32 %add.0.7, %iand.0.8
  %shr.1.8 = lshr i32 %data, 13
  %iand.0.9 = and i32 %shr.1.8, 1
  %add.0.9 = add nuw nsw i32 %add.0.8, %iand.0.9
  %shr.1.9 = lshr i32 %data, 14
  %iand.0.10 = and i32 %shr.1.9, 1
  %add.0.10 = add nuw nsw i32 %add.0.9, %iand.0.10
  %shr.1.10 = lshr i32 %data, 15
  %iand.0.11 = and i32 %shr.1.10, 1
  %add.0.11 = add nuw nsw i32 %add.0.10, %iand.0.11
  %shr.1.11 = lshr i32 %data, 16
  %iand.0.12 = and i32 %shr.1.11, 1
  %add.0.12 = add nuw nsw i32 %add.0.11, %iand.0.12
  %shr.1.12 = lshr i32 %data, 17
  %iand.0.13 = and i32 %shr.1.12, 1
  %add.0.13 = add nuw nsw i32 %add.0.12, %iand.0.13
  %shr.1.13 = lshr i32 %data, 18
  %iand.0.14 = and i32 %shr.1.13, 1
  %add.0.14 = add nuw nsw i32 %add.0.13, %iand.0.14
  %shr.1.14 = lshr i32 %data, 19
  %iand.0.15 = and i32 %shr.1.14, 1
  %add.0.15 = add nuw nsw i32 %add.0.14, %iand.0.15
  %shr.1.15 = lshr i32 %data, 20
  %iand.0.16 = and i32 %shr.1.15, 1
  %add.0.16 = add nuw nsw i32 %add.0.15, %iand.0.16
  %shr.1.16 = lshr i32 %data, 21
  %iand.0.17 = and i32 %shr.1.16, 1
  %add.0.17 = add nuw nsw i32 %add.0.16, %iand.0.17
  %shr.1.17 = lshr i32 %data, 22
  %iand.0.18 = and i32 %shr.1.17, 1
  %add.0.18 = add nuw nsw i32 %add.0.17, %iand.0.18
  %shr.1.18 = lshr i32 %data, 23
  %iand.0.19 = and i32 %shr.1.18, 1
  %add.0.19 = add nuw nsw i32 %add.0.18, %iand.0.19
  %shr.1.19 = lshr i32 %data, 24
  %iand.0.20 = and i32 %shr.1.19, 1
  %add.0.20 = add nuw nsw i32 %add.0.19, %iand.0.20
  %shr.1.20 = lshr i32 %data, 25
  %iand.0.21 = and i32 %shr.1.20, 1
  %add.0.21 = add nuw nsw i32 %add.0.20, %iand.0.21
  %shr.1.21 = lshr i32 %data, 26
  %iand.0.22 = and i32 %shr.1.21, 1
  %add.0.22 = add nuw nsw i32 %add.0.21, %iand.0.22
  %shr.1.22 = lshr i32 %data, 27
  %add.0.23 = add nuw nsw i32 %add.0.22, %shr.1.22
  %shr.1.23 = lshr i32 %data, 28
  %add.0.24 = add nuw nsw i32 %add.0.23, %shr.1.23
  %shr.1.24 = lshr i32 %data, 29
  %add.0.25 = add nuw nsw i32 %add.0.24, %shr.1.24
  %shr.1.25 = lshr i32 %data, 30
  %add.0.26 = add nuw nsw i32 %add.0.25, %shr.1.25
  %iand.1 = and i32 %add.0.26, 1
  ret i32 %iand.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_7(i32 noundef %data) #0 {
entry:
  %shr.0 = lshr i32 %data, 4
  %shr.1 = lshr i32 %data, 5
  %iand.011 = xor i32 %shr.0, %shr.1
  %shr.1.1 = lshr i32 %data, 6
  %xor.0.112 = xor i32 %iand.011, %shr.1.1
  %shr.1.2 = lshr i32 %data, 7
  %xor.0.213 = xor i32 %xor.0.112, %shr.1.2
  %shr.1.3 = lshr i32 %data, 8
  %xor.0.314 = xor i32 %xor.0.213, %shr.1.3
  %shr.1.4 = lshr i32 %data, 9
  %xor.0.415 = xor i32 %xor.0.314, %shr.1.4
  %shr.1.5 = lshr i32 %data, 10
  %xor.0.516 = xor i32 %xor.0.415, %shr.1.5
  %shr.1.6 = lshr i32 %data, 11
  %xor.0.617 = xor i32 %xor.0.516, %shr.1.6
  %shr.1.7 = lshr i32 %data, 12
  %xor.0.718 = xor i32 %xor.0.617, %shr.1.7
  %shr.1.8 = lshr i32 %data, 13
  %xor.0.819 = xor i32 %xor.0.718, %shr.1.8
  %shr.1.9 = lshr i32 %data, 14
  %xor.0.920 = xor i32 %xor.0.819, %shr.1.9
  %shr.1.10 = lshr i32 %data, 15
  %xor.0.1021 = xor i32 %xor.0.920, %shr.1.10
  %shr.1.11 = lshr i32 %data, 16
  %xor.0.1122 = xor i32 %xor.0.1021, %shr.1.11
  %shr.1.12 = lshr i32 %data, 17
  %xor.0.1223 = xor i32 %xor.0.1122, %shr.1.12
  %shr.1.13 = lshr i32 %data, 18
  %xor.0.1324 = xor i32 %xor.0.1223, %shr.1.13
  %shr.1.14 = lshr i32 %data, 19
  %xor.0.1425 = xor i32 %xor.0.1324, %shr.1.14
  %shr.1.15 = lshr i32 %data, 20
  %xor.0.1526 = xor i32 %xor.0.1425, %shr.1.15
  %shr.1.16 = lshr i32 %data, 21
  %xor.0.1627 = xor i32 %xor.0.1526, %shr.1.16
  %shr.1.17 = lshr i32 %data, 22
  %xor.0.1728 = xor i32 %xor.0.1627, %shr.1.17
  %shr.1.18 = lshr i32 %data, 23
  %xor.0.1829 = xor i32 %xor.0.1728, %shr.1.18
  %shr.1.19 = lshr i32 %data, 24
  %xor.0.1930 = xor i32 %xor.0.1829, %shr.1.19
  %shr.1.20 = lshr i32 %data, 25
  %xor.0.2031 = xor i32 %xor.0.1930, %shr.1.20
  %shr.1.21 = lshr i32 %data, 26
  %xor.0.2132 = xor i32 %xor.0.2031, %shr.1.21
  %shr.1.22 = lshr i32 %data, 27
  %xor.0.2233 = xor i32 %xor.0.2132, %shr.1.22
  %shr.1.23 = lshr i32 %data, 28
  %xor.0.2334 = xor i32 %xor.0.2233, %shr.1.23
  %shr.1.24 = lshr i32 %data, 29
  %xor.0.2435 = xor i32 %xor.0.2334, %shr.1.24
  %shr.1.25 = lshr i32 %data, 30
  %xor.0.2536 = xor i32 %xor.0.2435, %shr.1.25
  %xor.0.26 = and i32 %xor.0.2536, 1
  ret i32 %xor.0.26
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_8(i32 noundef %data) #0 {
entry:
  %shr.0 = lshr i32 %data, 4
  %iand.0 = and i32 %shr.0, 1
  %shr.1 = lshr i32 %data, 5
  %iand.0.1 = and i32 %shr.1, 1
  %parity.1.1 = add nuw nsw i32 %iand.0, %iand.0.1
  %shr.1.1 = lshr i32 %data, 6
  %iand.0.2 = and i32 %shr.1.1, 1
  %parity.1.2 = add nuw nsw i32 %parity.1.1, %iand.0.2
  %shr.1.2 = lshr i32 %data, 7
  %iand.0.3 = and i32 %shr.1.2, 1
  %parity.1.3 = add nuw nsw i32 %parity.1.2, %iand.0.3
  %shr.1.3 = lshr i32 %data, 8
  %iand.0.4 = and i32 %shr.1.3, 1
  %parity.1.4 = add nuw nsw i32 %parity.1.3, %iand.0.4
  %shr.1.4 = lshr i32 %data, 9
  %iand.0.5 = and i32 %shr.1.4, 1
  %parity.1.5 = add nuw nsw i32 %parity.1.4, %iand.0.5
  %shr.1.5 = lshr i32 %data, 10
  %iand.0.6 = and i32 %shr.1.5, 1
  %parity.1.6 = add nuw nsw i32 %parity.1.5, %iand.0.6
  %shr.1.6 = lshr i32 %data, 11
  %iand.0.7 = and i32 %shr.1.6, 1
  %parity.1.7 = add nuw nsw i32 %parity.1.6, %iand.0.7
  %shr.1.7 = lshr i32 %data, 12
  %iand.0.8 = and i32 %shr.1.7, 1
  %parity.1.8 = add nuw nsw i32 %parity.1.7, %iand.0.8
  %shr.1.8 = lshr i32 %data, 13
  %iand.0.9 = and i32 %shr.1.8, 1
  %parity.1.9 = add nuw nsw i32 %parity.1.8, %iand.0.9
  %shr.1.9 = lshr i32 %data, 14
  %iand.0.10 = and i32 %shr.1.9, 1
  %parity.1.10 = add nuw nsw i32 %parity.1.9, %iand.0.10
  %shr.1.10 = lshr i32 %data, 15
  %iand.0.11 = and i32 %shr.1.10, 1
  %parity.1.11 = add nuw nsw i32 %parity.1.10, %iand.0.11
  %shr.1.11 = lshr i32 %data, 16
  %iand.0.12 = and i32 %shr.1.11, 1
  %parity.1.12 = add nuw nsw i32 %parity.1.11, %iand.0.12
  %shr.1.12 = lshr i32 %data, 17
  %iand.0.13 = and i32 %shr.1.12, 1
  %parity.1.13 = add nuw nsw i32 %parity.1.12, %iand.0.13
  %shr.1.13 = lshr i32 %data, 18
  %iand.0.14 = and i32 %shr.1.13, 1
  %parity.1.14 = add nuw nsw i32 %parity.1.13, %iand.0.14
  %shr.1.14 = lshr i32 %data, 19
  %iand.0.15 = and i32 %shr.1.14, 1
  %parity.1.15 = add nuw nsw i32 %parity.1.14, %iand.0.15
  %shr.1.15 = lshr i32 %data, 20
  %iand.0.16 = and i32 %shr.1.15, 1
  %parity.1.16 = add nuw nsw i32 %parity.1.15, %iand.0.16
  %shr.1.16 = lshr i32 %data, 21
  %iand.0.17 = and i32 %shr.1.16, 1
  %parity.1.17 = add nuw nsw i32 %parity.1.16, %iand.0.17
  %shr.1.17 = lshr i32 %data, 22
  %iand.0.18 = and i32 %shr.1.17, 1
  %parity.1.18 = add nuw nsw i32 %parity.1.17, %iand.0.18
  %shr.1.18 = lshr i32 %data, 23
  %iand.0.19 = and i32 %shr.1.18, 1
  %parity.1.19 = add nuw nsw i32 %parity.1.18, %iand.0.19
  %shr.1.19 = lshr i32 %data, 24
  %iand.0.20 = and i32 %shr.1.19, 1
  %parity.1.20 = add nuw nsw i32 %parity.1.19, %iand.0.20
  %shr.1.20 = lshr i32 %data, 25
  %iand.0.21 = and i32 %shr.1.20, 1
  %parity.1.21 = add nuw nsw i32 %parity.1.20, %iand.0.21
  %shr.1.21 = lshr i32 %data, 26
  %iand.0.22 = and i32 %shr.1.21, 1
  %parity.1.22 = add nuw nsw i32 %parity.1.21, %iand.0.22
  %shr.1.22 = lshr i32 %data, 27
  %parity.1.23 = add nuw nsw i32 %parity.1.22, %shr.1.22
  %shr.1.23 = lshr i32 %data, 28
  %parity.1.24 = add nuw nsw i32 %parity.1.23, %shr.1.23
  %shr.1.24 = lshr i32 %data, 29
  %parity.1.25 = add nuw nsw i32 %parity.1.24, %shr.1.24
  %shr.1.25 = lshr i32 %data, 30
  %parity.1.26 = add nuw nsw i32 %parity.1.25, %shr.1.25
  %iand.1 = and i32 %parity.1.26, 1
  ret i32 %iand.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_9(i32 noundef %data) #0 {
entry:
  %shr.0 = lshr i32 %data, 4
  %shr.1 = lshr i32 %data, 5
  %iand.011 = xor i32 %shr.0, %shr.1
  %shr.1.1 = lshr i32 %data, 6
  %xor.0.112 = xor i32 %iand.011, %shr.1.1
  %shr.1.2 = lshr i32 %data, 7
  %xor.0.213 = xor i32 %xor.0.112, %shr.1.2
  %shr.1.3 = lshr i32 %data, 8
  %xor.0.314 = xor i32 %xor.0.213, %shr.1.3
  %shr.1.4 = lshr i32 %data, 9
  %xor.0.415 = xor i32 %xor.0.314, %shr.1.4
  %shr.1.5 = lshr i32 %data, 10
  %xor.0.516 = xor i32 %xor.0.415, %shr.1.5
  %shr.1.6 = lshr i32 %data, 11
  %xor.0.617 = xor i32 %xor.0.516, %shr.1.6
  %shr.1.7 = lshr i32 %data, 12
  %xor.0.718 = xor i32 %xor.0.617, %shr.1.7
  %shr.1.8 = lshr i32 %data, 13
  %xor.0.819 = xor i32 %xor.0.718, %shr.1.8
  %shr.1.9 = lshr i32 %data, 14
  %xor.0.920 = xor i32 %xor.0.819, %shr.1.9
  %shr.1.10 = lshr i32 %data, 15
  %xor.0.1021 = xor i32 %xor.0.920, %shr.1.10
  %shr.1.11 = lshr i32 %data, 16
  %xor.0.1122 = xor i32 %xor.0.1021, %shr.1.11
  %shr.1.12 = lshr i32 %data, 17
  %xor.0.1223 = xor i32 %xor.0.1122, %shr.1.12
  %shr.1.13 = lshr i32 %data, 18
  %xor.0.1324 = xor i32 %xor.0.1223, %shr.1.13
  %shr.1.14 = lshr i32 %data, 19
  %xor.0.1425 = xor i32 %xor.0.1324, %shr.1.14
  %shr.1.15 = lshr i32 %data, 20
  %xor.0.1526 = xor i32 %xor.0.1425, %shr.1.15
  %shr.1.16 = lshr i32 %data, 21
  %xor.0.1627 = xor i32 %xor.0.1526, %shr.1.16
  %shr.1.17 = lshr i32 %data, 22
  %xor.0.1728 = xor i32 %xor.0.1627, %shr.1.17
  %shr.1.18 = lshr i32 %data, 23
  %xor.0.1829 = xor i32 %xor.0.1728, %shr.1.18
  %shr.1.19 = lshr i32 %data, 24
  %xor.0.1930 = xor i32 %xor.0.1829, %shr.1.19
  %shr.1.20 = lshr i32 %data, 25
  %xor.0.2031 = xor i32 %xor.0.1930, %shr.1.20
  %shr.1.21 = lshr i32 %data, 26
  %xor.0.2132 = xor i32 %xor.0.2031, %shr.1.21
  %shr.1.22 = lshr i32 %data, 27
  %xor.0.2233 = xor i32 %xor.0.2132, %shr.1.22
  %shr.1.23 = lshr i32 %data, 28
  %xor.0.2334 = xor i32 %xor.0.2233, %shr.1.23
  %shr.1.24 = lshr i32 %data, 29
  %xor.0.2435 = xor i32 %xor.0.2334, %shr.1.24
  %shr.1.25 = lshr i32 %data, 30
  %xor.0.2536 = xor i32 %xor.0.2435, %shr.1.25
  %xor.0.26 = and i32 %xor.0.2536, 1
  ret i32 %xor.0.26
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_10(i32 noundef %data) #0 {
entry:
  %icmp.0.not7 = icmp ult i32 %data, 16
  br i1 %icmp.0.not7, label %else.0, label %then.0.preheader

then.0.preheader:                                 ; preds = %entry
  %shr.0 = lshr i32 %data, 4
  br label %then.0

then.0:                                           ; preds = %then.0, %then.0.preheader
  %parity.09 = phi i32 [ %xor.0, %then.0 ], [ 0, %then.0.preheader ]
  %data.addr.08 = phi i32 [ %shr.1, %then.0 ], [ %shr.0, %then.0.preheader ]
  %iand.0 = and i32 %data.addr.08, 1
  %xor.0 = xor i32 %parity.09, %iand.0
  %shr.1 = lshr i32 %data.addr.08, 1
  %icmp.0.not = icmp ult i32 %data.addr.08, 2
  br i1 %icmp.0.not, label %else.0.loopexit, label %then.0

else.0.loopexit:                                  ; preds = %then.0
  %phi.bo = and i32 %xor.0, 1
  br label %else.0

else.0:                                           ; preds = %else.0.loopexit, %entry
  %parity.0.lcssa = phi i32 [ 0, %entry ], [ %phi.bo, %else.0.loopexit ]
  ret i32 %parity.0.lcssa
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_11(i32 noundef %data) #0 {
entry:
  %shr.0 = lshr i32 %data, 4
  %iand.0 = and i32 %shr.0, 1
  %shr.1 = lshr i32 %data, 5
  %iand.0.1 = and i32 %shr.1, 1
  %parity.1.1 = add nuw nsw i32 %iand.0, %iand.0.1
  %shr.1.1 = lshr i32 %data, 6
  %iand.0.2 = and i32 %shr.1.1, 1
  %parity.1.2 = add nuw nsw i32 %parity.1.1, %iand.0.2
  %shr.1.2 = lshr i32 %data, 7
  %iand.0.3 = and i32 %shr.1.2, 1
  %parity.1.3 = add nuw nsw i32 %parity.1.2, %iand.0.3
  %shr.1.3 = lshr i32 %data, 8
  %iand.0.4 = and i32 %shr.1.3, 1
  %parity.1.4 = add nuw nsw i32 %parity.1.3, %iand.0.4
  %shr.1.4 = lshr i32 %data, 9
  %iand.0.5 = and i32 %shr.1.4, 1
  %parity.1.5 = add nuw nsw i32 %parity.1.4, %iand.0.5
  %shr.1.5 = lshr i32 %data, 10
  %iand.0.6 = and i32 %shr.1.5, 1
  %parity.1.6 = add nuw nsw i32 %parity.1.5, %iand.0.6
  %shr.1.6 = lshr i32 %data, 11
  %iand.0.7 = and i32 %shr.1.6, 1
  %parity.1.7 = add nuw nsw i32 %parity.1.6, %iand.0.7
  %shr.1.7 = lshr i32 %data, 12
  %iand.0.8 = and i32 %shr.1.7, 1
  %parity.1.8 = add nuw nsw i32 %parity.1.7, %iand.0.8
  %shr.1.8 = lshr i32 %data, 13
  %iand.0.9 = and i32 %shr.1.8, 1
  %parity.1.9 = add nuw nsw i32 %parity.1.8, %iand.0.9
  %shr.1.9 = lshr i32 %data, 14
  %iand.0.10 = and i32 %shr.1.9, 1
  %parity.1.10 = add nuw nsw i32 %parity.1.9, %iand.0.10
  %shr.1.10 = lshr i32 %data, 15
  %iand.0.11 = and i32 %shr.1.10, 1
  %parity.1.11 = add nuw nsw i32 %parity.1.10, %iand.0.11
  %shr.1.11 = lshr i32 %data, 16
  %iand.0.12 = and i32 %shr.1.11, 1
  %parity.1.12 = add nuw nsw i32 %parity.1.11, %iand.0.12
  %shr.1.12 = lshr i32 %data, 17
  %iand.0.13 = and i32 %shr.1.12, 1
  %parity.1.13 = add nuw nsw i32 %parity.1.12, %iand.0.13
  %shr.1.13 = lshr i32 %data, 18
  %iand.0.14 = and i32 %shr.1.13, 1
  %parity.1.14 = add nuw nsw i32 %parity.1.13, %iand.0.14
  %shr.1.14 = lshr i32 %data, 19
  %iand.0.15 = and i32 %shr.1.14, 1
  %parity.1.15 = add nuw nsw i32 %parity.1.14, %iand.0.15
  %shr.1.15 = lshr i32 %data, 20
  %iand.0.16 = and i32 %shr.1.15, 1
  %parity.1.16 = add nuw nsw i32 %parity.1.15, %iand.0.16
  %shr.1.16 = lshr i32 %data, 21
  %iand.0.17 = and i32 %shr.1.16, 1
  %parity.1.17 = add nuw nsw i32 %parity.1.16, %iand.0.17
  %shr.1.17 = lshr i32 %data, 22
  %iand.0.18 = and i32 %shr.1.17, 1
  %parity.1.18 = add nuw nsw i32 %parity.1.17, %iand.0.18
  %shr.1.18 = lshr i32 %data, 23
  %iand.0.19 = and i32 %shr.1.18, 1
  %parity.1.19 = add nuw nsw i32 %parity.1.18, %iand.0.19
  %shr.1.19 = lshr i32 %data, 24
  %iand.0.20 = and i32 %shr.1.19, 1
  %parity.1.20 = add nuw nsw i32 %parity.1.19, %iand.0.20
  %shr.1.20 = lshr i32 %data, 25
  %iand.0.21 = and i32 %shr.1.20, 1
  %parity.1.21 = add nuw nsw i32 %parity.1.20, %iand.0.21
  %shr.1.21 = lshr i32 %data, 26
  %iand.0.22 = and i32 %shr.1.21, 1
  %parity.1.22 = add nuw nsw i32 %parity.1.21, %iand.0.22
  %shr.1.22 = lshr i32 %data, 27
  %parity.1.23 = add nuw nsw i32 %parity.1.22, %shr.1.22
  %shr.1.23 = lshr i32 %data, 28
  %parity.1.24 = add nuw nsw i32 %parity.1.23, %shr.1.23
  %shr.1.24 = lshr i32 %data, 29
  %parity.1.25 = add nuw nsw i32 %parity.1.24, %shr.1.24
  %shr.1.25 = lshr i32 %data, 30
  %parity.1.26 = add nuw nsw i32 %parity.1.25, %shr.1.25
  %iand.1 = and i32 %parity.1.26, 1
  ret i32 %iand.1
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_1(i32 noundef %data) #0 {
entry:
  %data.addr = alloca i32, align 4
  %parity = alloca i32, align 4
  %bit = alloca i32, align 4
  store i32 %data, ptr %data.addr, align 4
  %0 = load i32, ptr %data.addr, align 4
  %shr = lshr i32 %0, 4
  store i32 %shr, ptr %data.addr, align 4
  store i32 0, ptr %parity, align 4
  store i32 4, ptr %bit, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %1 = load i32, ptr %bit, align 4
  %cmp = icmp sle i32 %1, 30
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %2 = load i32, ptr %data.addr, align 4
  %and = and i32 %2, 1
  %tobool = icmp ne i32 %and, 0
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %for.body
  %3 = load i32, ptr %parity, align 4
  %inc = add i32 %3, 1
  store i32 %inc, ptr %parity, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %for.body
  %4 = load i32, ptr %data.addr, align 4
  %shr1 = lshr i32 %4, 1
  store i32 %shr1, ptr %data.addr, align 4
  br label %for.inc

for.inc:                                          ; preds = %if.end
  %5 = load i32, ptr %bit, align 4
  %inc2 = add nsw i32 %5, 1
  store i32 %inc2, ptr %bit, align 4
  br label %for.cond, !llvm.loop !8

for.end:                                          ; preds = %for.cond
  %6 = load i32, ptr %parity, align 4
  %and3 = and i32 %6, 1
  ret i32 %and3
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
