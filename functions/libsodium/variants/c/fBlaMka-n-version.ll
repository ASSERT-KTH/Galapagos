; ModuleID = '/home/javier/Galapagos/functions/libsodium/4_fBlaMka.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/4_fBlaMka.run.c"
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
  %call1 = call i64 @n_version_call(i64 noundef 0, i64 noundef 0)
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
define internal i64 @n_version_call(i64 noundef %0, i64 noundef %1) #0 {
entry:
  %2 = call i64 @version_1(i64 %0, i64 %1)
  %3 = call i64 @version_2(i64 %0, i64 %1)
  %4 = call i64 @version_3(i64 %0, i64 %1)
  %5 = call i64 @version_4(i64 %0, i64 %1)
  %6 = call i64 @version_5(i64 %0, i64 %1)
  %7 = call i64 @version_6(i64 %0, i64 %1)
  %8 = call i64 @version_7(i64 %0, i64 %1)
  %9 = call i64 @version_8(i64 %0, i64 %1)
  %10 = call i64 @version_9(i64 %0, i64 %1)
  %11 = call i64 @version_10(i64 %0, i64 %1)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %12 = icmp eq i64 %2, %3
  br i1 %12, label %true, label %error

true:                                             ; preds = %comparisons
  %13 = icmp eq i64 %2, %4
  br i1 %13, label %true1, label %error

true1:                                            ; preds = %true
  %14 = icmp eq i64 %2, %5
  br i1 %14, label %true2, label %error

true2:                                            ; preds = %true1
  %15 = icmp eq i64 %2, %6
  br i1 %15, label %true3, label %error

true3:                                            ; preds = %true2
  %16 = icmp eq i64 %2, %7
  br i1 %16, label %true4, label %error

true4:                                            ; preds = %true3
  %17 = icmp eq i64 %2, %8
  br i1 %17, label %true5, label %error

true5:                                            ; preds = %true4
  %18 = icmp eq i64 %2, %9
  br i1 %18, label %true6, label %error

true6:                                            ; preds = %true5
  %19 = icmp eq i64 %2, %10
  br i1 %19, label %true7, label %error

true7:                                            ; preds = %true6
  %20 = icmp eq i64 %2, %11
  br i1 %20, label %true8, label %error

true8:                                            ; preds = %true7
  ret i64 %2

error:                                            ; preds = %true7, %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_2(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  %low_x = alloca i32, align 4
  %low_y = alloca i32, align 4
  %product = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  %0 = load i64, ptr %x.addr, align 8
  %and = and i64 %0, 4294967295
  %conv = trunc i64 %and to i32
  store i32 %conv, ptr %low_x, align 4
  %1 = load i64, ptr %y.addr, align 8
  %and1 = and i64 %1, 4294967295
  %conv2 = trunc i64 %and1 to i32
  store i32 %conv2, ptr %low_y, align 4
  %2 = load i32, ptr %low_x, align 4
  %conv3 = zext i32 %2 to i64
  %3 = load i32, ptr %low_y, align 4
  %conv4 = zext i32 %3 to i64
  %mul = mul i64 %conv3, %conv4
  store i64 %mul, ptr %product, align 8
  %4 = load i64, ptr %x.addr, align 8
  %5 = load i64, ptr %y.addr, align 8
  %add = add i64 %4, %5
  %6 = load i64, ptr %product, align 8
  %shl = shl i64 %6, 1
  %add5 = add i64 %add, %shl
  ret i64 %add5
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_3(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  %mask = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  store i64 4294967295, ptr %mask, align 8
  %0 = load i64, ptr %x.addr, align 8
  %1 = load i64, ptr %y.addr, align 8
  %add = add i64 %0, %1
  %2 = load i64, ptr %x.addr, align 8
  %and = and i64 %2, 4294967295
  %3 = load i64, ptr %y.addr, align 8
  %and1 = and i64 %3, 4294967295
  %mul = mul i64 %and, %and1
  %mul2 = mul i64 2, %mul
  %add3 = add i64 %add, %mul2
  ret i64 %add3
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_4(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  %low_x = alloca i32, align 4
  %low_y = alloca i32, align 4
  %product = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  %0 = load i64, ptr %x.addr, align 8
  %conv = trunc i64 %0 to i32
  store i32 %conv, ptr %low_x, align 4
  %1 = load i64, ptr %y.addr, align 8
  %conv1 = trunc i64 %1 to i32
  store i32 %conv1, ptr %low_y, align 4
  %2 = load i32, ptr %low_x, align 4
  %conv2 = zext i32 %2 to i64
  %3 = load i32, ptr %low_y, align 4
  %conv3 = zext i32 %3 to i64
  %mul = mul i64 %conv2, %conv3
  store i64 %mul, ptr %product, align 8
  %4 = load i64, ptr %x.addr, align 8
  %5 = load i64, ptr %y.addr, align 8
  %add = add i64 %4, %5
  %6 = load i64, ptr %product, align 8
  %shl = shl i64 %6, 1
  %add4 = add i64 %add, %shl
  ret i64 %add4
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_5(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  %a = alloca i64, align 8
  %b = alloca i64, align 8
  %prod = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  %0 = load i64, ptr %x.addr, align 8
  %and = and i64 %0, 4294967295
  store i64 %and, ptr %a, align 8
  %1 = load i64, ptr %y.addr, align 8
  %and1 = and i64 %1, 4294967295
  store i64 %and1, ptr %b, align 8
  %2 = load i64, ptr %a, align 8
  %3 = load i64, ptr %b, align 8
  %mul = mul i64 %2, %3
  store i64 %mul, ptr %prod, align 8
  %4 = load i64, ptr %x.addr, align 8
  %5 = load i64, ptr %y.addr, align 8
  %add = add i64 %4, %5
  %6 = load i64, ptr %prod, align 8
  %shl = shl i64 %6, 1
  %add2 = add i64 %add, %shl
  ret i64 %add2
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_6(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  %m = alloca i64, align 8
  %product = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  store i64 4294967295, ptr %m, align 8
  %0 = load i64, ptr %x.addr, align 8
  %and = and i64 %0, 4294967295
  %1 = load i64, ptr %y.addr, align 8
  %and1 = and i64 %1, 4294967295
  %mul = mul i64 %and, %and1
  store i64 %mul, ptr %product, align 8
  %2 = load i64, ptr %x.addr, align 8
  %3 = load i64, ptr %y.addr, align 8
  %add = add i64 %2, %3
  %4 = load i64, ptr %product, align 8
  %shl = shl i64 %4, 1
  %add2 = add i64 %add, %shl
  ret i64 %add2
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_7(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  %mask = alloca i64, align 8
  %low_x = alloca i64, align 8
  %low_y = alloca i64, align 8
  %product = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  store i64 4294967295, ptr %mask, align 8
  %0 = load i64, ptr %x.addr, align 8
  %1 = load i64, ptr %mask, align 8
  %and = and i64 %0, %1
  store i64 %and, ptr %low_x, align 8
  %2 = load i64, ptr %y.addr, align 8
  %3 = load i64, ptr %mask, align 8
  %and1 = and i64 %2, %3
  store i64 %and1, ptr %low_y, align 8
  %4 = load i64, ptr %low_x, align 8
  %5 = load i64, ptr %low_y, align 8
  %mul = mul i64 %4, %5
  store i64 %mul, ptr %product, align 8
  %6 = load i64, ptr %x.addr, align 8
  %7 = load i64, ptr %y.addr, align 8
  %add = add i64 %6, %7
  %8 = load i64, ptr %product, align 8
  %mul2 = mul i64 2, %8
  %add3 = add i64 %add, %mul2
  ret i64 %add3
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_8(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  %lower_x = alloca i64, align 8
  %lower_y = alloca i64, align 8
  %product = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  %0 = load i64, ptr %x.addr, align 8
  %and = and i64 %0, 4294967295
  store i64 %and, ptr %lower_x, align 8
  %1 = load i64, ptr %y.addr, align 8
  %and1 = and i64 %1, 4294967295
  store i64 %and1, ptr %lower_y, align 8
  %2 = load i64, ptr %lower_x, align 8
  %3 = load i64, ptr %lower_y, align 8
  %mul = mul i64 %2, %3
  store i64 %mul, ptr %product, align 8
  %4 = load i64, ptr %x.addr, align 8
  %5 = load i64, ptr %y.addr, align 8
  %add = add i64 %4, %5
  %6 = load i64, ptr %product, align 8
  %shl = shl i64 %6, 1
  %add2 = add i64 %add, %shl
  ret i64 %add2
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_9(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  %mask = alloca i64, align 8
  %product = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  store i64 4294967295, ptr %mask, align 8
  %0 = load i64, ptr %x.addr, align 8
  %and = and i64 %0, 4294967295
  %1 = load i64, ptr %y.addr, align 8
  %and1 = and i64 %1, 4294967295
  %mul = mul i64 %and, %and1
  store i64 %mul, ptr %product, align 8
  %2 = load i64, ptr %x.addr, align 8
  %3 = load i64, ptr %y.addr, align 8
  %add = add i64 %2, %3
  %4 = load i64, ptr %product, align 8
  %mul2 = mul i64 2, %4
  %add3 = add i64 %add, %mul2
  ret i64 %add3
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_10(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  %x_low = alloca i32, align 4
  %y_low = alloca i32, align 4
  %prod = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  %0 = load i64, ptr %x.addr, align 8
  %and = and i64 %0, 4294967295
  %conv = trunc i64 %and to i32
  store i32 %conv, ptr %x_low, align 4
  %1 = load i64, ptr %y.addr, align 8
  %and1 = and i64 %1, 4294967295
  %conv2 = trunc i64 %and1 to i32
  store i32 %conv2, ptr %y_low, align 4
  %2 = load i32, ptr %x_low, align 4
  %conv3 = zext i32 %2 to i64
  %3 = load i32, ptr %y_low, align 4
  %conv4 = zext i32 %3 to i64
  %mul = mul i64 %conv3, %conv4
  store i64 %mul, ptr %prod, align 8
  %4 = load i64, ptr %x.addr, align 8
  %5 = load i64, ptr %y.addr, align 8
  %add = add i64 %4, %5
  %6 = load i64, ptr %prod, align 8
  %shl = shl i64 %6, 1
  %add5 = add i64 %add, %shl
  ret i64 %add5
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @version_1(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  %m = alloca i64, align 8
  %xy = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  store i64 4294967295, ptr %m, align 8
  %0 = load i64, ptr %x.addr, align 8
  %and = and i64 %0, 4294967295
  %1 = load i64, ptr %y.addr, align 8
  %and1 = and i64 %1, 4294967295
  %mul = mul i64 %and, %and1
  store i64 %mul, ptr %xy, align 8
  %2 = load i64, ptr %x.addr, align 8
  %3 = load i64, ptr %y.addr, align 8
  %add = add i64 %2, %3
  %4 = load i64, ptr %xy, align 8
  %mul2 = mul i64 2, %4
  %add3 = add i64 %add, %mul2
  ret i64 %add3
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
