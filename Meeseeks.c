#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int childNum;   
    int grandchildNum;   
    int originalpid=getpid();
    int level = 1;
    int instace = 1;
    int solNum;   
    srand(time(NULL));
    printf("Cuantas solicitudes tiene? \n");
    scanf("%d", &solNum);

    int solTypeArray[solNum]; 
    char solArray[solNum][20];  
    int dificultyArray[solNum];

    int count = 0;
    while(count!=solNum){
        printf("Que tipo de solicitud es? (1 aritmetica, 2 programa, 3 textual) \n");
        scanf("%d", &solTypeArray[count]);
        printf("Cual es su solicitud? \n");
        scanf("%s", &solArray[count]);


        if(solTypeArray[count] != 3){
            dificultyArray[count] =    85 + rand() % 15;



        }else if(solTypeArray[count] == 3){
        printf("Cual es la dificultad de esta solicitud? ( de 0 a 100,  -1 para azar)\n");
        scanf("%d", &dificultyArray[count]);
        if(dificultyArray[count] == -1){
            dificultyArray[count] =     rand() % 100;
        }

        }
        count++;
    }

    count = 0;



    while(count!=solNum){

        if(solTypeArray[count]==1){///aritmetica
            pid_t   childPid = fork();

        }else if(solTypeArray[count]==2){///programa
            pid_t   childPid = fork();

            int status = system(solArray[count]);



        }else if(solTypeArray[count]==3){///textual
            pid_t   childPid = fork();
            pid_t ppid = getppid() ;
            printf("Hi I'm Mr Meeseeks! Look at Meeeee. (pid: %ld, ppid: %ld, N: %d, i:%d)\n", (long) childPid,(long) ppid, level, instace);
        } 



        count++;

    }



/*

	printf("Cuantos hijos? \n");
    scanf("%d", &childNum);

	printf("Cuantos nietos por hijo?\n");
    scanf("%d", &grandchildNum);


    for(int i=0;i<childNum;i++){
   		pid_t	childPid = fork();
        if(childPid== 0)
        {
            //printf("hijo %d de padre pid %d\n",getpid(),getppid());
   			for(int i=0;i<grandchildNum;i++){
   				pid_t	grandchildPid = fork();
        		if(grandchildPid== 0){
            		//printf("hijo %d de padre pid %d\n",getpid(),getppid());
            		 //printf("Hijo finalizado\n");
        			    		sleep(2);

        		}
    		}
    		sleep(2);
    		exit(0);


        }
    }*/


    if (getpid() == originalpid) {
        char treeInfo[1000];
        sprintf(treeInfo, "pstree -p  %d", originalpid);
        system(treeInfo);


        sprintf(treeInfo, "ps");
        system(treeInfo);

    }

		
}


