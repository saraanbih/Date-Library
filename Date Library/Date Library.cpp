#include <iostream>
#include "DateLibrary.h"

using namespace DateLibrary;




int main()
{
    //Leap Year
    short Year1 = ReadYear();
    if (IsLeapYear(Year1))
        cout << "Yes , Year [" << Year1 << "] is a leap year. \n";
    else
        cout << "No , Year [" << Year1 << "] is NOT a leap year. \n";
    
    //Number Of Days,Hours,Monutes,Seconds In a year
    short Year2 = ReadYear();
    cout << "\nNumber of Days in Year    [" << Year2 << "] is " << NumberOfDaysInAYear(Year1);
    cout << "\nNumber of Hours in Year   [" << Year2 << "] is " << NumberOfHoursInAYear(Year1);
    cout << "\nNumber of Minutes in Year [" << Year2 << "] is " << NumberOfMinutesInAYear(Year1);
    cout << "\nNumber of Seconds in Year [" << Year2 << "] is " << NumberOfSecondsInAYear(Year1);

    //Number Of Days,Hours,Minutes,Seconds InAMonth
    short Year3 = ReadYear();
    short Month1 = ReadMonth();
    cout << "\nNumber of Days in Month    [" << Month1 << "] is " << NumberOfDaysInAMonth(Month1, Year3);
    cout << "\nNumber of Hours in Month   [" << Month1 << "] is " << NumberOfHoursInAMonth(Month1, Year3);
    cout << "\nNumber of Minutes in Month [" << Month1 << "] is " << NumberOfMinutesInAMonth(Month1, Year3);
    cout << "\nNumber of Seconds in Month [" << Month1 << "] is " << NumberOfSecondsInAMonth(Month1, Year3);

    //Day Of Week Order,Day Short Name
    short Year4 = ReadYear();
    short Month2 = ReadMonth();
    short Day1 = ReadDay();
    short DayOrder = DayOfWeekOrder(Day1, Month2, Year4);
    cout << "\n\nDate        : " << Day1 << " / " << Month2 << " / " << Year4 << endl;
    cout << "Day Order       : " << DayOrder << endl;
    cout << "Day Name        : " << DayShortName(DayOrder) << endl;

    //Print Month Calendar
    short Year5 = ReadYear();
    short Month3 = ReadMonth();
    PrintMonthCalendar(Month3, Year5);

    //Print Year Calendar
    PrintYearCalendar(ReadYear());

    //Number Of Days From The Begining Of The Year
    short Day2 = ReadDay();
    short Month3 = ReadMonth();
    short Year5 = ReadYear();
    cout << "\n\nNumber of Days from beginning of the Year Is : " << NumberOfDaysFromTheBeginingOfTheYear(Day2, Month3, Year5);

    //Get Date From Day Order In Year
    short Day3 = ReadDay();
    short Month4 = ReadMonth();
    short Year6 = ReadYear();
    short DaysOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Day3, Month4, Year6);
    cout << "\n\nNumber of Days from beginning of the Year Is : " << DaysOrderInYear << endl;
    sDate Date1;
    Date1 = GetDateFromDayOrderInYear(DaysOrderInYear, Year6);    
    cout << "\nDate for [" << DaysOrderInYear << "] is: ";
    cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    //Date Add Days
    sDate Date2 = ReadFullDate();
    short Days = ReadDaysToAdd();
    Date2 = DateAddDays(Days, Date2);
    cout << "\nDate after adding [" << Days << "] days is: ";
    cout << Date2.Day << "/" << Date2.Month << "/" << Date2.Year;

    //Is Date3 One Before Date4
    sDate Date3 = ReadFullDate();
    cout << "\n\n";
    sDate Date4 = ReadFullDate();
    if (IsDate1BeforeDate2(Date3, Date4))
        cout << "\nYes, Date1 is Less than Date2.";
    else
        cout << "\nNo, Date1 is NOT Less than Date2.";
    
    //Is Date1 Equal Date2
    sDate Date5 = ReadFullDate();
    cout << "\n\n";
    sDate Date6 = ReadFullDate();
    if (IsDate1EqualDate2(Date5, Date6))
        cout << "\nYes, Date1 is Equal to Date2.";
    else
        cout << "\nNo, Date1 is NOT Equal to Date2.";

    //Is Last Day In Month && Is Last Month In Year
    sDate Date7 = ReadFullDate();
    if (IsLastDayInMonth(Date7))
        cout << "\nYes, Day is Last In Month.";
    else
        cout << "\nNo, Day is NOT Last In Month.";

    if (IsLastMonthInYear(Date7.Month))
        cout << "\nYes, Month is Last In Year.";
    else
        cout << "\nNo, Month is NOT Last In Year.";

    //Increase Date By One Day
    sDate Date8 = ReadFullDate();
    Date8 = IncreaseDateByOneDay(Date8);
    cout << "\nDate after adding one Day is : " << Date8.Day << "/" << Date8.Month << "/" << Date8.Year;

    //Get Difference In Days
    sDate Date9 = ReadFullDate();
    cout << "\n\n";
    sDate Date10 = ReadFullDate();
    cout << "\nDifference is: " << GetDifferenceInDays(Date8, Date10) << " Day(s).";
    cout << "\nDifference (Including End Day) is: " << GetDifferenceInDays(Date8, Date10, true) << " Day(s).";

    //Your Age In Days
    cout << "\nPlease Enter Your Date of Birth:\n";
    sDate Date11 = ReadFullDate();
    sDate Date12 = GetSystemDate();
    cout << "\nYour Age is : " << GetDifferenceInDays(Date11, Date12, true) << " Day(s).";

    //Diff In Days (Negative Days)
    sDate Date13 = ReadFullDate();
    cout << "\n\n";
    sDate Date14 = ReadFullDate();
    cout << "\nDifference is: " << GetDifferenceInDays(Date13, Date14) << " Day(s).";
    cout << "\nDifference (Including End Day) is: " << GetDifferenceInDays(Date13, Date14, true) << " Day(s).";

   //Increase Date Problems
    sDate Date14 = ReadFullDate();
    cout << "\nDate After: \n";

    Date14 = IncreaseDateByOneDay(Date14);
    cout << "\n01-Adding one day is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByXDays(10, Date14);
    cout << "\n02-Adding 10 days is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByOneWeek(Date14);
    cout << "\n03-Adding one week is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByXWeeks(10, Date14);
    cout << "\n04-Adding 10 weeks is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByOneMonth(Date14);
    cout << "\n05-Adding one month is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByXMonths(5, Date14);
    cout << "\n06-Adding 5 months is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByOneYear(Date14);
    cout << "\n07-Adding one year is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByXYears(10, Date14);
    cout << "\n08-Adding 10 Years is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByXYearsFaster(10, Date14);
    cout << "\n09-Adding 10 Years (faster) is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByOneDecade(Date14);
    cout << "\n10-Adding one Decade is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByXDecades(10, Date14);
    cout << "\n11-Adding 10 Decades is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByXDecadesFaster(10, Date14);
    cout << "\n12-Adding 10 Decade (faster) is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByOneCentury(Date14);
    cout << "\n13-Adding One Century is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;
    Date14 = IncreaseDateByOneMillennium(Date14);
    cout << "\n14-Adding One Millennium is: " << Date14.Day << "/" << Date14.Month << "/" << Date14.Year;

    //Decrease Date Problems  
    sDate Date15 = ReadFullDate();
    cout << "\nDate After: \n";

    Date15 = DecreaseDateByOneDay(Date15);
    cout << "\n01-Subtracting one day is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByXDays(10, Date15);
    cout << "\n02-Subtracting 10 days is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByOneWeek(Date15);
    cout << "\n03-Subtracting one week is:" << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByXWeeks(10, Date1);
    cout << "\n04-Subtracting 10 weeks is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByOneMonth(Date15);
    cout << "\n05-Subtracting one month is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByXMonths(5, Date15);
    cout << "\n06-Subtracting 5 months is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByOneYear(Date15);
    cout << "\n07-Subtracting one year is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByXYears(10, Date15);
    cout << "\n08-Subtracting 10 Years is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByXYearsFaster(10, Date15);
    cout << "\n09-Subtracting 10 Years (faster) is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByOneDecade(Date1);
    cout << "\n10-Subtracting one Decade is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByXDecades(10, Date15);
    cout << "\n11-Subtracting 10 Decades is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByXDecadesFaster(10, Date15);
    cout << "\n12-Subtracting 10 Decade (faster) is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByOneCentury(Date15);
    cout << "\n13-Subtracting One Century is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;
    Date15 = DecreaseDateByOneMillennium(Date15);
    cout << "\n14-Subtracting One Millennium is: " << Date15.Day << "/" << Date15.Month << "/" << Date15.Year;

    //More Date Problems
    sDate Date16;
    Date16 = GetSystemDate();

    cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date16)) << " , " << Date16.Day << "/" << Date16.Month << "/" << Date16.Year << endl;
    //-------------------- 
    cout << "\nIs it End of Week ? \n";
    if (IsEndOfWeek(Date16))
        cout << "Yes , it is Saturday , it's of Week .";
    else
        cout << "No , it is Not End of Week .";
    //-------------------- 
    cout << "\n\nIs it Weekend ? \n";
    if (IsWeekend(Date16))
        cout << "Yes , it is a Week end .";
    else
        cout << "No , today is : " << DayShortName(DayOfWeekOrder(Date16)) << " Not a Week end";
    //-------------------- 
    cout << "\n\nIs it Business Day ? \n";
    if (IsBusinessDay(Date16))
        cout << "Yes , it is a Business Day .";
    else
        cout << "No , it is Not Business Day .";
    //-------------------- 
    cout << "\n\nDays Until end of Week : "
        << DaysUntilTheEndOfWeek(Date16) << " Days.";
    //-------------------- 
    cout << "\nDays Until end of Month : "
        << DaysUntilTheEndOfMonth(Date16) << " Days.";
    //-------------------- 
    cout << "\nDays Until end of Month : " << DaysUntilTheEndOfYear(Date16) << " Days.";

    //Calculate Vacation Days
    cout << "\nVacations Starts : \n";
    sDate DateFrom = ReadFullDate();
    cout << "\nVacations Ends : \n";
    sDate DateTo = ReadFullDate();
    cout << "\n\nVacation From : " << DayShortName(DayOfWeekOrder(DateFrom)) << " , "
        << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;
    cout << "\n\nVacation End : " << DayShortName(DayOfWeekOrder(DateTo)) << " , " 
        << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;
    cout << "\n\nActual Vacations Days is : " <<
        CalculateVacationDays(DateFrom, DateTo);

    //Calculate Vacation Return Date 
    cout << "\nVacation Starts: ";
    sDate DateFrom = ReadFullDate();
    short VacationDays = ReadVacationDays();
    sDate ReturnDate = CalculateVacationReturnDate(DateFrom, VacationDays);
    cout << "\n\nReturn Date: " << DayShortName(DayOfWeekOrder(ReturnDate)) << " , " 
        << ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year << endl;

    //Is Date1 After Date2
    cout << "\nEnter Date1 : ";
    sDate Date17 = ReadFullDate();
    cout << "\nEnter Date2 : ";
    sDate Date18 = ReadFullDate();
    if (IsDate1AfterDate2(Date17, Date18))
        cout << "\nYes , Date1 is After Date2.";
    else
        cout << "\nNo , Date1 is NOT After Date2.";

    //Compare Dates
    cout << "\nEnter Date1:";
    sDate Date19 = ReadFullDate();
    cout << "\nEnter Date2:";
    sDate Date20 = ReadFullDate();
    cout << "\nCompare Result = " << CompareDates(Date19, Date20);
    cout << "\nNo , Date1 is NOT After Date2.";

    //Is OverlapP eriods
    cout << "\nEnter Period 1:";
    stPeriod Period1 = ReadPeriod();
    cout << "\nEnter Period 2:";
    stPeriod Period2 = ReadPeriod();
    if (IsOverlapPeriods(Period1, Period2))
        cout << "\nYes, Periods Overlap\n";
    else
        cout << "\nNo, Periods do not Overlap\n";

    //Period Length In Days
    cout << "\nEnter Period 1:";
    stPeriod Period3 = ReadPeriod();
    cout << "\nPeriod Length is: " << PeriodLengthInDays(Period3);
    cout << "\nPeriod Length (Including End Date) is: " << PeriodLengthInDays(Period3, true);

    //Is Date In Period
    cout << "\nEnter Period :";
    stPeriod Period4 = ReadPeriod();
    cout << "\nEnter Date to check:\n";
    sDate Date21 = ReadFullDate();
    if (IsDateInPeriod(Date21, Period4))
        cout << "\nYes, Date is within period\n";
    else
        cout << "\nNo, Date is NOT within period\n";

    //Count Overlap Days
    cout << "\nEnter Period 1 :";
    stPeriod Period5 = ReadPeriod();
    cout << "\nEnter Period 2 :";
    stPeriod Period6 = ReadPeriod();
    cout << "\nOverlap Days Count Is: " << CountOverlapDays(Period5, Period6);
    
    //Is Valid Date
    sDate Date22 = ReadFullDate();
    if (IsValidDate(Date22))
        cout << "\nYes, Date is a validate date.\n";
    else
        cout << "\nNo, Date is a NOT validate date\n";

    // Read / Print : Date String 
    string DateString1 = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    sDate Date23 = StringToDate(DateString1);
    cout << "\nDay:" << Date23.Day << endl;
    cout << "Month:" << Date23.Month << endl;
    cout << "Year:" << Date23.Year << endl;
    cout << "\nYou Entered: " << DateToString(Date23) << "\n";
    
    //Format Date
    string DateString2 = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    sDate Date24 = StringToDate(DateString2);
    cout << "\n" << FormateDate(Date24) << "\n";
    cout << "\n" << FormateDate(Date24, "yyyy/dd/mm") << "\n";
    cout << "\n" << FormateDate(Date24, "mm/dd/yyyy") << "\n";
    cout << "\n" << FormateDate(Date24, "mm-dd-yyyy") << "\n";
    cout << "\n" << FormateDate(Date24, "dd-mm-yyyy") << "\n";
    cout << "\n" << FormateDate(Date24, "Day:dd, Month:mm, Year:yyyy") << "\n";


    system("pause > 0");
    return 0;
    
}