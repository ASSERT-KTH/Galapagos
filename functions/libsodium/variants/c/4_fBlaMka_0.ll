; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/4_fBlaMka_0.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/4_fBlaMka_0.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i64 @fBlaMka(i64 noundef 0, i64 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @fBlaMka(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  %0 = load i64, ptr %x.addr, align 8
  %1 = load i64, ptr %y.addr, align 8
  %add = add i64 %0, %1
  %2 = load i64, ptr %x.addr, align 8
  %conv = trunc i64 %2 to i32
  %3 = load i64, ptr %y.addr, align 8
  %conv1 = trunc i64 %3 to i32
  %mul = mul i32 %conv, %conv1
  %conv2 = zext i32 %mul to i64
  %mul3 = mul i64 2, %conv2
  %add4 = add i64 %add, %mul3
  ret i64 %add4
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
