cmd_/root/myprog/C/book_os_concepts/ch2/simple.mod.o := gcc -Wp,-MD,/root/myprog/C/book_os_concepts/ch2/.simple.mod.o.d  -nostdinc -isystem /usr/lib64/gcc/x86_64-suse-linux/7/include -I/usr/src/linux-5.3.18-24.43/arch/x86/include -I./arch/x86/include/generated -I/usr/src/linux-5.3.18-24.43/include -I./include -I/usr/src/linux-5.3.18-24.43/arch/x86/include/uapi -I./arch/x86/include/generated/uapi -I/usr/src/linux-5.3.18-24.43/include/uapi -I./include/generated/uapi -include /usr/src/linux-5.3.18-24.43/include/linux/kconfig.h -include /usr/src/linux-5.3.18-24.43/include/linux/compiler_types.h -D__KERNEL__ -Wall -Wundef -Werror=strict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -fno-PIE -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Wno-format-security -std=gnu89 -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3 -mskip-rax-setup -mtune=generic -mno-red-zone -mcmodel=kernel -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_SSSE3=1 -DCONFIG_AS_AVX=1 -DCONFIG_AS_AVX2=1 -DCONFIG_AS_AVX512=1 -DCONFIG_AS_SHA1_NI=1 -DCONFIG_AS_SHA256_NI=1 -DCONFIG_AS_ADX=1 -Wno-sign-compare -fno-asynchronous-unwind-tables -mindirect-branch=thunk-extern -mindirect-branch-register -fno-jump-tables -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -O2 --param=allow-store-data-races=0 -Wframe-larger-than=2048 -fstack-protector-strong -Wno-unused-but-set-variable -Wimplicit-fallthrough -Wno-unused-const-variable -fno-var-tracking-assignments -g -gdwarf-4 -pg -mrecord-mcount -mfentry -DCC_USING_FENTRY -fno-inline-functions-called-once -flive-patching=inline-clone -Wdeclaration-after-statement -Wvla -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init  -DKBUILD_BASENAME='"simple.mod"' -DKBUILD_MODNAME='"simple"' -DMODULE  -c -o /root/myprog/C/book_os_concepts/ch2/simple.mod.o /root/myprog/C/book_os_concepts/ch2/simple.mod.c

source_/root/myprog/C/book_os_concepts/ch2/simple.mod.o := /root/myprog/C/book_os_concepts/ch2/simple.mod.c

deps_/root/myprog/C/book_os_concepts/ch2/simple.mod.o := \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/retpoline.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/kconfig.h \
    $(wildcard include/config/cpu/big/endian.h) \
    $(wildcard include/config/booger.h) \
    $(wildcard include/config/foo.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/compiler_types.h \
    $(wildcard include/config/have/arch/compiler/h.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/optimize/inlining.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/compiler_attributes.h \
  /usr/src/linux-5.3.18-24.43/include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/build-salt.h \
    $(wildcard include/config/build/salt.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/elfnote.h \
  /usr/src/linux-5.3.18-24.43/include/linux/elf.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/elf.h \
    $(wildcard include/config/x86/64.h) \
    $(wildcard include/config/x86/32.h) \
    $(wildcard include/config/ia32/emulation.h) \
    $(wildcard include/config/x86/x32/abi.h) \
    $(wildcard include/config/compat.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/thread_info.h \
    $(wildcard include/config/thread/info/in/task.h) \
    $(wildcard include/config/have/arch/within/stack/frames.h) \
    $(wildcard include/config/hardened/usercopy.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/types.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/types.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/asm-generic/types.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/int-ll64.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/asm-generic/int-ll64.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/bitsperlong.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/bitsperlong.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/asm-generic/bitsperlong.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/posix_types.h \
  /usr/src/linux-5.3.18-24.43/include/linux/stddef.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/stddef.h \
  /usr/src/linux-5.3.18-24.43/include/linux/compiler_types.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/posix_types.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/posix_types_64.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/asm-generic/posix_types.h \
  /usr/src/linux-5.3.18-24.43/include/linux/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/bug/on/data/corruption.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/bug.h \
    $(wildcard include/config/debug/bugverbose.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/stringify.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
    $(wildcard include/config/smp.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/stack/validation.h) \
    $(wildcard include/config/kasan.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/barrier.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/alternative.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/asm.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/nops.h \
    $(wildcard include/config/mk7.h) \
    $(wildcard include/config/x86/p6/nop.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/barrier.h \
  /usr/src/linux-5.3.18-24.43/include/linux/kasan-checks.h \
  /usr/src/linux-5.3.18-24.43/include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/suse/kernel/supported.h) \
    $(wildcard include/config/panic/timeout.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /usr/lib64/gcc/x86_64-suse-linux/7/include/stdarg.h \
  /usr/src/linux-5.3.18-24.43/include/linux/limits.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/limits.h \
  /usr/src/linux-5.3.18-24.43/include/linux/linkage.h \
  /usr/src/linux-5.3.18-24.43/include/linux/export.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/module/rel/crcs.h) \
    $(wildcard include/config/have/arch/prel32/relocations.h) \
    $(wildcard include/config/trim/unused/ksyms.h) \
    $(wildcard include/config/unused/symbols.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/linkage.h \
    $(wildcard include/config/x86/alignment/16.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/bitops.h \
  /usr/src/linux-5.3.18-24.43/include/linux/bits.h \
  /usr/src/linux-5.3.18-24.43/include/linux/const.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/const.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/bitops.h \
    $(wildcard include/config/x86/cmov.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/rmwcc.h \
    $(wildcard include/config/cc/has/asm/goto.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/bitops/sched.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/arch_hweight.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/cpufeatures.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/required-features.h \
    $(wildcard include/config/x86/minimum/cpu/family.h) \
    $(wildcard include/config/math/emulation.h) \
    $(wildcard include/config/x86/pae.h) \
    $(wildcard include/config/x86/cmpxchg64.h) \
    $(wildcard include/config/x86/use/3dnow.h) \
    $(wildcard include/config/matom.h) \
    $(wildcard include/config/paravirt.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/disabled-features.h \
    $(wildcard include/config/x86/intel/mpx.h) \
    $(wildcard include/config/x86/smap.h) \
    $(wildcard include/config/x86/intel/umip.h) \
    $(wildcard include/config/x86/intel/memory/protection/keys.h) \
    $(wildcard include/config/x86/5level.h) \
    $(wildcard include/config/page/table/isolation.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/bitops/const_hweight.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/bitops-instrumented.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/bitops/le.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/byteorder.h \
  /usr/src/linux-5.3.18-24.43/include/linux/byteorder/little_endian.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/byteorder/little_endian.h \
  /usr/src/linux-5.3.18-24.43/include/linux/swab.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/swab.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/swab.h \
  /usr/src/linux-5.3.18-24.43/include/linux/byteorder/generic.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/bitops/ext2-atomic-setbit.h \
  /usr/src/linux-5.3.18-24.43/include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/typecheck.h \
  /usr/src/linux-5.3.18-24.43/include/linux/printk.h \
    $(wildcard include/config/message/loglevel/default.h) \
    $(wildcard include/config/console/loglevel/default.h) \
    $(wildcard include/config/console/loglevel/quiet.h) \
    $(wildcard include/config/early/printk.h) \
    $(wildcard include/config/printk/nmi.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/init.h \
    $(wildcard include/config/strict/kernel/rwx.h) \
    $(wildcard include/config/strict/module/rwx.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/kern_levels.h \
  /usr/src/linux-5.3.18-24.43/include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/kernel.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/sysinfo.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/cache.h \
    $(wildcard include/config/x86/l1/cache/shift.h) \
    $(wildcard include/config/x86/internode/cache/shift.h) \
    $(wildcard include/config/x86/vsmp.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/dynamic_debug.h \
    $(wildcard include/config/jump/label.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/jump_label.h \
    $(wildcard include/config/have/arch/jump/label/relative.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/jump_label.h \
  /usr/src/linux-5.3.18-24.43/include/linux/build_bug.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/div64.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/div64.h \
  /usr/src/linux-5.3.18-24.43/include/linux/restart_block.h \
  /usr/src/linux-5.3.18-24.43/include/linux/time64.h \
  /usr/src/linux-5.3.18-24.43/include/linux/math64.h \
    $(wildcard include/config/arch/supports/int128.h) \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/time.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/time_types.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/current.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/percpu.h \
    $(wildcard include/config/x86/64/smp.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/percpu.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
    $(wildcard include/config/amd/mem/encrypt.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/thread_info.h \
    $(wildcard include/config/vm86.h) \
    $(wildcard include/config/frame/pointer.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/page.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/page_types.h \
    $(wildcard include/config/physical/start.h) \
    $(wildcard include/config/physical/align.h) \
    $(wildcard include/config/dynamic/physical/mask.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/mem_encrypt.h \
    $(wildcard include/config/arch/has/mem/encrypt.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/mem_encrypt.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/bootparam.h \
  /usr/src/linux-5.3.18-24.43/include/linux/screen_info.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/screen_info.h \
  /usr/src/linux-5.3.18-24.43/include/linux/apm_bios.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/apm_bios.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/ioctl.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/ioctl.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/ioctl.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/asm-generic/ioctl.h \
  /usr/src/linux-5.3.18-24.43/include/linux/edd.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/edd.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/ist.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/ist.h \
  /usr/src/linux-5.3.18-24.43/include/video/edid.h \
    $(wildcard include/config/x86.h) \
  /usr/src/linux-5.3.18-24.43/include/uapi/video/edid.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/page_64_types.h \
    $(wildcard include/config/dynamic/memory/layout.h) \
    $(wildcard include/config/randomize/base.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/kaslr.h \
    $(wildcard include/config/randomize/memory.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/page_64.h \
    $(wildcard include/config/debug/virtual.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/x86/vsyscall/emulation.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/range.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/memory_model.h \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/pfn.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/getorder.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/cpufeature.h \
    $(wildcard include/config/x86/feature/names.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/processor.h \
    $(wildcard include/config/kvm.h) \
    $(wildcard include/config/stackprotector.h) \
    $(wildcard include/config/paravirt/xxl.h) \
    $(wildcard include/config/x86/debugctlmsr.h) \
    $(wildcard include/config/cpu/sup/amd.h) \
    $(wildcard include/config/xen.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/processor-flags.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/processor-flags.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/math_emu.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/ptrace.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/segment.h \
    $(wildcard include/config/xen/pv.h) \
    $(wildcard include/config/x86/32/lazy/gs.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/ptrace.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/ptrace-abi.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/paravirt_types.h \
    $(wildcard include/config/pgtable/levels.h) \
    $(wildcard include/config/paravirt/debug.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/desc_defs.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/kmap_types.h \
    $(wildcard include/config/debug/highmem.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/kmap_types.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/pgtable_types.h \
    $(wildcard include/config/mem/soft/dirty.h) \
    $(wildcard include/config/proc/fs.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/pgtable_64_types.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/sparsemem.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/nospec-branch.h \
  /usr/src/linux-5.3.18-24.43/include/linux/static_key.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/alternative-asm.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/msr-index.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/spinlock_types.h \
    $(wildcard include/config/paravirt/spinlocks.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/qspinlock_types.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/qrwlock_types.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/sigcontext.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/msr.h \
    $(wildcard include/config/tracepoints.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/msr-index.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/errno.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/asm-generic/errno.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/asm-generic/errno-base.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/cpumask.h \
  /usr/src/linux-5.3.18-24.43/include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/bitmap.h \
  /usr/src/linux-5.3.18-24.43/include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
    $(wildcard include/config/fortify/source.h) \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/string.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/string.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/string_64.h \
    $(wildcard include/config/x86/mce.h) \
    $(wildcard include/config/arch/has/uaccess/flushcache.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/msr.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/atomic.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/cmpxchg.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/cmpxchg_64.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/atomic64_64.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/atomic-instrumented.h \
  /usr/src/linux-5.3.18-24.43/include/linux/tracepoint-defs.h \
  /usr/src/linux-5.3.18-24.43/include/linux/atomic.h \
  /usr/src/linux-5.3.18-24.43/include/linux/atomic-fallback.h \
    $(wildcard include/config/generic/atomic64.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/atomic-long.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/paravirt.h \
    $(wildcard include/config/debug/entry.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/frame.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/special_insns.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/fpu/types.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/unwind_hints.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/orc_types.h \
  /usr/src/linux-5.3.18-24.43/include/linux/personality.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/personality.h \
  /usr/src/linux-5.3.18-24.43/include/linux/err.h \
  /usr/src/linux-5.3.18-24.43/include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/irqflags.h \
    $(wildcard include/config/debug/lock/alloc.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/user.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/user_64.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/auxvec.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/fsgsbase.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/vdso.h \
    $(wildcard include/config/x86/x32.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/mm_types.h \
    $(wildcard include/config/have/aligned/struct/page.h) \
    $(wildcard include/config/memcg.h) \
    $(wildcard include/config/userfaultfd.h) \
    $(wildcard include/config/swap.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/have/arch/compat/mmap/bases.h) \
    $(wildcard include/config/membarrier.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mmu/notifier.h) \
    $(wildcard include/config/transparent/hugepage.h) \
    $(wildcard include/config/numa/balancing.h) \
    $(wildcard include/config/arch/want/batched/unmap/tlb/flush.h) \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hmm/mirror.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/mm_types_task.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/arch/enable/split/pmd/ptlock.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/tlbbatch.h \
  /usr/src/linux-5.3.18-24.43/include/linux/auxvec.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/auxvec.h \
  /usr/src/linux-5.3.18-24.43/include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
    $(wildcard include/config/page/poisoning/zero.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/preemption.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/preempt.h \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/trace/preempt/toggle.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/preempt.h \
  /usr/src/linux-5.3.18-24.43/include/linux/bottom_half.h \
  arch/x86/include/generated/asm/mmiowb.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/mmiowb.h \
    $(wildcard include/config/mmiowb.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/spinlock_types.h \
  /usr/src/linux-5.3.18-24.43/include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/rwlock_types.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/spinlock.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/qspinlock.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/qspinlock.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/qrwlock.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/qrwlock.h \
  /usr/src/linux-5.3.18-24.43/include/linux/rwlock.h \
    $(wildcard include/config/preempt.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/uninline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
    $(wildcard include/config/generic/lockbreak.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/rbtree.h \
  /usr/src/linux-5.3.18-24.43/include/linux/rcupdate.h \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/rcu/stall/common.h) \
    $(wildcard include/config/no/hz/full.h) \
    $(wildcard include/config/rcu/nocb/cpu.h) \
    $(wildcard include/config/tasks/rcu.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/prove/rcu.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/arch/weak/release/acquire.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/rcutree.h \
  /usr/src/linux-5.3.18-24.43/include/linux/rwsem.h \
    $(wildcard include/config/rwsem/spin/on/owner.h) \
    $(wildcard include/config/debug/rwsems.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/osq_lock.h \
  /usr/src/linux-5.3.18-24.43/include/linux/completion.h \
  /usr/src/linux-5.3.18-24.43/include/linux/wait.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/wait.h \
  /usr/src/linux-5.3.18-24.43/include/linux/uprobes.h \
    $(wildcard include/config/uprobes.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/errno.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/errno.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/uprobes.h \
  /usr/src/linux-5.3.18-24.43/include/linux/notifier.h \
    $(wildcard include/config/tree/srcu.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/mutex.h \
    $(wildcard include/config/mutex/spin/on/owner.h) \
    $(wildcard include/config/debug/mutexes.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/debug_locks.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/srcu.h \
    $(wildcard include/config/tiny/srcu.h) \
    $(wildcard include/config/srcu.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/wq/watchdog.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/timer.h \
    $(wildcard include/config/debug/objects/timers.h) \
    $(wildcard include/config/no/hz/common.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/ktime.h \
  /usr/src/linux-5.3.18-24.43/include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/seqlock.h \
  /usr/src/linux-5.3.18-24.43/include/linux/time32.h \
  /usr/src/linux-5.3.18-24.43/include/linux/timex.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/timex.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/param.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/param.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  /usr/src/linux-5.3.18-24.43/include/uapi/asm-generic/param.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/timex.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/tsc.h \
    $(wildcard include/config/x86/tsc.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/jiffies.h \
  include/generated/timeconst.h \
  /usr/src/linux-5.3.18-24.43/include/linux/timekeeping.h \
  /usr/src/linux-5.3.18-24.43/include/linux/timekeeping32.h \
  /usr/src/linux-5.3.18-24.43/include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/rcu_segcblist.h \
  /usr/src/linux-5.3.18-24.43/include/linux/srcutree.h \
  /usr/src/linux-5.3.18-24.43/include/linux/rcu_node_tree.h \
    $(wildcard include/config/rcu/fanout.h) \
    $(wildcard include/config/rcu/fanout/leaf.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/page-flags-layout.h \
    $(wildcard include/config/kasan/sw/tags.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  include/generated/bounds.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/mmu.h \
    $(wildcard include/config/modify/ldt/syscall.h) \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/elf.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/elf-em.h \
  /usr/src/linux-5.3.18-24.43/include/linux/module.h \
    $(wildcard include/config/modules/tree/lookup.h) \
    $(wildcard include/config/livepatch.h) \
    $(wildcard include/config/module/sig.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/bpf/events.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/function/error/injection.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/stat.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/stat.h \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/stat.h \
  /usr/src/linux-5.3.18-24.43/include/linux/uidgid.h \
    $(wildcard include/config/multiuser.h) \
    $(wildcard include/config/user/ns.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/highuid.h \
  /usr/src/linux-5.3.18-24.43/include/linux/kmod.h \
  /usr/src/linux-5.3.18-24.43/include/linux/umh.h \
  /usr/src/linux-5.3.18-24.43/include/linux/gfp.h \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/zone/device.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/contig/alloc.h) \
    $(wildcard include/config/cma.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/vm/pgflags.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/memory/isolation.h) \
    $(wildcard include/config/shuffle/page/allocator.h) \
    $(wildcard include/config/zsmalloc.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/page/extension.h) \
    $(wildcard include/config/deferred/struct/page/init.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/nodemask.h \
  /usr/src/linux-5.3.18-24.43/include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/page-flags.h \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/memory/failure.h) \
    $(wildcard include/config/idle/page/tracking.h) \
    $(wildcard include/config/thp/swap.h) \
    $(wildcard include/config/ksm.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/memory_hotplug.h \
    $(wildcard include/config/arch/has/add/pages.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/have/bootmem/info/node.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/mmzone.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/mmzone_64.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/smp.h \
    $(wildcard include/config/x86/local/apic.h) \
    $(wildcard include/config/x86/io/apic.h) \
    $(wildcard include/config/debug/nmi/selftest.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/mpspec.h \
    $(wildcard include/config/eisa.h) \
    $(wildcard include/config/x86/mpparse.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/mpspec_def.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/x86_init.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/apicdef.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/apic.h \
    $(wildcard include/config/x86/x2apic.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/fixmap.h \
    $(wildcard include/config/provide/ohci1394/dma/init.h) \
    $(wildcard include/config/pci/mmconfig.h) \
    $(wildcard include/config/x86/intel/mid.h) \
    $(wildcard include/config/acpi/apei/ghes.h) \
    $(wildcard include/config/intel/txt.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/acpi.h \
    $(wildcard include/config/acpi/apei.h) \
    $(wildcard include/config/acpi.h) \
    $(wildcard include/config/acpi/numa.h) \
  /usr/src/linux-5.3.18-24.43/include/acpi/pdc_intel.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/numa.h \
    $(wildcard include/config/numa/emu.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/topology.h \
    $(wildcard include/config/sched/mc/prio.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/topology.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/realmode.h \
    $(wildcard include/config/acpi/sleep.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/io.h \
    $(wildcard include/config/mtrr.h) \
    $(wildcard include/config/x86/pat.h) \
  arch/x86/include/generated/asm/early_ioremap.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/early_ioremap.h \
    $(wildcard include/config/generic/early/ioremap.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/iomap.h \
    $(wildcard include/config/has/ioport/map.h) \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/generic/iomap.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/pci_iomap.h \
    $(wildcard include/config/no/generic/pci/ioport/map.h) \
    $(wildcard include/config/generic/pci/iomap.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/io.h \
    $(wildcard include/config/virt/to/bus.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/logic_pio.h \
    $(wildcard include/config/indirect/pio.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/fwnode.h \
  /usr/src/linux-5.3.18-24.43/include/linux/vmalloc.h \
  /usr/src/linux-5.3.18-24.43/include/linux/llist.h \
    $(wildcard include/config/arch/have/nmi/safe/cmpxchg.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/overflow.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/uapi/asm/vsyscall.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/fixmap.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/hardirq.h \
    $(wildcard include/config/kvm/intel.h) \
    $(wildcard include/config/have/kvm.h) \
    $(wildcard include/config/x86/thermal/vector.h) \
    $(wildcard include/config/x86/mce/threshold.h) \
    $(wildcard include/config/x86/mce/amd.h) \
    $(wildcard include/config/x86/hv/callback/vector.h) \
    $(wildcard include/config/hyperv.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/io_apic.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/irq_vectors.h \
    $(wildcard include/config/pci/msi.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/topology.h \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
    $(wildcard include/config/sched/smt.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/smp.h \
    $(wildcard include/config/up/late/init.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/sysctl.h \
    $(wildcard include/config/sysctl.h) \
  /usr/src/linux-5.3.18-24.43/include/uapi/linux/sysctl.h \
  /usr/src/linux-5.3.18-24.43/include/linux/kobject.h \
    $(wildcard include/config/uevent/helper.h) \
    $(wildcard include/config/debug/kobject/release.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/sysfs.h \
  /usr/src/linux-5.3.18-24.43/include/linux/kernfs.h \
    $(wildcard include/config/kernfs.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/idr.h \
  /usr/src/linux-5.3.18-24.43/include/linux/radix-tree.h \
  /usr/src/linux-5.3.18-24.43/include/linux/xarray.h \
    $(wildcard include/config/xarray/multi.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/kconfig.h \
  /usr/src/linux-5.3.18-24.43/include/linux/kobject_ns.h \
  /usr/src/linux-5.3.18-24.43/include/linux/kref.h \
  /usr/src/linux-5.3.18-24.43/include/linux/refcount.h \
  /usr/src/linux-5.3.18-24.43/include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  /usr/src/linux-5.3.18-24.43/include/linux/rbtree_latch.h \
  /usr/src/linux-5.3.18-24.43/include/linux/error-injection.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/error-injection.h \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/error-injection.h \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/module.h \
    $(wildcard include/config/unwinder/orc.h) \
    $(wildcard include/config/m486.h) \
    $(wildcard include/config/m586.h) \
    $(wildcard include/config/m586tsc.h) \
    $(wildcard include/config/m586mmx.h) \
    $(wildcard include/config/mcore2.h) \
    $(wildcard include/config/m686.h) \
    $(wildcard include/config/mpentiumii.h) \
    $(wildcard include/config/mpentiumiii.h) \
    $(wildcard include/config/mpentiumm.h) \
    $(wildcard include/config/mpentium4.h) \
    $(wildcard include/config/mk6.h) \
    $(wildcard include/config/mk8.h) \
    $(wildcard include/config/melan.h) \
    $(wildcard include/config/mcrusoe.h) \
    $(wildcard include/config/mefficeon.h) \
    $(wildcard include/config/mwinchipc6.h) \
    $(wildcard include/config/mwinchip3d.h) \
    $(wildcard include/config/mcyrixiii.h) \
    $(wildcard include/config/mviac3/2.h) \
    $(wildcard include/config/mviac7.h) \
    $(wildcard include/config/mgeodegx1.h) \
    $(wildcard include/config/mgeode/lx.h) \
  /usr/src/linux-5.3.18-24.43/include/asm-generic/module.h \
    $(wildcard include/config/have/mod/arch/specific.h) \
    $(wildcard include/config/modules/use/elf/rel.h) \
    $(wildcard include/config/modules/use/elf/rela.h) \
  /usr/src/linux-5.3.18-24.43/arch/x86/include/asm/orc_types.h \
  /usr/src/linux-5.3.18-24.43/include/linux/vermagic.h \
  include/generated/utsrelease.h \

/root/myprog/C/book_os_concepts/ch2/simple.mod.o: $(deps_/root/myprog/C/book_os_concepts/ch2/simple.mod.o)

$(deps_/root/myprog/C/book_os_concepts/ch2/simple.mod.o):
