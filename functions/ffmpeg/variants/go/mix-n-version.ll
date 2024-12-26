; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/1_mix.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/1_mix.run.c"
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
  %call1 = call i32 @n_version_call(i32 noundef 0, i32 noundef 0)
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
define internal i32 @n_version_call(i32 noundef %0, i32 noundef %1) #0 {
entry:
  %2 = call i32 @version_1(i32 %0, i32 %1)
  %3 = call i32 @version_2(i32 %0, i32 %1)
  %4 = call i32 @version_3(i32 %0, i32 %1)
  %5 = call i32 @version_4(i32 %0, i32 %1)
  %6 = call i32 @version_5(i32 %0, i32 %1)
  %7 = call i32 @version_6(i32 %0, i32 %1)
  %8 = call i32 @version_7(i32 %0, i32 %1)
  %9 = call i32 @version_8(i32 %0, i32 %1)
  %10 = call i32 @version_9(i32 %0, i32 %1)
  %11 = call i32 @version_10(i32 %0, i32 %1)
  %12 = call i32 @version_11(i32 %0, i32 %1)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %13 = icmp eq i32 %2, %3
  br i1 %13, label %true, label %error

true:                                             ; preds = %comparisons
  %14 = icmp eq i32 %2, %4
  br i1 %14, label %true1, label %error

true1:                                            ; preds = %true
  %15 = icmp eq i32 %2, %5
  br i1 %15, label %true2, label %error

true2:                                            ; preds = %true1
  %16 = icmp eq i32 %2, %6
  br i1 %16, label %true3, label %error

true3:                                            ; preds = %true2
  %17 = icmp eq i32 %2, %7
  br i1 %17, label %true4, label %error

true4:                                            ; preds = %true3
  %18 = icmp eq i32 %2, %8
  br i1 %18, label %true5, label %error

true5:                                            ; preds = %true4
  %19 = icmp eq i32 %2, %9
  br i1 %19, label %true6, label %error

true6:                                            ; preds = %true5
  %20 = icmp eq i32 %2, %10
  br i1 %20, label %true7, label %error

true7:                                            ; preds = %true6
  %21 = icmp eq i32 %2, %11
  br i1 %21, label %true8, label %error

true8:                                            ; preds = %true7
  %22 = icmp eq i32 %2, %12
  br i1 %22, label %true9, label %error

true9:                                            ; preds = %true8
  ret i32 %2

error:                                            ; preds = %true8, %true7, %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_2(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %iand.0 = shl i32 %c0, 1
  %mul.0 = and i32 %iand.0, 62
  %iand.1 = and i32 %c1, 31
  %add.0 = add nuw nsw i32 %mul.0, %iand.1
  %mul.1 = and i32 %iand.0, 1984
  %iand.3 = and i32 %c1, 992
  %add.1 = add nuw nsw i32 %mul.1, %iand.3
  %0 = ashr i32 %c0, 9
  %mul.2 = and i32 %0, -2
  %shr.2 = ashr i32 %c1, 10
  %add.2 = add nsw i32 %mul.2, %shr.2
  %div.0 = sdiv i32 %add.2, 3
  %mul.3 = shl i32 %div.0, 10
  %div.1.lhs.trunc = trunc i32 %add.1 to i16
  %div.19 = udiv i16 %div.1.lhs.trunc, 96
  %1 = shl nuw nsw i16 %div.19, 5
  %mul.4 = zext i16 %1 to i32
  %div.2.lhs.trunc = trunc i32 %add.0 to i8
  %div.210 = udiv i8 %div.2.lhs.trunc, 3
  %div.2.zext = zext i8 %div.210 to i32
  %add.3 = or i32 %mul.3, %div.2.zext
  %add.4 = add i32 %add.3, %mul.4
  ret i32 %add.4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_3(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %iand.0 = shl i32 %c0, 1
  %mul.0 = and i32 %iand.0, 62
  %iand.1 = and i32 %c1, 31
  %add.0 = add nuw nsw i32 %mul.0, %iand.1
  %0 = lshr i32 %c0, 4
  %1 = and i32 %0, 62
  %iand.3 = lshr i32 %c1, 5
  %2 = and i32 %iand.3, 31
  %add.1 = add nuw nsw i32 %2, %1
  %3 = ashr i32 %c0, 9
  %mul.2 = and i32 %3, -2
  %shr.3 = ashr i32 %c1, 10
  %add.2 = add nsw i32 %mul.2, %shr.3
  %div.0 = sdiv i32 %add.2, 3
  %mul.3 = shl i32 %div.0, 10
  %div.1.lhs.trunc = trunc i32 %add.1 to i8
  %div.19 = udiv i8 %div.1.lhs.trunc, 3
  %div.1.zext = zext i8 %div.19 to i32
  %mul.4 = shl nuw nsw i32 %div.1.zext, 5
  %div.2.lhs.trunc = trunc i32 %add.0 to i8
  %div.210 = udiv i8 %div.2.lhs.trunc, 3
  %div.2.zext = zext i8 %div.210 to i32
  %add.3 = or i32 %mul.3, %div.2.zext
  %add.4 = add i32 %add.3, %mul.4
  ret i32 %add.4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_4(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %iand.0 = shl i32 %c0, 1
  %mul.0 = and i32 %iand.0, 62
  %iand.1 = and i32 %c1, 31
  %add.0 = add nuw nsw i32 %mul.0, %iand.1
  %mul.1 = and i32 %iand.0, 1984
  %iand.3 = and i32 %c1, 992
  %add.1 = add nuw nsw i32 %mul.1, %iand.3
  %0 = ashr i32 %c0, 9
  %mul.2 = and i32 %0, -2
  %shr.2 = ashr i32 %c1, 10
  %add.2 = add nsw i32 %mul.2, %shr.2
  %div.0 = sdiv i32 %add.2, 3
  %mul.3 = shl i32 %div.0, 10
  %div.1.lhs.trunc = trunc i32 %add.1 to i16
  %div.19 = udiv i16 %div.1.lhs.trunc, 96
  %1 = shl nuw nsw i16 %div.19, 5
  %mul.4 = zext i16 %1 to i32
  %div.2.lhs.trunc = trunc i32 %add.0 to i8
  %div.210 = udiv i8 %div.2.lhs.trunc, 3
  %div.2.zext = zext i8 %div.210 to i32
  %add.3 = or i32 %mul.3, %div.2.zext
  %add.4 = add i32 %add.3, %mul.4
  ret i32 %add.4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_5(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %iand.0 = shl i32 %c0, 1
  %mul.0 = and i32 %iand.0, 62
  %iand.1 = and i32 %c1, 31
  %add.0 = add nuw nsw i32 %mul.0, %iand.1
  %0 = lshr i32 %c0, 4
  %1 = and i32 %0, 62
  %iand.3 = lshr i32 %c1, 5
  %2 = and i32 %iand.3, 31
  %add.1 = add nuw nsw i32 %2, %1
  %3 = ashr i32 %c0, 9
  %mul.2 = and i32 %3, -2
  %shr.3 = ashr i32 %c1, 10
  %add.2 = add nsw i32 %mul.2, %shr.3
  %div.0 = sdiv i32 %add.2, 3
  %mul.3 = shl i32 %div.0, 10
  %div.1.lhs.trunc = trunc i32 %add.1 to i8
  %div.19 = udiv i8 %div.1.lhs.trunc, 3
  %div.1.zext = zext i8 %div.19 to i32
  %mul.4 = shl nuw nsw i32 %div.1.zext, 5
  %div.2.lhs.trunc = trunc i32 %add.0 to i8
  %div.210 = udiv i8 %div.2.lhs.trunc, 3
  %div.2.zext = zext i8 %div.210 to i32
  %add.3 = or i32 %mul.3, %div.2.zext
  %add.4 = add i32 %add.3, %mul.4
  ret i32 %add.4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_6(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %iand.0 = shl i32 %c0, 1
  %mul.0 = and i32 %iand.0, 62
  %iand.1 = and i32 %c1, 31
  %add.0 = add nuw nsw i32 %mul.0, %iand.1
  %0 = lshr i32 %c0, 4
  %1 = and i32 %0, 62
  %iand.3 = lshr i32 %c1, 5
  %2 = and i32 %iand.3, 31
  %add.1 = add nuw nsw i32 %2, %1
  %3 = ashr i32 %c0, 9
  %mul.2 = and i32 %3, -2
  %shr.3 = ashr i32 %c1, 10
  %add.2 = add nsw i32 %mul.2, %shr.3
  %div.0 = sdiv i32 %add.2, 3
  %mul.3 = shl i32 %div.0, 10
  %div.1.lhs.trunc = trunc i32 %add.1 to i8
  %div.19 = udiv i8 %div.1.lhs.trunc, 3
  %div.1.zext = zext i8 %div.19 to i32
  %mul.4 = shl nuw nsw i32 %div.1.zext, 5
  %div.2.lhs.trunc = trunc i32 %add.0 to i8
  %div.210 = udiv i8 %div.2.lhs.trunc, 3
  %div.2.zext = zext i8 %div.210 to i32
  %add.3 = or i32 %mul.3, %div.2.zext
  %add.4 = add i32 %add.3, %mul.4
  ret i32 %add.4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_7(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %iand.0 = shl i32 %c0, 1
  %mul.0 = and i32 %iand.0, 62
  %iand.1 = and i32 %c1, 31
  %add.0 = add nuw nsw i32 %mul.0, %iand.1
  %mul.1 = and i32 %iand.0, 1984
  %iand.3 = and i32 %c1, 992
  %add.1 = add nuw nsw i32 %mul.1, %iand.3
  %0 = ashr i32 %c0, 9
  %mul.2 = and i32 %0, -2
  %shr.2 = ashr i32 %c1, 10
  %add.2 = add nsw i32 %mul.2, %shr.2
  %div.0 = sdiv i32 %add.2, 3
  %mul.3 = shl i32 %div.0, 10
  %div.1.lhs.trunc = trunc i32 %add.1 to i16
  %div.19 = udiv i16 %div.1.lhs.trunc, 96
  %1 = shl nuw nsw i16 %div.19, 5
  %mul.4 = zext i16 %1 to i32
  %div.2.lhs.trunc = trunc i32 %add.0 to i8
  %div.210 = udiv i8 %div.2.lhs.trunc, 3
  %div.2.zext = zext i8 %div.210 to i32
  %add.3 = or i32 %mul.3, %div.2.zext
  %add.4 = add i32 %add.3, %mul.4
  ret i32 %add.4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_8(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %iand.0 = shl i32 %c0, 1
  %mul.0 = and i32 %iand.0, 62
  %iand.1 = and i32 %c1, 31
  %add.0 = add nuw nsw i32 %mul.0, %iand.1
  %0 = lshr i32 %c0, 4
  %1 = and i32 %0, 62
  %iand.3 = lshr i32 %c1, 5
  %2 = and i32 %iand.3, 31
  %add.1 = add nuw nsw i32 %2, %1
  %3 = ashr i32 %c0, 9
  %mul.2 = and i32 %3, -2
  %shr.3 = ashr i32 %c1, 10
  %add.2 = add nsw i32 %mul.2, %shr.3
  %div.0 = sdiv i32 %add.2, 3
  %mul.3 = shl i32 %div.0, 10
  %div.1.lhs.trunc = trunc i32 %add.1 to i8
  %div.19 = udiv i8 %div.1.lhs.trunc, 3
  %div.1.zext = zext i8 %div.19 to i32
  %mul.4 = shl nuw nsw i32 %div.1.zext, 5
  %div.2.lhs.trunc = trunc i32 %add.0 to i8
  %div.210 = udiv i8 %div.2.lhs.trunc, 3
  %div.2.zext = zext i8 %div.210 to i32
  %add.3 = or i32 %mul.3, %div.2.zext
  %add.4 = add i32 %add.3, %mul.4
  ret i32 %add.4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_9(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %iand.0 = shl i32 %c0, 1
  %mul.0 = and i32 %iand.0, 62
  %iand.1 = and i32 %c1, 31
  %add.0 = add nuw nsw i32 %mul.0, %iand.1
  %mul.1 = and i32 %iand.0, 1984
  %iand.3 = and i32 %c1, 992
  %add.1 = add nuw nsw i32 %mul.1, %iand.3
  %0 = ashr i32 %c0, 9
  %mul.2 = and i32 %0, -2
  %shr.2 = ashr i32 %c1, 10
  %add.2 = add nsw i32 %mul.2, %shr.2
  %div.0 = sdiv i32 %add.2, 3
  %mul.3 = shl i32 %div.0, 10
  %div.1.lhs.trunc = trunc i32 %add.1 to i16
  %div.19 = udiv i16 %div.1.lhs.trunc, 96
  %1 = shl nuw nsw i16 %div.19, 5
  %mul.4 = zext i16 %1 to i32
  %div.2.lhs.trunc = trunc i32 %add.0 to i8
  %div.210 = udiv i8 %div.2.lhs.trunc, 3
  %div.2.zext = zext i8 %div.210 to i32
  %add.3 = or i32 %mul.3, %div.2.zext
  %add.4 = add i32 %add.3, %mul.4
  ret i32 %add.4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_10(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %iand.0 = shl i32 %c0, 1
  %mul.0 = and i32 %iand.0, 62
  %iand.1 = and i32 %c1, 31
  %add.0 = add nuw nsw i32 %mul.0, %iand.1
  %mul.1 = and i32 %iand.0, 1984
  %iand.3 = and i32 %c1, 992
  %add.1 = add nuw nsw i32 %mul.1, %iand.3
  %0 = ashr i32 %c0, 9
  %mul.2 = and i32 %0, -2
  %shr.2 = ashr i32 %c1, 10
  %add.2 = add nsw i32 %mul.2, %shr.2
  %div.0 = sdiv i32 %add.2, 3
  %mul.3 = shl i32 %div.0, 10
  %div.1.lhs.trunc = trunc i32 %add.1 to i16
  %div.19 = udiv i16 %div.1.lhs.trunc, 96
  %1 = shl nuw nsw i16 %div.19, 5
  %mul.4 = zext i16 %1 to i32
  %div.2.lhs.trunc = trunc i32 %add.0 to i8
  %div.210 = udiv i8 %div.2.lhs.trunc, 3
  %div.2.zext = zext i8 %div.210 to i32
  %add.3 = or i32 %mul.3, %div.2.zext
  %add.4 = add i32 %add.3, %mul.4
  ret i32 %add.4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_11(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %iand.0 = shl i32 %c0, 1
  %mul.0 = and i32 %iand.0, 62
  %iand.1 = and i32 %c1, 31
  %add.0 = add nuw nsw i32 %mul.0, %iand.1
  %mul.1 = and i32 %iand.0, 1984
  %iand.3 = and i32 %c1, 992
  %add.1 = add nuw nsw i32 %mul.1, %iand.3
  %0 = ashr i32 %c0, 9
  %mul.2 = and i32 %0, -2
  %shr.2 = ashr i32 %c1, 10
  %add.2 = add nsw i32 %mul.2, %shr.2
  %div.0 = sdiv i32 %add.2, 3
  %mul.3 = shl i32 %div.0, 10
  %div.1.lhs.trunc = trunc i32 %add.1 to i16
  %div.19 = udiv i16 %div.1.lhs.trunc, 96
  %1 = shl nuw nsw i16 %div.19, 5
  %mul.4 = zext i16 %1 to i32
  %div.2.lhs.trunc = trunc i32 %add.0 to i8
  %div.210 = udiv i8 %div.2.lhs.trunc, 3
  %div.2.zext = zext i8 %div.210 to i32
  %add.3 = or i32 %mul.3, %div.2.zext
  %add.4 = add i32 %add.3, %mul.4
  ret i32 %add.4
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_1(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %c0.addr = alloca i32, align 4
  %c1.addr = alloca i32, align 4
  %blue = alloca i32, align 4
  %green = alloca i32, align 4
  %red = alloca i32, align 4
  store i32 %c0, ptr %c0.addr, align 4
  store i32 %c1, ptr %c1.addr, align 4
  %0 = load i32, ptr %c0.addr, align 4
  %and = and i32 %0, 31
  %mul = mul nsw i32 2, %and
  %1 = load i32, ptr %c1.addr, align 4
  %and1 = and i32 %1, 31
  %add = add nsw i32 %mul, %and1
  store i32 %add, ptr %blue, align 4
  %2 = load i32, ptr %c0.addr, align 4
  %and2 = and i32 %2, 992
  %mul3 = mul nsw i32 2, %and2
  %3 = load i32, ptr %c1.addr, align 4
  %and4 = and i32 %3, 992
  %add5 = add nsw i32 %mul3, %and4
  %shr = ashr i32 %add5, 5
  store i32 %shr, ptr %green, align 4
  %4 = load i32, ptr %c0.addr, align 4
  %shr6 = ashr i32 %4, 10
  %mul7 = mul nsw i32 2, %shr6
  %5 = load i32, ptr %c1.addr, align 4
  %shr8 = ashr i32 %5, 10
  %add9 = add nsw i32 %mul7, %shr8
  store i32 %add9, ptr %red, align 4
  %6 = load i32, ptr %red, align 4
  %div = sdiv i32 %6, 3
  %mul10 = mul nsw i32 %div, 1024
  %7 = load i32, ptr %green, align 4
  %div11 = sdiv i32 %7, 3
  %mul12 = mul nsw i32 %div11, 32
  %add13 = add nsw i32 %mul10, %mul12
  %8 = load i32, ptr %blue, align 4
  %div14 = sdiv i32 %8, 3
  %add15 = add nsw i32 %add13, %div14
  ret i32 %add15
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
