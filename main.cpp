#include <iostream>
#include <stdio.h>
#include <wchar.h>

#define BUFFER_SIZE 50
using namespace std;

struct money {
    int hrn;
    short int kop;
};

int main() {
    money total = {0, 0}; 
     int kilkist = 2; 

    money items[kilkist] = {
        {19, 89},
        {13, 29}
    };

    int number[kilkist] = {3, 1}; 
    int total_kop = 0;

    for (int i = 0; i < kilkist; i++) {
        total_kop += (items[i].hrn * 100 + items[i].kop) * number[i];
    }

    total.hrn = total_kop / 100;
    total.kop = total_kop % 100;

    FILE* my_file;
    int error = fopen_s(&my_file, "D:/test.txt", "w+t"); 

    if (error != 0) {
        wprintf(L"Помилка відкриття файлу!\n");
        return 0; 
    }

    fprintf(my_file, "Загальна сума: %d грн %02d коп\n", total.hrn, total.kop);

    int rounded_kop = total.kop;  
    int rounded_hrn = total.hrn; 
    
    if (rounded_kop % 10 >= 5) {
       
        rounded_kop = (rounded_kop / 10) * 10 + 10;  
    } else {
 
        rounded_kop = (rounded_kop / 10) * 10;  
    }
 
    if (rounded_kop >= 100) {
  
        rounded_hrn += rounded_kop / 100;  
        rounded_kop = rounded_kop % 100;   
    }
    
    fprintf(my_file, "Сума до оплати: %d грн %02d коп\n", rounded_hrn, rounded_kop);
    fclose(my_file);

    cout << "Загальна сума: " << total.hrn << " грн " << total.kop << " коп" << endl;
    cout << "Сума до оплати: " << rounded_hrn << " грн " << rounded_kop << " коп" << endl;

    return 0;
} 