/*****************************
 * Автор: Щербакова Кристина *
 *****************************/

#include <iostream>
#include <iomanip>
using namespace std;

bool isLeapYear(int year) {
  return (year % 4 == 0);
}

int getDaysInMonth(int month, int year) {
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
  if (month == 2 && isLeapYear(year)) {
    return 29;
  }
  return days[month - 1];
}

int getFirstDayOfYear(int year) {
  int day = (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
  return (day + 6) % 7; 
}

int main() {
  int year;
    
  cout << "Enter the year: ";
  cin >> year;
    
  string months[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    
  int firstDay = getFirstDayOfYear(year);
    
  cout << "\nКАЛЕНДАРЬ НА " << year << " ГОД\n";
  cout << "====================\n";
    
  for (int month = 1; month <= 12; ++month) {
    cout << "\n" << months[month - 1] << "\n";
    cout << "Пн Вт Ср Чт Пт Сб Вс\n";
        
  int daysInMonth = getDaysInMonth(month, year);
  int currentDay = firstDay;
        
  for (int space = 0; space < firstDay; ++space) {
    cout << "   ";
  }
        
  for (int day = 1; day <= daysInMonth; ++day) {
    cout << setw(2) << day << " ";
            
  currentDay++;
    if (currentDay == 7) {
      cout << "\n";
      currentDay = 0;
    }
  }
        
  firstDay = currentDay;
  cout << "\n\n";
}
    
  return 0;
}
