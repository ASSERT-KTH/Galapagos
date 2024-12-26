; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/3_weight.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/3_weight.run.c"
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
  %call1 = call i32 @n_version_call(i32 noundef 0, i32 noundef 0, i32 noundef 0)
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
define internal i32 @n_version_call(i32 noundef %0, i32 noundef %1, i32 noundef %2) #0 {
entry:
  %3 = call i32 @version_1(i32 %0, i32 %1, i32 %2)
  %4 = call i32 @version_2(i32 %0, i32 %1, i32 %2)
  %5 = call i32 @version_3(i32 %0, i32 %1, i32 %2)
  %6 = call i32 @version_4(i32 %0, i32 %1, i32 %2)
  %7 = call i32 @version_5(i32 %0, i32 %1, i32 %2)
  %8 = call i32 @version_6(i32 %0, i32 %1, i32 %2)
  %9 = call i32 @version_7(i32 %0, i32 %1, i32 %2)
  %10 = call i32 @version_8(i32 %0, i32 %1, i32 %2)
  %11 = call i32 @version_9(i32 %0, i32 %1, i32 %2)
  %12 = call i32 @version_10(i32 %0, i32 %1, i32 %2)
  %13 = call i32 @version_11(i32 %0, i32 %1, i32 %2)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %14 = icmp eq i32 %3, %4
  br i1 %14, label %true, label %error

true:                                             ; preds = %comparisons
  %15 = icmp eq i32 %3, %5
  br i1 %15, label %true1, label %error

true1:                                            ; preds = %true
  %16 = icmp eq i32 %3, %6
  br i1 %16, label %true2, label %error

true2:                                            ; preds = %true1
  %17 = icmp eq i32 %3, %7
  br i1 %17, label %true3, label %error

true3:                                            ; preds = %true2
  %18 = icmp eq i32 %3, %8
  br i1 %18, label %true4, label %error

true4:                                            ; preds = %true3
  %19 = icmp eq i32 %3, %9
  br i1 %19, label %true5, label %error

true5:                                            ; preds = %true4
  %20 = icmp eq i32 %3, %10
  br i1 %20, label %true6, label %error

true6:                                            ; preds = %true5
  %21 = icmp eq i32 %3, %11
  br i1 %21, label %true7, label %error

true7:                                            ; preds = %true6
  %22 = icmp eq i32 %3, %12
  br i1 %22, label %true8, label %error

true8:                                            ; preds = %true7
  %23 = icmp eq i32 %3, %13
  br i1 %23, label %true9, label %error

true9:                                            ; preds = %true8
  ret i32 %3

error:                                            ; preds = %true8, %true7, %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_2(i32 noundef %i, i32 noundef %blen, i32 noundef %offset) #0 {
entry:
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  %ret = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  store i32 8, ptr %ret, align 4
  %0 = load i32, ptr %i.addr, align 4
  %1 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %1
  %cmp = icmp slt i32 %0, %mul
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %offset.addr, align 4
  %cmp1 = icmp eq i32 %2, 1
  br i1 %cmp1, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %tobool = icmp ne i32 %3, 0
  %4 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 5, i32 3
  br label %cond.end

cond.false:                                       ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %mul2 = mul nsw i32 6, %5
  %6 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul2, %6
  %sub = sub nsw i32 %add, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul3 = mul nsw i32 2, %7
  %sub4 = sub nsw i32 %mul3, 1
  %div = sdiv i32 %sub, %sub4
  %add5 = add nsw i32 1, %div
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond6 = phi i32 [ %cond, %cond.true ], [ %add5, %cond.false ]
  store i32 %cond6, ptr %ret, align 4
  br label %if.end30

if.else:                                          ; preds = %entry
  %8 = load i32, ptr %i.addr, align 4
  %9 = load i32, ptr %blen.addr, align 4
  %sub7 = sub nsw i32 %9, 1
  %10 = load i32, ptr %offset.addr, align 4
  %mul8 = mul nsw i32 2, %10
  %sub9 = sub nsw i32 %sub7, %mul8
  %cmp10 = icmp sgt i32 %8, %sub9
  br i1 %cmp10, label %if.then11, label %if.end

if.then11:                                        ; preds = %if.else
  %11 = load i32, ptr %offset.addr, align 4
  %cmp12 = icmp eq i32 %11, 1
  br i1 %cmp12, label %cond.true13, label %cond.false18

cond.true13:                                      ; preds = %if.then11
  %12 = load i32, ptr %blen.addr, align 4
  %sub14 = sub nsw i32 %12, 1
  %13 = load i32, ptr %i.addr, align 4
  %sub15 = sub nsw i32 %sub14, %13
  %tobool16 = icmp ne i32 %sub15, 0
  %14 = zext i1 %tobool16 to i64
  %cond17 = select i1 %tobool16, i32 5, i32 3
  br label %cond.end28

cond.false18:                                     ; preds = %if.then11
  %15 = load i32, ptr %blen.addr, align 4
  %sub19 = sub nsw i32 %15, 1
  %16 = load i32, ptr %i.addr, align 4
  %sub20 = sub nsw i32 %sub19, %16
  %mul21 = mul nsw i32 6, %sub20
  %17 = load i32, ptr %offset.addr, align 4
  %add22 = add nsw i32 %mul21, %17
  %sub23 = sub nsw i32 %add22, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul24 = mul nsw i32 2, %18
  %sub25 = sub nsw i32 %mul24, 1
  %div26 = sdiv i32 %sub23, %sub25
  %add27 = add nsw i32 1, %div26
  br label %cond.end28

cond.end28:                                       ; preds = %cond.false18, %cond.true13
  %cond29 = phi i32 [ %cond17, %cond.true13 ], [ %add27, %cond.false18 ]
  store i32 %cond29, ptr %ret, align 4
  br label %if.end

if.end:                                           ; preds = %cond.end28, %if.else
  br label %if.end30

if.end30:                                         ; preds = %if.end, %cond.end
  %19 = load i32, ptr %ret, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_3(i32 noundef %i, i32 noundef %blen, i32 noundef %offset) #0 {
entry:
  %retval = alloca i32, align 4
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  %0 = load i32, ptr %offset.addr, align 4
  %cmp = icmp eq i32 %0, 1
  br i1 %cmp, label %if.then, label %if.else13

if.then:                                          ; preds = %entry
  %1 = load i32, ptr %i.addr, align 4
  %2 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %2
  %cmp1 = icmp slt i32 %1, %mul
  br i1 %cmp1, label %if.then2, label %if.else

if.then2:                                         ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %cmp3 = icmp ne i32 %3, 0
  %4 = zext i1 %cmp3 to i64
  %cond = select i1 %cmp3, i32 5, i32 3
  store i32 %cond, ptr %retval, align 4
  br label %return

if.else:                                          ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %6 = load i32, ptr %blen.addr, align 4
  %sub = sub nsw i32 %6, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul4 = mul nsw i32 2, %7
  %sub5 = sub nsw i32 %sub, %mul4
  %cmp6 = icmp sgt i32 %5, %sub5
  br i1 %cmp6, label %if.then7, label %if.else12

if.then7:                                         ; preds = %if.else
  %8 = load i32, ptr %blen.addr, align 4
  %sub8 = sub nsw i32 %8, 1
  %9 = load i32, ptr %i.addr, align 4
  %sub9 = sub nsw i32 %sub8, %9
  %cmp10 = icmp ne i32 %sub9, 0
  %10 = zext i1 %cmp10 to i64
  %cond11 = select i1 %cmp10, i32 5, i32 3
  store i32 %cond11, ptr %retval, align 4
  br label %return

if.else12:                                        ; preds = %if.else
  store i32 8, ptr %retval, align 4
  br label %return

if.else13:                                        ; preds = %entry
  %11 = load i32, ptr %i.addr, align 4
  %12 = load i32, ptr %offset.addr, align 4
  %mul14 = mul nsw i32 2, %12
  %cmp15 = icmp slt i32 %11, %mul14
  br i1 %cmp15, label %if.then16, label %if.else22

if.then16:                                        ; preds = %if.else13
  %13 = load i32, ptr %i.addr, align 4
  %mul17 = mul nsw i32 6, %13
  %14 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul17, %14
  %sub18 = sub nsw i32 %add, 1
  %15 = load i32, ptr %offset.addr, align 4
  %mul19 = mul nsw i32 2, %15
  %sub20 = sub nsw i32 %mul19, 1
  %div = sdiv i32 %sub18, %sub20
  %add21 = add nsw i32 1, %div
  store i32 %add21, ptr %retval, align 4
  br label %return

if.else22:                                        ; preds = %if.else13
  %16 = load i32, ptr %i.addr, align 4
  %17 = load i32, ptr %blen.addr, align 4
  %sub23 = sub nsw i32 %17, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul24 = mul nsw i32 2, %18
  %sub25 = sub nsw i32 %sub23, %mul24
  %cmp26 = icmp sgt i32 %16, %sub25
  br i1 %cmp26, label %if.then27, label %if.else37

if.then27:                                        ; preds = %if.else22
  %19 = load i32, ptr %blen.addr, align 4
  %sub28 = sub nsw i32 %19, 1
  %20 = load i32, ptr %i.addr, align 4
  %sub29 = sub nsw i32 %sub28, %20
  %mul30 = mul nsw i32 6, %sub29
  %21 = load i32, ptr %offset.addr, align 4
  %add31 = add nsw i32 %mul30, %21
  %sub32 = sub nsw i32 %add31, 1
  %22 = load i32, ptr %offset.addr, align 4
  %mul33 = mul nsw i32 2, %22
  %sub34 = sub nsw i32 %mul33, 1
  %div35 = sdiv i32 %sub32, %sub34
  %add36 = add nsw i32 1, %div35
  store i32 %add36, ptr %retval, align 4
  br label %return

if.else37:                                        ; preds = %if.else22
  store i32 8, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.else37, %if.then27, %if.then16, %if.else12, %if.then7, %if.then2
  %23 = load i32, ptr %retval, align 4
  ret i32 %23
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_4(i32 noundef %i, i32 noundef %blen, i32 noundef %offset) #0 {
entry:
  %retval = alloca i32, align 4
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  %0 = load i32, ptr %i.addr, align 4
  %1 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %1
  %cmp = icmp slt i32 %0, %mul
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %offset.addr, align 4
  %cmp1 = icmp eq i32 %2, 1
  br i1 %cmp1, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %tobool = icmp ne i32 %3, 0
  %4 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 5, i32 3
  br label %cond.end

cond.false:                                       ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %mul2 = mul nsw i32 6, %5
  %6 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul2, %6
  %sub = sub nsw i32 %add, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul3 = mul nsw i32 2, %7
  %sub4 = sub nsw i32 %mul3, 1
  %div = sdiv i32 %sub, %sub4
  %add5 = add nsw i32 1, %div
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond6 = phi i32 [ %cond, %cond.true ], [ %add5, %cond.false ]
  store i32 %cond6, ptr %retval, align 4
  br label %return

if.else:                                          ; preds = %entry
  %8 = load i32, ptr %i.addr, align 4
  %9 = load i32, ptr %blen.addr, align 4
  %sub7 = sub nsw i32 %9, 1
  %10 = load i32, ptr %offset.addr, align 4
  %mul8 = mul nsw i32 2, %10
  %sub9 = sub nsw i32 %sub7, %mul8
  %cmp10 = icmp sgt i32 %8, %sub9
  br i1 %cmp10, label %if.then11, label %if.end

if.then11:                                        ; preds = %if.else
  %11 = load i32, ptr %offset.addr, align 4
  %cmp12 = icmp eq i32 %11, 1
  br i1 %cmp12, label %cond.true13, label %cond.false18

cond.true13:                                      ; preds = %if.then11
  %12 = load i32, ptr %blen.addr, align 4
  %sub14 = sub nsw i32 %12, 1
  %13 = load i32, ptr %i.addr, align 4
  %sub15 = sub nsw i32 %sub14, %13
  %tobool16 = icmp ne i32 %sub15, 0
  %14 = zext i1 %tobool16 to i64
  %cond17 = select i1 %tobool16, i32 5, i32 3
  br label %cond.end28

cond.false18:                                     ; preds = %if.then11
  %15 = load i32, ptr %blen.addr, align 4
  %sub19 = sub nsw i32 %15, 1
  %16 = load i32, ptr %i.addr, align 4
  %sub20 = sub nsw i32 %sub19, %16
  %mul21 = mul nsw i32 6, %sub20
  %17 = load i32, ptr %offset.addr, align 4
  %add22 = add nsw i32 %mul21, %17
  %sub23 = sub nsw i32 %add22, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul24 = mul nsw i32 2, %18
  %sub25 = sub nsw i32 %mul24, 1
  %div26 = sdiv i32 %sub23, %sub25
  %add27 = add nsw i32 1, %div26
  br label %cond.end28

cond.end28:                                       ; preds = %cond.false18, %cond.true13
  %cond29 = phi i32 [ %cond17, %cond.true13 ], [ %add27, %cond.false18 ]
  store i32 %cond29, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %if.else
  br label %if.end30

if.end30:                                         ; preds = %if.end
  store i32 8, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end30, %cond.end28, %cond.end
  %19 = load i32, ptr %retval, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_5(i32 noundef %i, i32 noundef %blen, i32 noundef %offset) #0 {
entry:
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  %result = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  %0 = load i32, ptr %i.addr, align 4
  %1 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %1
  %cmp = icmp slt i32 %0, %mul
  br i1 %cmp, label %if.then, label %if.else8

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %offset.addr, align 4
  %cmp1 = icmp eq i32 %2, 1
  br i1 %cmp1, label %if.then2, label %if.else

if.then2:                                         ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %cmp3 = icmp ne i32 %3, 0
  %4 = zext i1 %cmp3 to i64
  %cond = select i1 %cmp3, i32 5, i32 3
  store i32 %cond, ptr %result, align 4
  br label %if.end

if.else:                                          ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %mul4 = mul nsw i32 6, %5
  %6 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul4, %6
  %sub = sub nsw i32 %add, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul5 = mul nsw i32 2, %7
  %sub6 = sub nsw i32 %mul5, 1
  %div = sdiv i32 %sub, %sub6
  %add7 = add nsw i32 1, %div
  store i32 %add7, ptr %result, align 4
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then2
  br label %if.end33

if.else8:                                         ; preds = %entry
  %8 = load i32, ptr %i.addr, align 4
  %9 = load i32, ptr %blen.addr, align 4
  %sub9 = sub nsw i32 %9, 1
  %10 = load i32, ptr %offset.addr, align 4
  %mul10 = mul nsw i32 2, %10
  %sub11 = sub nsw i32 %sub9, %mul10
  %cmp12 = icmp sgt i32 %8, %sub11
  br i1 %cmp12, label %if.then13, label %if.else31

if.then13:                                        ; preds = %if.else8
  %11 = load i32, ptr %offset.addr, align 4
  %cmp14 = icmp eq i32 %11, 1
  br i1 %cmp14, label %if.then15, label %if.else20

if.then15:                                        ; preds = %if.then13
  %12 = load i32, ptr %blen.addr, align 4
  %sub16 = sub nsw i32 %12, 1
  %13 = load i32, ptr %i.addr, align 4
  %sub17 = sub nsw i32 %sub16, %13
  %cmp18 = icmp ne i32 %sub17, 0
  %14 = zext i1 %cmp18 to i64
  %cond19 = select i1 %cmp18, i32 5, i32 3
  store i32 %cond19, ptr %result, align 4
  br label %if.end30

if.else20:                                        ; preds = %if.then13
  %15 = load i32, ptr %blen.addr, align 4
  %sub21 = sub nsw i32 %15, 1
  %16 = load i32, ptr %i.addr, align 4
  %sub22 = sub nsw i32 %sub21, %16
  %mul23 = mul nsw i32 6, %sub22
  %17 = load i32, ptr %offset.addr, align 4
  %add24 = add nsw i32 %mul23, %17
  %sub25 = sub nsw i32 %add24, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul26 = mul nsw i32 2, %18
  %sub27 = sub nsw i32 %mul26, 1
  %div28 = sdiv i32 %sub25, %sub27
  %add29 = add nsw i32 1, %div28
  store i32 %add29, ptr %result, align 4
  br label %if.end30

if.end30:                                         ; preds = %if.else20, %if.then15
  br label %if.end32

if.else31:                                        ; preds = %if.else8
  store i32 8, ptr %result, align 4
  br label %if.end32

if.end32:                                         ; preds = %if.else31, %if.end30
  br label %if.end33

if.end33:                                         ; preds = %if.end32, %if.end
  %19 = load i32, ptr %result, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_6(i32 noundef %i, i32 noundef %blen, i32 noundef %offset) #0 {
entry:
  %retval = alloca i32, align 4
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  %0 = load i32, ptr %i.addr, align 4
  %1 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %1
  %cmp = icmp slt i32 %0, %mul
  br i1 %cmp, label %if.then, label %if.else7

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %offset.addr, align 4
  %cmp1 = icmp eq i32 %2, 1
  br i1 %cmp1, label %if.then2, label %if.else

if.then2:                                         ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %tobool = icmp ne i32 %3, 0
  %4 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 5, i32 3
  store i32 %cond, ptr %retval, align 4
  br label %return

if.else:                                          ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %mul3 = mul nsw i32 6, %5
  %6 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul3, %6
  %sub = sub nsw i32 %add, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul4 = mul nsw i32 2, %7
  %sub5 = sub nsw i32 %mul4, 1
  %div = sdiv i32 %sub, %sub5
  %add6 = add nsw i32 1, %div
  store i32 %add6, ptr %retval, align 4
  br label %return

if.else7:                                         ; preds = %entry
  %8 = load i32, ptr %i.addr, align 4
  %9 = load i32, ptr %blen.addr, align 4
  %sub8 = sub nsw i32 %9, 1
  %10 = load i32, ptr %offset.addr, align 4
  %mul9 = mul nsw i32 2, %10
  %sub10 = sub nsw i32 %sub8, %mul9
  %cmp11 = icmp sgt i32 %8, %sub10
  br i1 %cmp11, label %if.then12, label %if.end

if.then12:                                        ; preds = %if.else7
  %11 = load i32, ptr %offset.addr, align 4
  %cmp13 = icmp eq i32 %11, 1
  br i1 %cmp13, label %if.then14, label %if.else19

if.then14:                                        ; preds = %if.then12
  %12 = load i32, ptr %blen.addr, align 4
  %sub15 = sub nsw i32 %12, 1
  %13 = load i32, ptr %i.addr, align 4
  %sub16 = sub nsw i32 %sub15, %13
  %tobool17 = icmp ne i32 %sub16, 0
  %14 = zext i1 %tobool17 to i64
  %cond18 = select i1 %tobool17, i32 5, i32 3
  store i32 %cond18, ptr %retval, align 4
  br label %return

if.else19:                                        ; preds = %if.then12
  %15 = load i32, ptr %blen.addr, align 4
  %sub20 = sub nsw i32 %15, 1
  %16 = load i32, ptr %i.addr, align 4
  %sub21 = sub nsw i32 %sub20, %16
  %mul22 = mul nsw i32 6, %sub21
  %17 = load i32, ptr %offset.addr, align 4
  %add23 = add nsw i32 %mul22, %17
  %sub24 = sub nsw i32 %add23, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul25 = mul nsw i32 2, %18
  %sub26 = sub nsw i32 %mul25, 1
  %div27 = sdiv i32 %sub24, %sub26
  %add28 = add nsw i32 1, %div27
  store i32 %add28, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %if.else7
  br label %if.end29

if.end29:                                         ; preds = %if.end
  store i32 8, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end29, %if.else19, %if.then14, %if.else, %if.then2
  %19 = load i32, ptr %retval, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_7(i32 noundef %i, i32 noundef %blen, i32 noundef %offset) #0 {
entry:
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  %result = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  %0 = load i32, ptr %i.addr, align 4
  %1 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %1
  %cmp = icmp slt i32 %0, %mul
  br i1 %cmp, label %if.then, label %if.else7

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %offset.addr, align 4
  %cmp1 = icmp eq i32 %2, 1
  br i1 %cmp1, label %if.then2, label %if.else

if.then2:                                         ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %tobool = icmp ne i32 %3, 0
  %4 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 5, i32 3
  store i32 %cond, ptr %result, align 4
  br label %if.end

if.else:                                          ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %mul3 = mul nsw i32 6, %5
  %6 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul3, %6
  %sub = sub nsw i32 %add, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul4 = mul nsw i32 2, %7
  %sub5 = sub nsw i32 %mul4, 1
  %div = sdiv i32 %sub, %sub5
  %add6 = add nsw i32 1, %div
  store i32 %add6, ptr %result, align 4
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then2
  br label %if.end32

if.else7:                                         ; preds = %entry
  %8 = load i32, ptr %i.addr, align 4
  %9 = load i32, ptr %blen.addr, align 4
  %sub8 = sub nsw i32 %9, 1
  %10 = load i32, ptr %offset.addr, align 4
  %mul9 = mul nsw i32 2, %10
  %sub10 = sub nsw i32 %sub8, %mul9
  %cmp11 = icmp sgt i32 %8, %sub10
  br i1 %cmp11, label %if.then12, label %if.else30

if.then12:                                        ; preds = %if.else7
  %11 = load i32, ptr %offset.addr, align 4
  %cmp13 = icmp eq i32 %11, 1
  br i1 %cmp13, label %if.then14, label %if.else19

if.then14:                                        ; preds = %if.then12
  %12 = load i32, ptr %blen.addr, align 4
  %sub15 = sub nsw i32 %12, 1
  %13 = load i32, ptr %i.addr, align 4
  %sub16 = sub nsw i32 %sub15, %13
  %tobool17 = icmp ne i32 %sub16, 0
  %14 = zext i1 %tobool17 to i64
  %cond18 = select i1 %tobool17, i32 5, i32 3
  store i32 %cond18, ptr %result, align 4
  br label %if.end29

if.else19:                                        ; preds = %if.then12
  %15 = load i32, ptr %blen.addr, align 4
  %sub20 = sub nsw i32 %15, 1
  %16 = load i32, ptr %i.addr, align 4
  %sub21 = sub nsw i32 %sub20, %16
  %mul22 = mul nsw i32 6, %sub21
  %17 = load i32, ptr %offset.addr, align 4
  %add23 = add nsw i32 %mul22, %17
  %sub24 = sub nsw i32 %add23, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul25 = mul nsw i32 2, %18
  %sub26 = sub nsw i32 %mul25, 1
  %div27 = sdiv i32 %sub24, %sub26
  %add28 = add nsw i32 1, %div27
  store i32 %add28, ptr %result, align 4
  br label %if.end29

if.end29:                                         ; preds = %if.else19, %if.then14
  br label %if.end31

if.else30:                                        ; preds = %if.else7
  store i32 8, ptr %result, align 4
  br label %if.end31

if.end31:                                         ; preds = %if.else30, %if.end29
  br label %if.end32

if.end32:                                         ; preds = %if.end31, %if.end
  %19 = load i32, ptr %result, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_8(i32 noundef %i, i32 noundef %blen, i32 noundef %offset) #0 {
entry:
  %retval = alloca i32, align 4
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  %0 = load i32, ptr %i.addr, align 4
  %1 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %1
  %cmp = icmp slt i32 %0, %mul
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %offset.addr, align 4
  %cmp1 = icmp eq i32 %2, 1
  br i1 %cmp1, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %tobool = icmp ne i32 %3, 0
  %4 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 5, i32 3
  br label %cond.end

cond.false:                                       ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %mul2 = mul nsw i32 6, %5
  %6 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul2, %6
  %sub = sub nsw i32 %add, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul3 = mul nsw i32 2, %7
  %sub4 = sub nsw i32 %mul3, 1
  %div = sdiv i32 %sub, %sub4
  %add5 = add nsw i32 1, %div
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond6 = phi i32 [ %cond, %cond.true ], [ %add5, %cond.false ]
  store i32 %cond6, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %8 = load i32, ptr %i.addr, align 4
  %9 = load i32, ptr %blen.addr, align 4
  %sub7 = sub nsw i32 %9, 1
  %10 = load i32, ptr %offset.addr, align 4
  %mul8 = mul nsw i32 2, %10
  %sub9 = sub nsw i32 %sub7, %mul8
  %cmp10 = icmp sgt i32 %8, %sub9
  br i1 %cmp10, label %if.then11, label %if.end30

if.then11:                                        ; preds = %if.end
  %11 = load i32, ptr %offset.addr, align 4
  %cmp12 = icmp eq i32 %11, 1
  br i1 %cmp12, label %cond.true13, label %cond.false18

cond.true13:                                      ; preds = %if.then11
  %12 = load i32, ptr %blen.addr, align 4
  %sub14 = sub nsw i32 %12, 1
  %13 = load i32, ptr %i.addr, align 4
  %sub15 = sub nsw i32 %sub14, %13
  %tobool16 = icmp ne i32 %sub15, 0
  %14 = zext i1 %tobool16 to i64
  %cond17 = select i1 %tobool16, i32 5, i32 3
  br label %cond.end28

cond.false18:                                     ; preds = %if.then11
  %15 = load i32, ptr %blen.addr, align 4
  %sub19 = sub nsw i32 %15, 1
  %16 = load i32, ptr %i.addr, align 4
  %sub20 = sub nsw i32 %sub19, %16
  %mul21 = mul nsw i32 6, %sub20
  %17 = load i32, ptr %offset.addr, align 4
  %add22 = add nsw i32 %mul21, %17
  %sub23 = sub nsw i32 %add22, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul24 = mul nsw i32 2, %18
  %sub25 = sub nsw i32 %mul24, 1
  %div26 = sdiv i32 %sub23, %sub25
  %add27 = add nsw i32 1, %div26
  br label %cond.end28

cond.end28:                                       ; preds = %cond.false18, %cond.true13
  %cond29 = phi i32 [ %cond17, %cond.true13 ], [ %add27, %cond.false18 ]
  store i32 %cond29, ptr %retval, align 4
  br label %return

if.end30:                                         ; preds = %if.end
  store i32 8, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end30, %cond.end28, %cond.end
  %19 = load i32, ptr %retval, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_9(i32 noundef %i, i32 noundef %blen, i32 noundef %offset) #0 {
entry:
  %retval = alloca i32, align 4
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  %0 = load i32, ptr %offset.addr, align 4
  %cmp = icmp eq i32 %0, 1
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %1 = load i32, ptr %i.addr, align 4
  %2 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %2
  %cmp1 = icmp slt i32 %1, %mul
  br i1 %cmp1, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %tobool = icmp ne i32 %3, 0
  %4 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 5, i32 3
  br label %cond.end12

cond.false:                                       ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %6 = load i32, ptr %blen.addr, align 4
  %sub = sub nsw i32 %6, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul2 = mul nsw i32 2, %7
  %sub3 = sub nsw i32 %sub, %mul2
  %cmp4 = icmp sgt i32 %5, %sub3
  br i1 %cmp4, label %cond.true5, label %cond.false10

cond.true5:                                       ; preds = %cond.false
  %8 = load i32, ptr %blen.addr, align 4
  %sub6 = sub nsw i32 %8, 1
  %9 = load i32, ptr %i.addr, align 4
  %sub7 = sub nsw i32 %sub6, %9
  %tobool8 = icmp ne i32 %sub7, 0
  %10 = zext i1 %tobool8 to i64
  %cond9 = select i1 %tobool8, i32 5, i32 3
  br label %cond.end

cond.false10:                                     ; preds = %cond.false
  br label %cond.end

cond.end:                                         ; preds = %cond.false10, %cond.true5
  %cond11 = phi i32 [ %cond9, %cond.true5 ], [ 8, %cond.false10 ]
  br label %cond.end12

cond.end12:                                       ; preds = %cond.end, %cond.true
  %cond13 = phi i32 [ %cond, %cond.true ], [ %cond11, %cond.end ]
  store i32 %cond13, ptr %retval, align 4
  br label %return

if.else:                                          ; preds = %entry
  %11 = load i32, ptr %i.addr, align 4
  %12 = load i32, ptr %offset.addr, align 4
  %mul14 = mul nsw i32 2, %12
  %cmp15 = icmp slt i32 %11, %mul14
  br i1 %cmp15, label %cond.true16, label %cond.false22

cond.true16:                                      ; preds = %if.else
  %13 = load i32, ptr %i.addr, align 4
  %mul17 = mul nsw i32 6, %13
  %14 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul17, %14
  %sub18 = sub nsw i32 %add, 1
  %15 = load i32, ptr %offset.addr, align 4
  %mul19 = mul nsw i32 2, %15
  %sub20 = sub nsw i32 %mul19, 1
  %div = sdiv i32 %sub18, %sub20
  %add21 = add nsw i32 1, %div
  br label %cond.end40

cond.false22:                                     ; preds = %if.else
  %16 = load i32, ptr %i.addr, align 4
  %17 = load i32, ptr %blen.addr, align 4
  %sub23 = sub nsw i32 %17, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul24 = mul nsw i32 2, %18
  %sub25 = sub nsw i32 %sub23, %mul24
  %cmp26 = icmp sgt i32 %16, %sub25
  br i1 %cmp26, label %cond.true27, label %cond.false37

cond.true27:                                      ; preds = %cond.false22
  %19 = load i32, ptr %blen.addr, align 4
  %sub28 = sub nsw i32 %19, 1
  %20 = load i32, ptr %i.addr, align 4
  %sub29 = sub nsw i32 %sub28, %20
  %mul30 = mul nsw i32 6, %sub29
  %21 = load i32, ptr %offset.addr, align 4
  %add31 = add nsw i32 %mul30, %21
  %sub32 = sub nsw i32 %add31, 1
  %22 = load i32, ptr %offset.addr, align 4
  %mul33 = mul nsw i32 2, %22
  %sub34 = sub nsw i32 %mul33, 1
  %div35 = sdiv i32 %sub32, %sub34
  %add36 = add nsw i32 1, %div35
  br label %cond.end38

cond.false37:                                     ; preds = %cond.false22
  br label %cond.end38

cond.end38:                                       ; preds = %cond.false37, %cond.true27
  %cond39 = phi i32 [ %add36, %cond.true27 ], [ 8, %cond.false37 ]
  br label %cond.end40

cond.end40:                                       ; preds = %cond.end38, %cond.true16
  %cond41 = phi i32 [ %add21, %cond.true16 ], [ %cond39, %cond.end38 ]
  store i32 %cond41, ptr %retval, align 4
  br label %return

return:                                           ; preds = %cond.end40, %cond.end12
  %23 = load i32, ptr %retval, align 4
  ret i32 %23
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_10(i32 noundef %i, i32 noundef %blen, i32 noundef %offset) #0 {
entry:
  %retval = alloca i32, align 4
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  %0 = load i32, ptr %i.addr, align 4
  %1 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %1
  %cmp = icmp slt i32 %0, %mul
  br i1 %cmp, label %if.then, label %if.else7

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %offset.addr, align 4
  %cmp1 = icmp eq i32 %2, 1
  br i1 %cmp1, label %if.then2, label %if.else

if.then2:                                         ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %tobool = icmp ne i32 %3, 0
  %4 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 5, i32 3
  store i32 %cond, ptr %retval, align 4
  br label %return

if.else:                                          ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %mul3 = mul nsw i32 6, %5
  %6 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul3, %6
  %sub = sub nsw i32 %add, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul4 = mul nsw i32 2, %7
  %sub5 = sub nsw i32 %mul4, 1
  %div = sdiv i32 %sub, %sub5
  %add6 = add nsw i32 1, %div
  store i32 %add6, ptr %retval, align 4
  br label %return

if.else7:                                         ; preds = %entry
  %8 = load i32, ptr %i.addr, align 4
  %9 = load i32, ptr %blen.addr, align 4
  %sub8 = sub nsw i32 %9, 1
  %10 = load i32, ptr %offset.addr, align 4
  %mul9 = mul nsw i32 2, %10
  %sub10 = sub nsw i32 %sub8, %mul9
  %cmp11 = icmp sgt i32 %8, %sub10
  br i1 %cmp11, label %if.then12, label %if.end

if.then12:                                        ; preds = %if.else7
  %11 = load i32, ptr %offset.addr, align 4
  %cmp13 = icmp eq i32 %11, 1
  br i1 %cmp13, label %if.then14, label %if.else19

if.then14:                                        ; preds = %if.then12
  %12 = load i32, ptr %blen.addr, align 4
  %sub15 = sub nsw i32 %12, 1
  %13 = load i32, ptr %i.addr, align 4
  %sub16 = sub nsw i32 %sub15, %13
  %tobool17 = icmp ne i32 %sub16, 0
  %14 = zext i1 %tobool17 to i64
  %cond18 = select i1 %tobool17, i32 5, i32 3
  store i32 %cond18, ptr %retval, align 4
  br label %return

if.else19:                                        ; preds = %if.then12
  %15 = load i32, ptr %blen.addr, align 4
  %sub20 = sub nsw i32 %15, 1
  %16 = load i32, ptr %i.addr, align 4
  %sub21 = sub nsw i32 %sub20, %16
  %mul22 = mul nsw i32 6, %sub21
  %17 = load i32, ptr %offset.addr, align 4
  %add23 = add nsw i32 %mul22, %17
  %sub24 = sub nsw i32 %add23, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul25 = mul nsw i32 2, %18
  %sub26 = sub nsw i32 %mul25, 1
  %div27 = sdiv i32 %sub24, %sub26
  %add28 = add nsw i32 1, %div27
  store i32 %add28, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %if.else7
  br label %if.end29

if.end29:                                         ; preds = %if.end
  store i32 8, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end29, %if.else19, %if.then14, %if.else, %if.then2
  %19 = load i32, ptr %retval, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_11(i32 noundef %i, i32 noundef %blen, i32 noundef %offset) #0 {
entry:
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  %result = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  %0 = load i32, ptr %i.addr, align 4
  %1 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %1
  %cmp = icmp slt i32 %0, %mul
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %offset.addr, align 4
  %cmp1 = icmp eq i32 %2, 1
  br i1 %cmp1, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %tobool = icmp ne i32 %3, 0
  %4 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 5, i32 3
  br label %cond.end

cond.false:                                       ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %mul2 = mul nsw i32 6, %5
  %6 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul2, %6
  %sub = sub nsw i32 %add, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul3 = mul nsw i32 2, %7
  %sub4 = sub nsw i32 %mul3, 1
  %div = sdiv i32 %sub, %sub4
  %add5 = add nsw i32 1, %div
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond6 = phi i32 [ %cond, %cond.true ], [ %add5, %cond.false ]
  store i32 %cond6, ptr %result, align 4
  br label %if.end31

if.else:                                          ; preds = %entry
  %8 = load i32, ptr %i.addr, align 4
  %9 = load i32, ptr %blen.addr, align 4
  %sub7 = sub nsw i32 %9, 1
  %10 = load i32, ptr %offset.addr, align 4
  %mul8 = mul nsw i32 2, %10
  %sub9 = sub nsw i32 %sub7, %mul8
  %cmp10 = icmp sgt i32 %8, %sub9
  br i1 %cmp10, label %if.then11, label %if.else30

if.then11:                                        ; preds = %if.else
  %11 = load i32, ptr %offset.addr, align 4
  %cmp12 = icmp eq i32 %11, 1
  br i1 %cmp12, label %cond.true13, label %cond.false18

cond.true13:                                      ; preds = %if.then11
  %12 = load i32, ptr %blen.addr, align 4
  %sub14 = sub nsw i32 %12, 1
  %13 = load i32, ptr %i.addr, align 4
  %sub15 = sub nsw i32 %sub14, %13
  %tobool16 = icmp ne i32 %sub15, 0
  %14 = zext i1 %tobool16 to i64
  %cond17 = select i1 %tobool16, i32 5, i32 3
  br label %cond.end28

cond.false18:                                     ; preds = %if.then11
  %15 = load i32, ptr %blen.addr, align 4
  %sub19 = sub nsw i32 %15, 1
  %16 = load i32, ptr %i.addr, align 4
  %sub20 = sub nsw i32 %sub19, %16
  %mul21 = mul nsw i32 6, %sub20
  %17 = load i32, ptr %offset.addr, align 4
  %add22 = add nsw i32 %mul21, %17
  %sub23 = sub nsw i32 %add22, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul24 = mul nsw i32 2, %18
  %sub25 = sub nsw i32 %mul24, 1
  %div26 = sdiv i32 %sub23, %sub25
  %add27 = add nsw i32 1, %div26
  br label %cond.end28

cond.end28:                                       ; preds = %cond.false18, %cond.true13
  %cond29 = phi i32 [ %cond17, %cond.true13 ], [ %add27, %cond.false18 ]
  store i32 %cond29, ptr %result, align 4
  br label %if.end

if.else30:                                        ; preds = %if.else
  store i32 8, ptr %result, align 4
  br label %if.end

if.end:                                           ; preds = %if.else30, %cond.end28
  br label %if.end31

if.end31:                                         ; preds = %if.end, %cond.end
  %19 = load i32, ptr %result, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_1(i32 noundef %i, i32 noundef %blen, i32 noundef %offset) #0 {
entry:
  %retval = alloca i32, align 4
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  %0 = load i32, ptr %i.addr, align 4
  %1 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %1
  %cmp = icmp slt i32 %0, %mul
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %offset.addr, align 4
  %cmp1 = icmp eq i32 %2, 1
  br i1 %cmp1, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %tobool = icmp ne i32 %3, 0
  %4 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 5, i32 3
  br label %cond.end

cond.false:                                       ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %mul2 = mul nsw i32 6, %5
  %6 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul2, %6
  %sub = sub nsw i32 %add, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul3 = mul nsw i32 2, %7
  %sub4 = sub nsw i32 %mul3, 1
  %div = sdiv i32 %sub, %sub4
  %add5 = add nsw i32 1, %div
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond6 = phi i32 [ %cond, %cond.true ], [ %add5, %cond.false ]
  store i32 %cond6, ptr %retval, align 4
  br label %return

if.else:                                          ; preds = %entry
  %8 = load i32, ptr %i.addr, align 4
  %9 = load i32, ptr %blen.addr, align 4
  %sub7 = sub nsw i32 %9, 1
  %10 = load i32, ptr %offset.addr, align 4
  %mul8 = mul nsw i32 2, %10
  %sub9 = sub nsw i32 %sub7, %mul8
  %cmp10 = icmp sgt i32 %8, %sub9
  br i1 %cmp10, label %if.then11, label %if.end

if.then11:                                        ; preds = %if.else
  %11 = load i32, ptr %offset.addr, align 4
  %cmp12 = icmp eq i32 %11, 1
  br i1 %cmp12, label %cond.true13, label %cond.false18

cond.true13:                                      ; preds = %if.then11
  %12 = load i32, ptr %blen.addr, align 4
  %sub14 = sub nsw i32 %12, 1
  %13 = load i32, ptr %i.addr, align 4
  %sub15 = sub nsw i32 %sub14, %13
  %tobool16 = icmp ne i32 %sub15, 0
  %14 = zext i1 %tobool16 to i64
  %cond17 = select i1 %tobool16, i32 5, i32 3
  br label %cond.end28

cond.false18:                                     ; preds = %if.then11
  %15 = load i32, ptr %blen.addr, align 4
  %sub19 = sub nsw i32 %15, 1
  %16 = load i32, ptr %i.addr, align 4
  %sub20 = sub nsw i32 %sub19, %16
  %mul21 = mul nsw i32 6, %sub20
  %17 = load i32, ptr %offset.addr, align 4
  %add22 = add nsw i32 %mul21, %17
  %sub23 = sub nsw i32 %add22, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul24 = mul nsw i32 2, %18
  %sub25 = sub nsw i32 %mul24, 1
  %div26 = sdiv i32 %sub23, %sub25
  %add27 = add nsw i32 1, %div26
  br label %cond.end28

cond.end28:                                       ; preds = %cond.false18, %cond.true13
  %cond29 = phi i32 [ %cond17, %cond.true13 ], [ %add27, %cond.false18 ]
  store i32 %cond29, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %if.else
  br label %if.end30

if.end30:                                         ; preds = %if.end
  store i32 8, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end30, %cond.end28, %cond.end
  %19 = load i32, ptr %retval, align 4
  ret i32 %19
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
