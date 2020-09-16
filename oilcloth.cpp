#include <iostream>
#include <fstream>
//#include <math.h>

using namespace std;

int pow(int,int);

bool znak(int ro,int st){
	if(st==0) return true; //1
	else if(ro>pow(3,st-1) && ro<=2*pow(3,st-1)) return false;//0
	else return znak((ro+pow(3,st-1)-1)%pow(3,st-1)+1,st-1);
}

int pow(int b,int w){
	int r0 = 1;
	for(int i=1;i<=w;i++) r0*=b;
	return r0;
}

int main(){
	string st;
	cout<<"Podaj stopien rekurencji: ";
	cin>>st;
	int stl = atoi(st.c_str());
	ofstream plik("cerata"+st+".pbm");
	plik<<"P1\n"<<pow(3,stl)<<" "<<pow(3,stl)<<"\n";
	if(stl>10){
		stl=10; st="10";
	}
	const int W = pow(3,stl);
	const int H = W;
	const int duzaL = pow(3,2*stl-1);
	for(int i=0;i<duzaL;i++){
		for(int j=1;j<=3;j++){
			int poz = 3*i+j;
			int r = ((poz+W-1)/W);
			int k = poz - (r-1)*W;
			//r+=1;k+=1;
			if((!znak(r,stl)) && (!znak(k,stl))) plik<<"0";
			else plik<<"1";
		}
		plik<<"\n";
	}
	plik.close();
	//cout<<pow(2,3)<<endl;
	/*int st;
	cin>>st;
	//const int st=3;
	for(int i=1;i<=pow(3,st);i++) cout<<znak(i,st);*/
	return 0;
}
