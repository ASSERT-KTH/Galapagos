; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/variants/c/3_int16_t_nonzero_mask_4.bc'
source_filename = "/home/javier/Galapagos/functions/libgcrypt/variants/c/3_int16_t_nonzero_mask_4.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @int16_t_nonzero_mask(i16 noundef signext 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @int16_t_nonzero_mask(i16 noundef signext %x) #0 {
entry:
  %x.addr = alloca i16, align 2
  %mask = alloca i32, align 4
  store i16 %x, ptr %x.addr, align 2
  %0 = load i16, ptr %x.addr, align 2
  %conv = sext i16 %0 to i32
  %cmp = icmp ne i32 %conv, 0
  %conv1 = zext i1 %cmp to i32
  store i32 %conv1, ptr %mask, align 4
  %1 = load i32, ptr %mask, align 4
  %shl = shl i32 %1, 31
  %shr = ashr i32 %shl, 31
  ret i32 %shr
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
