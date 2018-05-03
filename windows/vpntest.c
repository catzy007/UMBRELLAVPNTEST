#include <stdio.h>
#include <conio.h>
#include "rlutil.h"

//core_program
void tstcore(char **addr,int count){
  int n=0;
  char *command=malloc(sizeof(char)*128);
  while(n<count-1){
    strcpy(command,"ping -n 1 ");
    strcat(command,addr[n]);
    strcat(command," | find \"TTL=\"");
    //printf("%s\n",command); //debug_line_can_be_deleted
    system(command);
    n++;
  }
  free(command);
}

int main(){
//add_some_variables_and_allocate_mem
  system("title UMBRELLA-VPNTEST");
  setColor(11);
  int count=0,n=0,size=0;
  char temp[255]={'\0'}; //https://maximum dns=250 char. stackoverflow.com/questions/32290167
  char **addr=malloc(sizeof(char*)*2); //allocate some memory

//interface_and_help
  printf("UMBRELLA-VPNTEST V2.1\n");
  printf("usage : Type as many address you want\n");
  printf("then type \"BEGIN\" to begin test\n\n");

  while(strcmp(temp,"BEGIN")!=0){
    addr=realloc(addr,sizeof(char*)*(count+1)); //reallocate some memory
    if(!addr){ //allocate check
      printf("Can't allocate more memory - %d\n",sizeof(char*)*(count+1));
      return -1;
    }

    printf("IP Address %.3d : ",count+1);
    scanf("%s",temp);

    size=0;
    while(temp[size] != '\0'){
      size++; //count size of input
    }
    addr[count]=malloc(sizeof(char)*(size+1)); //allocate memory based on size of input

    strcpy(addr[count],temp); //put input into allocated memory
    //printf("idx=%d size=%d addr=%p cntnt=%s\n",count,size,&addr[count],addr[count]); //debug_line_can_be_deleted
    count++;
  }

//starting_vpntest_core
  printf("\nVPNTEST BEGIN . . .\n");
  tstcore(addr,count); //run test

//free_some_memory
  for(n=0;n<count;n++){
    //printf("%.2d %p\n",n,&addr[n]); //debug_line_can_be_deleted
    free(addr[n]);
  }
  free(addr);

//2018 Bagus Saputra
//this program uses https://github.com/tapio/rlutil
  return 0;
}
