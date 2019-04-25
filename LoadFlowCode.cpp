#include<iostream>
#include<complex>
#include<bits/stdc++.h>
using namespace std;
struct comp{
	double R;
	double X;
	double P;
	double Q;
	std::complex<double> Z;
	std::complex<double> E;
	std::complex<double> I;
	//int a;
	//int b;
	int n;
};
int main(){
	int N,a,b;
	double B,B1,B2,B3;
	cout<<"Enter the no of buses:";
	cin>>N;
	cout<<"enter base KVA ,base KV";
	cin>>B>>B1;
	B2=(B1*B1)*1000/B;
    B3=B/(B1*sqrt(3));
	cout<<endl;
	int A[N+1][N+1];
	for(int i=0;i<N+1;i++)
	for(int j=0;j<N+1;j++)
	A[i][j]=0;
	struct comp C[N];
	for(int i=0;i<N;i++){
		cout<<"Enter values of starting and end busno, resistance ,inductance,real power,reactive power:";
		cin>>a>>b>>C[i].R>>C[i].X>>C[i].P>>C[i].Q;
	    C[i].P=C[i].P;
	    C[i].Q=C[i].Q;
		C[i].E=1;
		C[i].I=0;
//		A[C[i].a][C[i].b]=1;
        A[a][b]=1;
       // A[b][a]=1;
//		A[C[i].b][C[i].a]=1;
		C[i].n=i;
	}
	int count2=0,count=0,count1=0;
	while(count1<4){
		count=0;
		count2=0;
    	//for current ----iteration
    	cout<<endl;
    	for(int i=0;i<=N;i++){
    		for(int j=0;j<=N;j++){
    		cout<<A[i][j]<<"  ";
    	}
    	cout<<endl;
    }
    	cout<<"current values"<<endl;
	for(int j=N-1;j>=0;j--){
		double prev1=abs(C[j].I);
		std::complex<double> S(C[j].P,C[j].Q);
		std::complex<double> x1;
		std::complex<double> x3;
		x1=S/(B*C[j].E);
		x3=conj(x1);
		std::complex<double> x2(0,0);
		if(j!=N-1){
	    int	j1=j+1;
			for(int k=j1+1;k<=N;k++){
				if(A[j1][k]==1 )//|| A[k][j1]==1)
				x2=x2+C[k-1].I;
			}
		}
		C[j].I=x3+x2;
		double present1=abs(C[j].I);
		long double sub1=present1-prev1;//comaparing previous and present values
		cout<<C[j].I<<"  "<<present1<<"  "<<prev1<<"  "<<sub1<<endl;
		 if((sub1>0 && sub1<=0.001) || (sub1<0 && sub1>=-0.001)){
			count++;
		}		
		}
	
	std::complex<double> V=1;
		//for voltage
		cout<<endl<<"voltage values"<<endl;
		if(count1==3)
		cout<<"from to   "<<"voltage magnitude   "<<"angle in degrees"<<endl;
	for(int i=0;i<N;i++){
		double prev2;
		for(int j=i+1;j<=N;j++){
			
		
			if(A[i][j]==1){
			// || A[j][i]==1){
			   prev2=abs(C[j-1].E);
				
				std::complex<double> Z(C[j-1].R,C[j-1].X);
				if(i==0)
				  C[j-1].E=V-(C[j-1].I*Z/B2);
				else
					C[j-1].E=C[i-1].E-(C[j-1].I*Z/B2);	
		double present2=abs(C[j-1].E);
		long double sub2=present2-prev2;//comaparing previous and present values
		if(count1==3){
		cout<<i<<"     "<<j<<"      "<<present2<<"        "<<arg(C[j-1].E)*180*7/22<<endl;//<<"  "<<C[j-1].E<<"  "<<prev2<<"  "<<sub2<<endl;
		 if((sub2>0 && sub2<=0.001) || (sub2<0 && sub2>=-0.001))
			count2++;
	//	}
          }
		}
	}
	}	
	cout<<count<<"   "<<count2;
//f(count==N && count2==N)//if in each iteration diff is less than 0.0001 for verifying it
		count1++;
}
std:: complex<double> L(0,0);
double f1=0.0,f2=0.0;
for(int i=0;i<N;i++){
//	std:: complex<double> Z(C[i].R,C[i].X);
//	cout<<B3<<"  "<<Z<<endl;
//	L=(C[i].I*C[i].I*Z*B3*B3)+L;
f1+=3.0*(abs((C[i].I)*B3)*abs((C[i].I)*B3))*(C[i].R);
f2+=3.0*(abs((C[i].I)*B3)*abs((C[i].I)*B3))*(C[i].X);
}

//cout<<"from to"<<"   "<<"voltage magnitude"<<"   "<<"angle in degrees"<<"   "<<"current magnitude";
//for(int i=0;i<N;i++){
//}
cout<<"Power losses real and reactive"<<f1<<"  "<<f2<<"    "<<B2<<" "<<B3<<endl;
	return 0;
}

