// Login and Registration application - Giang Vu
#include "ui.h"

int main () {
    try
    {
        UI ui;
        ui.start();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...) {
        std::cout << "Oops, someone threw an exception!" << std::endl;
    }
    
    return 0;
}