#include <ctime>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{
	int tstart, tend, seconds, sec, NUM, value;
	int NUMDIG = 0;
	srand(time(0));
	
	vector<int> COMV;
    
// Computer Numbers and User Input
    while(NUMDIG < 4) {
        NUM = rand()%10;
        bool numFound = false; 
		
        for (int i = 0; i < COMV.size(); i++){
            if (COMV[i] == NUM){
                numFound = true;
                break;
            }
        }
        if (!numFound){
            COMV.push_back(NUM);
            ++NUMDIG;
        }
    }
    cout << "Here is a sample run, where the program picked ";
    for (int i = 0; i < COMV.size(); i++) {
        cout << COMV[i];
    }
	
// Print User Bulls & Cows
	
	int bulls = 0;
	int cows = 0;
	bool is_done = false;
	int counter = 0;
	tstart = time(0);

	while (!(is_done)){ 
		cout << "\nEnter a 4 digit number(unique digits): ";
		cin >> value;
// Isolate User Values
		int valueOne = value/1000; 
		int valueTwo = (value%1000)/100;
		int valueThree = ((value%1000)%100)/10;
		int valueFour = (((value%1000)%100)%10)/1;

// Evaluate Values and COMV Vector

		if (COMV[0] == valueOne){
			++bulls;
		}
		else if (COMV[0] != valueOne){
			++cows;
		}
		if (COMV[1] == valueTwo){
			++bulls;
		}
		else if (COMV[1] != valueTwo){
			++cows;
		}
		if (COMV[2] == valueThree){
			++bulls;
		}
		else if (COMV[2] != valueThree){
			++cows;
		}
		if (COMV[3] == valueFour){
			++bulls;
		}
		else if (COMV[3] != valueFour){
			++cows;
		}

	cout << "bulls = " << bulls << " and cows = " << cows << '\n';
	counter++;
	if(bulls == 4) is_done = true;
	bulls = 0; cows = 0;
	}

// Evaluation of Time 

    tend = time(0);
    seconds = (tend - tstart);
	int min = seconds/60;
	sec = seconds%60; 

    cout << "You guessed it in " << counter << " tries, taking "<< min << " minutes and " << sec << " seconds" << endl;
}