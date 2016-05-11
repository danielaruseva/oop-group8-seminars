#ifndef COMPETITIONBYMOSTTIMESPENT15_H
#define COMPETITIONBYMOSTTIMESPENT15_H

#include "Competition.h"
#include <iostream>
#include <string>


class CompetitionByMostTimeSpent15 : public Competition
{
public:
	CompetitionByMostTimeSpent15(const Date&, std::string = "");;
	TimeLord winner();


};

#endif //COMPETITIONBYMOSTTIMESPENT15_H