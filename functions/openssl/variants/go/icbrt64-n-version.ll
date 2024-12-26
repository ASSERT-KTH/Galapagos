; ModuleID = '/home/javier/Galapagos/functions/openssl/0_icbrt64.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/0_icbrt64.run.c"
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
  %call1 = call i64 @n_version_call(i64 noundef 0)
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
  %6 = call i64 @version_6(i64 %0)
  %7 = call i64 @version_7(i64 %0)
  %8 = call i64 @version_8(i64 %0)
  %9 = call i64 @version_9(i64 %0)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %10 = icmp eq i64 %1, %2
  br i1 %10, label %true, label %error

true:                                             ; preds = %comparisons
  %11 = icmp eq i64 %1, %3
  br i1 %11, label %true1, label %error

true1:                                            ; preds = %true
  %12 = icmp eq i64 %1, %4
  br i1 %12, label %true2, label %error

true2:                                            ; preds = %true1
  %13 = icmp eq i64 %1, %5
  br i1 %13, label %true3, label %error

true3:                                            ; preds = %true2
  %14 = icmp eq i64 %1, %6
  br i1 %14, label %true4, label %error

true4:                                            ; preds = %true3
  %15 = icmp eq i64 %1, %7
  br i1 %15, label %true5, label %error

true5:                                            ; preds = %true4
  %16 = icmp eq i64 %1, %8
  br i1 %16, label %true6, label %error

true6:                                            ; preds = %true5
  %17 = icmp eq i64 %1, %9
  br i1 %17, label %true7, label %error

true7:                                            ; preds = %true6
  ret i64 %1

error:                                            ; preds = %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_2(i64 noundef %x) #0 {
entry:
  br label %then.3

then.3:                                           ; preds = %then.3, %entry
  %x.addr.018 = phi i64 [ %x, %entry ], [ %x.addr.1.1, %then.3 ]
  %s.017 = phi i64 [ 63, %entry ], [ %sub.1.1, %then.3 ]
  %r.016 = phi i64 [ 0, %entry ], [ %r.1.1, %then.3 ]
  %shl.0 = shl i64 %r.016, 1
  %mul.0 = mul i64 %r.016, 6
  %add.0 = or i64 %shl.0, 1
  %mul.1 = mul i64 %mul.0, %add.0
  %add.1 = or i64 %mul.1, 1
  %shr.0 = lshr i64 %x.addr.018, %s.017
  %icmp.2.not = icmp ult i64 %shr.0, %add.1
  %shl.1 = shl i64 %add.1, %s.017
  %r.1 = select i1 %icmp.2.not, i64 %shl.0, i64 %add.0
  %sub.0 = select i1 %icmp.2.not, i64 0, i64 %shl.1
  %x.addr.1 = sub i64 %x.addr.018, %sub.0
  %sub.1 = add nsw i64 %s.017, -3
  %shl.0.1 = shl i64 %r.1, 1
  %mul.0.1 = mul i64 %r.1, 6
  %add.0.1 = or i64 %shl.0.1, 1
  %mul.1.1 = mul i64 %mul.0.1, %add.0.1
  %add.1.1 = or i64 %mul.1.1, 1
  %shr.0.1 = lshr i64 %x.addr.1, %sub.1
  %icmp.2.not.1 = icmp ult i64 %shr.0.1, %add.1.1
  %shl.1.1 = shl i64 %add.1.1, %sub.1
  %r.1.1 = select i1 %icmp.2.not.1, i64 %shl.0.1, i64 %add.0.1
  %sub.0.1 = select i1 %icmp.2.not.1, i64 0, i64 %shl.1.1
  %x.addr.1.1 = sub i64 %x.addr.1, %sub.0.1
  %sub.1.1 = add nsw i64 %s.017, -6
  %icmp.3.1 = icmp ugt i64 %sub.1, 2
  br i1 %icmp.3.1, label %then.3, label %else.3

else.3:                                           ; preds = %then.3
  ret i64 %r.1.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_3(i64 noundef %x) #0 {
entry:
  br label %then.5

then.5:                                           ; preds = %then.5, %entry
  %x.addr.020 = phi i64 [ %x, %entry ], [ %x.addr.1.1, %then.5 ]
  %r.019 = phi i64 [ 0, %entry ], [ %r.1.1, %then.5 ]
  %s.018 = phi i64 [ 63, %entry ], [ %sub.1.1, %then.5 ]
  %shl.0 = shl i64 %r.019, 1
  %mul.0 = mul i64 %r.019, 6
  %add.0 = or i64 %shl.0, 1
  %mul.1 = mul i64 %mul.0, %add.0
  %add.1 = or i64 %mul.1, 1
  %shr.0 = lshr i64 %x.addr.020, %s.018
  %icmp.4.not = icmp ult i64 %shr.0, %add.1
  %shl.1 = shl i64 %add.1, %s.018
  %r.1 = select i1 %icmp.4.not, i64 %shl.0, i64 %add.0
  %sub.0 = select i1 %icmp.4.not, i64 0, i64 %shl.1
  %x.addr.1 = sub i64 %x.addr.020, %sub.0
  %sub.1 = add nsw i64 %s.018, -3
  %shl.0.1 = shl i64 %r.1, 1
  %mul.0.1 = mul i64 %r.1, 6
  %add.0.1 = or i64 %shl.0.1, 1
  %mul.1.1 = mul i64 %mul.0.1, %add.0.1
  %add.1.1 = or i64 %mul.1.1, 1
  %shr.0.1 = lshr i64 %x.addr.1, %sub.1
  %icmp.4.not.1 = icmp ult i64 %shr.0.1, %add.1.1
  %shl.1.1 = shl i64 %add.1.1, %sub.1
  %r.1.1 = select i1 %icmp.4.not.1, i64 %shl.0.1, i64 %add.0.1
  %sub.0.1 = select i1 %icmp.4.not.1, i64 0, i64 %shl.1.1
  %x.addr.1.1 = sub i64 %x.addr.1, %sub.0.1
  %sub.1.1 = add nsw i64 %s.018, -6
  %icmp.5.1 = icmp ugt i64 %sub.1, 2
  br i1 %icmp.5.1, label %then.5, label %else.5

else.5:                                           ; preds = %then.5
  ret i64 %r.1.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_4(i64 noundef %x) #0 {
entry:
  br label %then.3

then.3:                                           ; preds = %then.3, %entry
  %x.addr.018 = phi i64 [ %x, %entry ], [ %x.addr.1.1, %then.3 ]
  %r.017 = phi i64 [ 0, %entry ], [ %r.1.1, %then.3 ]
  %s.016 = phi i64 [ 63, %entry ], [ %sub.1.1, %then.3 ]
  %shl.0 = shl i64 %r.017, 1
  %mul.0 = mul i64 %r.017, 6
  %add.0 = or i64 %shl.0, 1
  %mul.1 = mul i64 %mul.0, %add.0
  %add.1 = or i64 %mul.1, 1
  %shr.0 = lshr i64 %x.addr.018, %s.016
  %icmp.2.not = icmp ult i64 %shr.0, %add.1
  %shl.1 = shl i64 %add.1, %s.016
  %r.1 = select i1 %icmp.2.not, i64 %shl.0, i64 %add.0
  %sub.0 = select i1 %icmp.2.not, i64 0, i64 %shl.1
  %x.addr.1 = sub i64 %x.addr.018, %sub.0
  %sub.1 = add nsw i64 %s.016, -3
  %shl.0.1 = shl i64 %r.1, 1
  %mul.0.1 = mul i64 %r.1, 6
  %add.0.1 = or i64 %shl.0.1, 1
  %mul.1.1 = mul i64 %mul.0.1, %add.0.1
  %add.1.1 = or i64 %mul.1.1, 1
  %shr.0.1 = lshr i64 %x.addr.1, %sub.1
  %icmp.2.not.1 = icmp ult i64 %shr.0.1, %add.1.1
  %shl.1.1 = shl i64 %add.1.1, %sub.1
  %r.1.1 = select i1 %icmp.2.not.1, i64 %shl.0.1, i64 %add.0.1
  %sub.0.1 = select i1 %icmp.2.not.1, i64 0, i64 %shl.1.1
  %x.addr.1.1 = sub i64 %x.addr.1, %sub.0.1
  %sub.1.1 = add nsw i64 %s.016, -6
  %icmp.3.1 = icmp ugt i64 %sub.1, 2
  br i1 %icmp.3.1, label %then.3, label %else.3

else.3:                                           ; preds = %then.3
  ret i64 %r.1.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_5(i64 noundef %x) #0 {
entry:
  br label %then.3

then.3:                                           ; preds = %then.3, %entry
  %x.addr.018 = phi i64 [ %x, %entry ], [ %x.addr.1.1, %then.3 ]
  %r.017 = phi i64 [ 0, %entry ], [ %r.1.1, %then.3 ]
  %s.016 = phi i64 [ 63, %entry ], [ %sub.1.1, %then.3 ]
  %shl.0 = shl i64 %r.017, 1
  %mul.0 = mul i64 %r.017, 6
  %add.0 = or i64 %shl.0, 1
  %mul.1 = mul i64 %mul.0, %add.0
  %add.1 = or i64 %mul.1, 1
  %shr.0 = lshr i64 %x.addr.018, %s.016
  %icmp.2.not = icmp ult i64 %shr.0, %add.1
  %shl.1 = shl i64 %add.1, %s.016
  %r.1 = select i1 %icmp.2.not, i64 %shl.0, i64 %add.0
  %sub.0 = select i1 %icmp.2.not, i64 0, i64 %shl.1
  %x.addr.1 = sub i64 %x.addr.018, %sub.0
  %sub.1 = add nsw i64 %s.016, -3
  %shl.0.1 = shl i64 %r.1, 1
  %mul.0.1 = mul i64 %r.1, 6
  %add.0.1 = or i64 %shl.0.1, 1
  %mul.1.1 = mul i64 %mul.0.1, %add.0.1
  %add.1.1 = or i64 %mul.1.1, 1
  %shr.0.1 = lshr i64 %x.addr.1, %sub.1
  %icmp.2.not.1 = icmp ult i64 %shr.0.1, %add.1.1
  %shl.1.1 = shl i64 %add.1.1, %sub.1
  %r.1.1 = select i1 %icmp.2.not.1, i64 %shl.0.1, i64 %add.0.1
  %sub.0.1 = select i1 %icmp.2.not.1, i64 0, i64 %shl.1.1
  %x.addr.1.1 = sub i64 %x.addr.1, %sub.0.1
  %sub.1.1 = add nsw i64 %s.016, -6
  %icmp.3.1 = icmp ugt i64 %sub.1, 2
  br i1 %icmp.3.1, label %then.3, label %else.3

else.3:                                           ; preds = %then.3
  ret i64 %r.1.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_6(i64 noundef %x) #0 {
entry:
  br label %then.3

then.3:                                           ; preds = %then.3, %entry
  %x.addr.018 = phi i64 [ %x, %entry ], [ %x.addr.1.1, %then.3 ]
  %s.017 = phi i64 [ 63, %entry ], [ %sub.1.1, %then.3 ]
  %r.016 = phi i64 [ 0, %entry ], [ %r.1.1, %then.3 ]
  %shl.0 = shl i64 %r.016, 1
  %mul.0 = mul i64 %r.016, 6
  %add.0 = or i64 %shl.0, 1
  %mul.1 = mul i64 %mul.0, %add.0
  %add.1 = or i64 %mul.1, 1
  %shr.0 = lshr i64 %x.addr.018, %s.017
  %icmp.2.not = icmp ult i64 %shr.0, %add.1
  %shl.1 = shl i64 %add.1, %s.017
  %r.1 = select i1 %icmp.2.not, i64 %shl.0, i64 %add.0
  %sub.0 = select i1 %icmp.2.not, i64 0, i64 %shl.1
  %x.addr.1 = sub i64 %x.addr.018, %sub.0
  %sub.1 = add nsw i64 %s.017, -3
  %shl.0.1 = shl i64 %r.1, 1
  %mul.0.1 = mul i64 %r.1, 6
  %add.0.1 = or i64 %shl.0.1, 1
  %mul.1.1 = mul i64 %mul.0.1, %add.0.1
  %add.1.1 = or i64 %mul.1.1, 1
  %shr.0.1 = lshr i64 %x.addr.1, %sub.1
  %icmp.2.not.1 = icmp ult i64 %shr.0.1, %add.1.1
  %shl.1.1 = shl i64 %add.1.1, %sub.1
  %r.1.1 = select i1 %icmp.2.not.1, i64 %shl.0.1, i64 %add.0.1
  %sub.0.1 = select i1 %icmp.2.not.1, i64 0, i64 %shl.1.1
  %x.addr.1.1 = sub i64 %x.addr.1, %sub.0.1
  %sub.1.1 = add nsw i64 %s.017, -6
  %icmp.3.1 = icmp ugt i64 %sub.1, 2
  br i1 %icmp.3.1, label %then.3, label %else.3

else.3:                                           ; preds = %then.3
  ret i64 %r.1.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_7(i64 noundef %x) #0 {
entry:
  br label %then.3

then.3:                                           ; preds = %then.3, %entry
  %x.addr.019 = phi i64 [ %x, %entry ], [ %x.addr.1.1, %then.3 ]
  %r.018 = phi i64 [ 0, %entry ], [ %r.1.1, %then.3 ]
  %s.017 = phi i64 [ 63, %entry ], [ %sub.1.1, %then.3 ]
  %shl.0 = shl i64 %r.018, 1
  %add.0 = or i64 %shl.0, 1
  %mul.0 = mul i64 %r.018, 6
  %mul.1 = mul i64 %mul.0, %add.0
  %add.1 = or i64 %mul.1, 1
  %shr.0 = lshr i64 %x.addr.019, %s.017
  %icmp.2.not = icmp ult i64 %shr.0, %add.1
  %shl.1 = shl i64 %add.1, %s.017
  %r.1 = select i1 %icmp.2.not, i64 %shl.0, i64 %add.0
  %sub.0 = select i1 %icmp.2.not, i64 0, i64 %shl.1
  %x.addr.1 = sub i64 %x.addr.019, %sub.0
  %sub.1 = add nsw i64 %s.017, -3
  %shl.0.1 = shl i64 %r.1, 1
  %add.0.1 = or i64 %shl.0.1, 1
  %mul.0.1 = mul i64 %r.1, 6
  %mul.1.1 = mul i64 %mul.0.1, %add.0.1
  %add.1.1 = or i64 %mul.1.1, 1
  %shr.0.1 = lshr i64 %x.addr.1, %sub.1
  %icmp.2.not.1 = icmp ult i64 %shr.0.1, %add.1.1
  %shl.1.1 = shl i64 %add.1.1, %sub.1
  %r.1.1 = select i1 %icmp.2.not.1, i64 %shl.0.1, i64 %add.0.1
  %sub.0.1 = select i1 %icmp.2.not.1, i64 0, i64 %shl.1.1
  %x.addr.1.1 = sub i64 %x.addr.1, %sub.0.1
  %sub.1.1 = add nsw i64 %s.017, -6
  %icmp.3.1 = icmp ugt i64 %sub.1, 2
  br i1 %icmp.3.1, label %then.3, label %else.3

else.3:                                           ; preds = %then.3
  ret i64 %r.1.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_8(i64 noundef %x) #0 {
entry:
  br label %then.3

then.3:                                           ; preds = %then.3, %entry
  %x.addr.018 = phi i64 [ %x, %entry ], [ %x.addr.1.1, %then.3 ]
  %r.017 = phi i64 [ 0, %entry ], [ %r.1.1, %then.3 ]
  %s.016 = phi i64 [ 63, %entry ], [ %sub.1.1, %then.3 ]
  %shl.0 = shl i64 %r.017, 1
  %mul.0 = mul i64 %r.017, 6
  %add.0 = or i64 %shl.0, 1
  %mul.1 = mul i64 %mul.0, %add.0
  %add.1 = or i64 %mul.1, 1
  %shr.0 = lshr i64 %x.addr.018, %s.016
  %icmp.2.not = icmp ult i64 %shr.0, %add.1
  %shl.1 = shl i64 %add.1, %s.016
  %r.1 = select i1 %icmp.2.not, i64 %shl.0, i64 %add.0
  %sub.0 = select i1 %icmp.2.not, i64 0, i64 %shl.1
  %x.addr.1 = sub i64 %x.addr.018, %sub.0
  %sub.1 = add nsw i64 %s.016, -3
  %shl.0.1 = shl i64 %r.1, 1
  %mul.0.1 = mul i64 %r.1, 6
  %add.0.1 = or i64 %shl.0.1, 1
  %mul.1.1 = mul i64 %mul.0.1, %add.0.1
  %add.1.1 = or i64 %mul.1.1, 1
  %shr.0.1 = lshr i64 %x.addr.1, %sub.1
  %icmp.2.not.1 = icmp ult i64 %shr.0.1, %add.1.1
  %shl.1.1 = shl i64 %add.1.1, %sub.1
  %r.1.1 = select i1 %icmp.2.not.1, i64 %shl.0.1, i64 %add.0.1
  %sub.0.1 = select i1 %icmp.2.not.1, i64 0, i64 %shl.1.1
  %x.addr.1.1 = sub i64 %x.addr.1, %sub.0.1
  %sub.1.1 = add nsw i64 %s.016, -6
  %icmp.3.1 = icmp ugt i64 %sub.1, 2
  br i1 %icmp.3.1, label %then.3, label %else.3

else.3:                                           ; preds = %then.3
  ret i64 %r.1.1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_9(i64 noundef %x) #0 {
entry:
  br label %then.3

then.3:                                           ; preds = %then.3, %entry
  %x.addr.018 = phi i64 [ %x, %entry ], [ %x.addr.1.1, %then.3 ]
  %r.017 = phi i64 [ 0, %entry ], [ %r.1.1, %then.3 ]
  %s.016 = phi i64 [ 63, %entry ], [ %sub.1.1, %then.3 ]
  %shl.0 = shl i64 %r.017, 1
  %mul.0 = mul i64 %r.017, 6
  %add.0 = or i64 %shl.0, 1
  %mul.1 = mul i64 %mul.0, %add.0
  %add.1 = or i64 %mul.1, 1
  %shr.0 = lshr i64 %x.addr.018, %s.016
  %icmp.2.not = icmp ult i64 %shr.0, %add.1
  %shl.1 = shl i64 %add.1, %s.016
  %r.1 = select i1 %icmp.2.not, i64 %shl.0, i64 %add.0
  %sub.0 = select i1 %icmp.2.not, i64 0, i64 %shl.1
  %x.addr.1 = sub i64 %x.addr.018, %sub.0
  %sub.1 = add nsw i64 %s.016, -3
  %shl.0.1 = shl i64 %r.1, 1
  %mul.0.1 = mul i64 %r.1, 6
  %add.0.1 = or i64 %shl.0.1, 1
  %mul.1.1 = mul i64 %mul.0.1, %add.0.1
  %add.1.1 = or i64 %mul.1.1, 1
  %shr.0.1 = lshr i64 %x.addr.1, %sub.1
  %icmp.2.not.1 = icmp ult i64 %shr.0.1, %add.1.1
  %shl.1.1 = shl i64 %add.1.1, %sub.1
  %r.1.1 = select i1 %icmp.2.not.1, i64 %shl.0.1, i64 %add.0.1
  %sub.0.1 = select i1 %icmp.2.not.1, i64 0, i64 %shl.1.1
  %x.addr.1.1 = sub i64 %x.addr.1, %sub.0.1
  %sub.1.1 = add nsw i64 %s.016, -6
  %icmp.3.1 = icmp ugt i64 %sub.1, 2
  br i1 %icmp.3.1, label %then.3, label %else.3

else.3:                                           ; preds = %then.3
  ret i64 %r.1.1
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_1(i64 noundef %x) #0 {
entry:
  %x.addr = alloca i64, align 8
  %r = alloca i64, align 8
  %b = alloca i64, align 8
  %s = alloca i32, align 4
  store i64 %x, ptr %x.addr, align 8
  store i64 0, ptr %r, align 8
  store i32 63, ptr %s, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, ptr %s, align 4
  %cmp = icmp sge i32 %0, 0
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %1 = load i64, ptr %r, align 8
  %shl = shl i64 %1, 1
  store i64 %shl, ptr %r, align 8
  %2 = load i64, ptr %r, align 8
  %mul = mul i64 3, %2
  %3 = load i64, ptr %r, align 8
  %add = add i64 %3, 1
  %mul1 = mul i64 %mul, %add
  %add2 = add i64 %mul1, 1
  store i64 %add2, ptr %b, align 8
  %4 = load i64, ptr %x.addr, align 8
  %5 = load i32, ptr %s, align 4
  %sh_prom = zext i32 %5 to i64
  %shr = lshr i64 %4, %sh_prom
  %6 = load i64, ptr %b, align 8
  %cmp3 = icmp uge i64 %shr, %6
  br i1 %cmp3, label %if.then, label %if.end

if.then:                                          ; preds = %for.body
  %7 = load i64, ptr %b, align 8
  %8 = load i32, ptr %s, align 4
  %sh_prom4 = zext i32 %8 to i64
  %shl5 = shl i64 %7, %sh_prom4
  %9 = load i64, ptr %x.addr, align 8
  %sub = sub i64 %9, %shl5
  store i64 %sub, ptr %x.addr, align 8
  %10 = load i64, ptr %r, align 8
  %inc = add i64 %10, 1
  store i64 %inc, ptr %r, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %for.body
  br label %for.inc

for.inc:                                          ; preds = %if.end
  %11 = load i32, ptr %s, align 4
  %sub6 = sub nsw i32 %11, 3
  store i32 %sub6, ptr %s, align 4
  br label %for.cond, !llvm.loop !8

for.end:                                          ; preds = %for.cond
  %12 = load i64, ptr %r, align 8
  %mul7 = mul i64 %12, 1
  %shl8 = shl i64 %mul7, 12
  ret i64 %shl8
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
