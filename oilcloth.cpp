#include <iostream>
#include <fstream>

using namespace std;

int pow(int,int);

bool sign(int ro,int st){
	if(st==0) return true; //1
	else if(ro>pow(3,st-1) && ro<=2*pow(3,st-1)) return false;//0
	else return sign((ro+pow(3,st-1)-1)%pow(3,st-1)+1,st-1);
}

int pow(int b,int w){
	int r0 = 1;
	for(int i=1;i<=w;i++) r0*=b;
	return r0;
}

int main(){
	string st;
	cout<<"Enter degree of recursion (<10 - safe): ";
	cin>>st;
	int stl = atoi(st.c_str());
	ofstream file("oilcloth"+st+".pbm");
	file<<"P1\n"<<pow(3,stl)<<" "<<pow(3,stl)<<"\n";
	if(stl>10){
		stl=10; st="10";
	}
	const int W = pow(3,stl);
	const int H = W;
	const int bigL = pow(3,2*stl-1);
	for(int i=0;i<bigL;i++){
		for(int j=1;j<=3;j++){
			int poz = 3*i+j;
			int r = ((poz+W-1)/W);
			int k = poz - (r-1)*W;
			
			if((!sign(r,stl)) && (!sign(k,stl))) file<<"0";
			else file<<"1";
		}
		file<<"\n";
	}
	file.close();
	return 0;
}
