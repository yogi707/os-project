#include<stdio.h>
struct process
{
int at,bt;

};
int main()
{
int n,i=0;
printf("\n enter the Number of process :  ");
scanf("%d",&n);
struct process p[n];
 for(i=0;i<n;i++)
 {
printf("\n enter arival time : ");
scanf("%d",&p[i].at);
printf("\n enter brust time :  ");
scanf("%d",&p[i].bt);

 }

 for(i=0;i<n;i++)
 {
printf("\n arival time : %d ",p[i].at);
printf("\n brust time :  %d",p[i].bt);
printf("\n *****************************");
 }

 int j=0;
int temp1,temp3;
for(i=0;i<=n-1;i++){
	for(j=0;j<n-i-1;j++)
  {
		if(p[j].at>p[j+1].at)
    {
printf("\n");
			temp1=p[j].at;
			temp3=p[j].bt;
			p[j].at=p[j+1].at;
			p[j].bt=p[j+1].bt;
			p[j+1].at=temp1;
			p[j+1].bt=temp3;
			}
		}
}
int total=0;
 for(i=0;i<n;i++)
 {
printf("\n P[%d] arival time  : %d ",i,p[i].at);
printf("\n P[%d] brust time :  %d",i,p[i].bt);
total=total+p[i].bt;
printf("\n *****************************");
 }

int q1[n],q2[n],t1,t2,k=0,time=0;
printf("\n enter quntum for 1st que :");
scanf("%d",&t1);
j=0;

for (i=0;i<n;i++)
{
if(p[i].at<=t1)
{
q1[k]=p[i].bt;
k++;
}
}
for(i=0;i<k-1;i++)
{
  printf("\n process[%d] executed from time %d : ",i,time);
  q1[i]=q1[i]-t1;
  time=time+t1;
  printf(" to  %d ",time);
  q2[i]=q1[i];

}



}
