#include "../GUI/Graph.h"
#include "../GUI/Simple_window.h"

#include <string>
#include <iostream>

using namespace Graph_lib;	

int main(){
	try{
	
		Point t1{300, 50};
		Simple_window win{t1, 1000, 800, "My window"};
		win.wait_for_button();
		Lines grid;
		int x_size = 800;
		int y_size = 800;
		for(int i = 100; i <=x_size; i+=100){
			grid.add(Point(i,0), Point(i, y_size));
			grid.add(Point(0,i), Point(x_size, i));
		}
		
		win.attach(grid);
		win.wait_for_button();
		
		
		
	/*Rectangle r1 { Point{0, 0}, 100, 100};
		r1.set_fill_color(Color::red);
		win.attach(r1);
		win.wait_for_button();
		*/

		Vector_ref<Rectangle> koordinatak;
		//Vector ref<Graph_lib::Rectangle> vr;
		/*for(int i = 0; i < 8; i++){
			Rectangle r1 { Point{i+100, i+100}, 100, 100};
			r1.set_fill_color(Color::red);
			win.attach(r1);
			win.wait_for_button();
			
		}
	*/

		for(int i = 0; i<x_size; i+=100){
			koordinatak.push_back(new Rectangle(Point{i, i}, 100, 100));
		}
		for (int i = 0; i < 8; ++i)
		{
			koordinatak[i].set_fill_color(Color::red);
			win.attach(koordinatak[i]);
			//win.wait_for_button();
		}
	win.wait_for_button();
	Image kep{Point{0,200}, "badge.jpg"};
	kep.set_mask(Point{0,200}, 200,200);
	win.attach(kep);
	win.wait_for_button();

	Image kep2{Point{400,200}, "badge.jpg"};
	kep2.set_mask(Point{10,20}, 200,200);
	win.attach(kep2);
	win.wait_for_button();

	Image kep3{Point{400,600}, "badge.jpg"};
	kep3.set_mask(Point{80,60}, 200,200);
	win.attach(kep3);
	win.wait_for_button();

	int previousX = 0;
	int previousY = 0;
	int randomX = 0;
	int randomY = 0;
	int a= 0;
	int b=0;
	

	Image kep4{Point{0,0}, "badge.jpg"};
	kep4.set_mask(Point{50,250}, 100,100);
	win.attach(kep4);
	while(true)
	{
		randomX = (rand() % 7 + 1) *100;
		randomY = (rand() % 7 + 1) *100;
		win.wait_for_button();
		kep4.move(randomX-previousX,randomY-previousY);
		previousY = randomY;
		previousX = randomX;
	}
	win.wait_for_button();
	// img.set_mask(Point(100,100), 200,200)		/ move(int x, int y)
	}catch(exception& e){
		cerr << "exception: " << e.what() << endl;
		return 1;
	}catch(...) {
		cerr << "exception\n";
		return 2;
	}

}