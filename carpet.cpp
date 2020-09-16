#include <iostream>
#include <fstream>

using namespace std;

unsigned pow(unsigned,unsigned);

bool sign(unsigned ro,unsigned st){
	if(st==0) return true; //1
	else if(ro>pow(3,st-1) && ro<=2*pow(3,st-1)) return false;//0
	else return sign((ro+pow(3,st-1)-1)%pow(3,st-1)+1,st-1);
}

bool sign2(unsigned r,unsigned k,unsigned st){
	if(st==0) return true; //1
	else if(r>pow(3,st-1) && r<=2*pow(3,st-1) && k>pow(3,st-1) && k<=2*pow(3,st-1)) return false;//0
	else return sign2((r+pow(3,st-1)-1)%pow(3,st-1)+1,(k+pow(3,st-1)-1)%pow(3,st-1)+1,st-1);
}

unsigned pow(unsigned b,unsigned w){
	unsigned r0 = 1;
	for(unsigned i=1;i<=w;i++) r0*=b;
	return r0;
}

int main(){
	string st;
	cout<<"Enter degree of recursion (<10 - safe): ";
	cin>>st;
	unsigned stl = atoi(st.c_str());
	ofstream file("carpet"+st+".pbm");
	file<<"P1\n"<<pow(3,stl)<<" "<<pow(3,stl)<<"\n";
	if(stl>9){
		stl=9; st="9";
	}
	const unsigned W = pow(3,stl);
	const unsigned H = W;
	const unsigned bigL = pow(3,2*stl-1);
	for(unsigned i=0;i<bigL;i++){
		for(unsigned j=1;j<=3;j++){
			unsigned poz = 3*i+j;
			unsigned r = ((poz+W-1)/W);
			unsigned k = poz - (r-1)*W;
			if(!sign2(r,k,stl)) file<<"0";
			else file<<"1";
		}
		file<<"\n";
	}
	file.close();
	return 0;
}
