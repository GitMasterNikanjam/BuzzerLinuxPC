// For compile and build:
// mkdir -p ./bin &&  g++ -o ./bin/ex1 ex1.cpp ../BuzzerLinuxPC.cpp -Wall -Wextra -std=c++17

// For run:
// sudo ./bin/ex1

// #######################################################################################

#include "../BuzzerLinuxPC.h"

Buzzer buzzer;

int main() {
  
    buzzer.begin();

    buzzer.alarmWarning_1();

    buzzer.clean();
    return 0;
}
