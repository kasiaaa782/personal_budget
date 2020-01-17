#include "Budget.h"

void Budget::userRegistration() {
    userMenager.userRegistration();
}

void Budget::writeAllUsers() {
    userMenager.writeAllUsers();
}

void Budget::userLogin() {
    userMenager.userLogin();
    if(userMenager.ifUserIsLogged()){
        incomesMenager = new IncomesMenager(INCOMES_FILE_NAME, userMenager.getIDLoggedUser());
        expensesMenager = new ExpensesMenager(EXPENSES_FILE_NAME, userMenager.getIDLoggedUser());
    }
}

void Budget::userLogout() {
    userMenager.userLogout();
    incomesMenager->userLogout();
    delete incomesMenager;
    incomesMenager = NULL;
    expensesMenager->userLogout();
    delete expensesMenager;
    expensesMenager = NULL;
}

bool Budget::ifUserIsLogged() {
    userMenager.ifUserIsLogged();
}

char Budget::selectOptionFromMainMenu() {
    char choice;
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "8. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AssistantMethods::loadChar();
    return choice;
}

char Budget::selectOptionFromUserMenu() {
    char choice;
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AssistantMethods::loadChar();
    return choice;
}

void Budget::changePassword() {
    userMenager.changePasswordLoggedUser();
}

void Budget::addIncome(){
    if(userMenager.ifUserIsLogged()){
        incomesMenager->addIncome();
    }
    else {
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void Budget::addExpense(){
    if(userMenager.ifUserIsLogged()){
        expensesMenager->addExpense();
    }
    else {
        cout << "Aby dodac wydatek, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void Budget::balanceOfCurrentMonth(){
    if(userMenager.ifUserIsLogged()){
        float balance;
        system("cls");
        cout << ">>>BILANS Z AKTUALNEGO MIESIACA<<<" << endl;
        cout << endl;
        incomesMenager->printIncomesOfCurrentMonth();
        expensesMenager->printExpensesOfCurrentMonth();
        cout << endl << "PODSUMOWNIE: " << endl << endl;
        cout << "Przychody: " << incomesMenager->sumOfIncomesOfCurrentMonth() << " zl." << endl;
        cout << "Wydatki: " << expensesMenager->sumOfExpensesOfCurrentMonth() << " zl." << endl;
        balance = incomesMenager->sumOfIncomesOfCurrentMonth() - expensesMenager->sumOfExpensesOfCurrentMonth();
        if(balance > 0){
            cout << "Oszczednosci: " << balance << " zl." << endl;
        } else {
            cout << "Dlug: " << balance << " zl." << endl;
        }
        cout << endl;
        system("pause");
    } else {
        cout << "Aby pokazac bilans, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void Budget::balanceOfPreviousMonth(){
    if(userMenager.ifUserIsLogged()){
        float balance;
        system("cls");
        cout << ">>>BILANS Z POPRZEDNIEGO MIESIACA<<<" << endl;
        cout << endl;
        incomesMenager->printIncomesOfPreviousMonth();
        expensesMenager->printExpensesOfPreviousMonth();
        cout << endl << "PODSUMOWNIE: " << endl << endl;
        cout << "Przychody: " << incomesMenager->sumOfIncomesOfPreviousMonth() << " zl." << endl;
        cout << "Wydatki: " << expensesMenager->sumOfExpensesOfPreviousMonth() << " zl." << endl;
        balance = incomesMenager->sumOfIncomesOfPreviousMonth() - expensesMenager->sumOfExpensesOfPreviousMonth();
        if(balance > 0){
            cout << "Oszczednosci: " << balance << " zl." << endl;
        } else {
            cout << "Dlug: " << balance << " zl." << endl;
        }
        cout << endl;
        system("pause");
    } else {
        cout << "Aby pokazac bilans, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void Budget::balanceOfSelectedPeriod(){
    if(userMenager.ifUserIsLogged()){
        float balance;
        int dateBegin, dateEnd;
        system("cls");
        cout << ">>>BILANS Z WYBRANEGO OKRESU CZASU<<<" << endl;
        cout << endl;
        cout << "Podaj date poczatkowa: " << endl;
        dateBegin = AssistantMethods::changeDateOnInt(AssistantMethods::getEnteredDateFromUser());
        cout << endl << "Podaj date koncowa: " << endl;
        dateEnd = AssistantMethods::changeDateOnInt(AssistantMethods::getEnteredDateFromUser());
        cout << endl;
        incomesMenager->printIncomesOfSelectedPeriod(dateBegin, dateEnd);
        expensesMenager->printExpensesOfSelectedPeriod(dateBegin, dateEnd);
        cout << endl << "PODSUMOWNIE: " << endl << endl;
        cout << "Przychody: " << incomesMenager->sumOfIncomesOfSelectedPeriod(dateBegin, dateEnd) << " zl." << endl;
        cout << "Wydatki: " << expensesMenager->sumOfExpensesOfSelectedPeriod(dateBegin, dateEnd) << " zl." << endl;
        balance = incomesMenager->sumOfIncomesOfSelectedPeriod(dateBegin, dateEnd) - expensesMenager->sumOfExpensesOfSelectedPeriod(dateBegin, dateEnd);
        if(balance > 0){
            cout << "Oszczednosci: " << balance << " zl." << endl;
        } else {
            cout << "Dlug: " << balance << " zl." << endl;
        }
        cout << endl;
        system("pause");
    } else {
        cout << "Aby pokazac bilans, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}
