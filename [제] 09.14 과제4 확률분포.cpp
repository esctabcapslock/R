#include<stdio.h>
int com(int x,int y){return (x==y || y==0) ? 1 : com(x-1,y-1)*x/y;}
int abs(int x){return x>0?x:-x;}
long long int fac(long long int x){
	long long int s=1;
	for(int i=1;i<=x;i++) s*=i;
	return s;
}
int ar[4][50]={};
void printn(int x,char c, int f,int sum, double su){
	long long int s=0;
	for(int i=0;ar[x][i];i++){
		s+=ar[x][i];
		if (i==0) printf("P(%c<=x) = 0.000000 (x<%d)\n",c,i-f);
		if (s!=sum) printf("P(%c<=x) = %lf (x<%d)\n",c,s/su,i+1-f);
		else printf("P(%c<=x) = %lf (x>=%d)\n",c,s/su,i-f);
	} puts("");
}
int main(){
	long long int x,y,s=0,sum=0;
	for(int i=0;i<=5;i++) for(int j=0;j<=3;j++){
			s=fac(8)/fac(i)/fac(j)/fac(8-i-j)*com(8,i)*com(8-i,j);
			ar[0][i]+=s;
			ar[1][j]+=s;
			ar[2][i-j+3]+=s;
			ar[3][abs(i-j)]+=s;
			sum+=s;
		}
	double su=sum;
	for(int i=0;ar[0][i];i++) printf("P(X=%d) = %lf\n",i,ar[0][i]/su);puts("");
	for(int i=0;ar[1][i];i++) printf("P(Y=%d) = %lf\n",i,ar[1][i]/su);puts("");
	for(int i=0;ar[2][i];i++) printf("P(V=%d) = %lf\n",i-3,ar[2][i]/su);puts("");
	for(int i=0;ar[3][i];i++) printf("P(W=%d) = %lf\n",i,ar[3][i]/su);puts("");
	printn(0,'X',0,sum,su);
	printn(1,'Y',0,sum,su);
	printn(2,'V',3,sum,su);
	printn(3,'W',0,sum,su);
}
