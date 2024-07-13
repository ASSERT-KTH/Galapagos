; ModuleID = '/home/javier/Galapagos/miscompilation/bug-2/project/main.bc'
source_filename = "main.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@a = internal global i32 -3, align 4
@__const.foo.h = private unnamed_addr constant [2 x ptr] [ptr @a, ptr @a], align 16
@c = internal global i8 0, align 1
@b = internal global i32 0, align 4
@d = dso_local global i32 0, align 4
@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

; Function Attrs: nounwind optsize uwtable
define dso_local i32 @e(i32 noundef %f, i32 noundef %g) #0 {
entry:
  %retval = alloca i32, align 4
  %f.addr = alloca i32, align 4
  %g.addr = alloca i32, align 4
  store i32 %f, ptr %f.addr, align 4
  store i32 %g, ptr %g.addr, align 4
  %0 = load i32, ptr %f.addr, align 4
  %1 = load i32, ptr %g.addr, align 4
  %sub = sub nsw i32 %0, %1
  %cmp = icmp slt i32 %sub, 10000
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %f.addr, align 4
  store i32 %2, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %3 = load i32, ptr %f.addr, align 4
  %4 = load i32, ptr %f.addr, align 4
  %sub1 = sub nsw i32 0, %4
  %rem = srem i32 1, %sub1
  %add = add nsw i32 %3, %rem
  store i32 %add, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end, %if.then
  %5 = load i32, ptr %retval, align 4
  ret i32 %5
}

; Function Attrs: nounwind optsize uwtable
define dso_local i32 @n_version_call() #0 {
entry:
  %0 = call i32 @version_1()
  %1 = call i32 @version_2()
  %2 = call i32 @version_3()
  %3 = call i32 @version_4()
  %4 = call i32 @version_5()
  %5 = call i32 @version_6()
  %6 = call i32 @version_7()
  %7 = call i32 @version_8()
  %8 = call i32 @version_9()
  %9 = call i32 @version_10()
  %10 = call i32 @version_11()
  br label %comparisons

comparisons:                                      ; preds = %entry
  %11 = icmp eq i32 %0, %1
  br i1 %11, label %true, label %error

true:                                             ; preds = %comparisons
  %12 = icmp eq i32 %0, %2
  br i1 %12, label %true1, label %error

true1:                                            ; preds = %true
  %13 = icmp eq i32 %0, %3
  br i1 %13, label %true2, label %error

true2:                                            ; preds = %true1
  %14 = icmp eq i32 %0, %4
  br i1 %14, label %true3, label %error

true3:                                            ; preds = %true2
  %15 = icmp eq i32 %0, %5
  br i1 %15, label %true4, label %error

true4:                                            ; preds = %true3
  %16 = icmp eq i32 %0, %6
  br i1 %16, label %true5, label %error

true5:                                            ; preds = %true4
  %17 = icmp eq i32 %0, %7
  br i1 %17, label %true6, label %error

true6:                                            ; preds = %true5
  %18 = icmp eq i32 %0, %8
  br i1 %18, label %true7, label %error

true7:                                            ; preds = %true6
  %19 = icmp eq i32 %0, %9
  br i1 %19, label %true8, label %error

true8:                                            ; preds = %true7
  %20 = icmp eq i32 %0, %10
  br i1 %20, label %true9, label %error

true9:                                            ; preds = %true8
  ret i32 %0

error:                                            ; preds = %true8, %true7, %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_2(i32 noundef %0, i32 noundef %1) #1 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, ptr %3, align 4
  store i32 %1, ptr %4, align 4
  %5 = load i32, ptr %3, align 4
  %6 = load i32, ptr %4, align 4
  %7 = sub nsw i32 %5, %6
  %8 = icmp slt i32 %7, 10000
  br i1 %8, label %9, label %11

9:                                                ; preds = %2
  %10 = load i32, ptr %3, align 4
  br label %17

11:                                               ; preds = %2
  %12 = load i32, ptr %3, align 4
  %13 = load i32, ptr %3, align 4
  %14 = sub nsw i32 0, %13
  %15 = srem i32 1, %14
  %16 = add nsw i32 %12, %15
  br label %17

17:                                               ; preds = %11, %9
  %18 = phi i32 [ %10, %9 ], [ %16, %11 ]
  ret i32 %18
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_3(i32 noundef %0, i32 noundef %1) #1 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  %8 = load i32, ptr %4, align 4
  %9 = load i32, ptr %5, align 4
  %10 = sub nsw i32 %8, %9
  store i32 %10, ptr %6, align 4
  %11 = load i32, ptr %6, align 4
  %12 = icmp slt i32 %11, 10000
  br i1 %12, label %13, label %15

13:                                               ; preds = %2
  %14 = load i32, ptr %4, align 4
  store i32 %14, ptr %3, align 4
  br label %22

15:                                               ; preds = %2
  %16 = load i32, ptr %4, align 4
  %17 = load i32, ptr %4, align 4
  %18 = sub nsw i32 0, %17
  %19 = srem i32 1, %18
  %20 = add nsw i32 %16, %19
  store i32 %20, ptr %7, align 4
  %21 = load i32, ptr %7, align 4
  store i32 %21, ptr %3, align 4
  br label %22

22:                                               ; preds = %15, %13
  %23 = load i32, ptr %3, align 4
  ret i32 %23
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_4(i32 noundef %0, i32 noundef %1) #1 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  %6 = load i32, ptr %4, align 4
  %7 = load i32, ptr %5, align 4
  %8 = sub nsw i32 %6, %7
  %9 = icmp slt i32 %8, 10000
  br i1 %9, label %10, label %12

10:                                               ; preds = %2
  %11 = load i32, ptr %4, align 4
  store i32 %11, ptr %3, align 4
  br label %18

12:                                               ; preds = %2
  %13 = load i32, ptr %4, align 4
  %14 = load i32, ptr %4, align 4
  %15 = sub nsw i32 0, %14
  %16 = srem i32 1, %15
  %17 = add nsw i32 %13, %16
  store i32 %17, ptr %3, align 4
  br label %18

18:                                               ; preds = %12, %10
  %19 = load i32, ptr %3, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_5(i32 noundef %0, i32 noundef %1) #1 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  %7 = load i32, ptr %4, align 4
  %8 = load i32, ptr %5, align 4
  %9 = sub nsw i32 %7, %8
  store i32 %9, ptr %6, align 4
  %10 = load i32, ptr %6, align 4
  %11 = icmp slt i32 %10, 10000
  br i1 %11, label %12, label %14

12:                                               ; preds = %2
  %13 = load i32, ptr %4, align 4
  store i32 %13, ptr %3, align 4
  br label %20

14:                                               ; preds = %2
  %15 = load i32, ptr %4, align 4
  %16 = load i32, ptr %4, align 4
  %17 = sub nsw i32 0, %16
  %18 = srem i32 1, %17
  %19 = add nsw i32 %15, %18
  store i32 %19, ptr %3, align 4
  br label %20

20:                                               ; preds = %14, %12
  %21 = load i32, ptr %3, align 4
  ret i32 %21
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_6(i32 noundef %0, i32 noundef %1) #1 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  %6 = load i32, ptr %4, align 4
  %7 = load i32, ptr %5, align 4
  %8 = sub nsw i32 %6, %7
  %9 = icmp sge i32 %8, 10000
  br i1 %9, label %10, label %16

10:                                               ; preds = %2
  %11 = load i32, ptr %4, align 4
  %12 = load i32, ptr %4, align 4
  %13 = sub nsw i32 0, %12
  %14 = srem i32 1, %13
  %15 = add nsw i32 %11, %14
  store i32 %15, ptr %3, align 4
  br label %18

16:                                               ; preds = %2
  %17 = load i32, ptr %4, align 4
  store i32 %17, ptr %3, align 4
  br label %18

18:                                               ; preds = %16, %10
  %19 = load i32, ptr %3, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_7(i32 noundef %0, i32 noundef %1) #1 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  %6 = load i32, ptr %4, align 4
  %7 = load i32, ptr %5, align 4
  %8 = sub nsw i32 %6, %7
  %9 = icmp slt i32 %8, 10000
  br i1 %9, label %10, label %12

10:                                               ; preds = %2
  %11 = load i32, ptr %4, align 4
  store i32 %11, ptr %3, align 4
  br label %18

12:                                               ; preds = %2
  %13 = load i32, ptr %4, align 4
  %14 = load i32, ptr %4, align 4
  %15 = sub nsw i32 0, %14
  %16 = srem i32 1, %15
  %17 = add nsw i32 %13, %16
  store i32 %17, ptr %3, align 4
  br label %18

18:                                               ; preds = %12, %10
  %19 = load i32, ptr %3, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_8(i32 noundef %0, i32 noundef %1) #1 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, ptr %3, align 4
  store i32 %1, ptr %4, align 4
  %5 = load i32, ptr %3, align 4
  %6 = load i32, ptr %4, align 4
  %7 = sub nsw i32 %5, %6
  %8 = icmp slt i32 %7, 10000
  br i1 %8, label %9, label %11

9:                                                ; preds = %2
  %10 = load i32, ptr %3, align 4
  br label %17

11:                                               ; preds = %2
  %12 = load i32, ptr %3, align 4
  %13 = load i32, ptr %3, align 4
  %14 = sub nsw i32 0, %13
  %15 = srem i32 1, %14
  %16 = add nsw i32 %12, %15
  br label %17

17:                                               ; preds = %11, %9
  %18 = phi i32 [ %10, %9 ], [ %16, %11 ]
  ret i32 %18
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_9(i32 noundef %0, i32 noundef %1) #1 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  %8 = load i32, ptr %4, align 4
  %9 = load i32, ptr %5, align 4
  %10 = sub nsw i32 %8, %9
  store i32 %10, ptr %6, align 4
  %11 = load i32, ptr %6, align 4
  %12 = icmp slt i32 %11, 10000
  br i1 %12, label %13, label %15

13:                                               ; preds = %2
  %14 = load i32, ptr %4, align 4
  store i32 %14, ptr %3, align 4
  br label %22

15:                                               ; preds = %2
  %16 = load i32, ptr %4, align 4
  %17 = sub nsw i32 0, %16
  %18 = srem i32 1, %17
  store i32 %18, ptr %7, align 4
  %19 = load i32, ptr %4, align 4
  %20 = load i32, ptr %7, align 4
  %21 = add nsw i32 %19, %20
  store i32 %21, ptr %3, align 4
  br label %22

22:                                               ; preds = %15, %13
  %23 = load i32, ptr %3, align 4
  ret i32 %23
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_10(i32 noundef %0, i32 noundef %1) #1 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  %6 = load i32, ptr %4, align 4
  %7 = load i32, ptr %5, align 4
  %8 = sub nsw i32 %6, %7
  %9 = icmp slt i32 %8, 10000
  br i1 %9, label %10, label %12

10:                                               ; preds = %2
  %11 = load i32, ptr %4, align 4
  store i32 %11, ptr %3, align 4
  br label %18

12:                                               ; preds = %2
  %13 = load i32, ptr %4, align 4
  %14 = load i32, ptr %4, align 4
  %15 = sub nsw i32 0, %14
  %16 = srem i32 1, %15
  %17 = add nsw i32 %13, %16
  store i32 %17, ptr %3, align 4
  br label %18

18:                                               ; preds = %12, %10
  %19 = load i32, ptr %3, align 4
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_11(i32 noundef %0, i32 noundef %1) #1 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 %0, ptr %3, align 4
  store i32 %1, ptr %4, align 4
  %6 = load i32, ptr %3, align 4
  store i32 %6, ptr %5, align 4
  %7 = load i32, ptr %3, align 4
  %8 = load i32, ptr %4, align 4
  %9 = sub nsw i32 %7, %8
  %10 = icmp sge i32 %9, 10000
  br i1 %10, label %11, label %17

11:                                               ; preds = %2
  %12 = load i32, ptr %3, align 4
  %13 = load i32, ptr %3, align 4
  %14 = sub nsw i32 0, %13
  %15 = srem i32 1, %14
  %16 = add nsw i32 %12, %15
  store i32 %16, ptr %5, align 4
  br label %17

17:                                               ; preds = %11, %2
  %18 = load i32, ptr %5, align 4
  ret i32 %18
}

; Function Attrs: nounwind optsize uwtable
define dso_local i32 @version_1() #0 {
entry:
  %h = alloca [2 x ptr], align 16
  %i = alloca ptr, align 8
  call void @llvm.lifetime.start.p0(i64 16, ptr %h) #6
  call void @llvm.memcpy.p0.p0.i64(ptr align 16 %h, ptr align 16 @__const.foo.h, i64 16, i1 false)
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %0 = load i8, ptr @c, align 1
  %conv = sext i8 %0 to i32
  %cmp = icmp sle i32 %conv, 37
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  call void @llvm.lifetime.start.p0(i64 8, ptr %i) #6
  store ptr @b, ptr %i, align 8
  %1 = load i32, ptr @a, align 4
  %call = call i32 @e(i32 noundef %1, i32 noundef 8) #7
  %2 = load i32, ptr @d, align 4
  %add = add nsw i32 %call, %2
  %3 = load ptr, ptr %i, align 8
  %4 = load i32, ptr %3, align 4
  %or = or i32 %4, %add
  store i32 %or, ptr %3, align 4
  call void @llvm.lifetime.end.p0(i64 8, ptr %i) #6
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %5 = load i8, ptr @c, align 1
  %inc = add i8 %5, 1
  store i8 %inc, ptr @c, align 1
  br label %for.cond, !llvm.loop !5

for.end:                                          ; preds = %for.cond
  %6 = load i32, ptr @b, align 4
  call void @llvm.lifetime.end.p0(i64 16, ptr %h) #6
  ret i32 %6
}

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #2

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: readwrite)
declare void @llvm.memcpy.p0.p0.i64(ptr noalias nocapture writeonly, ptr noalias nocapture readonly, i64, i1 immarg) #3

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.end.p0(i64 immarg, ptr nocapture) #2

; Function Attrs: nounwind optsize uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @n_version_call() #7
  %call1 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %call) #7
  ret i32 0
}

; Function Attrs: optsize
declare i32 @printf(ptr noundef, ...) #4

; Function Attrs: cold noreturn nounwind
declare void @llvm.trap() #5

attributes #0 = { nounwind optsize uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }
attributes #3 = { nocallback nofree nounwind willreturn memory(argmem: readwrite) }
attributes #4 = { optsize "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { cold noreturn nounwind }
attributes #6 = { nounwind }
attributes #7 = { optsize }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"clang version 17.0.0 (git@github.com:llvm/llvm-project.git 1a7a00bdc99fa2b2ca19ecd2d1069991b3c1006b)"}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.mustprogress"}
