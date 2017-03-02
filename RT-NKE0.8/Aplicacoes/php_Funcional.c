#include "../Kernel/kernel.h"

sem_t s0,s1,s2;
int num=0, flag=3;

void task0()
{
    setmyname(__FUNCTION__);

    while(1){
	if(flag==3){
		semwait(&s0);
		//nkprint(".",0);
		sempost(&s0);
	}
    }
    nkprint("fim! ",0);
    taskexit();
}

void task1()
{
    setmyname(__FUNCTION__);
    while(1){
    }
    taskexit();
}

void task2()
{
    setmyname(__FUNCTION__);
    flag=3;
    semwait(&s0);
    while(1){
//	sempost(&s0);
	}
    taskexit();   
}

int main(int argc, char *argv[])
{
  seminit(&s0,1);
  int t4,t2,t3;
  taskcreate(&t2,task0, 10, 2);
  taskcreate(&t3,task1, 15, 4);
  taskcreate(&t4,task2, 35, 10);
  start(RM);
  return 0;
}
