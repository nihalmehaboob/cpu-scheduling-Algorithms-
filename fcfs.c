#include<stdio.h>
int n;
struct process{
int pid;
int at;
int bt;
int ct;
int ta;
};
void sort(struct process *p,int n){
     struct process temp;
    for(int i=0;i<n;++i){
       
        for(int j=i+1;j<n;++j){
            if(p[i].at>p[j].at){
                  temp=p[i];
                 p[i]=p[j];
                 p[j]=temp;
            }
        }
    }
}
void fcfs(struct process *p,int n){
    p[0].ct=p[0].bt;
    int sum=p[0].bt;
    p[0].ta=p[0].bt-p[0].at;
    for(int i=1;i<n;++i){
        sum +=p[i].bt;
        p[i].ct=sum;
         p[i].ta=p[i].bt-p[i].at;
    }
}
struct process p[15];
void main(){
    int n;
    printf("how many processes :");
    scanf("%d",&n);
    for(int i=0 ;i<n;++i){
        printf("enter ur process id of process %d :",i+1);
        scanf("%d",&p[i].pid);
        printf("enter arrival time of process %d :",i+1);
        scanf("%d",&p[i].at);
        printf("enter the burst time of process %d :",i+1);
        scanf("%d",&p[i].bt);

    }
    sort(p,n);
    fcfs(p,n);
    printf("\n");
    printf("process id\tarrival time\tburst time\tcompleteion time\tturn around time\n");
    for(int i=0;i<n;++i){
        printf("  %d\t\t   %d\t\t    %d\t\t     %d\t\t\t    %d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].ta);
    }

}