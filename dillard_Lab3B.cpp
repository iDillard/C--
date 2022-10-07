// Isaiah Dillard
// 09/08/2022
// Calculate student totals and averages as a whole

# include <iostream>
# include <fstream>
# include <iomanip>
using namespace std;

int main(){

    double oddScores;
    double evenScores;
    double evenTotal = 0;
    double oddTotal = 0;
    int score = 0;
    int totalScore = 0;
    int counter = 0;
    int minGrade = 101;
    int maxGrade = 0;
    ifstream inFile;
    string firstName;
    string lastName;
    string fileName;

    cout << "What is the name of your file? ";
    cin >> fileName;

    inFile.open(fileName);

    inFile >> firstName >> lastName >> score;

    while (inFile){

        // inFile >> firstName >> lastName >> score;


        if (score % 2 == 0){

            evenScores++; // add one if the number is even
            evenTotal += score;

        } else {

            oddScores++; // add one if the number is odd
            oddTotal += score;
        } // end of if else statement

        totalScore += score; // add the current score to the total score

        counter++; // increase the counter by one

        if (score < minGrade ){

            minGrade = score; // test the score against the minimum grade. if score lower assign it to minGrade

        } else if (score > maxGrade) {

            maxGrade = score; // test the score against the highest grade. if the score is higher assign to maxGrade
        }

        inFile >> firstName >> lastName >> score;

    } // end of while loop

    cout << endl;
    cout << "Number of students in the file is " << counter << endl;
    cout << "There are " << oddScores << " odd scores and " << evenScores << " even scores" << endl;
    cout << "The sum of all odd numbers is " << oddTotal << endl;
    cout << "The sum of all even mubers is " << evenTotal << endl;
    cout << "Sum of all grades: " << totalScore << endl;
    cout << "The highest score is " << maxGrade << endl;
    cout << "The lowest score is " << minGrade << endl;
    cout << "The average score is " << fixed << setprecision(2) << double(totalScore / counter) << endl;

    inFile.close();

    return 0;


} // end of main function