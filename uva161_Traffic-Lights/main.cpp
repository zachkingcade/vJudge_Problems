/** 
 * Written by zachkingcade: 04/10/2020 5:42pm
 * Problem: uva 161 - Traffic Lights
 * 
 * Notes:
 * ------------------------- Storing the Data-------------------------------
 * So my approach to this went something like this, we first nerd to be able
 * to store all the intervals in a quick and concise format, for this I used
 * Vectors in a loop that reads in a set and the prepares to process it before
 * grabbing the next data set. I next decided instead of trying a costly simulation
 * I would pick one light to test off of but only when that light it green. I decided
 * to do the least amount of testing I would do it on the one with the smallest interval time
 * since I only test for when it's green and a good amount of that will be taken by the
 * 5 seconds it spends yellow of which I will not test for. One good reason for doing this is
 * all the lights start as green and we only care about the next time they become green
 * after the first yellow light which is gonna be on the smallest interval.
 * 
 * ------------------------ Processing the Data ---------------------------
 * When processing the data we check each second of a given green light interval
 * using the green light intervals of the smallest interval in the set. We check
 * if the other lights are green by dividing the current time by that lights interval and
 * truncating it. Since we start with the lowest interval we know the division will
 * never break out of the interval it is in be it green or red so we can truncate it
 * and only worry about if it is in a red or green interval current, since the lights
 * start out green we can the following logic, if the number is even it matches the the starting
 * value of green. If it is odd it is not and is thus red. Now that just checks if we're
 * in a red or green interval, lastly we mod the number by the interval and make sure
 * the remainder is not more then the interval minus 5 to check for yellow lights.
 * If both of these are true then the light is currently green.
 * 
 * ------------------------- Displaying output ---------------------------
 * Since we chose to store everything in seconds when printing our display we
 * must convert/format things in hours, minutes and seconds to match the desired
 * output of the original problem.
 */

//-----PreCompiler Directives-----
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main(){
    //varibles
    int interval;

    //loop to read our data into a vector but process it before reading
    //the next data set, end file marker is 3 zeros in a row, we are granteed
    //that a interval value will never be less then 10 so we can us that to test
    //if a data set starts with a 0 it is actaully then end of file marker. so here
    //we cin during our while loop test to make sure we can because if we can't then
    //we have for sure reached the end of the redirected and then we test for the
    //end of file sentenal value of 0 by treating the cined value as a logical varible
    while(std::cin >> interval && interval){
        std::vector <int>lights;
        //first adds the value read in by the while loops logic
        //then read the rest of the values in this data set
        while (interval != 0){
            lights.push_back(interval);
            std::cin >> interval;
        }
        //sort the vector from smallest to largest
        std::sort(lights.begin(), lights.end());

        //now we have our data and it is sorted and we can process the data
        bool timeFound = false;
        int currentIntervalStartTime = lights[0]*2;
        int resultTime = -1;
        std::vector <bool> greens(lights.size()-1, false);
        while (timeFound == false && currentIntervalStartTime <= 18000){
            //while loop moves between green light intervals, this for
            //loop covers every second of green in that interval,
            //not counting seconds of the light being yellow
            int secondsOffset = 0;
            for (int i = 0; i < lights[0] - 5 && timeFound == false; i++){
                //loop to check if green on all other intervals
                for (int j = 1; j < lights.size(); j++){
                    int floor = (currentIntervalStartTime + i) / lights[j];
                    int remainder = (currentIntervalStartTime + i) % lights[j];
                    if (floor % 2 == 0 && remainder < lights[j] - 5){
                        greens[j - 1] = true;
                    }
                }
                //check if they were all green this second
                if (std::count(greens.begin(), greens.end(), false) == 0){
                    timeFound = true;
                    resultTime = currentIntervalStartTime + i;
                } else {
                    //reset the values for the vector test
                    for (int i = 0; i < greens.size(); i++){
                    greens[i] = false;
                    }
                }
            }
            if (!timeFound){
                //set time forwards by smallest interval to next green
                currentIntervalStartTime += lights[0] * 2;
            }
        }

        //at this point the main while loop has broke either because a value
        //was found or 5 hours had been tested for
        if (timeFound){
            //convert raw seconds to hours, minutes and seconds
            int hours = resultTime / 3600;
            resultTime -= 3600 * hours;
            int minutes = resultTime / 60;
            int seconds = resultTime % 60;

            std::cout << std::setfill('0') << std::setw(2) << hours << ':';
            std::cout << std::setfill('0') << std::setw(2) << minutes << ':';
            std::cout << std::setfill('0') << std::setw(2) << seconds << '\n';
        } else {
            std::cout << "Signals fail to synchronise in 5 hours\n";
        }
    }

}
