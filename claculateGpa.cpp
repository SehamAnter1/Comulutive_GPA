#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
 
using namespace std;
#define run ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl "\n"
pair<string, string> letterWordGrade(double grade) {
	string letterGrade, wordGrade;
	if (grade >= 3.7) {
		letterGrade = "A", wordGrade = "Excellent";
	}
	else if (grade >= 3.3) {
		letterGrade = "A-", wordGrade = "Very good";
	}
	else if (grade >= 3.0) {
		letterGrade = "B+", wordGrade = "Very good";
	}
	else if (grade >= 2.7) {
		letterGrade = "B", wordGrade = "Good";
	}
	else if (grade >= 2.3) {
		letterGrade = "B-", wordGrade = "Good";
	}
	else if (grade >= 2.0) {
		letterGrade = "c+", wordGrade = "Pass";
	}
	else if (grade >= 1.7) {
		letterGrade = "C", wordGrade = "Pass";
	}
	else if (grade >= 1.3) {
		letterGrade = "C-", wordGrade = "Pass";
	}
	else if (grade >= 1.0) {
		letterGrade = "D", wordGrade = "Weak";
	}
	else {
		letterGrade = "F", wordGrade = "Fail";
	}
	return make_pair(letterGrade, wordGrade);

}
void findGpa() {
	int  coursesNumber, numberOfSemesters =0,counter = 0;
	string courseName;
	double courseGrade, qualityPoints = 0, totalCredit = 0, courseCredits, GPA = 0, previousCumulativeGPA=0, totalCumulativeGPA = 0;
	cout << "please enter number of previous semesters: ";
	cin >> numberOfSemesters;
	cout << "please enter previous  Cumulative GPA: ";
	cin >> previousCumulativeGPA;
	cout<<"\nFor This Semesters!..\n\n";
	cout << "please enter courses number: ";
	cin >> coursesNumber;
	vector<pair<string, pair<double, double>>>courseInfo(coursesNumber);
	cout << "if the grades are out of 100 please enter 1, if the grades are out of 4 please enter 2 : ";
	string option;
	cin >> option;
	while (!(option=="1" || option=="2")) {
	  cout << "please enter a valid option or press 0 to end program\n";
		cin >> option;
		if (option=="0") {
			return;
		}
	}
	while (counter < coursesNumber) {
		cout << "\nplease enter course " << counter + 1 << " name: ";
		cin >> courseName;
		cout << "\nplease enter course " << counter + 1 << " grade: ";
		cin >> courseGrade;
		cout << "\nplease enter course " << counter + 1 << " credits: ";
		cin >> courseCredits;
		if (option == "1") {
			courseGrade = courseGrade / 25.0;
		}
		courseInfo[counter].first = courseName, courseInfo[counter].second.first = courseGrade, courseInfo[counter].second.second = courseCredits;
		qualityPoints += courseGrade * courseCredits;
		totalCredit += courseCredits;
		counter++;
	}
	if (qualityPoints && totalCredit)
		GPA = qualityPoints / totalCredit;
	totalCumulativeGPA = previousCumulativeGPA+(GPA/(numberOfSemesters + 1));
	counter = 0;	
	while (coursesNumber--) {
	pair<string, string> LetterWordGrade = letterWordGrade(courseInfo[counter].second.first);
	cout << courseInfo[counter].first<<" GPA is:\n"<< courseInfo[counter].second.first << "    " << LetterWordGrade.first << "    " << LetterWordGrade.second << nl;;
	counter++;
	}
	cout << "\n=======================================================================\n";
	pair<string, string> LetterWordGrade1 = letterWordGrade(GPA);
	pair<string, string> LetterWordGrade2 = letterWordGrade(totalCumulativeGPA);
	cout<< "Your GPA is: "<<fixed << setprecision(2) << GPA <<nl<< LetterWordGrade1.first <<"    "<< LetterWordGrade1.second <<nl<<nl;
	cout << "Cumulative GPA is: \n" << fixed << setprecision(2) << totalCumulativeGPA << nl << LetterWordGrade2.first << "    " << LetterWordGrade2.second<<nl;
	cout << "=======================================================================\n";
}
int main() {
     	run
		findGpa();
	//	system ("pause");
}
