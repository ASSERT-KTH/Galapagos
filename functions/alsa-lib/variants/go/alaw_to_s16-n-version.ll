; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/0_alaw_to_s16.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/0_alaw_to_s16.run.c"
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
  br label %comparisons

comparisons:                                      ; preds = %entry
  %8 = icmp eq i32 %1, %2
  br i1 %8, label %true, label %error

true:                                             ; preds = %comparisons
  %9 = icmp eq i32 %1, %3
  br i1 %9, label %true1, label %error

true1:                                            ; preds = %true
  %10 = icmp eq i32 %1, %4
  br i1 %10, label %true2, label %error

true2:                                            ; preds = %true1
  %11 = icmp eq i32 %1, %5
  br i1 %11, label %true3, label %error

true3:                                            ; preds = %true2
  %12 = icmp eq i32 %1, %6
  br i1 %12, label %true4, label %error

true4:                                            ; preds = %true3
  %13 = icmp eq i32 %1, %7
  br i1 %13, label %true5, label %error

true5:                                            ; preds = %true4
  ret i32 %1

error:                                            ; preds = %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_2(i8 noundef zeroext %aVal) #0 {
entry:
  %xor.0 = and i8 %aVal, 127
  %iand.0 = xor i8 %xor.0, 85
  %zext.0 = zext i8 %iand.0 to i32
  %icmp.6 = icmp ult i8 %iand.0, 16
  br i1 %icmp.6, label %then.0, label %else.0

then.0:                                           ; preds = %entry
  %mul.0 = shl nuw nsw i32 %zext.0, 4
  %add.0 = or i32 %mul.0, 8
  br label %fallthrough.0

fallthrough.0:                                    ; preds = %else.0, %then.0
  %t.0 = phi i32 [ %add.0, %then.0 ], [ %shl.0, %else.0 ]
  %icmp.7.not = icmp sgt i8 %aVal, -1
  %sub.2 = sub i32 0, %t.0
  %common.ret.op = select i1 %icmp.7.not, i32 %sub.2, i32 %t.0
  ret i32 %common.ret.op

else.0:                                           ; preds = %entry
  %div.0 = lshr i32 %zext.0, 4
  %mod.0 = shl nuw nsw i32 %zext.0, 4
  %mul.1 = and i32 %mod.0, 240
  %add.1 = or i32 %mul.1, 264
  %sub.1 = add nsw i32 %div.0, -1
  %shl.0 = shl i32 %add.1, %sub.1
  br label %fallthrough.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_3(i8 noundef zeroext %aVal) #0 {
entry:
  %xor.0 = and i8 %aVal, 127
  %iand.0 = xor i8 %xor.0, 85
  %zext.0 = zext i8 %iand.0 to i32
  %icmp.2 = icmp ugt i8 %iand.0, 15
  br i1 %icmp.2, label %then.0, label %else.0

then.0:                                           ; preds = %entry
  %0 = lshr i32 %zext.0, 4
  %iand.2 = shl nuw nsw i32 %zext.0, 4
  %shl.0 = and i32 %iand.2, 240
  %add.0 = or i32 %shl.0, 264
  %sub.0 = add nsw i32 %0, -1
  %shl.1 = shl i32 %add.0, %sub.0
  br label %fallthrough.0

fallthrough.0:                                    ; preds = %else.0, %then.0
  %t.0 = phi i32 [ %shl.1, %then.0 ], [ %add.1, %else.0 ]
  %icmp.3.not = icmp sgt i8 %aVal, -1
  %sub.1 = sub i32 0, %t.0
  %common.ret.op = select i1 %icmp.3.not, i32 %sub.1, i32 %t.0
  ret i32 %common.ret.op

else.0:                                           ; preds = %entry
  %shl.2 = shl nuw nsw i32 %zext.0, 4
  %add.1 = or i32 %shl.2, 8
  br label %fallthrough.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_4(i8 noundef zeroext %aVal) #0 {
entry:
  %xor.0 = and i8 %aVal, 127
  %iand.0 = xor i8 %xor.0, 85
  %zext.0 = zext i8 %iand.0 to i32
  %icmp.6 = icmp ult i8 %iand.0, 16
  br i1 %icmp.6, label %then.0, label %else.0

then.0:                                           ; preds = %entry
  %mul.0 = shl nuw nsw i32 %zext.0, 4
  %add.0 = or i32 %mul.0, 8
  br label %fallthrough.0

fallthrough.0:                                    ; preds = %else.0, %then.0
  %t.0 = phi i32 [ %add.0, %then.0 ], [ %shl.0, %else.0 ]
  %icmp.7.not = icmp sgt i8 %aVal, -1
  %sub.2 = sub i32 0, %t.0
  %common.ret.op = select i1 %icmp.7.not, i32 %sub.2, i32 %t.0
  ret i32 %common.ret.op

else.0:                                           ; preds = %entry
  %div.0 = lshr i32 %zext.0, 4
  %mod.0 = shl nuw nsw i32 %zext.0, 4
  %mul.1 = and i32 %mod.0, 240
  %add.1 = or i32 %mul.1, 264
  %sub.1 = add nsw i32 %div.0, -1
  %shl.0 = shl i32 %add.1, %sub.1
  br label %fallthrough.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_5(i8 noundef zeroext %aVal) #0 {
entry:
  %xor.0 = and i8 %aVal, 127
  %iand.0 = xor i8 %xor.0, 85
  %zext.0 = zext i8 %iand.0 to i32
  %icmp.2 = icmp ult i8 %iand.0, 16
  br i1 %icmp.2, label %then.0, label %else.0

then.0:                                           ; preds = %entry
  %shl.0 = shl nuw nsw i32 %zext.0, 4
  %add.0 = or i32 %shl.0, 8
  br label %fallthrough.0

fallthrough.0:                                    ; preds = %else.0, %then.0
  %t.0 = phi i32 [ %add.0, %then.0 ], [ %shl.2, %else.0 ]
  %icmp.3.not = icmp sgt i8 %aVal, -1
  %sub.1 = sub i32 0, %t.0
  %common.ret.op = select i1 %icmp.3.not, i32 %sub.1, i32 %t.0
  ret i32 %common.ret.op

else.0:                                           ; preds = %entry
  %0 = lshr i32 %zext.0, 4
  %iand.2 = shl nuw nsw i32 %zext.0, 4
  %shl.1 = and i32 %iand.2, 240
  %add.1 = or i32 %shl.1, 264
  %sub.0 = add nsw i32 %0, -1
  %shl.2 = shl i32 %add.1, %sub.0
  br label %fallthrough.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_6(i8 noundef zeroext %aVal) #0 {
entry:
  %xor.0 = and i8 %aVal, 127
  %iand.0 = xor i8 %xor.0, 85
  %zext.0 = zext i8 %iand.0 to i32
  %icmp.0 = icmp ugt i8 %iand.0, 15
  br i1 %icmp.0, label %label.0, label %else.0

else.0:                                           ; preds = %entry
  %shl.0 = shl nuw nsw i32 %zext.0, 4
  %add.0 = or i32 %shl.0, 8
  br label %label.1

label.0:                                          ; preds = %entry
  %0 = lshr i32 %zext.0, 4
  %iand.2 = shl nuw nsw i32 %zext.0, 4
  %shl.1 = and i32 %iand.2, 240
  %add.1 = or i32 %shl.1, 264
  %sub.0 = add nsw i32 %0, -1
  %shl.2 = shl i32 %add.1, %sub.0
  br label %label.1

label.1:                                          ; preds = %label.0, %else.0
  %t.0 = phi i32 [ %shl.2, %label.0 ], [ %add.0, %else.0 ]
  %icmp.5.not = icmp sgt i8 %aVal, -1
  %sub.1 = sub i32 0, %t.0
  %common.ret.op = select i1 %icmp.5.not, i32 %sub.1, i32 %t.0
  ret i32 %common.ret.op
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_7(i8 noundef zeroext %aVal) #0 {
entry:
  %xor.0 = and i8 %aVal, 127
  %iand.0 = xor i8 %xor.0, 85
  %zext.0 = zext i8 %iand.0 to i32
  %icmp.2 = icmp ult i8 %iand.0, 16
  br i1 %icmp.2, label %then.0, label %else.0

then.0:                                           ; preds = %entry
  %shl.0 = shl nuw nsw i32 %zext.0, 4
  %add.0 = or i32 %shl.0, 8
  br label %fallthrough.0

fallthrough.0:                                    ; preds = %else.0, %then.0
  %t.0 = phi i32 [ %add.0, %then.0 ], [ %shl.2, %else.0 ]
  %icmp.3.not = icmp sgt i8 %aVal, -1
  %sub.1 = sub i32 0, %t.0
  %common.ret.op = select i1 %icmp.3.not, i32 %sub.1, i32 %t.0
  ret i32 %common.ret.op

else.0:                                           ; preds = %entry
  %0 = lshr i32 %zext.0, 4
  %iand.2 = shl nuw nsw i32 %zext.0, 4
  %shl.1 = and i32 %iand.2, 240
  %add.1 = or i32 %shl.1, 264
  %sub.0 = add nsw i32 %0, -1
  %shl.2 = shl i32 %add.1, %sub.0
  br label %fallthrough.0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @version_1(i8 noundef zeroext %a_val) #0 {
entry:
  %a_val.addr = alloca i8, align 1
  %t = alloca i32, align 4
  %seg = alloca i32, align 4
  store i8 %a_val, ptr %a_val.addr, align 1
  %0 = load i8, ptr %a_val.addr, align 1
  %conv = zext i8 %0 to i32
  %xor = xor i32 %conv, 85
  %conv1 = trunc i32 %xor to i8
  store i8 %conv1, ptr %a_val.addr, align 1
  %1 = load i8, ptr %a_val.addr, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 127
  store i32 %and, ptr %t, align 4
  %2 = load i32, ptr %t, align 4
  %cmp = icmp slt i32 %2, 16
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %3 = load i32, ptr %t, align 4
  %shl = shl i32 %3, 4
  %add = add nsw i32 %shl, 8
  store i32 %add, ptr %t, align 4
  br label %if.end

if.else:                                          ; preds = %entry
  %4 = load i32, ptr %t, align 4
  %shr = ashr i32 %4, 4
  %and4 = and i32 %shr, 7
  store i32 %and4, ptr %seg, align 4
  %5 = load i32, ptr %t, align 4
  %and5 = and i32 %5, 15
  %shl6 = shl i32 %and5, 4
  %add7 = add nsw i32 %shl6, 264
  store i32 %add7, ptr %t, align 4
  %6 = load i32, ptr %seg, align 4
  %sub = sub nsw i32 %6, 1
  %7 = load i32, ptr %t, align 4
  %shl8 = shl i32 %7, %sub
  store i32 %shl8, ptr %t, align 4
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  %8 = load i8, ptr %a_val.addr, align 1
  %conv9 = zext i8 %8 to i32
  %and10 = and i32 %conv9, 128
  %tobool = icmp ne i32 %and10, 0
  br i1 %tobool, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.end
  %9 = load i32, ptr %t, align 4
  br label %cond.end

cond.false:                                       ; preds = %if.end
  %10 = load i32, ptr %t, align 4
  %sub11 = sub nsw i32 0, %10
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %9, %cond.true ], [ %sub11, %cond.false ]
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
