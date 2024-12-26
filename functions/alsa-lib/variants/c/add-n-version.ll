; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/2_add.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/2_add.run.c"
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
  br label %comparisons

comparisons:                                      ; preds = %entry
  %12 = icmp eq i32 %2, %3
  br i1 %12, label %true, label %error

true:                                             ; preds = %comparisons
  %13 = icmp eq i32 %2, %4
  br i1 %13, label %true1, label %error

true1:                                            ; preds = %true
  %14 = icmp eq i32 %2, %5
  br i1 %14, label %true2, label %error

true2:                                            ; preds = %true1
  %15 = icmp eq i32 %2, %6
  br i1 %15, label %true3, label %error

true3:                                            ; preds = %true2
  %16 = icmp eq i32 %2, %7
  br i1 %16, label %true4, label %error

true4:                                            ; preds = %true3
  %17 = icmp eq i32 %2, %8
  br i1 %17, label %true5, label %error

true5:                                            ; preds = %true4
  %18 = icmp eq i32 %2, %9
  br i1 %18, label %true6, label %error

true6:                                            ; preds = %true5
  %19 = icmp eq i32 %2, %10
  br i1 %19, label %true7, label %error

true7:                                            ; preds = %true6
  %20 = icmp eq i32 %2, %11
  br i1 %20, label %true8, label %error

true8:                                            ; preds = %true7
  ret i32 %2

error:                                            ; preds = %true7, %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_2(i32 noundef %a, i32 noundef %b) #0 {
entry:
  %retval = alloca i32, align 4
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  %sum = alloca i32, align 4
  store i32 %a, ptr %a.addr, align 4
  store i32 %b, ptr %b.addr, align 4
  %0 = load i32, ptr %a.addr, align 4
  %1 = load i32, ptr %b.addr, align 4
  %add = add i32 %0, %1
  store i32 %add, ptr %sum, align 4
  %2 = load i32, ptr %sum, align 4
  %3 = load i32, ptr %b.addr, align 4
  %cmp = icmp ult i32 %2, %3
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 -1, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %4 = load i32, ptr %sum, align 4
  store i32 %4, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end, %if.then
  %5 = load i32, ptr %retval, align 4
  ret i32 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_3(i32 noundef %a, i32 noundef %b) #0 {
entry:
  %retval = alloca i32, align 4
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  %sum = alloca i32, align 4
  store i32 %a, ptr %a.addr, align 4
  store i32 %b, ptr %b.addr, align 4
  %0 = load i32, ptr %b.addr, align 4
  %cmp = icmp eq i32 %0, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %1 = load i32, ptr %a.addr, align 4
  store i32 %1, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %2 = load i32, ptr %a.addr, align 4
  %3 = load i32, ptr %b.addr, align 4
  %add = add i32 %2, %3
  store i32 %add, ptr %sum, align 4
  %4 = load i32, ptr %sum, align 4
  %5 = load i32, ptr %a.addr, align 4
  %cmp1 = icmp ult i32 %4, %5
  br i1 %cmp1, label %if.then3, label %lor.lhs.false

lor.lhs.false:                                    ; preds = %if.end
  %6 = load i32, ptr %sum, align 4
  %7 = load i32, ptr %b.addr, align 4
  %cmp2 = icmp ult i32 %6, %7
  br i1 %cmp2, label %if.then3, label %if.end4

if.then3:                                         ; preds = %lor.lhs.false, %if.end
  store i32 -1, ptr %retval, align 4
  br label %return

if.end4:                                          ; preds = %lor.lhs.false
  %8 = load i32, ptr %sum, align 4
  store i32 %8, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end4, %if.then3, %if.then
  %9 = load i32, ptr %retval, align 4
  ret i32 %9
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_4(i32 noundef %a, i32 noundef %b) #0 {
entry:
  %retval = alloca i32, align 4
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  store i32 %a, ptr %a.addr, align 4
  store i32 %b, ptr %b.addr, align 4
  %0 = load i32, ptr %b.addr, align 4
  %conv = zext i32 %0 to i64
  %1 = load i32, ptr %a.addr, align 4
  %conv1 = zext i32 %1 to i64
  %sub = sub nsw i64 4294967295, %conv1
  %cmp = icmp sgt i64 %conv, %sub
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 -1, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %2 = load i32, ptr %a.addr, align 4
  %3 = load i32, ptr %b.addr, align 4
  %add = add i32 %2, %3
  store i32 %add, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end, %if.then
  %4 = load i32, ptr %retval, align 4
  ret i32 %4
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_5(i32 noundef %a, i32 noundef %b) #0 {
entry:
  %retval = alloca i32, align 4
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  %sum = alloca i64, align 8
  store i32 %a, ptr %a.addr, align 4
  store i32 %b, ptr %b.addr, align 4
  %0 = load i32, ptr %a.addr, align 4
  %conv = zext i32 %0 to i64
  %1 = load i32, ptr %b.addr, align 4
  %conv1 = zext i32 %1 to i64
  %add = add i64 %conv, %conv1
  store i64 %add, ptr %sum, align 8
  %2 = load i64, ptr %sum, align 8
  %cmp = icmp ugt i64 %2, 4294967295
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 -1, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %3 = load i64, ptr %sum, align 8
  %conv3 = trunc i64 %3 to i32
  store i32 %conv3, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end, %if.then
  %4 = load i32, ptr %retval, align 4
  ret i32 %4
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_6(i32 noundef %a, i32 noundef %b) #0 {
entry:
  %retval = alloca i32, align 4
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  %sum = alloca i32, align 4
  store i32 %a, ptr %a.addr, align 4
  store i32 %b, ptr %b.addr, align 4
  %0 = load i32, ptr %a.addr, align 4
  %1 = load i32, ptr %b.addr, align 4
  %add = add i32 %0, %1
  store i32 %add, ptr %sum, align 4
  %2 = load i32, ptr %sum, align 4
  %3 = load i32, ptr %a.addr, align 4
  %cmp = icmp ult i32 %2, %3
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 -1, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %4 = load i32, ptr %sum, align 4
  store i32 %4, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end, %if.then
  %5 = load i32, ptr %retval, align 4
  ret i32 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_7(i32 noundef %a, i32 noundef %b) #0 {
entry:
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  store i32 %a, ptr %a.addr, align 4
  store i32 %b, ptr %b.addr, align 4
  %0 = load i32, ptr %a.addr, align 4
  %conv = zext i32 %0 to i64
  %1 = load i32, ptr %b.addr, align 4
  %conv1 = zext i32 %1 to i64
  %sub = sub nsw i64 4294967295, %conv1
  %cmp = icmp sgt i64 %conv, %sub
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  br label %cond.end

cond.false:                                       ; preds = %entry
  %2 = load i32, ptr %a.addr, align 4
  %3 = load i32, ptr %b.addr, align 4
  %add = add i32 %2, %3
  %conv3 = zext i32 %add to i64
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i64 [ 4294967295, %cond.true ], [ %conv3, %cond.false ]
  %conv4 = trunc i64 %cond to i32
  ret i32 %conv4
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_8(i32 noundef %a, i32 noundef %b) #0 {
entry:
  %retval = alloca i32, align 4
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  %sum = alloca i32, align 4
  store i32 %a, ptr %a.addr, align 4
  store i32 %b, ptr %b.addr, align 4
  %0 = load i32, ptr %a.addr, align 4
  %and = and i32 %0, -2147483648
  %tobool = icmp ne i32 %and, 0
  br i1 %tobool, label %land.lhs.true, label %if.end

land.lhs.true:                                    ; preds = %entry
  %1 = load i32, ptr %b.addr, align 4
  %and1 = and i32 %1, -2147483648
  %tobool2 = icmp ne i32 %and1, 0
  br i1 %tobool2, label %if.then, label %if.end

if.then:                                          ; preds = %land.lhs.true
  store i32 -1, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %land.lhs.true, %entry
  %2 = load i32, ptr %a.addr, align 4
  %3 = load i32, ptr %b.addr, align 4
  %add = add i32 %2, %3
  store i32 %add, ptr %sum, align 4
  %4 = load i32, ptr %b.addr, align 4
  %cmp = icmp ugt i32 %4, 0
  br i1 %cmp, label %land.lhs.true3, label %if.end6

land.lhs.true3:                                   ; preds = %if.end
  %5 = load i32, ptr %sum, align 4
  %6 = load i32, ptr %a.addr, align 4
  %cmp4 = icmp ult i32 %5, %6
  br i1 %cmp4, label %if.then5, label %if.end6

if.then5:                                         ; preds = %land.lhs.true3
  store i32 -1, ptr %retval, align 4
  br label %return

if.end6:                                          ; preds = %land.lhs.true3, %if.end
  %7 = load i32, ptr %sum, align 4
  store i32 %7, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end6, %if.then5, %if.then
  %8 = load i32, ptr %retval, align 4
  ret i32 %8
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_9(i32 noundef %a, i32 noundef %b) #0 {
entry:
  %retval = alloca i32, align 4
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  %sum = alloca i32, align 4
  store i32 %a, ptr %a.addr, align 4
  store i32 %b, ptr %b.addr, align 4
  %0 = load i32, ptr %a.addr, align 4
  %1 = load i32, ptr %b.addr, align 4
  %and = and i32 %0, %1
  %and1 = and i32 %and, -2147483648
  %cmp = icmp eq i32 %and1, -2147483648
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 -1, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %2 = load i32, ptr %a.addr, align 4
  %3 = load i32, ptr %b.addr, align 4
  %add = add i32 %2, %3
  store i32 %add, ptr %sum, align 4
  %4 = load i32, ptr %sum, align 4
  %5 = load i32, ptr %a.addr, align 4
  %cmp2 = icmp ult i32 %4, %5
  br i1 %cmp2, label %if.then3, label %if.end4

if.then3:                                         ; preds = %if.end
  store i32 -1, ptr %retval, align 4
  br label %return

if.end4:                                          ; preds = %if.end
  %6 = load i32, ptr %sum, align 4
  store i32 %6, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end4, %if.then3, %if.then
  %7 = load i32, ptr %retval, align 4
  ret i32 %7
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_10(i32 noundef %a, i32 noundef %b) #0 {
entry:
  %retval = alloca i32, align 4
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  %sum = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 %a, ptr %a.addr, align 4
  store i32 %b, ptr %b.addr, align 4
  %0 = load i32, ptr %a.addr, align 4
  store i32 %0, ptr %sum, align 4
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %1 = load i32, ptr %i, align 4
  %2 = load i32, ptr %b.addr, align 4
  %cmp = icmp ult i32 %1, %2
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %3 = load i32, ptr %sum, align 4
  %conv = zext i32 %3 to i64
  %cmp1 = icmp eq i64 %conv, 4294967295
  br i1 %cmp1, label %if.then, label %if.end

if.then:                                          ; preds = %for.body
  store i32 -1, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %for.body
  %4 = load i32, ptr %sum, align 4
  %inc = add i32 %4, 1
  store i32 %inc, ptr %sum, align 4
  br label %for.inc

for.inc:                                          ; preds = %if.end
  %5 = load i32, ptr %i, align 4
  %inc3 = add i32 %5, 1
  store i32 %inc3, ptr %i, align 4
  br label %for.cond, !llvm.loop !8

for.end:                                          ; preds = %for.cond
  %6 = load i32, ptr %sum, align 4
  store i32 %6, ptr %retval, align 4
  br label %return

return:                                           ; preds = %for.end, %if.then
  %7 = load i32, ptr %retval, align 4
  ret i32 %7
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_1(i32 noundef %a, i32 noundef %b) #0 {
entry:
  %retval = alloca i32, align 4
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  store i32 %a, ptr %a.addr, align 4
  store i32 %b, ptr %b.addr, align 4
  %0 = load i32, ptr %a.addr, align 4
  %conv = zext i32 %0 to i64
  %1 = load i32, ptr %b.addr, align 4
  %conv1 = zext i32 %1 to i64
  %sub = sub nsw i64 4294967295, %conv1
  %cmp = icmp sge i64 %conv, %sub
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 -1, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %2 = load i32, ptr %a.addr, align 4
  %3 = load i32, ptr %b.addr, align 4
  %add = add i32 %2, %3
  store i32 %add, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end, %if.then
  %4 = load i32, ptr %retval, align 4
  ret i32 %4
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
