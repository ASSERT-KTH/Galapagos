; ModuleID = 'main.c.bc'
source_filename = "chi/chi.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [5 x i8] c"%ld\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca [5 x [5 x i64]], align 16
  store i32 0, ptr %1, align 4
  %3 = getelementptr inbounds [5 x [5 x i64]], ptr %2, i64 0, i64 0
  %4 = call i64 @Chi(ptr noundef %3, i64 noundef 0)
  %5 = call i32 (ptr, ...) @printf(ptr noundef @.str, i64 noundef %4)
  ret i32 0
}

declare i32 @printf(ptr noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @Chi(ptr noundef %A, i64 noundef %i) #0 {
entry:
  %C = alloca [5 x i64], align 8
  %0 = bitcast ptr %C to ptr
  %icmp.14 = icmp eq ptr %A, null
  %index.0 = getelementptr inbounds [5 x i64], ptr %C, i64 0, i64 0
  %index.7 = getelementptr inbounds [5 x i64], ptr %C, i64 0, i64 1
  %index.14 = getelementptr inbounds [5 x i64], ptr %C, i64 0, i64 2
  %index.21 = getelementptr inbounds [5 x i64], ptr %C, i64 0, i64 3
  %index.28 = getelementptr inbounds [5 x i64], ptr %C, i64 0, i64 4
  br label %then.70

then.7:                                           ; preds = %then.70
  unreachable

else.7:                                           ; preds = %then.70
  %index.2 = getelementptr [5 x [5 x i64]], ptr %A, i64 0, i64 %y.0103, i64 0
  %.index.index.ld.2 = load i64, ptr %index.2, align 8
  %index.4 = getelementptr [5 x [5 x i64]], ptr %A, i64 0, i64 %y.0103, i64 1
  %.index.index.ld.0 = load i64, ptr %index.4, align 8
  %xor.0 = xor i64 %.index.index.ld.0, -1
  %index.6 = getelementptr [5 x [5 x i64]], ptr %A, i64 0, i64 %y.0103, i64 2
  %.index.index.ld.1 = load i64, ptr %index.6, align 8
  %iand.7 = and i64 %.index.index.ld.1, %xor.0
  %xor.1 = xor i64 %iand.7, %.index.index.ld.2
  %xor.2 = xor i64 %.index.index.ld.1, -1
  %index.13 = getelementptr [5 x [5 x i64]], ptr %A, i64 0, i64 %y.0103, i64 3
  %.index.index.ld.4 = load i64, ptr %index.13, align 8
  %iand.15 = and i64 %.index.index.ld.4, %xor.2
  %xor.3 = xor i64 %iand.15, %.index.index.ld.0
  %xor.4 = xor i64 %.index.index.ld.4, -1
  %index.20 = getelementptr [5 x [5 x i64]], ptr %A, i64 0, i64 %y.0103, i64 4
  %.index.index.ld.7 = load i64, ptr %index.20, align 8
  %iand.23 = and i64 %.index.index.ld.7, %xor.4
  %xor.5 = xor i64 %iand.23, %.index.index.ld.1
  %xor.6 = xor i64 %.index.index.ld.7, -1
  %iand.31 = and i64 %.index.index.ld.2, %xor.6
  %xor.7 = xor i64 %iand.31, %.index.index.ld.4
  %xor.8 = xor i64 %.index.index.ld.2, -1
  %iand.39 = and i64 %.index.index.ld.0, %xor.8
  %xor.9 = xor i64 %.index.index.ld.7, %iand.39
  store i64 %xor.1, ptr %index.2, align 8
  store i64 %xor.3, ptr %index.4, align 8
  store i64 %xor.5, ptr %index.6, align 8
  store i64 %xor.7, ptr %index.13, align 8
  store i64 %xor.9, ptr %index.20, align 8
  %add.0 = add nuw nsw i64 %y.0103, 1
  %exitcond.not = icmp eq i64 %add.0, 5
  br i1 %exitcond.not, label %else.70, label %then.70

then.70:                                          ; preds = %else.7, %entry
  %y.0103 = phi i64 [ 0, %entry ], [ %add.0, %else.7 ]
  br i1 %icmp.14, label %then.7, label %else.7, !make.implicit !6

else.70:                                          ; preds = %else.7
  store i64 %xor.1, ptr %index.0, align 8
  store i64 %xor.3, ptr %index.7, align 8
  store i64 %xor.5, ptr %index.14, align 8
  store i64 %xor.7, ptr %index.21, align 8
  store i64 %xor.9, ptr %index.28, align 8
  %1 = icmp ult i64 %i, 5
  br i1 %1, label %fallthrough.71, label %else.71

fallthrough.71:                                   ; preds = %else.70
  %index.50 = getelementptr [5 x i64], ptr %C, i64 0, i64 %i
  %C.index.ld.5 = load i64, ptr %index.50, align 8
  ret i64 %C.index.ld.5

else.71:                                          ; preds = %else.70
  unreachable
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 17.0.6 (https://github.com/llvm/llvm-project.git 6009708b4367171ccdbf4b5905cb6a803753fe18)"}
!6 = !{}
