#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <windows.h>
#include <unistd.h>

using namespace std;

void setCursorPosition(int x, int y) {
	
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main() {
	
 	setCursorPosition(48, 12);
 	cout << "Welcome to Alarm Clock ";
 	sleep(3);
 	system("cls");
   int alarmHour, alarmMinute, alarmSecond;
    char colon = ':';

    cout << "Set the alarm time (HH:MM:SS): ";

    setCursorPosition(0, 1);//
    cin >> alarmHour;
    setCursorPosition(52, 12);//
    cout << alarmHour << colon;
    setCursorPosition(2, 1);//
    cin >> alarmMinute;
    setCursorPosition(54, 12);//
    cout << alarmMinute << colon;
    setCursorPosition(5, 1);//
    cin >> alarmSecond;
    setCursorPosition(57, 12);//
    cout << alarmSecond; 
    system("cls");
    sleep(2);
    while (true) {
        
        auto now = chrono::system_clock::now();   
		                                                                                                               
        time_t nowTime = chrono::system_clock::to_time_t(now);
        
        tm *currentTime = localtime(&nowTime);       
		                                               	
        setCursorPosition(52, 12);
        
        cout << currentTime->tm_hour << ":" 
             << currentTime->tm_min << ":" 
             << currentTime->tm_sec << "\r";
                                                                         
     sleep(1);
                                                                        
        if (currentTime->tm_hour == alarmHour &&
            currentTime->tm_min == alarmMinute &&
            currentTime->tm_sec == alarmSecond) {
             
            while(true){
			
			Beep(523,500);
			Beep(523,500);
			Beep(523,500);
			Beep(523,500);
            cin.get();
        }
          setCursorPosition(48, 14);
          cout << "Alarm";  

        

            
        }
            
	}
    return 0;
}
