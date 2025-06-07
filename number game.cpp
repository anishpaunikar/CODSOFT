#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

int main() {
    srand(time(0));  // seed for a new no each time
    int secret = rand() % 100 + 1;  // random number between 1 and 100
    int guess;
    int attempts=0;

    cout << "Guess a number between 1 and 100: ";

    while (true) {
        cin >> guess;
        attempts++;

        if (guess > secret) {
            cout << "Too high! Try again: ";
        } else if (guess < secret) {
            cout << "Too low! Try again: ";
        } else {
            cout << "Correct! you guessed the number in "<<attempts<<" attempts" << endl;
            break;
        }
    }

    return 0;
}
