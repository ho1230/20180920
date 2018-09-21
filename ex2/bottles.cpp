/**
 * Bottles implementation.
 *
 * Copyright (c) 2018, Sekhar Ravinutala.
 */

#include "ex2/bottles.h"
#include <assert.h>
#include <locale>

std::string lyric(uint8_t bottles) {
    /**
     * Get lyric line for specified number of bottles.
     * - bottles: Bottle count.
     */

    std::string numbers = word(bottles);
    std::string temp = "";      // for return value (temperary)

    if(bottles == 1){
        numbers += " bottle";
    }else{
        numbers += " bottles";
    }

    if(bottles){
        temp = numbers + " of beer on the wall, \n";
        temp += numbers + " of beer, \n";
        temp += "Take one down, pass it around,";
    }else{
        temp = numbers + " of beer on the wall. ";
    }

    return temp;
}

std::string word(uint8_t number) {
    /**
     * Convert number into word.
     * - number: Should be below 100.
     */
    assert(number < 100);

    std::string temp = "";      // for return value (temperary)
    int cal = 0;                // for caculation
    bool flag = false;          // for except

    cal = number / 10;
    switch(cal){
        case 9:
            temp = "Ninety";
            break;
        case 8:
            temp = "Eighty";
            break;
        case 7:
            temp = "Seventy";
            break;
        case 6:
            temp = "Sixty";
            break;
        case 5:
            temp = "Fifty";
            break;
        case 4:
            temp = "Forty";
            break;
        case 3:
            temp = "Thirty";
            break;
        case 2:
            temp = "Twenty";
            break;
        default:
            temp = "";
            flag = true;
            break;
    }

    if(flag){   // under 20
        if(number == 0){
            temp = "Zero";
        }else if(number == 10){
            temp = "Ten";
            // flag = false;
        }else if(number == 11){
            temp = "Eleven";
            // flag = false;
        }else if(number == 12){
            temp = "Twelve";
            // flag = false;
        }else if(number == 13){
            temp = "Thirteen";
            // flag = false;
        }else if(number == 18){
            temp = "Eighteen";
        }else{
            cal = number % 10;
            switch (cal){
                case 1:
                    temp += "One";
                    break;
                case 2:
                    temp += "Two";
                    break;
                case 3:
                    temp += "Three";
                    break;
                case 4:
                    temp += "Four";
                    break;
                case 5:
                    temp += "Five";
                    break;
                case 6:
                    temp += "Six";
                    break;
                case 7:
                    temp += "Seven";
                    break;
                case 8:
                    temp += "Eight";
                    break;
                case 9:
                    temp += "Nine";
                    break;
                    
            }
            cal = number / 10;
            if(cal){
                temp += "teen";
            }
        }
    }else{      // greater than 20
        cal = number % 10;
        switch (cal){
            case 1:
                temp += "-one";
                break;
            case 2:
                temp += "-two";
                break;
            case 3:
                temp += "-three";
                break;
            case 4:
                temp += "-four";
                break;
            case 5:
                temp += "-five";
                break;
            case 6:
                temp += "-six";
                break;
            case 7:
                temp += "-seven";
                break;
            case 8:
                temp += "-eight";
                break;
            case 9:
                temp += "-nine";
                break;
                
        }
    }

    return temp;
}
