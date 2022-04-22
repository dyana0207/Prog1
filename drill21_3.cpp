#include "fstream"
#include "iostream"
#include "numeric"
#include "vector"
#include "stdexcept"
#include "algorithm"

using namespace std;

/*class Less_than{
	double v;
	public:
		Less_tha(double vv): v{vv}{}
		bool operator()(const double val){return val<v;}
} */
 
template<typename C>
void print(const C &c, char sep='\n'){
	cout<<"Elements:"<<endl;
	for(const auto elem : c){
		cout<<elem<<sep;
	}
	cout<<endl;
}

int main(){
try{
	const string iname{"input_floats.txt"};
	ifstream ifs{iname};
	//ifstream ifs{input_floats.txt};
	if(!ifs) throw runtime_error("Could not read from file " +iname);
	
	vector<double> vd;
	for(double d; ifs >> d;){
		vd.push_back(d);
	}
	
	print(vd);
	vector<int> vi(vd.size()); //vd méretű 
	copy(vd.begin(), vd.end(), vi.begin());
	print(vi);

	for(int i=0; i<vd.size(); ++i){
		cout<<vd[i]<<'\t'<<vi[i]<<endl;
	}
	
	double vd_sum=accumulate(vd.begin(), vd.end(),0.0);
	cout<<"Összeg:"<<vd_sum<<endl;
	int vi_sum=accumulate(vi.begin(), vi.end(),0.0);
	cout<<"Összeg:"<<vi_sum<<endl;
	cout<<"A kettő közti különbség: "<< vd_sum-vi_sum<<endl;
	
	reverse(vd.begin(), vd.end()); //vektor megforgatása
	print(vd);
	
	double vd_mean=vd_sum/vd.size();
	cout<<"AVG: "<<vd_mean<<endl;
	
	vector<double> vd2;
	for(int i=0; i<vd.size(); ++i){
		if(vd[i]< vd_mean){
			vd2.push_back(vd[i]);
		}
	}
	cout<<"A vd2:"<<endl;
	print(vd2);
	
	/*auto it= copu_if(vd.begin(), vd.end(), vd2.begin(), //konstruktor hivodik meg
	Less_than(vd_mean));
	vd2.resize(distance(vd2.begin(),it));*/
	
	sort(vd.begin(), vd.end());
	print(vd);
	
}
catch(exception & e){
	cerr<<e.what()<<endl;
	return 1;
}
catch(...){
	cerr<<"Unknow exception:"<<endl;
	return 2;
}
}
