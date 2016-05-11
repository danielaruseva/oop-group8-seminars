#include "CompetitionByEarliestDateVisited.h"
#include <string>
#include <iostream>

CompetitionByEarliestDateVisited::CompetitionByEarliestDateVisited(const Date& date, std::string place) : Competition(date, place) {

}

// Without reduce
//TimeLord CompetitionByEarliestDateVisited::winner() {
//	Date temp(2000, 1, 1);
//	int idx = 0;
//	for (int i = 0; i < numParticipants(); i++) {
//		if (temp > participants[i]->earliestVisitedDate()) {
//			temp = participants[i]->earliestVisitedDate();
//			idx = i;
//		}
//	}
//	return *participants[idx];
//}

// With reduce
TimeLord CompetitionByEarliestDateVisited::winner() {
	Date end(2147483647, 12, 31);
	Date temp(2147483647, 12, 31);
	int idx = 0;
	for (int i = 0; i < numParticipants(); i++) {
		if (temp > participants[i]->reduce<Date, Calendar>(earliestVisitedDate, end)) {
			temp = participants[i]->reduce<Date, Calendar>(earliestVisitedDate, end);
			idx = i;
		}
	}
	return *participants[idx];
}

