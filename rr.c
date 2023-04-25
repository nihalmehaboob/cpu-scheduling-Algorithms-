#include<stdio.h>
int n;
struct process{
int pid;
int at;
int bt;
int ct;
int ta;
int wt;
};
struct process p[15];
int tq;
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
void rr(struct process *p,int  n){
    int rem[15];
   int  max=p[0].bt;
   int maxindex=0;
   // finding max burst
    for(int i=0;i<n;++i){
        rem[i]=p[i].bt;
    if(max<p[i].bt){
        max=p[i].bt;
        maxindex=i;
    }
    }
    // -------

    int sum=0;
    while(max>0){
        for(int i=0;i<n;++i){
            if(rem[i]>0 && sum>=p[i].at){
                if(rem[i]-tq>=0){
                    if(i==maxindex){
                    sum +=tq;
                    rem[i] -=tq;
                    max -=tq;
                     p[i].ct=sum;
                    }
                    else{
                    sum +=tq;
                    rem[i] -=tq;
                     p[i].ct=sum;
                    }
                }
                else{
                    if(i==maxindex){
                    sum +=rem[i];
                    rem[i]=0;
                    max -=tq;
                    p[i].ct=sum;
                    }
                    else {
                    sum +=rem[i];
                    rem[i]=0;
                    p[i].ct=sum;
                    }
                }
            }
        }
    }
    for(int i=0 ;i<n;++i){
        p[i].ta=p[i].ct-p[i].at;
        p[i].wt=p[i].ta-p[i].bt;
    }

}
void main(){
    int n;
    printf("how many processes :");
    scanf("%d",&n);
    printf("enter ur time quantum :");
    scanf("%d",&tq);
    for(int i=0 ;i<n;++i){
        printf("enter ur process id of process %d :",i+1);
        scanf("%d",&p[i].pid);
        printf("enter arrival time of process %d :",i+1);
        scanf("%d",&p[i].at);
        printf("enter the burst time of process %d :",i+1);
        scanf("%d",&p[i].bt);

    }
    sort(p,n);
    

    rr(p,n);
    printf("\n");
    printf("process id\tarrival time\tburst time\tcompleteion time\tturn around time\twaiting time\n");
    for(int i=0;i<n;++i){
        printf("  %d\t\t   %d\t\t    %d\t\t     %d\t\t\t    %d     \t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].ta,p[i].wt);
    }

}
// done