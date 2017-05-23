#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){

  int i = 500;
  int virtual =(int)&i;
  int physical=0;
  
  printf(1,"\n Testing Part 1: Memory translation system cal: \n system call v2p(int virtual, int *physical) \n\n");
  
  if(v2p(virtual, &physical))
	printf(1,"\n Virtual address 0x%x is mapped to physical address 0x%x \n",virtual, physical);
  else
	printf(2,"\n v2p system call faild! \n");
	
   printf(1,"\n An example of correct output:\n Virtual address 0x2FCC is mapped to physical address 0xDEDFFCC  \n");
   printf(1,"\n But it is not a guarantee that the system call is correct. The code will be checked! \n");
  
  //____________________________________________________________________
  
   printf(1,"\n Testing Part 2: Null pointer dereference \n");

   int *p;
   p = &i;

   printf(1,"\n Now we will dereference a proper pointer, we should not get an error\n");

   printf(1,"\n the contents of the proper pointer are %d and it points to address:0x%x\n\n",*p,&p);
   printf(1,"\n We are going to dereference the null pointer now\n");
   p = 0;
   printf(1,"\n Before fixing the null pointer problem we would get an output like this:\n the contents of the null pointer are 0x83E58955 and it points to address: 0x0\n");
   printf(1,"\n The correct output should be:\n pid 3 lab2: trap 14 err 4 on cpu 0 eip 0x10ba addr 0x0--kill proc \n\n");
   
   printf(1,"\n The contents of the null pointer are 0x%x and it points to address: 0x%x\n",*p,p);
  exit();
}
