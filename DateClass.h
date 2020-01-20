#ifndef DATECLASS.H
#define DATECLASS.H

#include <iostream>
#include <algorithm>
#include <windows.h>
#include <winbase.h>

#include "AssistantMethods.h"
#include "Income.h"
#include "Expense.h"

using namespace std;

class DateClass{

public:
    static bool checkFormatDate(string dateStr);
    static int amountOfDaysInMonth(int monthNumber, int year);
    static bool checkIfYearIsLeapYear(int year);
    static string getEnteredDateFromUser();
    static string getCurrentDate();
    static int changeDateOnIntWithoutDashes(string dateStr);
    static int changeDateOnInt(string dateStr);
    static string changeDateOnString(int dateInt);
    static string getYearFromDate(string date);
    static string getMonthFromDate(string date);
    static string getDayFromDate(string date);
    static bool sortByDateForIncomes(Income date1, Income date2);
    static bool sortByDateForExpenses(Expense date1, Expense date2);
    static string getDateOfPreviousMonth();
};

#endif
