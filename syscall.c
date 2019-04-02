#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"
#include "syscall.h"


int intCont16 = 0;

// User code makes a system call with INT T_SYSCALL.
// System call number in %eax.
// Arguments on the stack, from the user call to the C
// library system call function. The saved user %esp points
// to a saved program counter, and then the first argument.

// Fetch the int at addr from the current process.
int
fetchint(uint addr, int *ip)
{
  struct proc *curproc = myproc();

  if(addr >= curproc->sz || addr+4 > curproc->sz)
    return -1;
  *ip = *(int*)(addr);
  return 0;
}

// Fetch the nul-terminated string at addr from the current process.
// Doesn't actually copy the string - just sets *pp to point at it.
// Returns length of string, not including nul.
int
fetchstr(uint addr, char **pp)
{
  char *s, *ep;
  struct proc *curproc = myproc();

  if(addr >= curproc->sz)
    return -1;
  *pp = (char*)addr;
  ep = (char*)curproc->sz;
  for(s = *pp; s < ep; s++){
    if(*s == 0)
      return s - *pp;
  }
  return -1;
}

// Fetch the nth 32-bit system call argument.
int
argint(int n, int *ip)
{
  return fetchint((myproc()->tf->esp) + 4 + 4*n, ip);
}

// Fetch the nth word-sized system call argument as a pointer
// to a block of memory of size bytes.  Check that the pointer
// lies within the process address space.
int
argptr(int n, char **pp, int size)
{
  int i;
  struct proc *curproc = myproc();
 
  if(argint(n, &i) < 0)
    return -1;
  if(size < 0 || (uint)i >= curproc->sz || (uint)i+size > curproc->sz)
    return -1;
  *pp = (char*)i;
  return 0;
}

// Fetch the nth word-sized system call argument as a string pointer.
// Check that the pointer is valid and the string is nul-terminated.
// (There is no shared writable memory, so the string can't change
// between this check and being used by the kernel.)
int
argstr(int n, char **pp)
{
  int addr;
  if(argint(n, &addr) < 0)
    return -1;
  return fetchstr(addr, pp);
}

extern int sys_chdir(void);
extern int sys_close(void);
extern int sys_dup(void);
extern int sys_exec(void);
extern int sys_exit(void);
extern int sys_fork(void);
extern int sys_fstat(void);
extern int sys_getpid(void);
extern int sys_kill(void);
extern int sys_link(void);
extern int sys_mkdir(void);
extern int sys_mknod(void);
extern int sys_open(void);
extern int sys_pipe(void);
extern int sys_read(void);
extern int sys_sbrk(void);
extern int sys_sleep(void);
extern int sys_unlink(void);
extern int sys_wait(void);
extern int sys_write(void);
extern int sys_uptime(void);
extern int sys_shutdown(void);
extern int sys_reboot(void);
extern int sys_setpriority(void);
extern int sys_getpriority(void);
extern int sys_date(void);

static int (*syscalls[])(void) = {
[SYS_fork]    sys_fork,
[SYS_exit]    sys_exit,
[SYS_wait]    sys_wait,
[SYS_pipe]    sys_pipe,
[SYS_read]    sys_read,
[SYS_kill]    sys_kill,
[SYS_exec]    sys_exec,
[SYS_fstat]   sys_fstat,
[SYS_chdir]   sys_chdir,
[SYS_dup]     sys_dup,
[SYS_getpid]  sys_getpid,
[SYS_sbrk]    sys_sbrk,
[SYS_sleep]   sys_sleep,
[SYS_uptime]  sys_uptime,
[SYS_open]    sys_open,
[SYS_write]   sys_write,
[SYS_mknod]   sys_mknod,
[SYS_unlink]  sys_unlink,
[SYS_link]    sys_link,
[SYS_mkdir]   sys_mkdir,
[SYS_close]   sys_close,
[SYS_shutdown] sys_shutdown,
[SYS_reboot]   sys_reboot,
[SYS_reboot]   sys_reboot,
[SYS_setpriority] sys_setpriority,
[SYS_getpriority] sys_getpriority, 
[SYS_date]    sys_date,
};

void
syscall(void)
{
  int num;
  struct proc *curproc = myproc();
	
  char *syscall_nombres[]
					= {"SYS_nada",
                        "SYS_fork",
                        "SYS_exit",
                        "SYS_wait",
                        "SYS_pipe",
                        "SYS_read",
                        "SYS_kill",
                        "SYS_exec",
                        "SYS_fstat",
                        "SYS_chdir",
                        "SYS_dup",
                        "SYS_getpid",
                        "SYS_sbrk",
                        "SYS_sleep",
                        "SYS_uptime",
                        "SYS_open",
                        "SYS_write",
                        "SYS_mknod",
                        "SYS_unlink",
                        "SYS_link",
                        "SYS_mkdir",
                        "SYS_close",
                        "SYS_shutdown",
                        "SYS_reboot",
                        "SYS_setpriority",
                        "SYS_getpriority",
					  	"SYS_date"};

  num = curproc->tf->eax;
  if(num > 0 && num < NELEM(syscalls) && syscalls[num]) {
 
	if(num != 16){
		cprintf(" Syscall: %d → ", num);
		cprintf(syscall_nombres[num]);
		cprintf("\n");
	} else {
		intCont16 = intCont16 + 1;
	}
	  
	if(intCont16 >= 1416) {
		cprintf("\nSe llamo %d veces a:\n - Syscall: 16 → SYS_write", intCont16);
		intCont16 = 0;
  	}
	  
    curproc->tf->eax = syscalls[num]();
	  
  } else {
    cprintf("%d %s: unknown sys call %d\n",
            curproc->pid, curproc->name, num);
    curproc->tf->eax = -1;
  }
}
