#include "../GUI/Lines_window.h"
#include "../GUI/Graph.h"

int main()
try {
    Lines_window win {Point{100,100},1000,800,"Lines"};
    return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}