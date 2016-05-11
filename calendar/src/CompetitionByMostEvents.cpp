#include "CompetitionByMostEvents.h"
#include <string>
#include <iostream>

CompetitionByMostEvents::CompetitionByMostEvents(const Date& date, std::string place) : Competition(date, place) {

}

// Without reduce
//TimeLord CompetitionByMostEvents::winner() {
//	int temp = 0, idx = 0;
//	for (int i = 0; i < numParticipants(); i++) {
//		if (temp < participants[i]->numEvents()) {
//			temp = participants[i]->numEvents();
//			idx = i;
//		}
//	}
//	return *participants[idx];
//}

// With reduce
TimeLord CompetitionByMostEvents::winner() {
	int temp = 0, idx = 0;
		for (int i = 0; i < numParticipants(); i++) {
			if (temp < participants[i]->reduce<int, Calendar>(numEvents, 0)) {
				temp = participants[i]->reduce<int, Calendar>(numEvents, 0);
				idx = i;
			}
		}
		return *participants[idx];
}
