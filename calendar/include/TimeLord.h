#ifndef TIMELORD_H
#define TIMELORD_H

#include <iostream>
#include <vector>
#include <string>
#include "Date.h"
#include "Event.h"
#include "Calendar.h"

class TimeLord {
public:
	TimeLord(std::string name = "<New TimeLord>");
	TimeLord(const TimeLord& other);
	TimeLord& operator=(const TimeLord& other);
	~TimeLord();
	friend std::ostream& operator<< (std::ostream&, const TimeLord&);
	void newCalendar(std::string name = "<New Calendar>");
	void newEvent(const Date&, int, int, std::string = "Event", std::string = "", std::string = "");
	Calendar allArchives() const;
	bool canVisit(std::string, const Date&, int);
	// Without reduce
	/*int numEvents() const;
	Date earliestVisitedDate() const;
	int timeSpentInCentury(int century) const;*/

	// With reduce
	template <typename ResT, typename ElemT >
	using reduceFn = ResT(*) (ResT, ElemT);
	template <typename ResT, typename ElemT >
	ResT reduce(reduceFn <ResT, ElemT > f, ResT init) {
		ResT result = init;
		for (unsigned int i = 0; i < archives.size(); i++)
			result = f(result, *archives[i]);
		return result;
	}
	

private:
	std::string name;
	std::vector<Calendar*> archives;
	void init(const TimeLord& other);
	void destroy();

};

inline Date earliestVisitedDate(Date accumulated, Calendar x) {
	if (accumulated > x.earliestVisitedDateC()) {
		return x.earliestVisitedDateC();
	}
	else {
		return accumulated;
	}
}

inline int numEvents(int accumulated, Calendar x) {
	return accumulated + x.numEventsC();
}

// With reduce_1
//inline int* timeSpentInCentury(int* accumulated, Calendar x) {
//	accumulated[0] += x.timeSpentInCenturyC(accumulated[1]);
//	return accumulated;
//}

// With reduce_2
inline int timeSpentInCentury(int accumulated, Calendar x) {
	return accumulated + x.timeSpentInCenturyC(15);
}

#endif // TIMELORD_H

