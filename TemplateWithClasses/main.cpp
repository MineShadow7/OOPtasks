#define _CRT_SECURE_NO_WARNINGS


#include <string>
#include <iostream>
#include "Classwork.h"

using namespace std;


int main()
{
	struct values {
		double santim;
		double kilometers;
		double miles;
	};

	values first;
	Distance firstdist(4);
	
	first.kilometers = firstdist.to_kilometers();
	Distance seconddist = firstdist + first.kilometers * 1000;
	first.miles = firstdist.to_miles();
	Distance thirddist = firstdist + first.miles * 60000;
	
	cout << firstdist << endl;
	cout << "To kilometers value: " << first.kilometers << endl;
	cout << "To miles value: " << first.miles << endl;
	cout << seconddist << " First dist + "<< first.kilometers <<" kilometers"<< endl;
	cout << thirddist << " First dist + " << first.miles << " miles" << endl;

	thirddist -= first.kilometers * 1000;
	cout << thirddist << " Third dist itself minus number " << first.kilometers * 1000 << endl;

	Distance fourthdist = firstdist * thirddist;
	cout << fourthdist << " Fourth dist multiply on " << thirddist.meters << endl;

	firstdist = fourthdist;
	cout << firstdist << " First dist is now equal to fourth dist " << endl;

	if (firstdist == fourthdist)
		cout << "First dist equal to fourth dist" << endl;
	else
		cout << "First dist is not equal to fourth dist" << endl;

	if (fourthdist >= firstdist)
		cout << "Fourth dist is bigger or equal to first dist" << endl;
	else
		cout << "Fourth dist is smaller than first dist" << endl;
	
	
	
	system("Pause");

	
	
}