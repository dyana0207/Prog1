#include "string"
#include "iostream"
#include "vector"

using namespace std;

template<typename T> struct S{
	S(T vv=0) : val{vv}{};
	T& get();
	const T& get() const;
	void set(T new_t){val=new_t;} 
	void operator =(const T&);
	private:
		T val;
	
};

template<typename T> //T típus paraméter
T& S<T>::get(){
	return val;
}

template<typename T> //T típus paraméter
const T& S<T>::get() const {
	return val;
}

template<typename T>
void S<T>::operator=(const T& s){
	val=s;
}
template<typename T> void read_val(T& v){
	cin>>v;
}

template<typename T> ostream & operator<<(ostream & os, vector<T> & v) {

	os<<"{";
	for(int i=0; i=v.size(); ++i){
		os<<v[i]<<(i<v.size()-1 ? "," : " ");
	}
	os<<"}";
	return os;
}

template<typename T> istream & operator>>(istream & is, vector<T> & v) {
	char ch=0;
	is>>ch;
	if(ch!='{'){
		is.unget();
		return is;
	}
	for(T val; is>> val;){
		v.push_back(val);
		is>>ch;
		if(ch !=',') break;
	}
	return is;
}


int main(){

	S<int> s;  
	S<int> si{37};
	S<char> sc{'c'};
	S<double> sd{3.2};
	S<string> ss{"aaa"};
	S<vector<int>> svi {vector<int>{1,2,3,4,5,6}};

	cout<<"S<int>"<<s.get()<<endl;
	cout<<"S<int>"<<si.get()<<endl;
	cout<<"S<char>"<<sc.get()<<endl;
	cout<<"S<double>"<<sd.get()<<endl;
	cout<<"S<string>"<<ss.get()<<endl;
	//cout<<"S<vector<int>>"<<svi.val<<endl;
	
	for(auto &a : svi.get()){
		cout<<a<<' ';
	}
	cout<<endl;
	
	sc.set('k');
	cout<<"S<char>"<<sc.get()<<endl;
	si=30;
	
	int ii;
	read_val(ii);
	S<int> si2{ii};
	cout<<"S<int>"<<si2.get()<<endl;
	
	
	string st;
	read_val(st);
	S<string> si3{st};
	cout<<"S<string>"<<si3.get()<<endl;
	
	vector<int> vec;
	read_val(vec);
	S<vector<int>> svec {vec};
	cout<< "S<vector<int"<< svec.get()<<endl;
	
	
}
