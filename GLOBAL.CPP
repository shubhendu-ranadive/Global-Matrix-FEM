#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#define VAR 100001
void main(){
clrscr();
int n,i,j;
float k[20],a[20],h[20];
float glb[20][20],heat[20],temp[20];
cout<<"Enter number of elements\n";
cin>>n;
for(i=0;i<=n;i++){
	for(j=0;j<=n;j++){
		glb[i][j]=0;
	}
}
cout<<"Enter k,a,h for "<<n<<" elements\n";
for(i=0;i<n;i++)
{
	cin>>k[i]>>a[i]>>h[i];
}
cout<<"Enter heat at first and last points\n";
cin>>heat[0]>>heat[n];
temp[0]=VAR;
temp[n]=VAR;
for(i=1;i<n;i++){
heat[i]=VAR;
temp[i]=0;
}
//calculation of global matrix
for(i=0;i<=n;i++){
	for(j=0;j<=n;j++){
		if(i==j){
			if(i==0){
			glb[i][j]=k[i]*a[i]/h[i];
			}
			else if(i==n){
			glb[i][j]=k[i-1]*a[i-1]/h[i-1];
			glb[i-1][j]=(-1)*k[i-1]*a[i-1]/h[i-1];
			glb[i][j-1]=(-1)*k[i-1]*a[i-1]/h[i-1];
			}
			else{
			glb[i][j]=(k[i]*a[i]/h[i])+(k[i-1]*a[i-1]/h[i-1]);
			glb[i-1][j]=(-1)*k[i-1]*a[i-1]/h[i-1];
			glb[i][j-1]=(-1)*k[i-1]*a[i-1]/h[i-1];
			}
		}
	}
}
cout<<"Output\n";
for(i=0;i<=n;i++){
	for(j=0;j<=n;j++){
		cout<<setw(12)<<setprecision(5)<<glb[i][j];
	}
cout<<"\n";
}
for(i=0;i<=n;i++){
cout<<heat[i]<<"  "<<temp[i]<<"\n";
}

getch();
}