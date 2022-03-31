#include"ult.h"

using namespace std;

int main(){
    srand(time(NULL));
    
    for(int i = 0; i < 1; i++){
        Person p1;
        p1.next();
        cout << p1.getInfoPerson() << endl << "=================================================\n";
    }

}
