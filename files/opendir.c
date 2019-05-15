#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char **argv){
  struct dirent *pDirent;
  DIR *pDir;
  if (argc < 2) {
      printf ("Usage: ./opendir <dirname>\n");
      return 1;
  }
  pDir = opendir (argv[1]);
  if (pDir == NULL) {
      printf ("Cannot open directory '%s'\n", argv[1]);
      return 1;
  }
  while ((pDirent = readdir(pDir)) != NULL) {
      printf ("name: %s inode: %d\n", pDirent->d_name,(int)pDirent->d_ino);
  }
  closedir (pDir);
  return 0;
}