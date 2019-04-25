#include<iostream>
#include<cmath>
using namespace std;
double u[100],v[100];//declaring arrays for membership functions of tempsense and levelsense
int p[10];float q[10];//p array is for storing the linguistic variables of tempsense and level sense in which the inpus lie
int tempsense(double t){//q array if for stooring the minimum membership value of tempsense nd levelsense
                       //this func is for finding out the range in which the input lies nd find its membership value
	if(t>=0&&t<=20){
		u[0]=1-(t/20);
	}
	if(t>=10&&t<=22.5){
		u[1]=(t-10)/25;
	}
	if(t>=22.5&&t<=35){
		u[1]=(35-t)/12.5;
	}
	if(t>=30&&t<=52.5){
		u[2]=(t-30)/22.5;
	}
	if(t>=52.5&&t<=75){
		u[2]=(75-t)/22.5;
	}
	if(t>=60&&t<=77.5){
		u[3]=(t-60)/17.5;
	}
	if(t>=77.5&&t<=95){
		u[3]=(95-t)/17.5;
	}
	if(t>=85&&t<=125){
		u[4]=(t-85)/40;
	}
}
int levelsense(double l)//for finding the range in which input levelsense lies nd find its membership values
{
	if(l>=0&&l<=2){
		v[0]=1-(l/2);
	}
	if(l>=1.5&&l<=2.75){
		v[1]=(l-1.5)/1.25;
	}
	if(l>=2.75&&l<=4){
		v[1]=(4-l)/1.25;
	}
	if(l>=3&&l<=5){
		v[2]=(l-3)/2;
	}
	if(l>=5&&l<=7){
		v[2]=(7-l)/2;
	}
	if(l>=6&&l<=7.315){
		v[3]=(l-6)/1.315;
	}
	if(l>=7.315&&l<=8.5){
		v[3]=(8.5-l)/1.185;
	}
	if(l>=7.5&&l<=10){
		v[4]=(l-7.5)/2.5;
	}
}
double w[10];//for membership value of heatlknob
double a1,b1,c1,d1;// storing the all the membership values before nd after applying mamdanis rule for a given input
double heatknob(double l1)//function is for calculating membership values for heat knob
{
	a1=b1=c1=d1=0;
	if(l1>=0&&l1<2){
		w[0]=1-(l1/2);
		a1=w[0];
		c1=q[0];
		//cout<<q[0]<<endl;
	}
	if(l1>1.5&&l1<=2.75){
		w[1]=(l1-1.5)/1.25;
		if(a1!=0)
		b1=w[1];
		else
		a1=w[1];
		if(q[1]!=0){
		if(c1!=0)
		d1=q[1];
		else
		c1=q[1];
	}
	//cout<<c1<<"  "<<d1;
	}
	if(l1>=2.75&&l1<4){
		w[1]=(4-l1)/1.25;
		if(a1!=0)
		b1=w[1];
		else
		a1=w[1];
		if(c1==0)
		c1=q[1];
	}
	if(l1>3&&l1<=5){
		w[2]=(l1-3)/2;
		if(a1!=0)
		b1=w[2];
		else
		a1=w[2];
		if(q[2]!=0){
			if(c1!=0)
			d1=q[2];
			else
			c1=q[2];
		}
	}
	if(l1>=5&&l1<7){
		w[2]=(7-l1)/2;
		if(a1!=0)
		b1=w[2];
		else
		a1=w[2];
		if(c1==0)
		c1=q[2];
	}
	if(l1>6&&l1<=7.315){
		w[3]=(l1-6)/1.315;
		if(a1!=0)
		b1=w[3];
		else
		a1=w[3];
		if(q[3]!=0){
		    if(c1!=0)
		    d1=q[3];
		    else
		    c1=q[3];
		}
	}
	if(l1>=7.315&&l1<8.5){
		w[3]=(8.5-l1)/1.185;
		if(a1!=0)
		b1=w[3];
		else
		a1=w[3];
		if(c1==0)
		c1=q[3];
	}
	if(l1>=7.5&&l1<10){
		w[4]=(l1-10)/2.5;
		if(a1!=0)
		b1=w[4];
		else
		a1=w[4];
		if(q[4]!=0)
		{
		if(c1!=0)
		   d1=q[4];
		   else
		   c1=q[4];
	}
	}
	double e1,e2;
	double e=max(a1,b1);//finding max of two membership values
	//cout<<a1<<","<<b1<<","<<c1<<","<<d1<<endl;
    if(c1!=0&&d1!=0)
    {
        if((e>c1&&e<d1)||(e>d1&&e<c1))
		e1=e;
		else{
		e2=min(a1,b1);//minimum of membership values
		if((e2>c1)&&(e2<d1)||(e2>d1&&e2<c1))
		e1=e2;
		else{
		e1=min(c1,d1);//minimum of respective q values
		}
		}	
	}
	else    
	e1=min(e,c1);
//	cout<<e1;
	return e1;
}

int main()
{
	double t,l;//variables for taking input of temp nd level
	cout<<"enter temp";
	cin>>t;
	cout<<"enter level";
	cin>>l;
	for(int j=0;j<5;j++)//initializing the arrays q,u,v as zeroes
	{
		q[j]=0;
		u[j]=0;
		v[j]=0;
	}
    //string s[5];
	int a[5][5];//decl;aring a resultant matrix for diff combinations of tempsense nd levelsense as heatknob
	a[0][0]=a[1][1]=a[2][2]=a[4][3]=2;          //giving elements to the matrix a
	a[0][1]=a[3][3]=1;
	a[0][2]=a[1][2]=a[1][3]=a[1][4]=a[2][3]=a[2][4]=a[3][4]=a[4][4]=a[0][3]=a[0][4]=0;
	a[1][0]=a[2][1]=a[3][1]=a[3][2]=a[4][1]=a[4][2]=3;
	a[2][0]=a[3][0]=a[4][0]=4;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<a[i][j]<<" ";//displaying the matrix given by the user
		}
		cout<<endl;
	}
	cout<<endl;
	tempsense(t);//calling the func for temp
	levelsense(l);//calling the func for level
	int m[5][5];float n[5][5];int k=0;//matrix m[][] is for storing the linguistic variables in which input lies nd n[][] if for storing corresponding membership 
	                                  //values of m[][] using mamdani rules 
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(u[j]!=0&&v[i]!=0){
				m[i][j]=a[i][j];
				p[k]=m[i][j];
				k++;
				n[i][j]=min(v[i],u[j]);
				q[p[k-1]]=n[i][j];
			}
			else{
			n[j][i]=0;
			m[j][i]=0;
		}
		}
	}
		for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<m[i][j]<<","<<n[i][j]<<" ";//displaying the linguistic variables nd corresponding membership values(using mamdani rule) resp
		}
		cout<<endl;
}
double s1=0,sum=0;//sum nd s1 are used to find the overall average 
	double o=1;//o denotes the values of x which are used to fing COA
	while(o<=10)//loop for finding COA
	{
		cout<<heatknob(o)<<endl;
		sum=sum+(o*heatknob(o));
		s1=s1+heatknob(o);
		o=o+0.5;
	}
	cout<<sum/s1;//gives the final COA
}
