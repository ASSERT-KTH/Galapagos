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
  br label %comparisons

comparisons:                                      ; preds = %entry
  %9 = icmp eq i32 %2, %3
  br i1 %9, label %true, label %error

true:                                             ; preds = %comparisons
  %10 = icmp eq i32 %2, %4
  br i1 %10, label %true1, label %error

true1:                                            ; preds = %true
  %11 = icmp eq i32 %2, %5
  br i1 %11, label %true2, label %error

true2:                                            ; preds = %true1
  %12 = icmp eq i32 %2, %6
  br i1 %12, label %true3, label %error

true3:                                            ; preds = %true2
  %13 = icmp eq i32 %2, %7
  br i1 %13, label %true4, label %error

true4:                                            ; preds = %true3
  %14 = icmp eq i32 %2, %8
  br i1 %14, label %true5, label %error

true5:                                            ; preds = %true4
  ret i32 %2

error:                                            ; preds = %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_2(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %c0.addr = alloca i32, align 4
  %c1.addr = alloca i32, align 4
  %blue = alloca i32, align 4
  %green = alloca i32, align 4
  %red = alloca i32, align 4
  %result = alloca i32, align 4
  store i32 %c0, ptr %c0.addr, align 4
  store i32 %c1, ptr %c1.addr, align 4
  %0 = load i32, ptr %c0.addr, align 4
  %and = and i32 %0, 31
  %mul = mul nsw i32 %and, 2
  %1 = load i32, ptr %c1.addr, align 4
  %and1 = and i32 %1, 31
  %add = add nsw i32 %mul, %and1
  store i32 %add, ptr %blue, align 4
  %2 = load i32, ptr %c0.addr, align 4
  %and2 = and i32 %2, 992
  %mul3 = mul nsw i32 %and2, 2
  %3 = load i32, ptr %c1.addr, align 4
  %and4 = and i32 %3, 992
  %add5 = add nsw i32 %mul3, %and4
  %shr = ashr i32 %add5, 5
  store i32 %shr, ptr %green, align 4
  %4 = load i32, ptr %c0.addr, align 4
  %shr6 = ashr i32 %4, 10
  %mul7 = mul nsw i32 %shr6, 2
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
  store i32 %add15, ptr %result, align 4
  %9 = load i32, ptr %result, align 4
  ret i32 %9
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_3(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %c0.addr = alloca i32, align 4
  %c1.addr = alloca i32, align 4
  %blueComponent = alloca i32, align 4
  %blue = alloca i32, align 4
  %greenComponent = alloca i32, align 4
  %green = alloca i32, align 4
  %redComponent = alloca i32, align 4
  %red = alloca i32, align 4
  store i32 %c0, ptr %c0.addr, align 4
  store i32 %c1, ptr %c1.addr, align 4
  %0 = load i32, ptr %c0.addr, align 4
  %and = and i32 %0, 31
  %mul = mul nsw i32 2, %and
  store i32 %mul, ptr %blueComponent, align 4
  %1 = load i32, ptr %blueComponent, align 4
  %2 = load i32, ptr %c1.addr, align 4
  %and1 = and i32 %2, 31
  %add = add nsw i32 %1, %and1
  store i32 %add, ptr %blue, align 4
  %3 = load i32, ptr %c0.addr, align 4
  %and2 = and i32 %3, 992
  %mul3 = mul nsw i32 2, %and2
  store i32 %mul3, ptr %greenComponent, align 4
  %4 = load i32, ptr %greenComponent, align 4
  %5 = load i32, ptr %c1.addr, align 4
  %and4 = and i32 %5, 992
  %add5 = add nsw i32 %4, %and4
  %shr = ashr i32 %add5, 5
  store i32 %shr, ptr %green, align 4
  %6 = load i32, ptr %c0.addr, align 4
  %shr6 = ashr i32 %6, 10
  %mul7 = mul nsw i32 2, %shr6
  store i32 %mul7, ptr %redComponent, align 4
  %7 = load i32, ptr %redComponent, align 4
  %8 = load i32, ptr %c1.addr, align 4
  %shr8 = ashr i32 %8, 10
  %add9 = add nsw i32 %7, %shr8
  store i32 %add9, ptr %red, align 4
  %9 = load i32, ptr %red, align 4
  %div = sdiv i32 %9, 3
  %mul10 = mul nsw i32 %div, 1024
  %10 = load i32, ptr %green, align 4
  %div11 = sdiv i32 %10, 3
  %mul12 = mul nsw i32 %div11, 32
  %add13 = add nsw i32 %mul10, %mul12
  %11 = load i32, ptr %blue, align 4
  %div14 = sdiv i32 %11, 3
  %add15 = add nsw i32 %add13, %div14
  ret i32 %add15
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_4(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %c0.addr = alloca i32, align 4
  %c1.addr = alloca i32, align 4
  %bluePart = alloca i32, align 4
  %blue = alloca i32, align 4
  %greenPart = alloca i32, align 4
  %green = alloca i32, align 4
  %redPart = alloca i32, align 4
  %red = alloca i32, align 4
  store i32 %c0, ptr %c0.addr, align 4
  store i32 %c1, ptr %c1.addr, align 4
  %0 = load i32, ptr %c0.addr, align 4
  %and = and i32 %0, 31
  store i32 %and, ptr %bluePart, align 4
  %1 = load i32, ptr %bluePart, align 4
  %2 = load i32, ptr %bluePart, align 4
  %add = add nsw i32 %1, %2
  %3 = load i32, ptr %c1.addr, align 4
  %and1 = and i32 %3, 31
  %add2 = add nsw i32 %add, %and1
  store i32 %add2, ptr %blue, align 4
  %4 = load i32, ptr %c0.addr, align 4
  %and3 = and i32 %4, 992
  store i32 %and3, ptr %greenPart, align 4
  %5 = load i32, ptr %greenPart, align 4
  %6 = load i32, ptr %greenPart, align 4
  %add4 = add nsw i32 %5, %6
  %7 = load i32, ptr %c1.addr, align 4
  %and5 = and i32 %7, 992
  %add6 = add nsw i32 %add4, %and5
  %shr = ashr i32 %add6, 5
  store i32 %shr, ptr %green, align 4
  %8 = load i32, ptr %c0.addr, align 4
  %shr7 = ashr i32 %8, 10
  store i32 %shr7, ptr %redPart, align 4
  %9 = load i32, ptr %redPart, align 4
  %10 = load i32, ptr %redPart, align 4
  %add8 = add nsw i32 %9, %10
  %11 = load i32, ptr %c1.addr, align 4
  %shr9 = ashr i32 %11, 10
  %add10 = add nsw i32 %add8, %shr9
  store i32 %add10, ptr %red, align 4
  %12 = load i32, ptr %red, align 4
  %div = sdiv i32 %12, 3
  %mul = mul nsw i32 %div, 1024
  %13 = load i32, ptr %green, align 4
  %div11 = sdiv i32 %13, 3
  %mul12 = mul nsw i32 %div11, 32
  %add13 = add nsw i32 %mul, %mul12
  %14 = load i32, ptr %blue, align 4
  %div14 = sdiv i32 %14, 3
  %add15 = add nsw i32 %add13, %div14
  ret i32 %add15
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_5(i32 noundef %c0, i32 noundef %c1) #0 {
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
  %mul = mul nsw i32 %and, 2
  %1 = load i32, ptr %c1.addr, align 4
  %and1 = and i32 %1, 31
  %add = add nsw i32 %mul, %and1
  store i32 %add, ptr %blue, align 4
  %2 = load i32, ptr %c0.addr, align 4
  %and2 = and i32 %2, 992
  %mul3 = mul nsw i32 %and2, 2
  %3 = load i32, ptr %c1.addr, align 4
  %and4 = and i32 %3, 992
  %add5 = add nsw i32 %mul3, %and4
  %shr = ashr i32 %add5, 5
  store i32 %shr, ptr %green, align 4
  %4 = load i32, ptr %c0.addr, align 4
  %shr6 = ashr i32 %4, 10
  %mul7 = mul nsw i32 %shr6, 2
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

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_6(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %c0.addr = alloca i32, align 4
  %c1.addr = alloca i32, align 4
  %bluePart1 = alloca i32, align 4
  %blue = alloca i32, align 4
  %greenPart1 = alloca i32, align 4
  %green = alloca i32, align 4
  %redPart1 = alloca i32, align 4
  %red = alloca i32, align 4
  store i32 %c0, ptr %c0.addr, align 4
  store i32 %c1, ptr %c1.addr, align 4
  %0 = load i32, ptr %c0.addr, align 4
  %and = and i32 %0, 31
  %mul = mul nsw i32 2, %and
  store i32 %mul, ptr %bluePart1, align 4
  %1 = load i32, ptr %bluePart1, align 4
  %2 = load i32, ptr %c1.addr, align 4
  %and1 = and i32 %2, 31
  %add = add nsw i32 %1, %and1
  store i32 %add, ptr %blue, align 4
  %3 = load i32, ptr %c0.addr, align 4
  %and2 = and i32 %3, 992
  %mul3 = mul nsw i32 2, %and2
  store i32 %mul3, ptr %greenPart1, align 4
  %4 = load i32, ptr %greenPart1, align 4
  %5 = load i32, ptr %c1.addr, align 4
  %and4 = and i32 %5, 992
  %add5 = add nsw i32 %4, %and4
  %shr = ashr i32 %add5, 5
  store i32 %shr, ptr %green, align 4
  %6 = load i32, ptr %c0.addr, align 4
  %shr6 = ashr i32 %6, 10
  %mul7 = mul nsw i32 2, %shr6
  store i32 %mul7, ptr %redPart1, align 4
  %7 = load i32, ptr %redPart1, align 4
  %8 = load i32, ptr %c1.addr, align 4
  %shr8 = ashr i32 %8, 10
  %add9 = add nsw i32 %7, %shr8
  store i32 %add9, ptr %red, align 4
  %9 = load i32, ptr %red, align 4
  %div = sdiv i32 %9, 3
  %mul10 = mul nsw i32 %div, 1024
  %10 = load i32, ptr %green, align 4
  %div11 = sdiv i32 %10, 3
  %mul12 = mul nsw i32 %div11, 32
  %add13 = add nsw i32 %mul10, %mul12
  %11 = load i32, ptr %blue, align 4
  %div14 = sdiv i32 %11, 3
  %add15 = add nsw i32 %add13, %div14
  ret i32 %add15
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_7(i32 noundef %c0, i32 noundef %c1) #0 {
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
  %1 = load i32, ptr %c0.addr, align 4
  %and1 = and i32 %1, 31
  %add = add nsw i32 %and, %and1
  %2 = load i32, ptr %c1.addr, align 4
  %and2 = and i32 %2, 31
  %add3 = add nsw i32 %add, %and2
  store i32 %add3, ptr %blue, align 4
  %3 = load i32, ptr %c0.addr, align 4
  %and4 = and i32 %3, 992
  %4 = load i32, ptr %c0.addr, align 4
  %and5 = and i32 %4, 992
  %add6 = add nsw i32 %and4, %and5
  %5 = load i32, ptr %c1.addr, align 4
  %and7 = and i32 %5, 992
  %add8 = add nsw i32 %add6, %and7
  %shr = ashr i32 %add8, 5
  store i32 %shr, ptr %green, align 4
  %6 = load i32, ptr %c0.addr, align 4
  %shr9 = ashr i32 %6, 10
  %7 = load i32, ptr %c0.addr, align 4
  %shr10 = ashr i32 %7, 10
  %add11 = add nsw i32 %shr9, %shr10
  %8 = load i32, ptr %c1.addr, align 4
  %shr12 = ashr i32 %8, 10
  %add13 = add nsw i32 %add11, %shr12
  store i32 %add13, ptr %red, align 4
  %9 = load i32, ptr %red, align 4
  %div = sdiv i32 %9, 3
  %mul = mul nsw i32 %div, 1024
  %10 = load i32, ptr %green, align 4
  %div14 = sdiv i32 %10, 3
  %mul15 = mul nsw i32 %div14, 32
  %add16 = add nsw i32 %mul, %mul15
  %11 = load i32, ptr %blue, align 4
  %div17 = sdiv i32 %11, 3
  %add18 = add nsw i32 %add16, %div17
  ret i32 %add18
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
