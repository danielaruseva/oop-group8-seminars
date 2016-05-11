#ifndef COMPETITION_H
#define COMPETITION_H

#include <iostream>
#include <vector>
#include <string>
#include "Date.h"
#include "Event.h"
#include "Calendar.h"
#include "TimeLord.h"

class Competition {
public:
	Competition(const Date&, std::string place = "");
	Competition(const Competition& other);
	Competition& operator=(const Competition& other);
	~Competition();
	friend std::ostream& operator<< (std::ostream&, const Competition&);
	bool register_(TimeLord& other);
	int numParticipants();
	virtual TimeLord winner();

protected:
	Date date;
	std::string place;
	std::vector<TimeLord*> participants;

private:
	void init(const Competition& other);
	void destroy();

};

#endif // COMPETITION_H