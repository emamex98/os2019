#include "types.h"
#include "stat.h"
#include "user.h"

 int main(int argc, char ** argv){
  int pid;
  int prio;

   pid = atoi(argv[1]);
  prio = atoi(argv[2]);
  setpriority(pid,prio);
  exit();
}