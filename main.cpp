#include <iostream>
#include "Headers/Game.h"
#include "Headers/Libs/String.h"
#include "Headers/Models/Package.h"
#include "Headers/Libs/CSV_reader.h"
#include "Headers/Libs/CSV_reader_meeting.h"

using namespace std;
int main() {
    try{
        Game game1;
        game1.run();
    }
    catch(exception& e){
        cout << endl;
        cout << e.what();
    }

    return 0;
}