; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/3_ulaw_to_s16.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/3_ulaw_to_s16.run.c"
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
  %call1 = call i32 @n_version_call(i8 noundef zeroext 97)
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
define internal i32 @n_version_call(i8 noundef zeroext %0) #0 {
entry:
  %1 = call i32 @version_1(i8 %0)
  %2 = call i32 @version_2(i8 %0)
  %3 = call i32 @version_3(i8 %0)
  %4 = call i32 @version_4(i8 %0)
  %5 = call i32 @version_5(i8 %0)
  %6 = call i32 @version_6(i8 %0)
  %7 = call i32 @version_7(i8 %0)
  %8 = call i32 @version_8(i8 %0)
  %9 = call i32 @version_9(i8 %0)
  %10 = call i32 @version_10(i8 %0)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %11 = icmp eq i32 %1, %2
  br i1 %11, label %true, label %error

true:                                             ; preds = %comparisons
  %12 = icmp eq i32 %1, %3
  br i1 %12, label %true1, label %error

true1:                                            ; preds = %true
  %13 = icmp eq i32 %1, %4
  br i1 %13, label %true2, label %error

true2:                                            ; preds = %true1
  %14 = icmp eq i32 %1, %5
  br i1 %14, label %true3, label %error

true3:                                            ; preds = %true2
  %15 = icmp eq i32 %1, %6
  br i1 %15, label %true4, label %error

true4:                                            ; preds = %true3
  %16 = icmp eq i32 %1, %7
  br i1 %16, label %true5, label %error

true5:                                            ; preds = %true4
  %17 = icmp eq i32 %1, %8
  br i1 %17, label %true6, label %error

true6:                                            ; preds = %true5
  %18 = icmp eq i32 %1, %9
  br i1 %18, label %true7, label %error

true7:                                            ; preds = %true6
  %19 = icmp eq i32 %1, %10
  br i1 %19, label %true8, label %error

true8:                                            ; preds = %true7
  ret i32 %1

error:                                            ; preds = %true7, %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_2(i8 noundef zeroext %u_val) #0 {
entry:
  %u_val.addr = alloca i8, align 1
  %t = alloca i32, align 4
  %exponent = alloca i32, align 4
  %result = alloca i32, align 4
  store i8 %u_val, ptr %u_val.addr, align 1
  %0 = load i8, ptr %u_val.addr, align 1
  %conv = zext i8 %0 to i32
  %not = xor i32 %conv, -1
  %conv1 = trunc i32 %not to i8
  store i8 %conv1, ptr %u_val.addr, align 1
  %1 = load i8, ptr %u_val.addr, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 15
  %shl = shl i32 %and, 3
  %add = add nsw i32 %shl, 132
  store i32 %add, ptr %t, align 4
  %2 = load i8, ptr %u_val.addr, align 1
  %conv3 = zext i8 %2 to i32
  %and4 = and i32 %conv3, 112
  %shr = ashr i32 %and4, 4
  store i32 %shr, ptr %exponent, align 4
  %3 = load i32, ptr %exponent, align 4
  %4 = load i32, ptr %t, align 4
  %shl5 = shl i32 %4, %3
  store i32 %shl5, ptr %t, align 4
  %5 = load i8, ptr %u_val.addr, align 1
  %conv6 = zext i8 %5 to i32
  %and7 = and i32 %conv6, 128
  %tobool = icmp ne i32 %and7, 0
  br i1 %tobool, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %6 = load i32, ptr %t, align 4
  %sub = sub nsw i32 132, %6
  br label %cond.end

cond.false:                                       ; preds = %entry
  %7 = load i32, ptr %t, align 4
  %sub8 = sub nsw i32 %7, 132
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %sub, %cond.true ], [ %sub8, %cond.false ]
  store i32 %cond, ptr %result, align 4
  %8 = load i32, ptr %result, align 4
  ret i32 %8
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_3(i8 noundef zeroext %u_val) #0 {
entry:
  %u_val.addr = alloca i8, align 1
  %t = alloca i32, align 4
  %quantization_bits = alloca i32, align 4
  %segment_bits = alloca i32, align 4
  store i8 %u_val, ptr %u_val.addr, align 1
  %0 = load i8, ptr %u_val.addr, align 1
  %conv = zext i8 %0 to i32
  %not = xor i32 %conv, -1
  %conv1 = trunc i32 %not to i8
  store i8 %conv1, ptr %u_val.addr, align 1
  %1 = load i8, ptr %u_val.addr, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 15
  %shl = shl i32 %and, 3
  store i32 %shl, ptr %quantization_bits, align 4
  %2 = load i8, ptr %u_val.addr, align 1
  %conv3 = zext i8 %2 to i32
  %and4 = and i32 %conv3, 112
  %shr = ashr i32 %and4, 4
  store i32 %shr, ptr %segment_bits, align 4
  %3 = load i32, ptr %quantization_bits, align 4
  %add = add nsw i32 %3, 132
  %4 = load i32, ptr %segment_bits, align 4
  %shl5 = shl i32 %add, %4
  store i32 %shl5, ptr %t, align 4
  %5 = load i8, ptr %u_val.addr, align 1
  %conv6 = zext i8 %5 to i32
  %and7 = and i32 %conv6, 128
  %tobool = icmp ne i32 %and7, 0
  br i1 %tobool, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %6 = load i32, ptr %t, align 4
  %sub = sub nsw i32 132, %6
  br label %cond.end

cond.false:                                       ; preds = %entry
  %7 = load i32, ptr %t, align 4
  %sub8 = sub nsw i32 %7, 132
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %sub, %cond.true ], [ %sub8, %cond.false ]
  ret i32 %cond
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_4(i8 noundef zeroext %u_val) #0 {
entry:
  %u_val.addr = alloca i8, align 1
  %t = alloca i32, align 4
  %exp = alloca i32, align 4
  store i8 %u_val, ptr %u_val.addr, align 1
  %0 = load i8, ptr %u_val.addr, align 1
  %conv = zext i8 %0 to i32
  %not = xor i32 %conv, -1
  %conv1 = trunc i32 %not to i8
  store i8 %conv1, ptr %u_val.addr, align 1
  %1 = load i8, ptr %u_val.addr, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 15
  %shl = shl i32 %and, 3
  %add = add nsw i32 %shl, 132
  store i32 %add, ptr %t, align 4
  %2 = load i8, ptr %u_val.addr, align 1
  %conv3 = zext i8 %2 to i32
  %and4 = and i32 %conv3, 112
  %shr = ashr i32 %and4, 4
  store i32 %shr, ptr %exp, align 4
  %3 = load i32, ptr %exp, align 4
  %4 = load i32, ptr %t, align 4
  %shl5 = shl i32 %4, %3
  store i32 %shl5, ptr %t, align 4
  %5 = load i8, ptr %u_val.addr, align 1
  %conv6 = zext i8 %5 to i32
  %and7 = and i32 %conv6, 128
  %tobool = icmp ne i32 %and7, 0
  br i1 %tobool, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %6 = load i32, ptr %t, align 4
  %sub = sub nsw i32 132, %6
  br label %cond.end

cond.false:                                       ; preds = %entry
  %7 = load i32, ptr %t, align 4
  %sub8 = sub nsw i32 %7, 132
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %sub, %cond.true ], [ %sub8, %cond.false ]
  ret i32 %cond
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_5(i8 noundef zeroext %u_val) #0 {
entry:
  %retval = alloca i32, align 4
  %u_val.addr = alloca i8, align 1
  %inv_val = alloca i8, align 1
  %t = alloca i32, align 4
  store i8 %u_val, ptr %u_val.addr, align 1
  %0 = load i8, ptr %u_val.addr, align 1
  %conv = zext i8 %0 to i32
  %not = xor i32 %conv, -1
  %conv1 = trunc i32 %not to i8
  store i8 %conv1, ptr %inv_val, align 1
  %1 = load i8, ptr %inv_val, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 15
  %shl = shl i32 %and, 3
  store i32 %shl, ptr %t, align 4
  %2 = load i32, ptr %t, align 4
  %add = add nsw i32 %2, 132
  store i32 %add, ptr %t, align 4
  %3 = load i8, ptr %inv_val, align 1
  %conv3 = zext i8 %3 to i32
  %and4 = and i32 %conv3, 112
  %shr = ashr i32 %and4, 4
  %4 = load i32, ptr %t, align 4
  %shl5 = shl i32 %4, %shr
  store i32 %shl5, ptr %t, align 4
  %5 = load i8, ptr %inv_val, align 1
  %conv6 = zext i8 %5 to i32
  %and7 = and i32 %conv6, 128
  %tobool = icmp ne i32 %and7, 0
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %6 = load i32, ptr %t, align 4
  %sub = sub nsw i32 132, %6
  store i32 %sub, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %7 = load i32, ptr %t, align 4
  %sub8 = sub nsw i32 %7, 132
  store i32 %sub8, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end, %if.then
  %8 = load i32, ptr %retval, align 4
  ret i32 %8
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_6(i8 noundef zeroext %u_val) #0 {
entry:
  %retval = alloca i32, align 4
  %u_val.addr = alloca i8, align 1
  %t = alloca i32, align 4
  store i8 %u_val, ptr %u_val.addr, align 1
  %0 = load i8, ptr %u_val.addr, align 1
  %conv = zext i8 %0 to i32
  %not = xor i32 %conv, -1
  %conv1 = trunc i32 %not to i8
  store i8 %conv1, ptr %u_val.addr, align 1
  %1 = load i8, ptr %u_val.addr, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 15
  %shl = shl i32 %and, 3
  store i32 %shl, ptr %t, align 4
  %2 = load i32, ptr %t, align 4
  %add = add nsw i32 %2, 132
  store i32 %add, ptr %t, align 4
  %3 = load i8, ptr %u_val.addr, align 1
  %conv3 = zext i8 %3 to i32
  %and4 = and i32 %conv3, 112
  %shr = ashr i32 %and4, 4
  %4 = load i32, ptr %t, align 4
  %shl5 = shl i32 %4, %shr
  store i32 %shl5, ptr %t, align 4
  %5 = load i8, ptr %u_val.addr, align 1
  %conv6 = zext i8 %5 to i32
  %and7 = and i32 %conv6, 128
  %tobool = icmp ne i32 %and7, 0
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %6 = load i32, ptr %t, align 4
  %sub = sub nsw i32 132, %6
  store i32 %sub, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %7 = load i32, ptr %t, align 4
  %sub8 = sub nsw i32 %7, 132
  store i32 %sub8, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end, %if.then
  %8 = load i32, ptr %retval, align 4
  ret i32 %8
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_7(i8 noundef zeroext %u_val) #0 {
entry:
  %u_val.addr = alloca i8, align 1
  %shift = alloca i32, align 4
  %base = alloca i32, align 4
  store i8 %u_val, ptr %u_val.addr, align 1
  %0 = load i8, ptr %u_val.addr, align 1
  %conv = zext i8 %0 to i32
  %not = xor i32 %conv, -1
  %conv1 = trunc i32 %not to i8
  store i8 %conv1, ptr %u_val.addr, align 1
  %1 = load i8, ptr %u_val.addr, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 112
  %shr = ashr i32 %and, 4
  store i32 %shr, ptr %shift, align 4
  %2 = load i8, ptr %u_val.addr, align 1
  %conv3 = zext i8 %2 to i32
  %and4 = and i32 %conv3, 15
  %shl = shl i32 %and4, 3
  %add = add nsw i32 %shl, 132
  store i32 %add, ptr %base, align 4
  %3 = load i32, ptr %shift, align 4
  %4 = load i32, ptr %base, align 4
  %shl5 = shl i32 %4, %3
  store i32 %shl5, ptr %base, align 4
  %5 = load i8, ptr %u_val.addr, align 1
  %conv6 = zext i8 %5 to i32
  %and7 = and i32 %conv6, 128
  %tobool = icmp ne i32 %and7, 0
  br i1 %tobool, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %6 = load i32, ptr %base, align 4
  %sub = sub nsw i32 132, %6
  br label %cond.end

cond.false:                                       ; preds = %entry
  %7 = load i32, ptr %base, align 4
  %sub8 = sub nsw i32 %7, 132
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %sub, %cond.true ], [ %sub8, %cond.false ]
  ret i32 %cond
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_8(i8 noundef zeroext %u_val) #0 {
entry:
  %u_val.addr = alloca i8, align 1
  %t = alloca i32, align 4
  %mantissa = alloca i32, align 4
  %exponent = alloca i32, align 4
  store i8 %u_val, ptr %u_val.addr, align 1
  %0 = load i8, ptr %u_val.addr, align 1
  %conv = zext i8 %0 to i32
  %not = xor i32 %conv, -1
  %conv1 = trunc i32 %not to i8
  store i8 %conv1, ptr %u_val.addr, align 1
  %1 = load i8, ptr %u_val.addr, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 15
  %shl = shl i32 %and, 3
  store i32 %shl, ptr %mantissa, align 4
  %2 = load i32, ptr %mantissa, align 4
  %add = add nsw i32 %2, 132
  store i32 %add, ptr %mantissa, align 4
  %3 = load i8, ptr %u_val.addr, align 1
  %conv3 = zext i8 %3 to i32
  %and4 = and i32 %conv3, 112
  %shr = ashr i32 %and4, 4
  store i32 %shr, ptr %exponent, align 4
  %4 = load i32, ptr %mantissa, align 4
  %5 = load i32, ptr %exponent, align 4
  %shl5 = shl i32 %4, %5
  store i32 %shl5, ptr %t, align 4
  %6 = load i8, ptr %u_val.addr, align 1
  %conv6 = zext i8 %6 to i32
  %and7 = and i32 %conv6, 128
  %tobool = icmp ne i32 %and7, 0
  br i1 %tobool, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %7 = load i32, ptr %t, align 4
  %sub = sub nsw i32 132, %7
  br label %cond.end

cond.false:                                       ; preds = %entry
  %8 = load i32, ptr %t, align 4
  %sub8 = sub nsw i32 %8, 132
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %sub, %cond.true ], [ %sub8, %cond.false ]
  ret i32 %cond
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_9(i8 noundef zeroext %u_val) #0 {
entry:
  %u_val.addr = alloca i8, align 1
  %temp = alloca i32, align 4
  %result = alloca i32, align 4
  store i8 %u_val, ptr %u_val.addr, align 1
  %0 = load i8, ptr %u_val.addr, align 1
  %conv = zext i8 %0 to i32
  %not = xor i32 %conv, -1
  %conv1 = trunc i32 %not to i8
  store i8 %conv1, ptr %u_val.addr, align 1
  %1 = load i8, ptr %u_val.addr, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 15
  %shl = shl i32 %and, 3
  %add = add nsw i32 %shl, 132
  store i32 %add, ptr %temp, align 4
  %2 = load i8, ptr %u_val.addr, align 1
  %conv3 = zext i8 %2 to i32
  %and4 = and i32 %conv3, 112
  %shr = ashr i32 %and4, 4
  %3 = load i32, ptr %temp, align 4
  %shl5 = shl i32 %3, %shr
  store i32 %shl5, ptr %temp, align 4
  %4 = load i8, ptr %u_val.addr, align 1
  %conv6 = zext i8 %4 to i32
  %and7 = and i32 %conv6, 128
  %tobool = icmp ne i32 %and7, 0
  br i1 %tobool, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %5 = load i32, ptr %temp, align 4
  %sub = sub nsw i32 132, %5
  br label %cond.end

cond.false:                                       ; preds = %entry
  %6 = load i32, ptr %temp, align 4
  %sub8 = sub nsw i32 %6, 132
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %sub, %cond.true ], [ %sub8, %cond.false ]
  store i32 %cond, ptr %result, align 4
  %7 = load i32, ptr %result, align 4
  ret i32 %7
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_10(i8 noundef zeroext %u_val) #0 {
entry:
  %u_val.addr = alloca i8, align 1
  %t = alloca i32, align 4
  %q_bits = alloca i32, align 4
  %s_bits = alloca i32, align 4
  store i8 %u_val, ptr %u_val.addr, align 1
  %0 = load i8, ptr %u_val.addr, align 1
  %conv = zext i8 %0 to i32
  %not = xor i32 %conv, -1
  %conv1 = trunc i32 %not to i8
  store i8 %conv1, ptr %u_val.addr, align 1
  %1 = load i8, ptr %u_val.addr, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 15
  %shl = shl i32 %and, 3
  store i32 %shl, ptr %q_bits, align 4
  %2 = load i8, ptr %u_val.addr, align 1
  %conv3 = zext i8 %2 to i32
  %and4 = and i32 %conv3, 112
  %shr = ashr i32 %and4, 4
  store i32 %shr, ptr %s_bits, align 4
  %3 = load i32, ptr %q_bits, align 4
  %add = add nsw i32 %3, 132
  %4 = load i32, ptr %s_bits, align 4
  %shl5 = shl i32 %add, %4
  store i32 %shl5, ptr %t, align 4
  %5 = load i8, ptr %u_val.addr, align 1
  %conv6 = zext i8 %5 to i32
  %and7 = and i32 %conv6, 128
  %tobool = icmp ne i32 %and7, 0
  br i1 %tobool, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %6 = load i32, ptr %t, align 4
  %sub = sub nsw i32 132, %6
  br label %cond.end

cond.false:                                       ; preds = %entry
  %7 = load i32, ptr %t, align 4
  %sub8 = sub nsw i32 %7, 132
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %sub, %cond.true ], [ %sub8, %cond.false ]
  ret i32 %cond
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_1(i8 noundef zeroext %u_val) #0 {
entry:
  %u_val.addr = alloca i8, align 1
  %t = alloca i32, align 4
  store i8 %u_val, ptr %u_val.addr, align 1
  %0 = load i8, ptr %u_val.addr, align 1
  %conv = zext i8 %0 to i32
  %not = xor i32 %conv, -1
  %conv1 = trunc i32 %not to i8
  store i8 %conv1, ptr %u_val.addr, align 1
  %1 = load i8, ptr %u_val.addr, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 15
  %shl = shl i32 %and, 3
  %add = add nsw i32 %shl, 132
  store i32 %add, ptr %t, align 4
  %2 = load i8, ptr %u_val.addr, align 1
  %conv3 = zext i8 %2 to i32
  %and4 = and i32 %conv3, 112
  %shr = ashr i32 %and4, 4
  %3 = load i32, ptr %t, align 4
  %shl5 = shl i32 %3, %shr
  store i32 %shl5, ptr %t, align 4
  %4 = load i8, ptr %u_val.addr, align 1
  %conv6 = zext i8 %4 to i32
  %and7 = and i32 %conv6, 128
  %tobool = icmp ne i32 %and7, 0
  br i1 %tobool, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %5 = load i32, ptr %t, align 4
  %sub = sub nsw i32 132, %5
  br label %cond.end

cond.false:                                       ; preds = %entry
  %6 = load i32, ptr %t, align 4
  %sub8 = sub nsw i32 %6, 132
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %sub, %cond.true ], [ %sub8, %cond.false ]
  ret i32 %cond
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
