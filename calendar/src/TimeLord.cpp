#include "TimeLord.h"
#include <iostream>
#include <string>

void TimeLord::init(const TimeLord& other) {
	name = other.name;
	archives = other.archives;
	for (unsigned int i = 0; i < archives.size(); i++) {
		archives[i] = new Calendar(*archives[i]);
	}
}

void TimeLord::destroy() {
	for (unsigned int i = 0; i < archives.size(); i++) {
		delete archives[i];
	}
}

TimeLord::TimeLord(std::string name) : name(name) {

}

TimeLord::TimeLord(const TimeLord& other) {
	init(other);
}

TimeLord& TimeLord::operator=(const TimeLord& other) {
	if (this != &other) {
		destroy();
		init(other);
	}
	return *this;
}

TimeLord::~TimeLord() {
	destroy();
}

std::ostream& operator<< (std::ostream& out, const TimeLord& a) {
	out << "Name: " << a.name << std::endl;
	for (unsigned i = 0; i < a.archives.size(); i++) {
		out << *a.archives[i] << std::endl;
	}
	return out;
}

void TimeLord::newCalendar(std::string name) {
	Calendar* c = new Calendar(name);
	archives.push_back(c);
}

void TimeLord::newEvent(const Date& date, int start, int end, std::string title, std::string place, std::string descr) {
	archives.back()->addEvent(date, start, end, title, place, descr);
}

Calendar TimeLord::allArchives() const{
	Calendar* all = new Calendar(*archives[0]);
	for (unsigned int i = 1; i < archives.size(); i++) {
		*all += *archives[i];
	}
	return *all;
}

bool TimeLord::canVisit(std::string where, const Date& when, int hour) {
	for (unsigned int i = 0; i < archives.size(); i++) {
		if (archives[i]->hasEventAt(where, when, hour)) {
			return false;
		}
	}
	return true;
}

// Without reduce
//int TimeLord::numEvents() const {
//	return allArchives().numEventsC();
//}
//
//Date TimeLord::earliestVisitedDate() const{
//	return allArchives().earliestVisitedDateC();
//}
//
//int TimeLord::timeSpentInCentury(int century) const {
//	return allArchives().timeSpentInCenturyC(century);
//}

