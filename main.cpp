/* main.cpp
 * Tested with mbed board: FRDM-KL46Z
 * Author: Mark Gottscho
 * mgottscho@ucla.edu
 */

#include "mbed.h"
#include "util.h"
#include "SerialManager.h"
#include "Tester_MAX17043.h"
#include "Tester_INA219.h"

using namespace std;

//The console object is global so that all objects can use its generic serial methods.
SerialManager console(PTE16, PTE17, 115200, true); //For serial console
DigitalOut green(LED1);
DigitalOut red(LED2);

int main() {
    //Init
    green = 0;
    red = 0;

    //Do the unit tests, from lowest level classes first
    Tester_INA219::test_INA219();
    Tester_MAX17043::test_MAX17043();
    
    console.serial.printf("\r\n>>> All tests passed!\r\n");
    
    //Success!
    red = 1;

    while (1) {} //spinloop
}