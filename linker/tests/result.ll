; ModuleID = 'main.c.bc'
source_filename = "sum/sum.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @n_version_call(i32 noundef %0, i32 noundef %1) #0 {
entry:
  %2 = call i32 @version_1(i32 %0, i32 %1)
  %3 = call i32 @version_2(i32 %0, i32 %1)
  br label %comparisons

comparisons:                                      ; preds = %entry
  %4 = icmp eq i32 %2, %3
  br i1 %4, label %true, label %error

true:                                             ; preds = %comparisons
  ret i32 %2

error:                                            ; preds = %comparisons
  call void @llvm.trap()
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_2(i32 noundef %0, i32 noundef %1) #0 {
entry:
  %add.0 = add i32 %1, %0
  ret i32 %add.0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @version_1(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, ptr %3, align 4
  store i32 %1, ptr %4, align 4
  %5 = load i32, ptr %3, align 4
  %6 = load i32, ptr %4, align 4
  %7 = add nsw i32 %5, %6
  ret i32 %7
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  %2 = call i32 @n_version_call(i32 noundef 64, i32 noundef 2)
  ret i32 %2
}

; Function Attrs: cold noreturn nounwind
declare void @llvm.trap() #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { cold noreturn nounwind }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 17.0.6 (https://github.com/llvm/llvm-project.git 6009708b4367171ccdbf4b5905cb6a803753fe18)"}
