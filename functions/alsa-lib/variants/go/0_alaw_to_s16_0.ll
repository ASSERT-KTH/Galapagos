; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/go/0_alaw_to_s16_0.bc'
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
module asm "\09.ascii \22 32\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type -20>) <type -3>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22alawToS16\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22aVal\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -20>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:781>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/alsa-lib/variants/go/0_alaw_to_s16_0.go:3\\n aVal = (aVal ^ $convert(<type -20>, 85 )) //4\\n var t <type -3> = $convert(<type -3>, (aVal & $convert(<type -20>, 127 ))) //5\\n { //6\\n  if (t < $convert(<type -3>, 16 )) { //6\\n   t = ((t << $convert(<type -12>, 4 )) + $convert(<type -3>, 8 )) //7\\n  } else { //8\\n   var seg <type -3> = ((t >> $convert(<type -12>, 4 )) & 7 ) //9\\n   t = (((t & $convert(<type -3>, 15 )) << $convert(<type -12>, 4 )) + $convert(<type -3>, 264 )) //10\\n   t = (t << (seg - $convert(<type -3>, 1 ))) //11\\n  } //6\\n } //12\\n { //13\\n  if ((aVal & $convert(<type -20>, 128 )) != $convert(<type -20>, 0 )) { //13\\n   { //14\\n    $ret0 = t //14\\n    return //14\\n   } //0\\n  } //13\\n } //15\\n { //16\\n  $ret0 = -t //16\\n  return //16\\n } //0\\n\22"
module asm "\09.ascii \22checksum 004449DBD9AC78C5A16437A57A9270A177827218\\n\22"
module asm "\09.text"

@main..types = constant { i64, [1 x i8*] } zeroinitializer
@go..typelists = internal constant [1 x { i64, [1 x i8*] }*] [{ i64, [1 x i8*] }* @main..types]

; Function Attrs: null_pointer_is_valid
define void @__go_init_main(i8* nest nocapture readnone %nest.2) local_unnamed_addr #0 {
entry:
  call void @runtime.registerTypeDescriptors(i8* nest undef, i64 1, i8* bitcast ([1 x { i64, [1 x i8*] }*]* @go..typelists to i8*))
  ret void
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn
define i32 @main.alawToS16(i8* nest nocapture readnone %nest.0, i8 zeroext %aVal) local_unnamed_addr #1 {
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

; Function Attrs: mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn
define void @main.main(i8* nest nocapture %nest.1) local_unnamed_addr #1 {
entry:
  ret void
}

; Function Attrs: null_pointer_is_valid
declare void @runtime.registerTypeDescriptors(i8*, i64, i8*) local_unnamed_addr #0

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #2

attributes #0 = { null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #1 = { mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #2 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.module.flags = !{!0, !1, !2}

!0 = !{i32 7, !"PIC Level", i32 0}
!1 = !{i32 2, !"Debug Info Version", i32 3}
!2 = !{i32 2, !"Dwarf Version", i32 4}
