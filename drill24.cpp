#include "iostream"
#include "iomanip"
#include "cmath"
#include "complex"
#include "cerrno"
#include "Matrix.h"
#include "MatrixIO.h"
using namespace std;
using namespace Numeric_lib;

int main()
try{
	cout<<"Sizeof: "<<endl;
	cout<<"Char\t"<<sizeof(char)<<endl;
	cout<<"short\t"<<sizeof(short)<<endl;
	cout<<"int\t"<<sizeof(int)<<endl;
	cout<<"long\t"<<sizeof(long)<<endl;
	cout<<"float\t"<<sizeof(float)<<endl;
	cout<<"double\t"<<sizeof(double)<<endl;
	cout<<"int*\t"<<sizeof(int*)<<endl;
	cout<<"double*\t"<<sizeof(double*)<<endl;
	cout<<"long*\t"<<sizeof(long*)<<endl;
	cout<<"float*\t"<<sizeof(float*)<<endl;	
	
	Matrix<int>a(10);
	Matrix<int>b(100);
	Matrix<double>c(10);
	Matrix<int,2>d(10,10);
	Matrix<int,3>e(10,10,10);
	
	cout<<"1D int 10 elements: "<<sizeof(a)<<endl;
	cout<<"1D int 100 elements: "<<sizeof(b)<<endl;
	cout<<"1D double 10 elements: "<<sizeof(c)<<endl;
	cout<<"2D int 10x10 elements: "<<sizeof(d)<<endl;
	cout<<"3D int 10x10x10 elements: "<<sizeof(e)<<endl;
	
	cout<<"Number of elements: "<<endl;
	cout<<"a:\t"<<a.size()<<endl;
	cout<<"b:\t"<<b.size()<<endl;
	cout<<"c:\t"<<c.size()<<endl;
	cout<<"d:\t"<<d.size()<<endl;
	cout<<"e:\t"<<e.size()<<endl;
	
	for(double i; cin>>i;){
		if(i<0)
			cout<<"Invalid number"<<endl;
       	else
		cout<<sqrt(i)<<endl;
	}
	/*for(double i; cin>>i;){
		errno=0;
		double d=sqrt(i);
		if(errno==EDOM)
			cout<<"Invalid number"<<endl;
       	else
		cout<<i<<" : "<<d<<endl;
	}*/
	
	cin.clear();
	cin.ignore();
	
	cout<<"10 ertek:"<<endl;
	Matrix<double> m2(10);
	double d2;
	for(int i=0; i<m2.size(); ++i){
		cin>>d2;
		if(!cin) throw runtime_error("Reading problem");
		m2[i]=d2;
	}
	cout<<"Matrix: "<<m2<<endl;
		
	cout<<"Add meg a mátrix méreteit: ";
	int s,o;
	cin>>s>>o;	
	Matrix<int, 2>mtable(s,o);
	for(int i=0; i<mtable.dim1(); ++i){  //Index, mátrix saját long tipusa
		for(int j=0; j<mtable.dim2(); ++j){
			mtable(i,j)=(i+1)*(j+1);
			cout<<setw(5)<<mtable(i,j);	//setw() kimenet formázás
		}
		cout<<endl;
	}
	
	Matrix<complex<double>> m4(10);	//a mátrix komplex számokat tartalmaz, elyek double tipusuak
	/*cout<<"10 complec bnumber: "<<endl;
	complex<double>comp;
	for(int i=0; i<10; ++i){
		cin>>comp;
		if(!cin) throw runtime_error("Invalid number");
		else
		m4[i]=comp;
	}
	cout<<"Complex matrix: "<<m4<<endl;
	complex<double>sum;
	for(int i=0; i<m4.size(); ++i){
		sum+=m4[i];
	}
	
	cout<<"Sum: "<<sum<<endl;
	
	*/
	//Utolso feladatot megcsinálni!!!!!
	
	Matrix<int,2>m(2,3);
	for(int i=0; i<2; ++i){
		for(int j=0; j<3; ++j){
			cin >> m(i, j);
		}
	}
	for(int i=0; i<2; ++i){
		for(int j=0; j<3; ++j){
			cout<<setw(5)<<m(i,j);	
		}
		cout<<endl;
	}
	
}
catch(exception & e){
	cerr<<e.what()<<endl;
	return 1;
}
catch(...){
	cerr<<"Exception"<<endl;
	return 2;
}


