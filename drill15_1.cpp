#include "Simple_window.h"
#include "Graph.h"
#include "string"
#include "iostream"

using namespace Graph_lib;

double one(double x){return 1;}
double slope(double x){return x/2;}
double square(double x){return x*x;}
double sloping_cos(double x){return slope(x)+cos(x);}

int main(){
	try{
		Point p{100, 100};
		Simple_window win{p,600,600, "Function graph"};
		win.wait_for_button();
		
		Axis xa{Axis::x, Point{100,300},400,20,"1==20  pixels"};
		xa.set_color(Color::red);
		win.attach(xa);
		win.wait_for_button();
		
		Axis ya{Axis::y, Point{300,500},400,20,"1==20  pixels"};
		ya.set_color(Color::red);
		win.attach(ya);
		win.wait_for_button();
		Function double_one(one, -10, 11, Point{300,300}, 400, 20, 20);
		win.attach(double_one);
			
		int min=-10, max=11, l=400 ,x_scale=20, y_scale=20;
		Point p1{300,300};
			
		Function double_slope(slope, min, max, p1, l, x_scale, y_scale);
		win.attach(double_slope);
		Text slope_label{Point{double_slope.point(0).x,double_slope.point(20).y},"x/2"};
		win.attach(slope_label);
			
		Function double_square(square, min, max, p1, l, x_scale, y_scale);
		win.attach(double_square);
			
		Function cosine(cos, min, max, p1, l, x_scale, y_scale);
		cosine.set_color(Color::blue);
		win.attach(cosine);
			
		Function slope_cos(sloping_cos, min, max, p1, l, x_scale, y_scale);
		win.attach(slope_cos);
				
			
		win.wait_for_button();	
	}
	
	catch(exception& e){
		cerr<<"exception: "<<e.what()<<endl;
		return 1;
	} catch (...){
		cerr<<"error \n";
		return 2;
	}
}
