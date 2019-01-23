#ifndef HELPER_H
#define HELPER_H

#include <ctime> 
#include <string>
#include <sstream> // for converting to string

namespace Helper
{
	//Generic Types
	template <class T> 
	
	// Function: that converts anything to String
	// we are using the address of the passed in variable
	// this allows us to utilize generics
	std::string ToString(const T &);

	// like class (everything is by default public)
	struct DateTime
	{
		// local time on machine that keylogger is running
		DateTime()
		{
			// use from ctime library
			time_t ms;

			// set our time to variable
			time(&ms);
			struct tm *info = localtime(&ms);

			D = info->tm_mday;
			m = info->tm_mon + 1;
			y = 1900 + info->tm_year;
			M = info->tm_min;
			H = info->tm_hour;
			S = info->tm_sec;

		}

		DateTime(int D, int m, int y, int M, int H, int S) : D(D), m(m), y(y), M(M), H(H), S(S) {}
		DateTime(int D, int m, int y) : D(D), m(m), y(y), H(0), M(0), S(0) {}


		// only read and not change class
		DateTime Now() const
		{
			return DateTime();
		}

		int D, m, y, H, M, S;

		std::string GetDateString() const
		{
			// format output Date : ex -> DD.mm.YYYY
			return std::string(D < 10 ? "0" : "") + ToString(D) +
				std::string(m < 10 ? ".0" : ".") + ToString(m) + "." +
				ToString(y);
		}

		std::string GetTimeString(const std::string &sep = ":") const
		{
			//format output Time : ex -> HH:MM:SS 
			return std::string(H < 10 ? "0" : "") + ToString(H) + sep +
				std::string(M < 10 ? "0" : "") + ToString(M) + sep +
				std::string(S < 10 ? "0" : "") + ToString(S);
		}

		std::string GetDateTimeString(const std::string &sep = ":") const
		{
			return GetDateString() + " " + GetTimeString(sep);
		}

	};

	template <class T>
	std::string ToString(const T &e)
	{
		std::ostringstream s; 
		s << e; // Accepts values that accept insertion operator 
		return s.str();
	}

	

}

#endif // !HELPER_H


