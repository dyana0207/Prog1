//Contenerek
//iterátor=pointer, ami mutat a collekció egyik elemére. Lehet előre és visszalépni az elemek közt(inkrementálni, dekrementálni)
#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

template<typename C> 
void print(const C & c){
	ut << "Is the vector contain the 3?\n";

	if(vit != vi2.end()){
		cout << "Found at: " << distance(vi2.begin(), vit) << endl << endl;
	}else{
		cout<< "Not found" << endl << endl;
	}	
	cout << "Is the vector contain the 27?\n";

	std::list<int>::iterator lit;
	lit = std::find(li2.begin(), li2.end(), 27);

	if(lit != li2.end()){
		cout << "Found at: " << distance(li2.begin(), lit) << endl << endl;
	}else{
		cout<< "Not found" << endl << endl;
	}
 
}for(auto & a :c)
	{
		cout<< a <<' ';}
	cout<<endl;

}
template<typename C>
void inc(C& c, int n){
	for(auto & a : c)
		a+=n;
}
template<typename iter1, typename iter2>
iter2 orai_copy(iter1 f1, iter1 e1, iter2 f2){
	for(iter1 p =f1; p!=e1; ++p){
	ut << "Is the vector contain the 3?\n";

	if(vit != vi2.end()){
		cout << "Found at: " << distance(vi2.begin(), vit) << endl << endl;
	}else{
		cout<< "Not found" << endl << endl;
	}	
	cout << "Is the vector contain the 27?\n";

	std::list<int>::iterator lit;
	lit = std::find(li2.begin(), li2.end(), 27);

	if(lit != li2.end()){
		cout << "Found at: " << distance(li2.begin(), lit) << endl << endl;
	}else{
		cout<< "Not found" << endl << endl;
	}
 
}	*f2++=*p;
	}
	return f2;
}


int main(){
 
	 constexpr int size=10;
	 int arr[size]={0,1,2,3,4,5,6,7,8,9};
	 array<int, size> ai;
	 vector<int> vi(size);
	 list<int> li(size);
	 
	 copy(arr, arr+size, ai.begin());
	 copy(arr, arr+size, vi.begin());
	 copy(arr, arr+size, li.begin());

	 print(ai);
	 print(vi);
	 print(li);
	 array<int, size> ai2 = ai;
	 vector<int> vi2 = vi;
	 list<int> li2 = li;
	 
	 print(ai2);
	 print(vi2);
	 print(li2);
	 
	 inc(ai2,2);
	 inc(vi2,3);
	 inc(li2,5);
	 
	 print(ai2);
	 print(vi2);
	 print(li2);
	 
	 orai_copy(ai2.begin(), ai2.end(), vi2.begin());//elejétől, végéig, hova kezdje a másolást
	 orai_copy(li2.begin(), li2.end(), ai2.begin());
	 
	 print(ai2);
	 print(vi2);
	 print(li2);
	 
	 vector<int>::iterator vit;
	vit = find(vi2.begin(), vi2.end(), 3);
	cout << "Is the vector contain the 3?\n";

	if(vit != vi2.end()){
		cout << "Found at: " << distance(vi2.begin(), vit) << endl << endl;
	}else{
		cout<< "Not found" << endl << endl;
	}	
	cout << "Is the vector contain the 27?\n";

	std::list<int>::iterator lit;
	lit = std::find(li2.begin(), li2.end(), 27);

	if(lit != li2.end()){
		cout << "Found at: " << distance(li2.begin(), lit) << endl << endl;
	}else{
		cout<< "Not found" << endl << endl;
	}
 
}
