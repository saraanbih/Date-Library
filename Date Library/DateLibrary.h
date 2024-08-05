#pragma once
#pragma warning(disable : 4996) 

#include <iostream> 
#include <string> 
#include <iomanip> 
#include <ctime> 
#include <vector>
using namespace std;

namespace DateLibrary
{
	short ReadYear()
	{
		short Year = 0;

		cout << "\nPlease enter a year to check? ";
		cin >> Year;

		return Year;
	}

	short ReadMonth()
	{
		short Month = 0;

		cout << "\nPlease enter a Month to check ? ";
		cin >> Month;

		return Month;
	}

	short ReadDay()
	{
		short Day = 0;

		cout << "\nPlease enter a Day to check ? ";
		cin >> Day;

		return Day;
	}

	/*bool IsLeapYear(short Year)
	{
		// leap year if perfectly divisible by 40 
		if (Year % 400 == 0)
		{
			return true;
		}
		// not a leap year if divisible by 100 
		// but not divisible by 400 
		else if (Year % 100 == 0)
		{
			return false;
		}
		// leap year if not divisible by 100 
		// but divisible by 4 
		else if (Year % 4 == 0)
		{
			return true;
		}
		// all other years are not leap years 
		else
		{
			return false;
		}
	}*/

	bool IsLeapYear(short Year)
	{
		// if year is divisible by 4 AND not divisible by 10 OR if year is divisible by 400 then it is a leap year 

		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}

	int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}

	/*short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return  0;

		if (Month == 2)
		{
			return  IsLeapYear(Year) ? 29 : 28;
		}
		short arr31Days[7] = { 1,3,5,7,8,10,12 };
		for (short i = 1; i <= 7; i++)
		{
			if (arr31Days[i - 1] == Month)
				return 31;
		}
		//if you reach here then its 30 days. 
		return  30;
	}

	short NumberOfHoursInAMonth(short Month, short Year)
	{
		return NumberOfDaysInAMonth(Month, Year) * 24;
	}

	int NumberOfMinutesInAMonth(short Month, short Year)
	{
		return NumberOfHoursInAMonth(Month, Year) * 60;
	}

	int NumberOfSecondsInAMonth(short Month, short Year)
	{
		return NumberOfMinutesInAMonth(Month, Year) * 60;
	}*/

	short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
			return  0;

		int NumberOfDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

	}

	short NumberOfHoursInAMonth(short Month, short Year)
	{
		return NumberOfDaysInAMonth(Month, Year) * 24;
	}

	int NumberOfMinutesInAMonth(short Month, short Year)
	{
		return NumberOfHoursInAMonth(Month, Year) *	60;
	}

	int NumberOfSecondsInAMonth(short Month, short Year)
	{
		return NumberOfMinutesInAMonth(Month, Year)	* 60;
	}

	short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		// Gregorian: 
		//0:sun, 1:Mon, 2:Tue...etc.  
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrder(sDate Date)
	{
		return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder];
	}

	string MonthShortName(short MonthNumber)
	{
		string Months[12] =
		{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return (Months[MonthNumber - 1]);
	}

	void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;

		// Index of the day from 0 to 6 
		int current = DayOfWeekOrder(1, Month, Year);

		NumberOfDays = NumberOfDaysInAMonth(Month, Year);

		// Print the current month name 
		printf("\n _______________%s__________________\n\n",
		MonthShortName(Month).c_str()); 

		// Print the columns 
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces 
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n ____________________________________\n");
	}

	void PrintYearCalendar(short Year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("  _________________________________\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}

	short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		TotalDays += Day;

		return TotalDays;
	}

	struct sDate
	{
		short Year;
		short Month;
		short Day;
	};

	sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		sDate Date;

		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date.Year = Year;

		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	sDate DateAddDays(short Days, sDate Date)
	{
		short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
		short MonthDays = 0;
		Date.Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	sDate ReadFullDate()
	{
		sDate Date;
		Date.Day = ReadDay();
		Date.Month = ReadMonth();
		Date.Year = ReadYear();
		return Date;
	}

	short ReadDaysToAdd()
	{
		short Days;
		cout << "\nHow many days to add? ";
		cin >> Days;
		return Days;
	}


	bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
	{
		return  (Date1.Year < Date2.Year) ? true :
			((Date1.Year == Date2.Year) ?
			((Date1.Month < Date2.Month) ? true :
			(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	bool IsDate1EqualDate2(sDate Date1, sDate Date2)
	{
		return (Date1.Year == Date2.Year) ?
			((Date1.Month == Date2.Month) ?
			((Date1.Day ==	Date2.Day) ? true : false) : false) : false;
	}

	bool IsLastDayInMonth(sDate Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
	}

	bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	sDate IncreaseDateByOneDay(sDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}
		return Date;
	}

	int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days : Days;
	}

	sDate GetSystemDate()
	{
		sDate Date;

		time_t t = time(0);
		tm* now = localtime(&t);

		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;

		return Date;
	}

	void SwapDates(sDate& Date1, sDate& Date2)
	{
		sDate TempDate;

		TempDate.Year = Date1.Year;
		TempDate.Month = Date1.Month;
		TempDate.Day = Date1.Day;

		Date1.Year = Date2.Year;
		Date1.Month = Date2.Month;
		Date1.Day = Date2.Day;

		Date2.Year = TempDate.Year;
		Date2.Month = TempDate.Month;
		Date2.Day = TempDate.Day;

	}

	int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}

	sDate IncreaseDateByXDays(short Days, sDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	sDate IncreaseDateByOneWeek(sDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	sDate IncreaseDateByXWeeks(short Weeks, sDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	sDate IncreaseDateByOneMonth(sDate Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}
	   //last check day in date should not exceed max days in the current month 
	   // example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
	   // be 28/2/2022 
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	sDate IncreaseDateByXMonths(short Months, sDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	sDate IncreaseDateByOneYear(sDate Date)
	{
		Date.Year++;
		return Date;
	}

	sDate IncreaseDateByXYears(short Years, sDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}

	sDate IncreaseDateByXYearsFaster(short Years, sDate Date)
	{
		Date.Year += Years;
		return Date;
	}

	sDate IncreaseDateByOneDecade(sDate Date)
	{
		//Period of 10 years 
		Date.Year += 10;
		return Date;
	}

	sDate IncreaseDateByXDecades(short Decade, sDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}

	sDate IncreaseDateByXDecadesFaster(short Decade, sDate Date)
	{
		Date.Year += Decade * 10;
		return Date;
	}

	sDate IncreaseDateByOneCentury(sDate Date)
	{
		//Period of 100 years 
		Date.Year += 100;
		return Date;
	}

	sDate IncreaseDateByOneMillennium(sDate Date)
	{
		//Period of 1000 years 
		Date.Year += 1000;
		return Date;
	}

	sDate DecreaseDateByOneDay(sDate Date)
	{

		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}
		return Date;
	}

	sDate DecreaseDateByXDays(short Days, sDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	sDate DecreaseDateByOneWeek(sDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	sDate DecreaseDateByXWeeks(short Weeks, sDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	sDate DecreaseDateByOneMonth(sDate Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}
		short NumberOfDaysInCurrentMonth =
			NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	sDate DecreaseDateByXMonths(short Months, sDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	sDate DecreaseDateByOneYear(sDate Date)
	{
		Date.Year--;
		return Date;
	}

	sDate DecreaseDateByXYears(short Years, sDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	sDate DecreaseDateByXYearsFaster(short Years, sDate Date)
	{
		Date.Year -= Years;
		return Date;
	}

	sDate DecreaseDateByOneDecade(sDate Date)
	{
		//Period of 10 years 
		Date.Year -= 10;
		return Date;
	}

	sDate DecreaseDateByXDecades(short Decade, sDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	sDate DecreaseDateByXDecadesFaster(short Decade, sDate Date)
	{
		Date.Year -= Decade * 10;
		return Date;
	}

	sDate DecreaseDateByOneCentury(sDate Date)
	{
		//Period of 100 years 
		Date.Year -= 100;
		return Date;
	}

	sDate DecreaseDateByOneMillennium(sDate Date)
	{
		//Period of 1000 years 
		Date.Year -= 1000;
		return Date;
	}

	bool IsEndOfWeek(sDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}

	bool IsWeekend(sDate Date)
	{
		// Weekends are Fri and Sat 
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 6 || DayIndex == 5);
	}

	bool IsBusinessDay(sDate Date)
	{
		// Weekends are Sun , Mon , Tue , Wed and Thur 

		/*
		short DayIndex = DayOfWeekOrder(Date);
		return ( DayIndex >= 0 && DayIndex <= 4 );
		*/

		return !IsWeekend(Date);
	}

	short DaysUntilTheEndOfWeek(sDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}

	short DaysUntilTheEndOfMonth(sDate Date)
	{
		sDate EndOfMonthDate;

		EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);;
		EndOfMonthDate.Month = Date.Month;
		EndOfMonthDate.Year = Date.Year;

		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	}

	short DaysUntilTheEndOfYear(sDate Date)
	{
		sDate EndOfMonthDate;

		EndOfMonthDate.Day = 31;
		EndOfMonthDate.Month = 12;
		EndOfMonthDate.Year = Date.Year;

		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	}

	short CalculateVacationDays(sDate DateFrom, sDate DateTo)
	{
		short DaysCount = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;
			DateFrom = IncreaseDateByOneDay(DateFrom);

		}

		return DaysCount;
	}

	sDate CalculateVacationReturnDate(sDate DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		//in case the data  is weekend keep adding one day util you reach business day
			//we get rid of all weekends before the first business day 
			while (IsWeekend(DateFrom))
			{
				DateFrom = IncreaseDateByOneDay(DateFrom);
			}

		//here we increase the vacation dates to add all weekends to it. 

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekend(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//in case the return date is week end keep adding one day util you reach business day
			while (IsWeekend(DateFrom))
			{
				DateFrom = IncreaseDateByOneDay(DateFrom);
			}

		return DateFrom;
	}

	short ReadVacationDays()
	{
		short Days;
		cout << "\nPlease enter vacation days? ";
		cin >> Days;
		return Days;
	}

	bool IsDate1AfterDate2(sDate Date1, sDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2)
			&& !IsDate1EqualDate2(Date1, Date2));
	}

	enum enDateCompare {Before = -1, Equal = 0, After = 1};

	enDateCompare CompareDates(sDate Date1, sDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;
		/* if (IsDate1AfterDate2(Date1,Date2))
		return enDateCompare::After;*/
		//this is faster 
		return enDateCompare::After;
	}

	struct stPeriod
	{
		sDate StartDate;
		sDate EndDate;
	};

	bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
	{
		if (CompareDates(Period2.EndDate,Period1.StartDate) == enDateCompare::Before
			||
			CompareDates(Period2.StartDate,Period1.EndDate) == enDateCompare::After)
			return false;
		else
			return true;
	}

	stPeriod ReadPeriod()
	{
		stPeriod Period;

		cout << "\nEnter Start Date:\n";
		Period.StartDate = ReadFullDate();

		cout << "\nEnter End Date:\n";
		Period.EndDate = ReadFullDate();

		return Period;
	}

	int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false)
	{
		return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
	}

	bool IsDateInPeriod(sDate Date, stPeriod Period)
	{
		return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before ||
			CompareDates(Date, Period.EndDate) == enDateCompare::After);
	}

	bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
	{
		if (CompareDates(Period2.EndDate, Period1.StartDate) ==enDateCompare::Before ||
			CompareDates(Period2.StartDate, Period1.EndDate) ==enDateCompare::After)
			return false;
		else
			return true;
	}

	int CountOverlapDays(stPeriod Period1, stPeriod Period2)
	{
		int Period1Length = PeriodLengthInDays(Period1, true);
		int Period2Length = PeriodLengthInDays(Period2, true);
		int OverlapDays = 0;

		if (!IsOverlapPeriods(Period1, Period2))
			return 0;

		if (Period1Length < Period2Length)
		{
			while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsDateInPeriod(Period1.StartDate, Period2))
					OverlapDays++;

				Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
			}
		}
		else
		{
			while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
			{
				if (IsDateInPeriod(Period2.StartDate, Period1))
					OverlapDays++;

				Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
			}
		}
		return OverlapDays;
	}


	bool IsValidDate(sDate Date)
	{
		if (Date.Day < 1 || Date.Day > 31)
			return false;

		if (Date.Month < 1 || Date.Month > 12)
			return false;

		if (Date.Month == 2)
		{
			if
				(IsLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}
		short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInMonth)
			return false;

		return true;

	}


	vector<string> SplitString(string S1, string
		Delim)
	{
		vector<string> vString;
		short pos = 0;
		string sWord; // define a string variable 

		// use find() function to get the position of the delimiters

		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
				if (sWord != "")
				{
					vString.push_back(sWord);
				}
			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}
		return vString;
	}

	string DateToString(sDate Date)
	{
		return  to_string(Date.Day) + "/" +
			to_string(Date.Month) + "/" +
			to_string(Date.Year);
	}

	sDate StringToDate(string DateString)
	{
		sDate Date;
		vector <string> vDate;

		vDate = SplitString(DateString, "/");

		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		return Date;
	}

	string ReadStringDate(string Message)
	{
		string DateString;
		cout << Message;
		getline(cin >> ws, DateString);

		return DateString;
	}

	string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
	{
		short pos = S1.find(StringToReplace);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);

			pos = S1.find(StringToReplace);//find next     
		}
		return S1;
	}

	string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";

		FormattedDateString = ReplaceWordInString(DateFormat, "dd",
			to_string(Date.Day));
		FormattedDateString = ReplaceWordInString(FormattedDateString, "mm",
			to_string(Date.Month));
		FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy",
			to_string(Date.Year));

		return  FormattedDateString;
	}

	

}