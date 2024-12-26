; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/1_ctz.bc'
source_filename = "/home/javier/Galapagos/functions/libgcrypt/1_ctz.run.c"
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
  %call1 = call i32 @n_version_call(i64 noundef 0)
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
define internal i32 @n_version_call(i64 noundef %0) #0 {
entry:
  %1 = call i32 @version_1(i64 %0)
  %2 = call i32 @version_2(i64 %0)
  %3 = call i32 @version_3(i64 %0)
  %4 = call i32 @version_4(i64 %0)
  %5 = call i32 @version_5(i64 %0)
  %6 = call i32 @version_6(i64 %0)
  %7 = call i32 @version_7(i64 %0)
  %8 = call i32 @version_8(i64 %0)
  %9 = call i32 @version_9(i64 %0)
  %10 = call i32 @version_10(i64 %0)
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
define dso_local i32 @version_2(i64 noundef %in) #0 {
entry:
  %in.addr = alloca i64, align 8
  %r = alloca i32, align 4
  %mask = alloca i64, align 8
  store i64 %in, ptr %in.addr, align 8
  store i32 0, ptr %r, align 4
  store i64 1, ptr %mask, align 8
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %0 = load i64, ptr %in.addr, align 8
  %1 = load i64, ptr %mask, align 8
  %and = and i64 %0, %1
  %cmp = icmp eq i64 %and, 0
  br i1 %cmp, label %land.rhs, label %land.end

land.rhs:                                         ; preds = %while.cond
  %2 = load i32, ptr %r, align 4
  %cmp1 = icmp slt i32 %2, 64
  br label %land.end

land.end:                                         ; preds = %land.rhs, %while.cond
  %3 = phi i1 [ false, %while.cond ], [ %cmp1, %land.rhs ]
  br i1 %3, label %while.body, label %while.end

while.body:                                       ; preds = %land.end
  %4 = load i64, ptr %mask, align 8
  %shl = shl i64 %4, 1
  store i64 %shl, ptr %mask, align 8
  %5 = load i32, ptr %r, align 4
  %inc = add nsw i32 %5, 1
  store i32 %inc, ptr %r, align 4
  br label %while.cond, !llvm.loop !8

while.end:                                        ; preds = %land.end
  %6 = load i32, ptr %r, align 4
  ret i32 %6
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_3(i64 noundef %in) #0 {
entry:
  %in.addr = alloca i64, align 8
  %r = alloca i32, align 4
  %i = alloca i32, align 4
  store i64 %in, ptr %in.addr, align 8
  store i32 64, ptr %r, align 4
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %0, 64
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %1 = load i64, ptr %in.addr, align 8
  %2 = load i32, ptr %i, align 4
  %sh_prom = zext i32 %2 to i64
  %shl = shl i64 1, %sh_prom
  %and = and i64 %1, %shl
  %cmp1 = icmp ne i64 %and, 0
  br i1 %cmp1, label %if.then, label %if.end

if.then:                                          ; preds = %for.body
  %3 = load i32, ptr %i, align 4
  store i32 %3, ptr %r, align 4
  br label %for.end

if.end:                                           ; preds = %for.body
  br label %for.inc

for.inc:                                          ; preds = %if.end
  %4 = load i32, ptr %i, align 4
  %inc = add nsw i32 %4, 1
  store i32 %inc, ptr %i, align 4
  br label %for.cond, !llvm.loop !9

for.end:                                          ; preds = %if.then, %for.cond
  %5 = load i32, ptr %r, align 4
  ret i32 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_4(i64 noundef %in) #0 {
entry:
  %retval = alloca i32, align 4
  %in.addr = alloca i64, align 8
  %r = alloca i32, align 4
  store i64 %in, ptr %in.addr, align 8
  %0 = load i64, ptr %in.addr, align 8
  %cmp = icmp eq i64 %0, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 64, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  store i32 0, ptr %r, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %if.end
  %1 = load i64, ptr %in.addr, align 8
  %2 = load i32, ptr %r, align 4
  %sh_prom = zext i32 %2 to i64
  %shl = shl i64 1, %sh_prom
  %and = and i64 %1, %shl
  %cmp1 = icmp eq i64 %and, 0
  br i1 %cmp1, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %3 = load i32, ptr %r, align 4
  %inc = add nsw i32 %3, 1
  store i32 %inc, ptr %r, align 4
  br label %while.cond, !llvm.loop !10

while.end:                                        ; preds = %while.cond
  %4 = load i32, ptr %r, align 4
  store i32 %4, ptr %retval, align 4
  br label %return

return:                                           ; preds = %while.end, %if.then
  %5 = load i32, ptr %retval, align 4
  ret i32 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_5(i64 noundef %in) #0 {
entry:
  %in.addr = alloca i64, align 8
  %r = alloca i32, align 4
  %m = alloca i64, align 8
  store i64 %in, ptr %in.addr, align 8
  store i32 0, ptr %r, align 4
  store i64 1, ptr %m, align 8
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i64, ptr %m, align 8
  %cmp = icmp ne i64 %0, 0
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %1 = load i64, ptr %in.addr, align 8
  %2 = load i64, ptr %m, align 8
  %and = and i64 %1, %2
  %cmp1 = icmp ne i64 %and, 0
  br i1 %cmp1, label %if.then, label %if.end

if.then:                                          ; preds = %for.body
  br label %for.end

if.end:                                           ; preds = %for.body
  br label %for.inc

for.inc:                                          ; preds = %if.end
  %3 = load i64, ptr %m, align 8
  %shl = shl i64 %3, 1
  store i64 %shl, ptr %m, align 8
  %4 = load i32, ptr %r, align 4
  %inc = add nsw i32 %4, 1
  store i32 %inc, ptr %r, align 4
  br label %for.cond, !llvm.loop !11

for.end:                                          ; preds = %if.then, %for.cond
  %5 = load i32, ptr %r, align 4
  ret i32 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_6(i64 noundef %in) #0 {
entry:
  %retval = alloca i32, align 4
  %in.addr = alloca i64, align 8
  %r = alloca i32, align 4
  store i64 %in, ptr %in.addr, align 8
  %0 = load i64, ptr %in.addr, align 8
  %cmp = icmp eq i64 %0, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 64, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  store i32 0, ptr %r, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %if.end
  %1 = load i64, ptr %in.addr, align 8
  %and = and i64 %1, 1
  %cmp1 = icmp eq i64 %and, 0
  br i1 %cmp1, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %2 = load i64, ptr %in.addr, align 8
  %shr = lshr i64 %2, 1
  store i64 %shr, ptr %in.addr, align 8
  %3 = load i32, ptr %r, align 4
  %inc = add nsw i32 %3, 1
  store i32 %inc, ptr %r, align 4
  br label %while.cond, !llvm.loop !12

while.end:                                        ; preds = %while.cond
  %4 = load i32, ptr %r, align 4
  store i32 %4, ptr %retval, align 4
  br label %return

return:                                           ; preds = %while.end, %if.then
  %5 = load i32, ptr %retval, align 4
  ret i32 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_7(i64 noundef %in) #0 {
entry:
  %retval = alloca i32, align 4
  %in.addr = alloca i64, align 8
  %r = alloca i32, align 4
  %i = alloca i32, align 4
  store i64 %in, ptr %in.addr, align 8
  store i32 0, ptr %r, align 4
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %0, 64
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %1 = load i64, ptr %in.addr, align 8
  %2 = load i32, ptr %i, align 4
  %sh_prom = zext i32 %2 to i64
  %shl = shl i64 1, %sh_prom
  %and = and i64 %1, %shl
  %cmp1 = icmp ne i64 %and, 0
  br i1 %cmp1, label %if.then, label %if.end

if.then:                                          ; preds = %for.body
  %3 = load i32, ptr %r, align 4
  store i32 %3, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %for.body
  %4 = load i32, ptr %r, align 4
  %inc = add nsw i32 %4, 1
  store i32 %inc, ptr %r, align 4
  br label %for.inc

for.inc:                                          ; preds = %if.end
  %5 = load i32, ptr %i, align 4
  %inc2 = add nsw i32 %5, 1
  store i32 %inc2, ptr %i, align 4
  br label %for.cond, !llvm.loop !13

for.end:                                          ; preds = %for.cond
  %6 = load i32, ptr %r, align 4
  store i32 %6, ptr %retval, align 4
  br label %return

return:                                           ; preds = %for.end, %if.then
  %7 = load i32, ptr %retval, align 4
  ret i32 %7
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_8(i64 noundef %in) #0 {
entry:
  %retval = alloca i32, align 4
  %in.addr = alloca i64, align 8
  %r = alloca i32, align 4
  store i64 %in, ptr %in.addr, align 8
  %0 = load i64, ptr %in.addr, align 8
  %cmp = icmp eq i64 %0, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 64, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  store i32 0, ptr %r, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %if.end
  %1 = load i64, ptr %in.addr, align 8
  %and = and i64 %1, 1
  %cmp1 = icmp eq i64 %and, 0
  br i1 %cmp1, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %2 = load i32, ptr %r, align 4
  %inc = add nsw i32 %2, 1
  store i32 %inc, ptr %r, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %3 = load i64, ptr %in.addr, align 8
  %shr = lshr i64 %3, 1
  store i64 %shr, ptr %in.addr, align 8
  br label %for.cond, !llvm.loop !14

for.end:                                          ; preds = %for.cond
  %4 = load i32, ptr %r, align 4
  store i32 %4, ptr %retval, align 4
  br label %return

return:                                           ; preds = %for.end, %if.then
  %5 = load i32, ptr %retval, align 4
  ret i32 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_9(i64 noundef %in) #0 {
entry:
  %in.addr = alloca i64, align 8
  %r = alloca i32, align 4
  %m = alloca i64, align 8
  store i64 %in, ptr %in.addr, align 8
  store i32 0, ptr %r, align 4
  store i64 1, ptr %m, align 8
  br label %while.cond

while.cond:                                       ; preds = %if.end, %entry
  %0 = load i32, ptr %r, align 4
  %cmp = icmp slt i32 %0, 64
  br i1 %cmp, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %1 = load i64, ptr %in.addr, align 8
  %2 = load i64, ptr %m, align 8
  %and = and i64 %1, %2
  %cmp1 = icmp ne i64 %and, 0
  br i1 %cmp1, label %if.then, label %if.end

if.then:                                          ; preds = %while.body
  br label %while.end

if.end:                                           ; preds = %while.body
  %3 = load i64, ptr %m, align 8
  %shl = shl i64 %3, 1
  store i64 %shl, ptr %m, align 8
  %4 = load i32, ptr %r, align 4
  %inc = add nsw i32 %4, 1
  store i32 %inc, ptr %r, align 4
  br label %while.cond, !llvm.loop !15

while.end:                                        ; preds = %if.then, %while.cond
  %5 = load i32, ptr %r, align 4
  ret i32 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_10(i64 noundef %in) #0 {
entry:
  %retval = alloca i32, align 4
  %in.addr = alloca i64, align 8
  %r = alloca i32, align 4
  %m = alloca i64, align 8
  store i64 %in, ptr %in.addr, align 8
  store i32 0, ptr %r, align 4
  %0 = load i64, ptr %in.addr, align 8
  %cmp = icmp eq i64 %0, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 64, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  store i64 1, ptr %m, align 8
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %if.end
  %1 = load i64, ptr %in.addr, align 8
  %2 = load i64, ptr %m, align 8
  %and = and i64 %1, %2
  %cmp1 = icmp eq i64 %and, 0
  br i1 %cmp1, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %3 = load i32, ptr %r, align 4
  %inc = add nsw i32 %3, 1
  store i32 %inc, ptr %r, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %4 = load i64, ptr %m, align 8
  %shl = shl i64 %4, 1
  store i64 %shl, ptr %m, align 8
  br label %for.cond, !llvm.loop !16

for.end:                                          ; preds = %for.cond
  %5 = load i32, ptr %r, align 4
  store i32 %5, ptr %retval, align 4
  br label %return

return:                                           ; preds = %for.end, %if.then
  %6 = load i32, ptr %retval, align 4
  ret i32 %6
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_1(i64 noundef %in) #0 {
entry:
  %in.addr = alloca i64, align 8
  %i = alloca i32, align 4
  %b = alloca i32, align 4
  %m = alloca i32, align 4
  %r = alloca i32, align 4
  store i64 %in, ptr %in.addr, align 8
  store i32 0, ptr %m, align 4
  store i32 0, ptr %r, align 4
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %0, 64
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %1 = load i64, ptr %in.addr, align 8
  %2 = load i32, ptr %i, align 4
  %sh_prom = zext i32 %2 to i64
  %shr = lshr i64 %1, %sh_prom
  %and = and i64 %shr, 1
  %conv = trunc i64 %and to i32
  store i32 %conv, ptr %b, align 4
  %3 = load i32, ptr %b, align 4
  %4 = load i32, ptr %m, align 4
  %or = or i32 %4, %3
  store i32 %or, ptr %m, align 4
  %5 = load i32, ptr %m, align 4
  %xor = xor i32 %5, 1
  %6 = load i32, ptr %b, align 4
  %xor1 = xor i32 %6, 1
  %and2 = and i32 %xor, %xor1
  %7 = load i32, ptr %r, align 4
  %add = add nsw i32 %7, %and2
  store i32 %add, ptr %r, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %8 = load i32, ptr %i, align 4
  %inc = add nsw i32 %8, 1
  store i32 %inc, ptr %i, align 4
  br label %for.cond, !llvm.loop !17

for.end:                                          ; preds = %for.cond
  %9 = load i32, ptr %r, align 4
  ret i32 %9
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
!12 = distinct !{!12, !7}
!13 = distinct !{!13, !7}
!14 = distinct !{!14, !7}
!15 = distinct !{!15, !7}
!16 = distinct !{!16, !7}
!17 = distinct !{!17, !7}
