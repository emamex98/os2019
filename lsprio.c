#include "types.h"
#include "stat.h"
#include "user.h"

 int main(int argc, char ** argv){
  int pid;

   pid = atoi(argv[1]);
  getpriority(pid);
  exit();
} 