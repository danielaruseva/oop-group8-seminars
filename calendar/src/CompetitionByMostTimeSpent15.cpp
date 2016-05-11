#include "CompetitionByMostTimeSpent15.h"
#include <string>
#include <iostream>

CompetitionByMostTimeSpent15::CompetitionByMostTimeSpent15(const Date& date, std::string place) : Competition(date, place) {

}

// Without reduce
//TimeLord CompetitionByMostTimeSpent15::winner() {
//	int temp = 0, idx = 0, century = 15;
//	for (int i = 0; i < numParticipants(); i++) {
//		if (temp < participants[i]->timeSpentInCentury(century)) {
//			temp = participants[i]->timeSpentInCentury(century);
//			idx = i;
//		}
//	}
//	return *participants[idx];
//}

// With reduce_1
//TimeLord CompetitionByMostTimeSpent15::winner() {
//	int temp = 0, idx = 0;
//	int a[] = {0, 15};
// 		for (int i = 0; i < numParticipants(); i++) {
//			if (temp < participants[i]->reduce<int*, Calendar>(timeSpentInCentury, a)[0]) {
//				temp = participants[i]->reduce<int*, Calendar>(timeSpentInCentury, a)[0];
//				idx = i;
//			}
//		}
//		return *participants[idx];
//}

// With reduce_2
TimeLord CompetitionByMostTimeSpent15::winner() {
	int temp = 0, idx = 0;
	for (int i = 0; i < numParticipants(); i++) {
		if (temp < participants[i]->reduce<int, Calendar>(timeSpentInCentury, 0)) {
			temp = participants[i]->reduce<int, Calendar>(timeSpentInCentury, 0);
			idx = i;
		}
	}
	return *participants[idx];
}