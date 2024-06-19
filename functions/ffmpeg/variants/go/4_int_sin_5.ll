; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/go/4_int_sin_5.bc'
source_filename = "gomodule"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

module asm "\09.section \22.go_export\22,\22e\22,@progbits"
module asm "\09.ascii \22v3;\\n\22"
module asm "\09.ascii \22package \22"
module asm "\09.ascii \22main\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22pkgpath \22"
module asm "\09.ascii \22main\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22types 2 1\22"
module asm "\09.ascii \22 31\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type -4>) <type -4>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22intSin\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22a\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -4>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -4>\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22checksum 7308C6C618B8013BD926321ADB0C71AAEF4DB364\\n\22"
module asm "\09.text"

@main..types = constant { i64, [1 x i8*] } zeroinitializer
@go..typelists = internal constant [1 x { i64, [1 x i8*] }*] [{ i64, [1 x i8*] }* @main..types]

; Function Attrs: null_pointer_is_valid
define void @__go_init_main(i8* nest nocapture readnone %nest.2) local_unnamed_addr #0 {
entry:
  call void @runtime.registerTypeDescriptors(i8* nest undef, i64 1, i8* bitcast ([1 x { i64, [1 x i8*] }*]* @go..typelists to i8*))
  ret void
}

; Function Attrs: null_pointer_is_valid
define i64 @main.intSin(i8* nest nocapture readnone %nest.0, i64 %a) local_unnamed_addr #0 {
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

; Function Attrs: null_pointer_is_valid
define void @main.main(i8* nest nocapture readnone %nest.1) local_unnamed_addr #0 {
entry:
  %call.0 = call i64 @main.intSin(i8* nest undef, i64 0)
  ret void
}

; Function Attrs: null_pointer_is_valid
declare void @runtime.registerTypeDescriptors(i8*, i64, i8*) local_unnamed_addr #0

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #1

attributes #0 = { null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.module.flags = !{!0, !1, !2}

!0 = !{i32 7, !"PIC Level", i32 0}
!1 = !{i32 2, !"Debug Info Version", i32 3}
!2 = !{i32 2, !"Dwarf Version", i32 4}
