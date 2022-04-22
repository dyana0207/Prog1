//map= kulcs- érték pár
//Egyediségre van szükség,nincs duplikáltság, könnyű keresés
//A set csak kulcsokat tartalmaz. Rendezett.
#include "string"
#include "iostream"
#include "map"
#include "numeric"
#include "stdexcept"

using namespace std;

template<typename K, typename V>
void print(const map<K,V> & m){
	for(pair<K,V> a : m){
	//for(auto & a : m){
		cout<<a.first<< " "<<a.second<<endl;
	}

}
void read_map(map<string, int>& m){
	string s;
	int i=0;
	while(m.size()<10){
		cin>>s>>i;
		//m[s]=i;
		m.insert(make_pair(s,i));
	}
	
}

int main(){
	try{
		map<string, int> msi; //rendezve lesz. Az érték az módosítható
		msi["a"]=1;
		msi["b"]=2;
		msi["c"]=55;
		msi["f"]=6;
		msi["x"]=5;
		msi["h"]=6;
		msi["v"]=11;
		msi["n"]=65;
		msi["m"]=9;
		msi["k"]=36;
		print(msi);
		
		msi.erase("a");
		cout<<"Az a aelem törlése után"<<endl;
		print(msi);
		
		/*msi.erase(msi.begin(), msi.end());
		cout<<"A telsej törlés után"<<endl;
		print(msi);
		
		cout<<"10 kulcs érték pár megadása"<<endl;
		read_map(msi);
		cout<<"msi: "<<endl;
		print(msi);
		*/
		int sum=0;
		for(auto & a : msi){
			sum+=a.second;
		}
		cout<<"Sum: "<< sum<<endl;
		
		
		/*int sz=accumulate(msi.begin(), msi.end(),0,[](int s, const pair<sting, int> & p){}
			return s+=p.second;
		);
		sz=accumulate(msi.begin(), msi.end(),0);*/
		
		map <int,string> mis;
		for(pair<string, int> a : msi){
			mis[a.second]=a.first;
		}
		cout<<"Fordított map :) "<<endl;
		print(mis);
	
	}
	
	catch(exception& e){
		cerr<<"exception: "<<e.what()<<endl;
		return 1;
	}
	catch(...){
		cerr<<"exception: "<<endl;
		return 2;
	}


}

