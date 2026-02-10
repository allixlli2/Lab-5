#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
#include <iomanip> 

using namespace std;

struct BusinessCard {
    string companyName;
    string address;
    string phoneNumber;
    string workingHours;
    string poc;        
    double priceQuoted; 
};

int main() {
    srand(time(0)); // Seeds the generator so results change every run

    // A pool of potential company names to choose from
    string namePool[] = {"Clover supply", "Knox Co", "Maple Co", "Pearl Studio", "Honey Labs" };
    string pocPool[] = {"Jacob", "Bob", "Lauren", "Irvin", "Jenny", };
    string addrPool[] = {"247 Clover Ln", "213 Knox St", "364 Maple St", "507 Pearl Rd", "426 Honey Way"};
    string phonePool[] = {"529-8841", "905-4427", "562-9714", "713-5608", "318-7702"};

    BusinessCard companies[5];

    cout << left << setw(20) << "Company" << setw(15) << "POC" << "Price Quoted" << endl;
    
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < 5; i++) {
        int randomName = rand() % 5;
        int randomPoc = rand() % 5;

        // Assigning random details to the struct
        companies[i].companyName = namePool[i];
        companies[i].poc = pocPool[i];
        companies[i].address = addrPool[i];
        companies[i].phoneNumber = phonePool[i];
        
        companies[i].workingHours = "7am-6pm";
        
        // Task: Price quotes use rand +srand
        companies[i].priceQuoted = (rand() % 801) + 200;
        
        cout << left << setw(20) << companies[i].companyName 
             << setw(15) << companies[i].poc 
             << "$" << fixed << setprecision(2) << companies[i].priceQuoted << endl;
    }

    // Logic to find the best price
    int winningIndex = 0; 
    for (int i = 1; i < 5; i++) {
        if (companies[i].priceQuoted < companies[winningIndex].priceQuoted) {
            winningIndex = i;
        }
    }

    cout << "\nTHE WINNER IS: " << companies[winningIndex].companyName << " ($" << companies[winningIndex].priceQuoted << ")" << endl;

    return 0;
}