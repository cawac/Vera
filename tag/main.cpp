#include "library.h"
using namespace std;
int main() {
    srand(time(NULL));
    game tag;
    tag.create();
    tag.show();
    tag.set_x_y();
    while (!tag.wincondition()) {
        tag.move();
        tag.show();
    }
    cout<<"you are the champion!)";
    return 0;
}
