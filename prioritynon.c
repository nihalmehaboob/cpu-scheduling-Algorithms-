#include<stdio.h>
int n;
struct process{
int pid;
int at;
int bt;
int ct;
int ta;
int wt;
int p;
};
struct process p[15];
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
void priority(struct process *p,int n){
    int prev=p[0].at;
    for(int i=0;i<n;++i){
        int min=p[i].p;
        int minind=i;
        int flag=0;
        for(int j=i+1;j<n;++j){
            if(p[j].at>prev){
                break;
            }
            if(p[j].p>min){
                int min=p[j].p;
                int minind=j;
                flag=1;
            }
        }
        if(flag==1){
            struct process temp=p[minind];
            p[minind]=p[i];
            p[i]=temp;
        }
        p[i].wt = prev - p[i].at;
        if (p[i].wt < 0)
            p[i].wt = 0;

        p[i].ta = p[i].bt + p[i].wt;
        prev=p[i].at+p[i].ta;
        p[i].ct=prev;
    }
}

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
        printf("enter the priority :");
        scanf("%d",&p[i].p);

    }
    sort(p,n);
    priority(p,n);
    printf("\n");
    printf("process id\tarrival time\tburst time\tcompleteion time\tturn around time\twaiting time\n");
    for(int i=0;i<n;++i){
        printf("  %d\t\t   %d\t\t    %d\t\t     %d\t\t\t    %d     \t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].ta,p[i].wt);
    }

}