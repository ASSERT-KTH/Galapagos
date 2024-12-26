; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/4_int_sin.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/4_int_sin.run.c"
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
  %10 = call i64 @version_10(i64 %0)
  %11 = call i64 @version_11(i64 %0)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %12 = icmp eq i64 %1, %2
  br i1 %12, label %true, label %error

true:                                             ; preds = %comparisons
  %13 = icmp eq i64 %1, %3
  br i1 %13, label %true1, label %error

true1:                                            ; preds = %true
  %14 = icmp eq i64 %1, %4
  br i1 %14, label %true2, label %error

true2:                                            ; preds = %true1
  %15 = icmp eq i64 %1, %5
  br i1 %15, label %true3, label %error

true3:                                            ; preds = %true2
  %16 = icmp eq i64 %1, %6
  br i1 %16, label %true4, label %error

true4:                                            ; preds = %true3
  %17 = icmp eq i64 %1, %7
  br i1 %17, label %true5, label %error

true5:                                            ; preds = %true4
  %18 = icmp eq i64 %1, %8
  br i1 %18, label %true6, label %error

true6:                                            ; preds = %true5
  %19 = icmp eq i64 %1, %9
  br i1 %19, label %true7, label %error

true7:                                            ; preds = %true6
  %20 = icmp eq i64 %1, %10
  br i1 %20, label %true8, label %error

true8:                                            ; preds = %true7
  %21 = icmp eq i64 %1, %11
  br i1 %21, label %true9, label %error

true9:                                            ; preds = %true8
  ret i64 %1

error:                                            ; preds = %true8, %true7, %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_2(i64 noundef %a) #0 {
else.8.4:
  %icmp.0 = icmp slt i64 %a, 0
  %add.0 = add i64 %a, 3294199
  %spec.select = select i1 %icmp.0, i64 %add.0, i64 %a
  %mod.0 = srem i64 %spec.select, 6588398
  %icmp.3 = icmp sgt i64 %mod.0, 4941297
  %sub.0 = add nsw i64 %mod.0, -6588398
  %a.addr.1 = select i1 %icmp.3, i64 %sub.0, i64 %mod.0
  %icmp.4 = icmp sgt i64 %a.addr.1, 1647098
  %sub.1 = sub nsw i64 3294199, %a.addr.1
  %a.addr.2 = select i1 %icmp.4, i64 %sub.1, i64 %a.addr.1
  %mul.0 = mul nsw i64 %a.addr.2, %a.addr.2
  %div.0 = lshr i64 %mul.0, 20
  %0 = mul i64 %div.0, %a.addr.2
  %mul.1 = sub i64 0, %0
  %div.1 = sdiv i64 %mul.1, 6291456
  %1 = mul i64 %div.0, %div.1
  %mul.1.1 = sub i64 0, %1
  %div.1.1 = sdiv i64 %mul.1.1, 20971520
  %2 = mul i64 %div.0, %div.1.1
  %mul.1.2 = sub i64 0, %2
  %div.1.2 = sdiv i64 %mul.1.2, 44040192
  %3 = mul i64 %div.0, %div.1.2
  %mul.1.3 = sub i64 0, %3
  %div.1.3 = sdiv i64 %mul.1.3, 75497472
  %add.1.1 = add nsw i64 %div.1, %a.addr.2
  %add.1.2 = add nsw i64 %div.1.1, %add.1.1
  %add.1.3 = add nsw i64 %div.1.2, %add.1.2
  %add.1.4 = add nsw i64 %div.1.3, %add.1.3
  %add.4 = add nsw i64 %add.1.4, 8
  %shr.0 = ashr i64 %add.4, 4
  ret i64 %shr.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_3(i64 noundef %a) #0 {
else.8.4:
  %icmp.0 = icmp slt i64 %a, 0
  %add.0 = add i64 %a, 3294199
  %spec.select = select i1 %icmp.0, i64 %add.0, i64 %a
  %mod.0 = srem i64 %spec.select, 6588398
  %icmp.3 = icmp sgt i64 %mod.0, 4941297
  %sub.0 = add nsw i64 %mod.0, -6588398
  %a.addr.1 = select i1 %icmp.3, i64 %sub.0, i64 %mod.0
  %icmp.4 = icmp sgt i64 %a.addr.1, 1647098
  %sub.1 = sub nsw i64 3294199, %a.addr.1
  %a.addr.2 = select i1 %icmp.4, i64 %sub.1, i64 %a.addr.1
  %mul.0 = mul nsw i64 %a.addr.2, %a.addr.2
  %div.0 = lshr i64 %mul.0, 20
  %0 = mul i64 %div.0, %a.addr.2
  %mul.1 = sub i64 0, %0
  %div.1 = sdiv i64 %mul.1, 6291456
  %1 = mul i64 %div.0, %div.1
  %mul.1.1 = sub i64 0, %1
  %div.1.1 = sdiv i64 %mul.1.1, 20971520
  %2 = mul i64 %div.0, %div.1.1
  %mul.1.2 = sub i64 0, %2
  %div.1.2 = sdiv i64 %mul.1.2, 44040192
  %3 = mul i64 %div.0, %div.1.2
  %mul.1.3 = sub i64 0, %3
  %div.1.3 = sdiv i64 %mul.1.3, 75497472
  %add.1.1 = add nsw i64 %div.1, %a.addr.2
  %add.1.2 = add nsw i64 %div.1.1, %add.1.1
  %add.1.3 = add nsw i64 %div.1.2, %add.1.2
  %add.1.4 = add nsw i64 %div.1.3, %add.1.3
  %add.4 = add nsw i64 %add.1.4, 8
  %shr.0 = ashr i64 %add.4, 4
  ret i64 %shr.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_4(i64 noundef %a) #0 {
else.8.4:
  %icmp.0 = icmp slt i64 %a, 0
  %add.0 = add i64 %a, 3294199
  %spec.select = select i1 %icmp.0, i64 %add.0, i64 %a
  %mod.0 = srem i64 %spec.select, 6588398
  %icmp.3 = icmp sgt i64 %mod.0, 4941297
  %sub.0 = add nsw i64 %mod.0, -6588398
  %a.addr.1 = select i1 %icmp.3, i64 %sub.0, i64 %mod.0
  %icmp.4 = icmp sgt i64 %a.addr.1, 1647098
  %sub.1 = sub nsw i64 3294199, %a.addr.1
  %a.addr.2 = select i1 %icmp.4, i64 %sub.1, i64 %a.addr.1
  %mul.0 = mul nsw i64 %a.addr.2, %a.addr.2
  %div.0 = lshr i64 %mul.0, 20
  %0 = mul i64 %div.0, %a.addr.2
  %mul.1 = sub i64 0, %0
  %div.1 = sdiv i64 %mul.1, 6291456
  %1 = mul i64 %div.0, %div.1
  %mul.1.1 = sub i64 0, %1
  %div.1.1 = sdiv i64 %mul.1.1, 20971520
  %2 = mul i64 %div.0, %div.1.1
  %mul.1.2 = sub i64 0, %2
  %div.1.2 = sdiv i64 %mul.1.2, 44040192
  %3 = mul i64 %div.0, %div.1.2
  %mul.1.3 = sub i64 0, %3
  %div.1.3 = sdiv i64 %mul.1.3, 75497472
  %add.1.1 = add nsw i64 %div.1, %a.addr.2
  %add.1.2 = add nsw i64 %div.1.1, %add.1.1
  %add.1.3 = add nsw i64 %div.1.2, %add.1.2
  %add.1.4 = add nsw i64 %div.1.3, %add.1.3
  %add.4 = add nsw i64 %add.1.4, 8
  %shr.0 = ashr i64 %add.4, 4
  ret i64 %shr.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_5(i64 noundef %a) #0 {
else.8.4:
  %icmp.0 = icmp slt i64 %a, 0
  %add.0 = add i64 %a, 3294199
  %spec.select = select i1 %icmp.0, i64 %add.0, i64 %a
  %mod.0 = srem i64 %spec.select, 6588398
  %icmp.3 = icmp sgt i64 %mod.0, 4941297
  %sub.0 = add nsw i64 %mod.0, -6588398
  %a.addr.1 = select i1 %icmp.3, i64 %sub.0, i64 %mod.0
  %icmp.4 = icmp sgt i64 %a.addr.1, 1647098
  %sub.1 = sub nsw i64 3294199, %a.addr.1
  %a.addr.2 = select i1 %icmp.4, i64 %sub.1, i64 %a.addr.1
  %mul.0 = mul nsw i64 %a.addr.2, %a.addr.2
  %div.0 = lshr i64 %mul.0, 20
  %0 = mul i64 %div.0, %a.addr.2
  %mul.1 = sub i64 0, %0
  %div.1 = sdiv i64 %mul.1, 6291456
  %1 = mul i64 %div.0, %div.1
  %mul.1.1 = sub i64 0, %1
  %div.1.1 = sdiv i64 %mul.1.1, 20971520
  %2 = mul i64 %div.0, %div.1.1
  %mul.1.2 = sub i64 0, %2
  %div.1.2 = sdiv i64 %mul.1.2, 44040192
  %3 = mul i64 %div.0, %div.1.2
  %mul.1.3 = sub i64 0, %3
  %div.1.3 = sdiv i64 %mul.1.3, 75497472
  %add.1.1 = add nsw i64 %div.1, %a.addr.2
  %add.1.2 = add nsw i64 %div.1.1, %add.1.1
  %add.1.3 = add nsw i64 %div.1.2, %add.1.2
  %add.1.4 = add nsw i64 %div.1.3, %add.1.3
  %add.4 = add nsw i64 %add.1.4, 8
  %shr.0 = ashr i64 %add.4, 4
  ret i64 %shr.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_6(i64 noundef %a) #0 {
else.8.4:
  %icmp.0 = icmp slt i64 %a, 0
  %add.0 = add i64 %a, 3294199
  %spec.select = select i1 %icmp.0, i64 %add.0, i64 %a
  %mod.0 = srem i64 %spec.select, 6588398
  %icmp.3 = icmp sgt i64 %mod.0, 4941297
  %sub.0 = add nsw i64 %mod.0, -6588398
  %a.addr.1 = select i1 %icmp.3, i64 %sub.0, i64 %mod.0
  %icmp.4 = icmp sgt i64 %a.addr.1, 1647098
  %sub.1 = sub nsw i64 3294199, %a.addr.1
  %a.addr.2 = select i1 %icmp.4, i64 %sub.1, i64 %a.addr.1
  %mul.0 = mul nsw i64 %a.addr.2, %a.addr.2
  %div.0 = lshr i64 %mul.0, 20
  %0 = mul i64 %div.0, %a.addr.2
  %mul.1 = sub i64 0, %0
  %div.1 = sdiv i64 %mul.1, 6291456
  %1 = mul i64 %div.0, %div.1
  %mul.1.1 = sub i64 0, %1
  %div.1.1 = sdiv i64 %mul.1.1, 20971520
  %2 = mul i64 %div.0, %div.1.1
  %mul.1.2 = sub i64 0, %2
  %div.1.2 = sdiv i64 %mul.1.2, 44040192
  %3 = mul i64 %div.0, %div.1.2
  %mul.1.3 = sub i64 0, %3
  %div.1.3 = sdiv i64 %mul.1.3, 75497472
  %add.1.1 = add nsw i64 %div.1, %a.addr.2
  %add.1.2 = add nsw i64 %div.1.1, %add.1.1
  %add.1.3 = add nsw i64 %div.1.2, %add.1.2
  %add.1.4 = add nsw i64 %div.1.3, %add.1.3
  %add.4 = add nsw i64 %add.1.4, 8
  %shr.0 = ashr i64 %add.4, 4
  ret i64 %shr.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_7(i64 noundef %a) #0 {
else.8.4:
  %icmp.0 = icmp slt i64 %a, 0
  %add.0 = add i64 %a, 3294199
  %spec.select = select i1 %icmp.0, i64 %add.0, i64 %a
  %mod.0 = srem i64 %spec.select, 6588398
  %icmp.3 = icmp sgt i64 %mod.0, 4941297
  %sub.0 = add nsw i64 %mod.0, -6588398
  %a.addr.1 = select i1 %icmp.3, i64 %sub.0, i64 %mod.0
  %icmp.4 = icmp sgt i64 %a.addr.1, 1647098
  %sub.1 = sub nsw i64 3294199, %a.addr.1
  %a.addr.2 = select i1 %icmp.4, i64 %sub.1, i64 %a.addr.1
  %mul.0 = mul nsw i64 %a.addr.2, %a.addr.2
  %div.0 = lshr i64 %mul.0, 20
  %0 = mul i64 %div.0, %a.addr.2
  %mul.1 = sub i64 0, %0
  %div.1 = sdiv i64 %mul.1, 6291456
  %1 = mul i64 %div.0, %div.1
  %mul.1.1 = sub i64 0, %1
  %div.1.1 = sdiv i64 %mul.1.1, 20971520
  %2 = mul i64 %div.0, %div.1.1
  %mul.1.2 = sub i64 0, %2
  %div.1.2 = sdiv i64 %mul.1.2, 44040192
  %3 = mul i64 %div.0, %div.1.2
  %mul.1.3 = sub i64 0, %3
  %div.1.3 = sdiv i64 %mul.1.3, 75497472
  %add.1.1 = add nsw i64 %div.1, %a.addr.2
  %add.1.2 = add nsw i64 %div.1.1, %add.1.1
  %add.1.3 = add nsw i64 %div.1.2, %add.1.2
  %add.1.4 = add nsw i64 %div.1.3, %add.1.3
  %add.4 = add nsw i64 %add.1.4, 8
  %shr.0 = ashr i64 %add.4, 4
  ret i64 %shr.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_8(i64 noundef %a) #0 {
else.8.4:
  %icmp.0 = icmp slt i64 %a, 0
  %add.0 = add i64 %a, 3294199
  %spec.select = select i1 %icmp.0, i64 %add.0, i64 %a
  %mod.0 = srem i64 %spec.select, 6588398
  %icmp.3 = icmp sgt i64 %mod.0, 4941297
  %sub.0 = add nsw i64 %mod.0, -6588398
  %a.addr.1 = select i1 %icmp.3, i64 %sub.0, i64 %mod.0
  %icmp.4 = icmp sgt i64 %a.addr.1, 1647098
  %sub.1 = sub nsw i64 3294199, %a.addr.1
  %a.addr.2 = select i1 %icmp.4, i64 %sub.1, i64 %a.addr.1
  %mul.0 = mul nsw i64 %a.addr.2, %a.addr.2
  %div.0 = lshr i64 %mul.0, 20
  %0 = mul i64 %div.0, %a.addr.2
  %mul.1 = sub i64 0, %0
  %div.1 = sdiv i64 %mul.1, 6291456
  %1 = mul i64 %div.0, %div.1
  %mul.1.1 = sub i64 0, %1
  %div.1.1 = sdiv i64 %mul.1.1, 20971520
  %2 = mul i64 %div.0, %div.1.1
  %mul.1.2 = sub i64 0, %2
  %div.1.2 = sdiv i64 %mul.1.2, 44040192
  %3 = mul i64 %div.0, %div.1.2
  %mul.1.3 = sub i64 0, %3
  %div.1.3 = sdiv i64 %mul.1.3, 75497472
  %add.1.1 = add nsw i64 %div.1, %a.addr.2
  %add.1.2 = add nsw i64 %div.1.1, %add.1.1
  %add.1.3 = add nsw i64 %div.1.2, %add.1.2
  %add.1.4 = add nsw i64 %div.1.3, %add.1.3
  %add.4 = add nsw i64 %add.1.4, 8
  %shr.0 = ashr i64 %add.4, 4
  ret i64 %shr.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_9(i64 noundef %a) #0 {
else.8.4:
  %icmp.0 = icmp slt i64 %a, 0
  %add.0 = add i64 %a, 3294199
  %spec.select = select i1 %icmp.0, i64 %add.0, i64 %a
  %mod.0 = srem i64 %spec.select, 6588398
  %icmp.3 = icmp sgt i64 %mod.0, 4941297
  %sub.0 = add nsw i64 %mod.0, -6588398
  %a.addr.1 = select i1 %icmp.3, i64 %sub.0, i64 %mod.0
  %icmp.4 = icmp sgt i64 %a.addr.1, 1647098
  %sub.1 = sub nsw i64 3294199, %a.addr.1
  %a.addr.2 = select i1 %icmp.4, i64 %sub.1, i64 %a.addr.1
  %mul.0 = mul nsw i64 %a.addr.2, %a.addr.2
  %div.0 = lshr i64 %mul.0, 20
  %0 = mul i64 %div.0, %a.addr.2
  %mul.1 = sub i64 0, %0
  %div.1 = sdiv i64 %mul.1, 6291456
  %1 = mul i64 %div.0, %div.1
  %mul.1.1 = sub i64 0, %1
  %div.1.1 = sdiv i64 %mul.1.1, 20971520
  %2 = mul i64 %div.0, %div.1.1
  %mul.1.2 = sub i64 0, %2
  %div.1.2 = sdiv i64 %mul.1.2, 44040192
  %3 = mul i64 %div.0, %div.1.2
  %mul.1.3 = sub i64 0, %3
  %div.1.3 = sdiv i64 %mul.1.3, 75497472
  %add.1.1 = add nsw i64 %div.1, %a.addr.2
  %add.1.2 = add nsw i64 %div.1.1, %add.1.1
  %add.1.3 = add nsw i64 %div.1.2, %add.1.2
  %add.1.4 = add nsw i64 %div.1.3, %add.1.3
  %add.4 = add nsw i64 %add.1.4, 8
  %shr.0 = ashr i64 %add.4, 4
  ret i64 %shr.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_10(i64 noundef %a) #0 {
else.8.4:
  %icmp.0 = icmp slt i64 %a, 0
  %add.0 = add i64 %a, 3294199
  %spec.select = select i1 %icmp.0, i64 %add.0, i64 %a
  %mod.0 = srem i64 %spec.select, 6588398
  %icmp.3 = icmp sgt i64 %mod.0, 4941297
  %sub.0 = add nsw i64 %mod.0, -6588398
  %a.addr.1 = select i1 %icmp.3, i64 %sub.0, i64 %mod.0
  %icmp.4 = icmp sgt i64 %a.addr.1, 1647098
  %sub.1 = sub nsw i64 3294199, %a.addr.1
  %a.addr.2 = select i1 %icmp.4, i64 %sub.1, i64 %a.addr.1
  %mul.0 = mul nsw i64 %a.addr.2, %a.addr.2
  %div.0 = lshr i64 %mul.0, 20
  %0 = mul i64 %div.0, %a.addr.2
  %mul.1 = sub i64 0, %0
  %div.1 = sdiv i64 %mul.1, 6291456
  %1 = mul i64 %div.0, %div.1
  %mul.1.1 = sub i64 0, %1
  %div.1.1 = sdiv i64 %mul.1.1, 20971520
  %2 = mul i64 %div.0, %div.1.1
  %mul.1.2 = sub i64 0, %2
  %div.1.2 = sdiv i64 %mul.1.2, 44040192
  %3 = mul i64 %div.0, %div.1.2
  %mul.1.3 = sub i64 0, %3
  %div.1.3 = sdiv i64 %mul.1.3, 75497472
  %add.1.1 = add nsw i64 %div.1, %a.addr.2
  %add.1.2 = add nsw i64 %div.1.1, %add.1.1
  %add.1.3 = add nsw i64 %div.1.2, %add.1.2
  %add.1.4 = add nsw i64 %div.1.3, %add.1.3
  %add.4 = add nsw i64 %add.1.4, 8
  %shr.0 = ashr i64 %add.4, 4
  ret i64 %shr.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @version_11(i64 noundef %a) #0 {
else.8.4:
  %icmp.0 = icmp slt i64 %a, 0
  %add.0 = add i64 %a, 3294199
  %spec.select = select i1 %icmp.0, i64 %add.0, i64 %a
  %mod.0 = srem i64 %spec.select, 6588398
  %icmp.3 = icmp sgt i64 %mod.0, 4941297
  %sub.0 = add nsw i64 %mod.0, -6588398
  %a.addr.1 = select i1 %icmp.3, i64 %sub.0, i64 %mod.0
  %icmp.4 = icmp sgt i64 %a.addr.1, 1647098
  %sub.1 = sub nsw i64 3294199, %a.addr.1
  %a.addr.2 = select i1 %icmp.4, i64 %sub.1, i64 %a.addr.1
  %mul.0 = mul nsw i64 %a.addr.2, %a.addr.2
  %div.0 = lshr i64 %mul.0, 20
  %0 = mul i64 %div.0, %a.addr.2
  %mul.1 = sub i64 0, %0
  %div.1 = sdiv i64 %mul.1, 6291456
  %1 = mul i64 %div.0, %div.1
  %mul.1.1 = sub i64 0, %1
  %div.1.1 = sdiv i64 %mul.1.1, 20971520
  %2 = mul i64 %div.0, %div.1.1
  %mul.1.2 = sub i64 0, %2
  %div.1.2 = sdiv i64 %mul.1.2, 44040192
  %3 = mul i64 %div.0, %div.1.2
  %mul.1.3 = sub i64 0, %3
  %div.1.3 = sdiv i64 %mul.1.3, 75497472
  %add.1.1 = add nsw i64 %div.1, %a.addr.2
  %add.1.2 = add nsw i64 %div.1.1, %add.1.1
  %add.1.3 = add nsw i64 %div.1.2, %add.1.2
  %add.1.4 = add nsw i64 %div.1.3, %add.1.3
  %add.4 = add nsw i64 %add.1.4, 8
  %shr.0 = ashr i64 %add.4, 4
  ret i64 %shr.0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_1(i64 noundef %a) #0 {
entry:
  %a.addr = alloca i64, align 8
  %a2 = alloca i64, align 8
  %res = alloca i64, align 8
  %i = alloca i32, align 4
  store i64 %a, ptr %a.addr, align 8
  store i64 0, ptr %res, align 8
  %0 = load i64, ptr %a.addr, align 8
  %cmp = icmp slt i64 %0, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %1 = load i64, ptr %a.addr, align 8
  %sub = sub nsw i64 3294199, %1
  store i64 %sub, ptr %a.addr, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %2 = load i64, ptr %a.addr, align 8
  %rem = srem i64 %2, 6588398
  store i64 %rem, ptr %a.addr, align 8
  %3 = load i64, ptr %a.addr, align 8
  %cmp1 = icmp sge i64 %3, 4941298
  br i1 %cmp1, label %if.then2, label %if.end4

if.then2:                                         ; preds = %if.end
  %4 = load i64, ptr %a.addr, align 8
  %sub3 = sub nsw i64 %4, 6588398
  store i64 %sub3, ptr %a.addr, align 8
  br label %if.end4

if.end4:                                          ; preds = %if.then2, %if.end
  %5 = load i64, ptr %a.addr, align 8
  %cmp5 = icmp sge i64 %5, 1647099
  br i1 %cmp5, label %if.then6, label %if.end8

if.then6:                                         ; preds = %if.end4
  %6 = load i64, ptr %a.addr, align 8
  %sub7 = sub nsw i64 3294199, %6
  store i64 %sub7, ptr %a.addr, align 8
  br label %if.end8

if.end8:                                          ; preds = %if.then6, %if.end4
  %7 = load i64, ptr %a.addr, align 8
  %8 = load i64, ptr %a.addr, align 8
  %mul = mul nsw i64 %7, %8
  %div = sdiv i64 %mul, 1048576
  store i64 %div, ptr %a2, align 8
  store i32 2, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %if.end8
  %9 = load i32, ptr %i, align 4
  %cmp9 = icmp slt i32 %9, 11
  br i1 %cmp9, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %10 = load i64, ptr %a.addr, align 8
  %11 = load i64, ptr %res, align 8
  %add = add nsw i64 %11, %10
  store i64 %add, ptr %res, align 8
  %12 = load i64, ptr %a.addr, align 8
  %sub10 = sub nsw i64 0, %12
  %13 = load i64, ptr %a2, align 8
  %mul11 = mul nsw i64 %sub10, %13
  %14 = load i32, ptr %i, align 4
  %mul12 = mul nsw i32 1048576, %14
  %15 = load i32, ptr %i, align 4
  %add13 = add nsw i32 %15, 1
  %mul14 = mul nsw i32 %mul12, %add13
  %conv = sext i32 %mul14 to i64
  %div15 = sdiv i64 %mul11, %conv
  store i64 %div15, ptr %a.addr, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %16 = load i32, ptr %i, align 4
  %add16 = add nsw i32 %16, 2
  store i32 %add16, ptr %i, align 4
  br label %for.cond, !llvm.loop !8

for.end:                                          ; preds = %for.cond
  %17 = load i64, ptr %res, align 8
  %add17 = add nsw i64 %17, 8
  %shr = ashr i64 %add17, 4
  ret i64 %shr
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
