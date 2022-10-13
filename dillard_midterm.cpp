// Isaiah Dillard
// 10/13/1997
// midterm program: Calculate cost of parking

# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>

using namespace std;

// function declaration and definition

void getNameAndHours(string &firstName, string &lastName, double &hours){

    // Function gets the user input for name and hours

    cout << "Enter Customer Name: ";
    cin >> firstName >> lastName;

    // get the hours parked
    cout << "Enter Hours Parked: ";
    cin >> hours;
}

char isCommercial(char &answer){

    // ask the type of Vehicle
    cout << "Is vehicle commercial (Y / N)? ";
    cin >> answer;

    return answer;
}

double calcCharges(double hours, char commercial){

    double minimumFee = 8.00;
    int commercialCharge = 10;
    double hoursOver;

    if (hours > 4){

        hoursOver =  hours - 4;
    }

    if (hoursOver >= 4 && commercial != 'Y'){

        return hoursOver * 2.50 + minimumFee;
    } 
    else if (hoursOver >= 4 && commercial == 'Y')
    {
        return (hoursOver * 2.50) + commercialCharge;
    }
    else if (hoursOver <= 4 && commercial == 'Y')
    {
        return minimumFee + commercialCharge;
    }

    return minimumFee;
    
}

int main(){

    // declare the outfile
    ofstream outfile;

    // variable declaration
    string firstName;
    string lastName;
    double hoursParked;
    char commercial;
    double parkingCost;

    // open outfile for writing
    outfile.open("report.txt", ios::out);

    // formatting for outfile
    outfile << "Customer   ";
    outfile << "Hours  ";
    outfile << "Charge ";
    outfile << "Commercial" << endl;
    
    for (int i = 0; i < 3; i++){
        getNameAndHours(firstName, lastName, hoursParked); // pass by reference values

        isCommercial(commercial); // pass by reference for the type of vehicle

        parkingCost = calcCharges(hoursParked, commercial);
        
        cout << endl;

        // write to outfile
        outfile << firstName << " " << lastName <<"    ";
        outfile << hoursParked << "    ";
        outfile << parkingCost << fixed << setprecision(2) << "    ";
        outfile << commercial << endl;
    }

    // close outfile
    outfile.close();

    return 0;

}