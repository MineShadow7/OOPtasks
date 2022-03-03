#pragma once

#include <iostream>

using namespace std;


class Distance{
public:
	int meters;


	Distance() {
		meters = 0;
	}

	Distance(int _meters) {
		meters = _meters;
	}


	double to_miles() {
		double miles;
		miles = meters * 0.0006;
		return miles;
	}

	double to_kilometers() {
		double kilometers;
		kilometers = meters * 0.001;
		return kilometers;
	}

	Distance operator+(const Distance& right) {
		Distance res;
		res.meters = meters + right.meters;
		return res;
	}

	Distance operator-=(const Distance& right) {
		meters -= right.meters;
		return *this;
	}

	Distance operator*(const Distance& right) {
		Distance res;
		res.meters = meters * right.meters;
		return res;
	}

	Distance operator=(const Distance& right) {
		if (this == &right) {
			return *this;
		}
		meters = right.meters;
		return *this;
	}

	bool operator==(const Distance& right) {
		return (meters == right.meters);
	}

	bool operator!=(const Distance& right) {
		return (meters != right.meters);
	}

	bool operator>(const Distance& right) {
		return (meters > right.meters);
	}

	bool operator<(const Distance& right) {
		return (meters < right.meters);
	}

	bool operator>=(const Distance& right) {
		return (meters >= right.meters);
	}

	bool operator<=(const Distance& right) {
		return (meters <= right.meters);
	}

	friend ostream& operator<<(ostream& out, const Distance& right);
};

ostream& operator<<(ostream& out, const Distance& right) {
	out << "Your meters: " << right.meters;
	return out;
}




