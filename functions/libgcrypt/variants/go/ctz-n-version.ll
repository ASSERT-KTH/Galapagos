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
  %11 = call i32 @version_11(i64 %0)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %12 = icmp eq i32 %1, %2
  br i1 %12, label %true, label %error

true:                                             ; preds = %comparisons
  %13 = icmp eq i32 %1, %3
  br i1 %13, label %true1, label %error

true1:                                            ; preds = %true
  %14 = icmp eq i32 %1, %4
  br i1 %14, label %true2, label %error

true2:                                            ; preds = %true1
  %15 = icmp eq i32 %1, %5
  br i1 %15, label %true3, label %error

true3:                                            ; preds = %true2
  %16 = icmp eq i32 %1, %6
  br i1 %16, label %true4, label %error

true4:                                            ; preds = %true3
  %17 = icmp eq i32 %1, %7
  br i1 %17, label %true5, label %error

true5:                                            ; preds = %true4
  %18 = icmp eq i32 %1, %8
  br i1 %18, label %true6, label %error

true6:                                            ; preds = %true5
  %19 = icmp eq i32 %1, %9
  br i1 %19, label %true7, label %error

true7:                                            ; preds = %true6
  %20 = icmp eq i32 %1, %10
  br i1 %20, label %true8, label %error

true8:                                            ; preds = %true7
  %21 = icmp eq i32 %1, %11
  br i1 %21, label %true9, label %error

true9:                                            ; preds = %true8
  ret i32 %1

error:                                            ; preds = %true8, %true7, %true6, %true5, %true4, %true3, %true2, %true1, %true, %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_2(i64 noundef %in) #0 {
entry:
  br label %then.2

common.ret.split.loop.exit13:                     ; preds = %then.2, %else.1.2, %else.1.1, %else.1
  %indvars.iv.lcssa = phi i64 [ %indvars.iv, %then.2 ], [ %indvars.iv.next, %else.1 ], [ %indvars.iv.next.1, %else.1.1 ], [ %indvars.iv.next.2, %else.1.2 ]
  %0 = trunc i64 %indvars.iv.lcssa to i32
  br label %common.ret

common.ret:                                       ; preds = %else.1.3, %common.ret.split.loop.exit13
  %common.ret.op = phi i32 [ %0, %common.ret.split.loop.exit13 ], [ 64, %else.1.3 ]
  ret i32 %common.ret.op

else.1:                                           ; preds = %then.2
  %indvars.iv.next = or i64 %indvars.iv, 1
  %1 = shl nuw i64 1, %indvars.iv.next
  %2 = and i64 %1, %in
  %icmp.1.not.1 = icmp eq i64 %2, 0
  br i1 %icmp.1.not.1, label %else.1.1, label %common.ret.split.loop.exit13

else.1.1:                                         ; preds = %else.1
  %indvars.iv.next.1 = or i64 %indvars.iv, 2
  %3 = shl nuw i64 1, %indvars.iv.next.1
  %4 = and i64 %3, %in
  %icmp.1.not.2 = icmp eq i64 %4, 0
  br i1 %icmp.1.not.2, label %else.1.2, label %common.ret.split.loop.exit13

else.1.2:                                         ; preds = %else.1.1
  %indvars.iv.next.2 = or i64 %indvars.iv, 3
  %5 = shl nuw i64 1, %indvars.iv.next.2
  %6 = and i64 %5, %in
  %icmp.1.not.3 = icmp eq i64 %6, 0
  br i1 %icmp.1.not.3, label %else.1.3, label %common.ret.split.loop.exit13

else.1.3:                                         ; preds = %else.1.2
  %indvars.iv.next.3 = add nuw nsw i64 %indvars.iv, 4
  %exitcond.not.3 = icmp eq i64 %indvars.iv.next.3, 64
  br i1 %exitcond.not.3, label %common.ret, label %then.2

then.2:                                           ; preds = %else.1.3, %entry
  %indvars.iv = phi i64 [ 0, %entry ], [ %indvars.iv.next.3, %else.1.3 ]
  %7 = shl nuw i64 1, %indvars.iv
  %8 = and i64 %7, %in
  %icmp.1.not = icmp eq i64 %8, 0
  br i1 %icmp.1.not, label %else.1, label %common.ret.split.loop.exit13
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_3(i64 noundef %in) #0 {
entry:
  br label %then.2

else.1:                                           ; preds = %then.2
  %add.1 = or i64 %i.09, 1
  %shl.0.1 = shl nuw i64 1, %add.1
  %iand.0.1 = and i64 %shl.0.1, %in
  %icmp.1.not.1 = icmp eq i64 %iand.0.1, 0
  br i1 %icmp.1.not.1, label %else.1.1, label %label.2.split.loop.exit11

else.1.1:                                         ; preds = %else.1
  %add.1.1 = or i64 %i.09, 2
  %shl.0.2 = shl nuw i64 1, %add.1.1
  %iand.0.2 = and i64 %shl.0.2, %in
  %icmp.1.not.2 = icmp eq i64 %iand.0.2, 0
  br i1 %icmp.1.not.2, label %else.1.2, label %label.2.split.loop.exit11

else.1.2:                                         ; preds = %else.1.1
  %add.1.2 = or i64 %i.09, 3
  %shl.0.3 = shl nuw i64 1, %add.1.2
  %iand.0.3 = and i64 %shl.0.3, %in
  %icmp.1.not.3 = icmp eq i64 %iand.0.3, 0
  br i1 %icmp.1.not.3, label %else.1.3, label %label.2.split.loop.exit11

else.1.3:                                         ; preds = %else.1.2
  %add.1.3 = add nuw nsw i64 %i.09, 4
  %exitcond.not.3 = icmp eq i64 %add.1.3, 64
  br i1 %exitcond.not.3, label %label.2, label %then.2

label.2.split.loop.exit11:                        ; preds = %then.2, %else.1.2, %else.1.1, %else.1
  %i.09.lcssa = phi i64 [ %i.09, %then.2 ], [ %add.1, %else.1 ], [ %add.1.1, %else.1.1 ], [ %add.1.2, %else.1.2 ]
  %indvars10.le = trunc i64 %i.09.lcssa to i32
  br label %label.2

label.2:                                          ; preds = %label.2.split.loop.exit11, %else.1.3
  %r.0.lcssa = phi i32 [ %indvars10.le, %label.2.split.loop.exit11 ], [ 64, %else.1.3 ]
  ret i32 %r.0.lcssa

then.2:                                           ; preds = %else.1.3, %entry
  %i.09 = phi i64 [ 0, %entry ], [ %add.1.3, %else.1.3 ]
  %shl.0 = shl nuw i64 1, %i.09
  %iand.0 = and i64 %shl.0, %in
  %icmp.1.not = icmp eq i64 %iand.0, 0
  br i1 %icmp.1.not, label %else.1, label %label.2.split.loop.exit11
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_4(i64 noundef %in) #0 {
entry:
  %iand.07 = and i64 %in, 1
  %icmp.08 = icmp eq i64 %iand.07, 0
  br i1 %icmp.08, label %then.1, label %else.1

then.1:                                           ; preds = %then.1, %entry
  %r.010 = phi i32 [ %add.0, %then.1 ], [ 0, %entry ]
  %in.addr.09 = phi i64 [ %shr.0, %then.1 ], [ %in, %entry ]
  %shr.0 = lshr i64 %in.addr.09, 1
  %add.0 = add nuw nsw i32 %r.010, 1
  %0 = and i64 %in.addr.09, 2
  %icmp.0 = icmp eq i64 %0, 0
  %icmp.1 = icmp ult i32 %r.010, 63
  %spec.select = select i1 %icmp.0, i1 %icmp.1, i1 false
  br i1 %spec.select, label %then.1, label %else.1

else.1:                                           ; preds = %then.1, %entry
  %r.0.lcssa = phi i32 [ 0, %entry ], [ %add.0, %then.1 ]
  ret i32 %r.0.lcssa
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_5(i64 noundef %in) #0 {
entry:
  %icmp.0 = icmp eq i64 %in, 0
  %xor.0 = xor i64 %in, -1
  %sub.0 = add i64 %in, 4294967295
  %iand.0 = and i64 %sub.0, %xor.0
  %0 = trunc i64 %iand.0 to i32
  %trunc.1 = add i32 %0, 1
  %common.ret.op = select i1 %icmp.0, i32 64, i32 %trunc.1
  ret i32 %common.ret.op
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_6(i64 noundef %in) #0 {
entry:
  %icmp.0 = icmp eq i64 %in, 0
  br i1 %icmp.0, label %common.ret, label %label.0.preheader

label.0.preheader:                                ; preds = %entry
  %iand.013 = and i64 %in, 1
  %icmp.314 = icmp eq i64 %iand.013, 0
  br i1 %icmp.314, label %then.3, label %common.ret

common.ret.loopexit:                              ; preds = %then.3
  %indvars = trunc i64 %add.1 to i32
  br label %common.ret

common.ret:                                       ; preds = %common.ret.loopexit, %label.0.preheader, %entry
  %common.ret.op = phi i32 [ 64, %entry ], [ 0, %label.0.preheader ], [ %indvars, %common.ret.loopexit ]
  ret i32 %common.ret.op

then.3:                                           ; preds = %then.3, %label.0.preheader
  %i.016 = phi i64 [ %add.1, %then.3 ], [ 0, %label.0.preheader ]
  %add.1 = add nuw nsw i64 %i.016, 1
  %icmp.1 = icmp ult i64 %i.016, 63
  %shl.0 = shl i64 2, %i.016
  %iand.0 = and i64 %shl.0, %in
  %icmp.3 = icmp eq i64 %iand.0, 0
  %tmpv.0.0.in = select i1 %icmp.1, i1 %icmp.3, i1 false
  br i1 %tmpv.0.0.in, label %then.3, label %common.ret.loopexit
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_7(i64 noundef %in) #0 {
entry:
  %icmp.0 = icmp eq i64 %in, 0
  br i1 %icmp.0, label %common.ret, label %label.0.preheader

label.0.preheader:                                ; preds = %entry
  %iand.09 = and i64 %in, 1
  %icmp.110 = icmp eq i64 %iand.09, 0
  br i1 %icmp.110, label %then.1, label %common.ret

common.ret:                                       ; preds = %then.1, %label.0.preheader, %entry
  %common.ret.op = phi i32 [ 64, %entry ], [ 0, %label.0.preheader ], [ %add.0, %then.1 ]
  ret i32 %common.ret.op

then.1:                                           ; preds = %then.1, %label.0.preheader
  %r.012 = phi i32 [ %add.0, %then.1 ], [ 0, %label.0.preheader ]
  %in.addr.011 = phi i64 [ %shr.0, %then.1 ], [ %in, %label.0.preheader ]
  %add.0 = add i32 %r.012, 1
  %shr.0 = lshr i64 %in.addr.011, 1
  %0 = and i64 %in.addr.011, 2
  %icmp.1 = icmp eq i64 %0, 0
  br i1 %icmp.1, label %then.1, label %common.ret
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_8(i64 noundef %in) #0 {
entry:
  br label %then.3

else.2:                                           ; preds = %then.3
  %add.1 = or i64 %i.010, 1
  %0 = shl nuw i64 1, %add.1
  %1 = and i64 %0, %in
  %icmp.2.not.1 = icmp eq i64 %1, 0
  br i1 %icmp.2.not.1, label %else.2.1, label %label.2.split.loop.exit12

else.2.1:                                         ; preds = %else.2
  %add.1.1 = or i64 %i.010, 2
  %2 = shl nuw i64 1, %add.1.1
  %3 = and i64 %2, %in
  %icmp.2.not.2 = icmp eq i64 %3, 0
  br i1 %icmp.2.not.2, label %else.2.2, label %label.2.split.loop.exit12

else.2.2:                                         ; preds = %else.2.1
  %add.1.2 = or i64 %i.010, 3
  %4 = shl nuw i64 1, %add.1.2
  %5 = and i64 %4, %in
  %icmp.2.not.3 = icmp eq i64 %5, 0
  br i1 %icmp.2.not.3, label %else.2.3, label %label.2.split.loop.exit12

else.2.3:                                         ; preds = %else.2.2
  %add.1.3 = add nuw nsw i64 %i.010, 4
  %exitcond.not.3 = icmp eq i64 %add.1.3, 64
  br i1 %exitcond.not.3, label %label.2, label %then.3

label.2.split.loop.exit12:                        ; preds = %then.3, %else.2.2, %else.2.1, %else.2
  %i.010.lcssa = phi i64 [ %i.010, %then.3 ], [ %add.1, %else.2 ], [ %add.1.1, %else.2.1 ], [ %add.1.2, %else.2.2 ]
  %indvars11.le = trunc i64 %i.010.lcssa to i32
  br label %label.2

label.2:                                          ; preds = %label.2.split.loop.exit12, %else.2.3
  %r.0.lcssa = phi i32 [ %indvars11.le, %label.2.split.loop.exit12 ], [ 64, %else.2.3 ]
  ret i32 %r.0.lcssa

then.3:                                           ; preds = %else.2.3, %entry
  %i.010 = phi i64 [ 0, %entry ], [ %add.1.3, %else.2.3 ]
  %6 = shl nuw i64 1, %i.010
  %7 = and i64 %6, %in
  %icmp.2.not = icmp eq i64 %7, 0
  br i1 %icmp.2.not, label %else.2, label %label.2.split.loop.exit12
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_9(i64 noundef %in) #0 {
entry:
  br label %label.0

label.0:                                          ; preds = %then.2.3, %entry
  %i.0 = phi i64 [ 0, %entry ], [ %add.1.3, %then.2.3 ]
  %0 = lshr i64 -9223372036854775808, %i.0
  %1 = and i64 %0, %in
  %icmp.2 = icmp eq i64 %1, 0
  br i1 %icmp.2, label %then.2, label %label.2.split.loop.exit

label.2.split.loop.exit:                          ; preds = %then.2.2, %then.2.1, %then.2, %label.0
  %i.0.lcssa = phi i64 [ %i.0, %label.0 ], [ %add.1, %then.2 ], [ %add.1.1, %then.2.1 ], [ %add.1.2, %then.2.2 ]
  %indvars8.le = trunc i64 %i.0.lcssa to i32
  br label %label.2

label.2:                                          ; preds = %then.2.3, %label.2.split.loop.exit
  %r.1 = phi i32 [ %indvars8.le, %label.2.split.loop.exit ], [ 64, %then.2.3 ]
  ret i32 %r.1

then.2:                                           ; preds = %label.0
  %add.1 = or i64 %i.0, 1
  %2 = lshr i64 -9223372036854775808, %add.1
  %3 = and i64 %2, %in
  %icmp.2.1 = icmp eq i64 %3, 0
  br i1 %icmp.2.1, label %then.2.1, label %label.2.split.loop.exit

then.2.1:                                         ; preds = %then.2
  %add.1.1 = or i64 %i.0, 2
  %4 = lshr i64 -9223372036854775808, %add.1.1
  %5 = and i64 %4, %in
  %icmp.2.2 = icmp eq i64 %5, 0
  br i1 %icmp.2.2, label %then.2.2, label %label.2.split.loop.exit

then.2.2:                                         ; preds = %then.2.1
  %add.1.2 = or i64 %i.0, 3
  %6 = lshr i64 -9223372036854775808, %add.1.2
  %7 = and i64 %6, %in
  %icmp.2.3 = icmp eq i64 %7, 0
  br i1 %icmp.2.3, label %then.2.3, label %label.2.split.loop.exit

then.2.3:                                         ; preds = %then.2.2
  %add.1.3 = add nuw nsw i64 %i.0, 4
  %exitcond.3 = icmp eq i64 %add.1.3, 64
  br i1 %exitcond.3, label %label.2, label %label.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_10(i64 noundef %in) #0 {
entry:
  br label %then.2

else.1:                                           ; preds = %then.2
  %add.1 = or i64 %i.09, 1
  %shl.0.1 = shl nuw i64 1, %add.1
  %iand.0.1 = and i64 %shl.0.1, %in
  %icmp.1.not.1 = icmp eq i64 %iand.0.1, 0
  br i1 %icmp.1.not.1, label %else.1.1, label %label.2.split.loop.exit11

else.1.1:                                         ; preds = %else.1
  %add.1.1 = or i64 %i.09, 2
  %shl.0.2 = shl nuw i64 1, %add.1.1
  %iand.0.2 = and i64 %shl.0.2, %in
  %icmp.1.not.2 = icmp eq i64 %iand.0.2, 0
  br i1 %icmp.1.not.2, label %else.1.2, label %label.2.split.loop.exit11

else.1.2:                                         ; preds = %else.1.1
  %add.1.2 = or i64 %i.09, 3
  %shl.0.3 = shl nuw i64 1, %add.1.2
  %iand.0.3 = and i64 %shl.0.3, %in
  %icmp.1.not.3 = icmp eq i64 %iand.0.3, 0
  br i1 %icmp.1.not.3, label %else.1.3, label %label.2.split.loop.exit11

else.1.3:                                         ; preds = %else.1.2
  %add.1.3 = add nuw nsw i64 %i.09, 4
  %exitcond.not.3 = icmp eq i64 %add.1.3, 64
  br i1 %exitcond.not.3, label %label.2, label %then.2

label.2.split.loop.exit11:                        ; preds = %then.2, %else.1.2, %else.1.1, %else.1
  %i.09.lcssa = phi i64 [ %i.09, %then.2 ], [ %add.1, %else.1 ], [ %add.1.1, %else.1.1 ], [ %add.1.2, %else.1.2 ]
  %indvars10.le = trunc i64 %i.09.lcssa to i32
  br label %label.2

label.2:                                          ; preds = %label.2.split.loop.exit11, %else.1.3
  %r.0.lcssa = phi i32 [ %indvars10.le, %label.2.split.loop.exit11 ], [ 64, %else.1.3 ]
  ret i32 %r.0.lcssa

then.2:                                           ; preds = %else.1.3, %entry
  %i.09 = phi i64 [ 0, %entry ], [ %add.1.3, %else.1.3 ]
  %shl.0 = shl nuw i64 1, %i.09
  %iand.0 = and i64 %shl.0, %in
  %icmp.1.not = icmp eq i64 %iand.0, 0
  br i1 %icmp.1.not, label %else.1, label %label.2.split.loop.exit11
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_11(i64 noundef %in) #0 {
entry:
  %icmp.0 = icmp eq i64 %in, 0
  br i1 %icmp.0, label %common.ret, label %label.0.preheader

label.0.preheader:                                ; preds = %entry
  %iand.09 = and i64 %in, 1
  %icmp.110 = icmp eq i64 %iand.09, 0
  br i1 %icmp.110, label %then.1, label %common.ret

common.ret:                                       ; preds = %else.1.loopexit, %label.0.preheader, %entry
  %common.ret.op = phi i32 [ 64, %entry ], [ 0, %label.0.preheader ], [ %phi.cast, %else.1.loopexit ]
  ret i32 %common.ret.op

then.1:                                           ; preds = %then.1, %label.0.preheader
  %r.012 = phi i64 [ %add.0, %then.1 ], [ 0, %label.0.preheader ]
  %in.addr.011 = phi i64 [ %shr.0, %then.1 ], [ %in, %label.0.preheader ]
  %shr.0 = lshr i64 %in.addr.011, 1
  %add.0 = add i64 %r.012, 1
  %0 = and i64 %in.addr.011, 2
  %icmp.1 = icmp eq i64 %0, 0
  br i1 %icmp.1, label %then.1, label %else.1.loopexit

else.1.loopexit:                                  ; preds = %then.1
  %phi.cast = trunc i64 %add.0 to i32
  br label %common.ret
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
  br label %for.cond, !llvm.loop !8

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
