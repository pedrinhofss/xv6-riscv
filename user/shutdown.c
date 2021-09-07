#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  printf("[TEST]: User program.\n");
  printf("Forking...\n");
  int pid = fork();
  if (pid > 0) {
    pid = wait((int*) 0);
    printf("Child %d is done.\n", pid);
  }
  else if (pid == 0) {
    printf("[CHILD]: doing something...\n");
    printf("[CHILD]: exiting...\n");
  }
  else {
    printf("fork error\n");
  }
  exit(0);
}
