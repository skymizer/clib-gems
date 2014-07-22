dnl
dnl @synopsis CHECK_CANONICAL_SYSTEM
dnl
dnl @summary set up default value of `host`, `build` and `target`
dnl
dnl Luba Tang <luba@skymizer.com>

AC_DEFUN([CHECK_CANONICAL_SYSTEM],
[dnl

AC_CANONICAL_HOST

AC_CACHE_CHECK([type of operating system we're going to host on],
  [libcbench_cv_host_os_type],
  [case $host in
  *-*-aix*)
    libcbench_cv_host_os_type="AIX"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-irix*)
    libcbench_cv_host_os_type="IRIX"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-cygwin*)
    libcbench_cv_host_os_type="Cygwin"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-darwin*)
    libcbench_cv_host_os_type="Darwin"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-minix*)
    libcbench_cv_host_os_type="Minix"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-freebsd*)
    libcbench_cv_host_os_type="FreeBSD"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-openbsd*)
    libcbench_cv_host_os_type="OpenBSD"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-netbsd*)
    libcbench_cv_host_os_type="NetBSD"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-dragonfly*)
    libcbench_cv_host_os_type="DragonFly"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-hpux*)
    libcbench_cv_host_os_type="HP-UX"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-interix*)
    libcbench_cv_host_os_type="Interix"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-linux*)
    libcbench_cv_host_os_type="Linux"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-solaris*)
    libcbench_cv_host_os_type="SunOS"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-auroraux*)
    libcbench_cv_host_os_type="AuroraUX"
    libcbench_cv_host_platform_type="Unix" ;;
  *-*-win32*)
    libcbench_cv_host_os_type="Win32"
    libcbench_cv_host_platform_type="Win32" ;;
  *-*-mingw*)
    libcbench_cv_host_os_type="MingW"
    libcbench_cv_host_platform_type="Win32" ;;
  *-*-haiku*)
    libcbench_cv_host_os_type="Haiku"
    libcbench_cv_host_platform_type="Unix" ;;
  *-unknown-eabi*)
    libcbench_cv_host_os_type="Freestanding"
    libcbench_cv_host_platform_type="Unix" ;;
  *-unknown-elf*)
    libcbench_cv_host_os_type="Freestanding"
    libcbench_cv_host_platform_type="Unix" ;;
  *)
    libcbench_cv_host_os_type="Unknown"
    libcbench_cv_host_platform_type="Unknown" ;;
  esac])

dnl Set the "OS" Makefile variable based on the platform type so the
dnl makefile can configure itself to specific build hosts
if test "$libcbench_cv_host_os_type" = "Unknown" ; then
  AC_MSG_ERROR([Operating system is unknown, configure can't continue])
fi

dnl Set the "LIBCBENCH_ON_*" variables based on llvm_cv_llvm_cv_platform_type
dnl This is used by lib/Support to determine the basic kind of implementation
dnl to use.
case $libcbench_cv_host_platform_type in
Unix)
  AC_DEFINE([LIBCBENCH_ON_UNIX],[1],[Define if this is Unixish platform])
  AC_SUBST(LIBCBENCH_ON_PLATFORM,[LIBCBENCH_ON_UNIX])
;;
Win32)
  AC_DEFINE([LIBCBENCH_ON_WIN32],[1],[Define if this is Win32ish platform])
  AC_SUBST(LIBCBENCH_ON_PLATFORM,[LIBCBENCH_ON_WIN32])
;;
esac

AC_SUBST(HOST_OS,$libcbench_cv_host_os_type)

AC_CANONICAL_TARGET
AC_CACHE_CHECK([type of operating system we're going to target],
  [libcbench_cv_target_os_type],
  [case $target in
  *-*-aix*)
    libcbench_cv_target_os_type="AIX" ;;
  *-*-irix*)
    libcbench_cv_target_os_type="IRIX" ;;
  *-*-cygwin*)
    libcbench_cv_target_os_type="Cygwin" ;;
  *-*-darwin*)
  libcbench_cv_target_os_type="Darwin" ;;
  *-*-minix*)
    libcbench_cv_target_os_type="Minix" ;;
  *-*-freebsd* | *-*-kfreebsd-gnu)
    libcbench_cv_target_os_type="FreeBSD" ;;
  *-*-openbsd*)
    libcbench_cv_target_os_type="OpenBSD" ;;
  *-*-netbsd*)
    libcbench_cv_target_os_type="NetBSD" ;;
  *-*-dragonfly*)
    libcbench_cv_target_os_type="DragonFly" ;;
  *-*-hpux*)
    libcbench_cv_target_os_type="HP-UX" ;;
  *-*-interix*)
    libcbench_cv_target_os_type="Interix" ;;
  *-*-linux*)
    libcbench_cv_target_os_type="Linux" ;;
  *-*-gnu*)
    libcbench_cv_target_os_type="GNU" ;;
  *-*-solaris*)
    libcbench_cv_target_os_type="SunOS" ;;
  *-*-auroraux*)
    libcbench_cv_target_os_type="AuroraUX" ;;
  *-*-win32*)
    libcbench_cv_target_os_type="Win32" ;;
  *-*-mingw*)
    libcbench_cv_target_os_type="MingW" ;;
  *-*-haiku*)
    libcbench_cv_target_os_type="Haiku" ;;
  *-*-rtems*)
    libcbench_cv_target_os_type="RTEMS" ;;
  *-*-nacl*)
    libcbench_cv_target_os_type="NativeClient" ;;
  *-unknown-eabi*)
    libcbench_cv_target_os_type="Freestanding" ;;
  *)
    libcbench_cv_target_os_type="Unknown" ;;
  esac])

if test "$libcbench_cv_target_os_type" = "Unknown" ; then
  AC_MSG_WARN([Configuring for an unknown target operating system])
fi

AC_SUBST(TARGET_OS,$libcbench_cv_target_os_type)

AC_CACHE_CHECK([target architecture],
  [libcbench_cv_target_arch_type],
  [case $target in
  i?86-*)                 libcbench_cv_target_arch_type="x86" ;;
  amd64-* | x86_64-*)     libcbench_cv_target_arch_type="x86_64" ;;
  sparc*-*)               libcbench_cv_target_arch_type="Sparc" ;;
  powerpc*-*)             libcbench_cv_target_arch_type="PowerPC" ;;
  arm*-*)                 libcbench_cv_target_arch_type="ARM" ;;
  aarch64*-*)             libcbench_cv_target_arch_type="AArch64" ;;
  mips-* | mips64-*)      libcbench_cv_target_arch_type="Mips" ;;
  mipsel-* | mips64el-*)  libcbench_cv_target_arch_type="Mips" ;;
  xcore-*)                libcbench_cv_target_arch_type="XCore" ;;
  msp430-*)               libcbench_cv_target_arch_type="MSP430" ;;
  hexagon-*)              libcbench_cv_target_arch_type="Hexagon" ;;
  mblaze-*)               libcbench_cv_target_arch_type="MBlaze" ;;
  nvptx-*)                libcbench_cv_target_arch_type="NVPTX" ;;
  *)                      libcbench_cv_target_arch_type="Unknown" ;;
  esac])

if test "$libcbench_cv_target_arch_type" = "Unknown" ; then
  AC_MSG_WARN([Configuring for an unknown target archicture])
fi

AC_SUBST(TARGET_ARCH,$libcbench_cv_target_arch_type)

dnl Set the "LIBCBENCH_DEFAULT_TARGET_TRIPLE" variable based on $target.
dnl This is used to determine the default target triple and emulation
dnl to use.
AC_DEFINE([LIBCBENCH_DEFAULT_TARGET_TRIPLE],
          [$target],
          [default target triple])

])
