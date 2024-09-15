# Linux 0.11 Makefile Structure

```
.
├── blk_drv
│   ├── Makefile
│   ├── blk.h
│   ├── floppy.c
│   ├── hd.c
│   ├── ll_rw_blk.c
│   ├── main.c
│   └── ramdisk.c
├── chr_drv
│   ├── Makefile
│   ├── keyboard.S
│   ├── rs_io.s
│   ├── serial.c
│   ├── tty_io.c
│   └── tty_ioctl.c
├── math
│   ├── Makefile
│   └── math_emulate.c
├── Makefile
├── asm.s
├── exit.c
├── fork.c
├── mktime.c
├── panic.c
├── printk.c
├── sched.c
├── signal.c
├── sys.c
├── system_call.s
├── traps.c
└── vsprintf
```
