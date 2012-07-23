#include<cstdio>
#include<cstdlib>
#include "ghost.h"
#include "grader.h"
static int N;
static double Cx[100050];
static double Cy[100050];
static double Cz[100050];
static double Ty[100050];
static double Tz[100050];
static int mode=0;
static double ans_gx;
static double ans_gy;
static double ans_gz;

void answer(double gx,double gy,double gz)
{
	if(mode==1){
		ans_gx=gx;
		ans_gy=gy;
		ans_gz=gz;
	}
	else{
		fprintf(stderr,"You can call answer only in FindGhost.\n");
		return;
	}
}
int main()
{
	
	if(scanf("%d",&N)!=1){
		fprintf(stderr,"read error");
		return 1;
	}
	for(int i=0;i<N;i++){
		if(scanf("%lf%lf%lf",Cx+i,Cy+i,Cz+i)!=3){
			fprintf(stderr,"read error");
			return 1;
		}
	}
	for(int i=0;i<N;i++){
		if(scanf("%lf%lf",Ty+i,Tz+i)!=2){
			fprintf(stderr,"read error");
			return 1;
		}
	}
	mode=1;
	FindGhost(N,Cx,Cy,Cz,Ty,Tz);
	mode=0;
	printf("%+.20f %+.20f %+.20f\n",ans_gx,ans_gy,ans_gz);
    return 0;
}
