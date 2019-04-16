#include<stdio.h>
struct process
{
int at,bt,ct,id;

};
int main()
{
int n,i=0;
printf("\n enter the Number of process :  ");
scanf("%d",&n);
struct process p[n];
 for(i=0;i<n;i++)
 {
printf("\n enter process id :  ");
scanf("%d",&p[i].id);
printf("\n enter arival time : ");
scanf("%d",&p[i].at);
printf("\n enter brust time :  ");
scanf("%d",&p[i].bt);

 }

 for(i=0;i<n;i++)
 {
printf("\n process[%d] arival time : %d ",p[i].id,p[i].at);
printf("\n process[%d] brust time  : %d ",p[i].id,p[i].bt);
printf("\n *****************************");
 }

 int j=0;
int temp1,temp3,temp2;
for(i=0;i<=n-1;i++){
	for(j=0;j<n-i-1;j++)
  {
		if(p[j].at>p[j+1].at)
    {
printf("\n");
			temp1=p[j].at;
			temp3=p[j].bt;
      temp2=p[j].id;
			p[j].at=p[j+1].at;
			p[j].bt=p[j+1].bt;
      p[j].id=p[j+1].id;
			p[j+1].at=temp1;
			p[j+1].bt=temp3;
      p[j+1].id=temp2;
			}
		}
}
int total=0;
 for(i=0;i<n;i++)
 {
printf("\n P[%d] arival time  : %d ",p[i].id,p[i].at);
printf("\n P[%d] brust time   : %d ",p[i].id,p[i].bt);
total=total+p[i].bt;
printf("\n *****************************");
 }

int q1[n],q2[n],q3[n],t1,t2,k=0,time=0,l=0,u=0,q4[n],q5[n],q6[n],h=0;
printf("\n enter quntum for 1st que : ");
scanf("%d",&t1);
printf("\n enter quntum for 2nd que : ");
scanf("%d",&t2);
j=0;



for (i=0;i<n;i++)
{
q1[k]=p[i].bt;
q4[k]=p[i].id;
k++;
}
printf("\n ready que process order");
printf("\n *********************");
for(i=0;i<k;i++)
{

  printf("\n process[%d]",q4[i]);
  printf("\n brust time %d : ",q1[i]);
}
printf("\n********************");
do
{
for(i=0;i<=k-1;i++)
{
  printf("\n process[%d] executed from time : %d ",q4[i],time);
  if(q1[i]<=t1 && q1[i]>=0)
  {
  time =time+q1[i];
  q1[i]=0;
  }
  else if(q1[i]>0)
  {
  q1[i]=q1[i]-t1;
  time=time+t1;
  printf("\n process[%d] time value : %d ",q4[i],time);
  q2[l]=q1[i];
  q5[l]=q4[i];
  l++;
  }
if(q1[i]==0)
{
printf("\n process[%d] completed with time %d",q4[i],time);
h=q4[i];
p[h].ct=time;
//printf("\n process[%d] complition time %d : ",i,p[i].ct);

}

  }


printf("\n**************************");
  for(i=0;i<l;i++)
  {
    printf("\n que 2 with process[%d] and value %d",q5[i],q2[i]);
  }

printf("\n*************************");


for(i=0;i<l;i++)
{
if(q2[i]<=t2&& q2[i]>=0)
{
time =time+q2[i];
q2[i]=0;
}
else if(q2[i]>0)
{
q2[i]=q2[i]-t2;
time=time+t2;
printf("\n process[%d] value of time : %d",q5[i],time);
q3[u]=q2[i];
q6[u]=q5[i];
u++;
}
if(q2[i]==0)
{
printf("\n process[%d] completed with time %d",q5[i],time);
h=q5[i];
p[h].ct=time;
//printf("\n process[%d] completed with time %d",i,p[i].ct);

}

}
printf("\n******************");
for(i=0;i<u;i++)
{
  printf("\n que 3 with process[%d] value %d",q6[i],q3[i]);
}
printf("\n******************");


for(i=0;i<=u-1;i++)
{
	for(j=0;j<u-i-1;j++)
{
if(q3[j]<q3[j+1])
{
temp1=q3[j];
temp2=q6[j];
q3[j]=q3[j+1];
q6[j]=q6[j+1];
q3[j+1]=temp1;
q6[j+1]=temp2;
}

}
}

for(i=0;i<u;i++)
{
  printf("\n que 3  sorted with process[%d] value %d",q6[i],q3[i]);
}


for(i=0;i<u;i++)
{
time=time+q3[i];
q3[i]=0;
printf("\n process[%d] completed with time %d",q6[i],time);
h=q6[i];
p[h].ct=time;
//printf("\n process[%d] completed with time %d",q6[i],p[i].ct);

}

printf("\n total brust time %d",total);

}while(total!=time);

for(i=0;i<=n-1;i++){
	for(j=0;j<n-i-1;j++)
  {
		if(p[j].id>p[j+1].id)
    {
printf("\n");
			temp1=p[j].at;
			temp3=p[j].bt;
      temp2=p[j].id;
			p[j].at=p[j+1].at;
			p[j].bt=p[j+1].bt;
      p[j].id=p[j+1].id;
			p[j+1].at=temp1;
			p[j+1].bt=temp3;
      p[j+1].id=temp2;
			}
		}
}


// complition time
j=1;
float avgwt,avgtat;
int avg1=0,avg2=0;
printf("\n ###########################");
printf("\n Process  ||   Arival Time   ||    Brust Time   ||    Complition Time   ||    Waiting Time   ||    T.A.T   ");
for(i=0;i<n;i++)
{
  k=p[j].ct - p[i].bt;
  avg1=avg1+k;
  h=p[j].ct - p[i].at;
  avg2=avg2+h;
printf("\n p[%d]            %d                 %d                    %d                      %d               %d   ",p[i].id,p[i].at,p[i].bt,p[j].ct,k,h);
j++;
}
printf("\n");
avgwt=avg1/n;
avgtat=avg2/n;
printf("\n Average Waiting time  : %f ",avgwt);
printf("\n Average Turn around time : %f",avgtat);
printf("\n");
}
