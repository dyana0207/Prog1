/*GIT-IT
git-scm.com -letöltés
git init
git status- állapot
git add a.txt-hozzáadni staging areaba ha változtatjuk
git commit -m "elso commit" -véglegesités
git push

git pull - ha tavoli tárolóban változtatják
git clone https...

*/
/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"
#include "string"
#include "iostream"


using namespace Graph_lib;

int main(){
	try{
		Point t1(300,50);
		Simple_window win(t1,1000, 800, "My window");
		win.wait_for_button();
		
		Lines grid;
		int x_size=800;
		int y_size=800;
		for(int i=100; i<=x_size; i+=100){
			grid.add(Point(i,0), Point(i,y_size));
			grid.add(Point(0,i), Point(x_size,i));
		}
		
		win.attach(grid);
		win.wait_for_button();
		
		
		Vector_ref<Rectangle>v;
		for(int i=0; i<8; i++){
			v.push_back(new Rectangle(Point(i*100,i*100),100,100));     
			v[v.size()-1].set_fill_color(Color::red);
			win.attach(v[v.size()-1]);
		}
		win.wait_for_button();
		
		Vector_ref<Image>img;
		for(int i=1; i<=3; i++){
			img.push_back(new Image(Point(i*200,i*200-200),"badge.jpg"));     
			img[img.size()-1].set_mask(Point{100,100}, 200,200);
			win.attach(img[img.size()-1]);
		}
		win.wait_for_button();
		
		int x=0;
		int y=0;
		srand(time(0));
		
		
		x=rand()% 8*100;
		y=rand()% 8*100;
		Vector_ref<Image>i;
		i.push_back(new Image(Point(x,y),"asd.jpg"));     
		i[0].set_mask(Point{100,100}, 100,100);
		win.attach(i[0]);
		while(win.wait_for_button())
		{
			int xx=rand()% 8*100-x;
			int yy=rand()% 8*100-y;
			x+=xx;
			y+=yy;
			
			i[0].move(xx,yy);
		}
	}
	catch(exception& e){
		cerr<<"exception: "<<e.what()<<endl;
		return 1;
		}
	catch(...){
		cerr<<"exception \n";
		return 2;
	}


}
