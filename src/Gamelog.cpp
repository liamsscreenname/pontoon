#include "Gamelog.h"

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

Gamelog::Gamelog(){
	time_t rawTime = time(0); //get current time as a time_t object
	tm* timeStruct = localtime(&rawTime); //Save time as a tm struct

	string year = to_string(timeStruct->tm_year - 100); //tm_year is stored as the number of years since 1900

	string month;
	int temp = timeStruct->tm_mon + 1; //tm_mon is stored as the number of months since January
	if (temp < 10)
		month = "0" + to_string(temp); //add an extra 0 if the number of months is less than 10
	else
		month = to_string(temp); 

	string day;
	temp = timeStruct->tm_mday; 
	if (temp < 10)
		day = "0" + to_string(temp); 
	else
		day = to_string(temp); 

	string hour;
	temp = timeStruct->tm_hour; 
	if (temp < 10)
		hour = "0" + to_string(temp); 
	else
		hour = to_string(temp); 

	string min;
	temp = timeStruct->tm_min; 
	if (temp < 10)
		min = "0" + to_string(temp); 
	else
		min = to_string(temp); 

	startTime = hour + ":" + min + " " + day + "-" + month + "-20" + year;
	logName = year + month + day + "_" + hour + min + ".txt";
}

Gamelog::~Gamelog(){
	time_t rawTime = time(0); 
	tm* timeStruct = localtime(&rawTime); 

	string year = to_string(timeStruct->tm_year - 100); 

	string month;
	int temp = timeStruct->tm_mon + 1; 
	if (temp < 10)
		month = "0" + to_string(temp); 
	else
		month = to_string(temp); 

	string day;
	temp = timeStruct->tm_mday; 
	if (temp < 10)
		day = "0" + to_string(temp); 
	else
		day = to_string(temp); 

	string hour;
	temp = timeStruct->tm_hour; 
	if (temp < 10)
		hour = "0" + to_string(temp); 
	else
		hour = to_string(temp); 

	string min;
	temp = timeStruct->tm_min; 
	if (temp < 10)
		min = "0" + to_string(temp); 
	else
		min = to_string(temp); 

	endTime = hour + ":" + min + " " + day + "-" + month + "-20" + year;

	ofstream out(logName);
	out << "Game started at: " << startTime << "\nGame finished at: " << endTime << 
	"\nRounds: " << rounds - 1 << "\nWon: " << wins << "\nLost: " << losses << "\n--\n";
	for (int i = 0; i < results.size(); i++){
		out << results[i];
	}
	out.close();
}

void Gamelog::startRound(){
	roundResult = "Round " + to_string(rounds) + ": ";
	rounds++;
}

void Gamelog::endRound(const int code){
	if (code < 0){
		roundResult += "lost. \n";
		losses++;
	}
	else if (code > 0){
		roundResult += "won. \n";
		wins++;
	}
	else
		roundResult += "draw. \n";

	results.push_back(roundResult);
}