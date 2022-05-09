#include <types.h>
#include <kern/unistd.h>
#include <stdarg.h>
#include <lib.h>
#include <spl.h>
#include <cpu.h>
#include <thread.h>
#include <current.h>
#include <synch.h>
#include <mainbus.h>
#include <vfs.h>
#include <lamebus/ltrace.h>
#include <syscall.h>


ssize_t sys_write(int fd, userptr_t *buf, size_t count){
	char *p = (char *) buf;
	if(fd == 1){
		for(int i = 0; i < (int) count; i++){
			putch(p[i]);
		}
	}
	return (int) count;
}


ssize_t sys_read(int fd, userptr_t *buf, size_t count){
	char *p = (char *) buf;
	if(fd == 1){
		for(int i = 0; i < (int) count; i++){
			p[i] = getch();
			if(p[i] < 0)
				return i;
		}
	}
	return (int) count;
}
