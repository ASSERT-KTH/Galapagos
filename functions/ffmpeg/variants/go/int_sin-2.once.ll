; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/4_int_sin.once.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/4_int_sin.run.once.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i64 @int_sin(i64 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @int_sin(i64 noundef %a) #0 {
else.8.4:
  %icmp.0 = icmp slt i64 %a, 0
  %add.0 = add i64 %a, 3294199
  %spec.select = select i1 %icmp.0, i64 %add.0, i64 %a
  %mod.0 = srem i64 %spec.select, 6588398
  %icmp.3 = icmp sgt i64 %mod.0, 4941297
  %sub.0 = add nsw i64 %mod.0, -6588398
  %a.addr.1 = select i1 %icmp.3, i64 %sub.0, i64 %mod.0
  %icmp.4 = icmp sgt i64 %a.addr.1, 1647098
  %sub.1 = sub nsw i64 3294199, %a.addr.1
  %a.addr.2 = select i1 %icmp.4, i64 %sub.1, i64 %a.addr.1
  %mul.0 = mul nsw i64 %a.addr.2, %a.addr.2
  %div.0 = lshr i64 %mul.0, 20
  %0 = mul i64 %div.0, %a.addr.2
  %mul.1 = sub i64 0, %0
  %div.1 = sdiv i64 %mul.1, 6291456
  %1 = mul i64 %div.0, %div.1
  %mul.1.1 = sub i64 0, %1
  %div.1.1 = sdiv i64 %mul.1.1, 20971520
  %2 = mul i64 %div.0, %div.1.1
  %mul.1.2 = sub i64 0, %2
  %div.1.2 = sdiv i64 %mul.1.2, 44040192
  %3 = mul i64 %div.0, %div.1.2
  %mul.1.3 = sub i64 0, %3
  %div.1.3 = sdiv i64 %mul.1.3, 75497472
  %add.1.1 = add nsw i64 %div.1, %a.addr.2
  %add.1.2 = add nsw i64 %div.1.1, %add.1.1
  %add.1.3 = add nsw i64 %div.1.2, %add.1.2
  %add.1.4 = add nsw i64 %div.1.3, %add.1.3
  %add.4 = add nsw i64 %add.1.4, 8
  %shr.0 = ashr i64 %add.4, 4
  ret i64 %shr.0
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
