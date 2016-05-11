#include "Competition.h"
#include <iostream>
#include <string>  
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>  

void Competition::init(const Competition& other) {
	date = other.date;
	place = other.place;
	participants = other.participants;
	for (unsigned int i = 0; i < participants.size(); i++) {
		participants[i] = new TimeLord(*participants[i]);
	}
}

void Competition::destroy() {
	for (unsigned int i = 0; i < participants.size(); i++) {
		delete participants[i];
	}
}

Competition::Competition(const Date& date, std::string place) : date(date), place(place) {

}

Competition::Competition(const Competition& other) {
	init(other);
}

Competition& Competition::operator=(const Competition& other) {
	if (this != &other) {
		destroy();
		init(other);
	}
	return *this;
}

Competition::~Competition() {
	destroy();
}

std::ostream& operator<< (std::ostream& out, const Competition& a) {
	out << "Date: " << a.date << std::endl;
	out << "Place: " << a.place << std::endl;
	out << "Participants:" << std::endl;
	for (unsigned i = 0; i < a.participants.size(); i++) {
		out << *a.participants[i] << std::endl;
	}
	return out;
}

bool Competition::register_(TimeLord& other) {
	for (unsigned int i = 0; i < 24; i++) {
		if (!(other.canVisit(place, date, i))) {
			return false;
		}
	}
	TimeLord* t = new TimeLord(other);
	participants.push_back(t);
	return true;
}

int Competition::numParticipants() {
	return participants.size();
}

TimeLord Competition::winner() {
	srand((unsigned int)time(NULL));
	int i = rand() % participants.size();
	return *participants[i];
}

