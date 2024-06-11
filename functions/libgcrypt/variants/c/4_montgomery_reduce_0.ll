; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/variants/c/4_montgomery_reduce_0.bc'
source_filename = "/home/javier/Galapagos/functions/libgcrypt/variants/c/4_montgomery_reduce_0.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @montgomery_reduce(i32 noundef %a) #0 {
entry:
  %a.addr = alloca i32, align 4
  %t = alloca i16, align 2
  store i32 %a, ptr %a.addr, align 4
  %0 = load i32, ptr %a.addr, align 4
  %conv = trunc i32 %0 to i16
  %conv1 = zext i16 %conv to i32
  %mul = mul nsw i32 %conv1, 32209
  %conv2 = trunc i32 %mul to i16
  store i16 %conv2, ptr %t, align 2
  %1 = load i32, ptr %a.addr, align 4
  %2 = load i16, ptr %t, align 2
  %conv3 = sext i16 %2 to i32
  %mul4 = mul nsw i32 %conv3, 3329
  %sub = sub nsw i32 %1, %mul4
  %shr = ashr i32 %sub, 16
  %conv5 = trunc i32 %shr to i16
  store i16 %conv5, ptr %t, align 2
  %3 = load i16, ptr %t, align 2
  ret i16 %3
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call signext i16 @montgomery_reduce(i32 noundef 0)
  ret i32 0
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 17.0.0 (git@github.com:llvm/llvm-project.git 1a7a00bdc99fa2b2ca19ecd2d1069991b3c1006b)"}
