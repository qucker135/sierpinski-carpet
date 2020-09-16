#include <iostream>
#include <fstream>
//#include <math.h>

using namespace std;

unsigned int pow(unsigned int,unsigned int);

bool znak(unsigned int ro,unsigned int st){
	if(st==0) return true; //1
	else if(ro>pow(3,st-1) && ro<=2*pow(3,st-1)) return false;//0
	else return znak((ro+pow(3,st-1)-1)%pow(3,st-1)+1,st-1);
}

bool znak2(unsigned int r,unsigned int k,unsigned int st){
	if(st==0) return true; //1
	else if(r>pow(3,st-1) && r<=2*pow(3,st-1) && k>pow(3,st-1) && k<=2*pow(3,st-1)) return false;//0
	else return znak2((r+pow(3,st-1)-1)%pow(3,st-1)+1,(k+pow(3,st-1)-1)%pow(3,st-1)+1,st-1);
}

unsigned int pow(unsigned int b,unsigned int w){
	unsigned int r0 = 1;
	for(unsigned int i=1;i<=w;i++) r0*=b;
	return r0;
}

int main(){
	string st;
	cout<<"Podaj stopien rekurencji: ";
	cin>>st;
	unsigned int stl = atoi(st.c_str());
	ofstream plik("dywan"+st+".pbm");
	plik<<"P1\n"<<pow(3,stl)<<" "<<pow(3,stl)<<"\n";
	if(stl>9){
		stl=9; st="9";
	}
	const unsigned int W = pow(3,stl);
	const unsigned int H = W;
	const unsigned int duzaL = pow(3,2*stl-1);
	for(unsigned int i=0;i<duzaL;i++){
		for(unsigned int j=1;j<=3;j++){
			unsigned int poz = 3*i+j;
			unsigned int r = ((poz+W-1)/W);
			unsigned int k = poz - (r-1)*W;
			//r+=1;k+=1;
			if(!znak2(r,k,stl)) plik<<"0";
			else plik<<"1";
		}
		plik<<"\n";
	}
	plik.close();
	//cout<<pow(2,3)<<endl;
	/*unsigned int st;
	cin>>st;
	//const unsigned int st=3;
	for(unsigned int i=1;i<=pow(3,st);i++) cout<<znak(i,st);*/
	return 0;
}
