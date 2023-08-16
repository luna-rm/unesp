/* 
    feito por: Pedro Ricieri Marchi
    compilador: MinGW - compilado em um vscode 
    sistema operacional: Windows 11
*/

#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#define MAX 4444
#define ENTER 13
#define ESC 27
#define UP 72
#define DOWN 80

using namespace std;

void rand_sleep(int min, int max) {
    int aux = (rand()%(max-min))+min;
    Sleep(aux);
}

void cursor(int aux) {
    CONSOLE_CURSOR_INFO cursor = {1, aux};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void bold(int status) {
    static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
    printf("%s", seq[!!status]);
}

void italic(int status) {
    static const char *seq[] = {"\x1b[0m", "\x1b[3m"};
    printf("%s", seq[!!status]);
}

void printf_text(string text, int anim) { 
    int aux = text.size();
	float time = 25;
 
    if(anim) {
        cursor(1);
        int len_word = 0;
        int c_at = 0;

        for(int j = 0; j < aux; j++){
            len_word++;
            if(text[j] == ' ') {
                break;
            }
        }

        for(int i = 0; i < aux; i++){	
            cout << text[i];
            c_at++;

            if(text[i] == ' ') {
                len_word = 0;
                c_at = 0;
                for(int j = i+1; j < aux; j++){
                    len_word++;
                    if(text[j] == ' ') {
                        break;
                    }
                }
                time = 25;
            }
            
            if(i != 4){
                if (text[i] == '\n'){
                    rand_sleep(500, 750);
                } else if(i > (int) (aux*0.2)){
                    if(text[i] == ' '){
                        rand_sleep(250, 500);
                    } else {
                        if(c_at <= len_word/2){
                            time *= (6./len_word + 1);
                        } else {
                            time /= (6./len_word + 1);
                        }

                        rand_sleep((int) (time), (int) (time*1.25));
                    }
                }		
            }
        }
    } else {
        cursor(0);
        for(int i = 0; i < aux; i++){	
            cout << text[i];
            
            if (text[i] == '\n'){
                rand_sleep(50, 100);
            }
        }
    }
}

void end(){
    system("cls");
    
    italic(0);

    if(rand()%5 != 4){
        printf_text("obrigada por usar o programa! <3\n\nfeito por: Pedro Ricieri Marchi - 231024801\n", 1);
    } else {
        printf_text("obrigada por usar o programa! <3\n\nfeito por: Luna Ricieri Marchi - 231024801\n", 1);
        rand_sleep(1000, 1500);
        system("cls");
        printf_text("obrigada por usar o programa! <3\n\nfeito por: Pedro Ricieri Marchi - 231024801\n(emote suspeito)\n", 0);
    }

    italic(1);
    printf_text("\n____________________________________$$$$\n__________________________________$$____$\n_________________________________$_______$\n___$$$$_________________________$_________$\n__$____$$______________________$____$_____$\n_$_______$$___________________$____$$$____$\n_$_________$$_____$$$$_$$$___$____$$$$$___$\n$____________$_$$$__$$$__$$_$____$$$$$$___$\n$____$$_______$_$$__$$$__$$$____$$$$$$$___$\n$___$$$$_______$$$$_$$$___$$_____$$$$$$___$\n$___$$$$$$_____$$$$_$$$$__$$$______$$$$$__$\n$___$$$$$$$____$$$$_$$$$__$$$________$$$__$\n$___$$$$$______$$$$_$$$$__$$$$____________$\n$___$$$$_______$$$$_$$$$__$$$$____________$\n$___$$$________$$$$_$$$$__$$$$____________$\n$___$$_________$$$$__$$$__$$$$____________$\n$______________$$$___$$$___$$$____________$\n$_______________$_____$_____$_____________$\n_$_________________________________________$\n$________________________________$$$$_______$\n$_______________________________$__$$$______$\n$__________$$$$________________$$__$$$$_____$\n$_________$$$__$_______________$$$$$$$$_____$\n$________$$$$__$_______________$$$$$$$$_____$\n$________$$$$$$$$______________$$$$$$$$_____$\n$________$$$$$$$$_______________$$$$$$______$\n$________$$$$$$$$_______$___$____$$$$_______$\n$_________$$$$$$_____$__$$_$________________$\n$__________$$$$_______$$__$________________$\n_$_____________________$__$_______________$\n__$_____________________$$_______________$\n___$______________________________$$$___$\n____$$___________________________$___$_$\n______$$$_______________________$_____$\n_________$$$$_____________$$$$$$______$\n___$$________$$$$$$$$$$$$$____________$\n__$__$________$___$_________________$$\n__$___$_______$____$_____________$$$\n__$___$________$____$___________$$\n__$$$$$$_______$____$__________$__$\n___$___$$_______$___$_________$____$\n___$$$$$$$___$$$_$$$_________$_____$\n____$___$$$$$__$_____$_______$_____$\n_____$__$______$_____$_______$_____$\n______$$$$$$$$$$_____$_______$____$\n________________$$$$$_________$$$$\n", 0);
    italic(0);

    exit(0);
}

void press_any(){
    italic(1);
    cout << "\n\n\naperte qualquer <ESC> para sair ou qualquer tecla para voltar...";
    if(getch() == ESC){
        end();
    }
    system("cls");    
    italic(0);
}

void printf_num(string num, string base, int anim) { 
    num = num + " | " + base; 
    italic(1);
    printf_text(num, anim);
    italic(0);
}

int read_input(){

    int aux = getch();

    if(aux <= 0 || aux == 224){
        aux = getch();

        if(aux == UP){
            return 1;
        }

        if(aux == DOWN){
            return 2;
        }
    }

    if(aux == ENTER){
        return 3;
    }

    return -1;
}

void printf_header(int only_line, int anim){
    bold(1);
    if(!only_line){
        printf_text("    conversor de bases", anim);
    } 
    printf_text("\n--------------------------\n\n", anim);
    bold(0);
}

string choice(string num, string base){
    int how_many = 0;
    int position = 0;
    string opt[4];
    if(base != "2"){
        int can_be = 1;
        if(base == "0"){
            for(unsigned int i = 0; i < num.size(); i++){
                if(num[i] < '0' || num[i] > '1'){
                    can_be = 0;
                }
            }
        }
        if(can_be){
            opt[how_many] = "2 - binario";
            how_many++;
        }
    }
    if(base != "8"){
        int can_be = 1;
        if(base == "0"){
            for(unsigned int i = 0; i < num.size(); i++){
                if(num[i] < '0' || num[i] > '7'){
                    can_be = 0;
                }
            }
        }
        if(can_be){
            opt[how_many] = "8 - octal";
            how_many++;
        }
    }
    if(base != "10"){
        int can_be = 1;
        if(base == "0"){
            for(unsigned int i = 0; i < num.size(); i++){
                if(num[i] < '0' || num[i] > '9'){
                    can_be = 0;
                }
            }
        }
        if(can_be){
            opt[how_many] = "10 - decimal";
            how_many++;
        }
    }
    if(base != "16"){
        int can_be = 1;
        if(base == "0"){
            for(unsigned int i = 0; i < num.size(); i++){
                if(num[i] < '0' || num[i] > '9'){
                    if((num[i] < 'A' || num[i] > 'F') && (num[i] < 'a' || num[i] > 'f')){
                        can_be = 0;
                    }
                }
            }
        }
        if(can_be){
            opt[how_many] = "16 - hexadecimal";
            how_many++;
        }
    }

    if(how_many == 0){
        printf_text("numero invalido", 1);
        press_any();
        return "0";
    }

    while(1) {
        system("cls");

        rand_sleep(100, 200);

        printf_header(0, 0);

        if(base == "0"){
            printf_text("qual a ", 0);
                
            italic(1);
            printf_text("base", 0);
            italic(0);

            printf_text(" do numero ", 0);
            
            italic(1);
            printf_text(num, 1);
            italic(0);

            printf_text("? ", 1);
        } else {
            printf_text("para qual ", 0);
                
            italic(1);
            printf_text("base", 0);
            italic(0);

            printf_text(" o numero ", 0);

            printf_num(num, base, 1);

            printf_text(" sera convertido", 0);
            
            printf_text("? ", 1);
        }
        
        for(int i = 0; i < 4; i++){
            cout << endl;
            if(position == i){
                printf("  > ");
            } else {
                printf("    ");
            }
            printf_text(opt[i], 0);
            rand_sleep(100, 200);
        }

        int aux_input = 0;
        while(aux_input < 1 || aux_input > 3){
            aux_input = read_input();
        }

        if(aux_input == 3){
            string ansr = opt[position];
            string ret = "";
            ret = ret + ansr[0];

            if(ansr[0] == '1'){
                ret = ret + ansr[1];
            }
            
            return ret;
        }

        if(aux_input == 1){
            position--;
            if(position < 0){
                position = how_many-1;
            }
        } else if(aux_input == 2) {
            position++;
            if(position > how_many-1){
                position = 0;
            }
        }
    }
}

string x_to_bin(string num, string base) {
    string res = "";
    if(base == "2"){
        res = res + num;
    } else if (base == "8") {
        for(unsigned int i = 0; i < num.size(); i++){
            int digit = num[i] - '0';
            string bin_digit = "000";
            for(int aux = 2; aux >= 0; aux--){
                if(digit - (int)(pow(2., aux)) >= 0){
                    digit -= (int)(pow(2., aux));
                    bin_digit[2-aux] = '1';
                }
            }
            res = res + bin_digit;
        }
    } else if (base == "10") {
        int dec_num = 0;

        for(unsigned int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0';
            double digit_pos = pow(10.0, (double)(num.size() - 1 - i));
            dec_num += digit * (int) digit_pos;
        }

        while(dec_num != 0) {
            res = "X" + res;
            res[0] = dec_num%2 + '0';
            dec_num = dec_num/2;
        }
    } else if (base == "16") {
        for(unsigned int i = 0; i < num.size(); i++){
            int digit;
            if(num[i] >= '0' && num[i] <= '9'){
                digit = num[i] - '0';
            } else if(num[i] >= 'A' && num[i] <= 'F'){
                digit = num[i] - 'A' + 10;
            } else {
                digit = num[i] - 'a' + 10;
            }

            string bin_digit = "0000";
            for(int aux = 3; aux >= 0; aux--){
                if(digit - (int)(pow(2., aux)) >= 0){
                    digit -= (int)(pow(2., aux));
                    bin_digit[3-aux] = '1';
                }
            }
            res = res + bin_digit;
        }
    }

    return res;
}

string bin_to_x(string num, string base) {
    string res = "";
    if(base == "2"){
        res = res + num;
    } else if (base == "8") {
        while(num.size()%3 != 0){
            num = "0" + num;
        }
        for(unsigned int i = 0; i < num.size(); i+=3){
            int digit = 0;
            for(int j = 0; j < 3; j++){
                if(num[i+j] == '1'){
                    digit += (int) pow(2.0, 2.0 - j);
                }
            }
            
            res = res + to_string(digit);
        }
    } else if (base == "10") {
        int digit = 0;

        for(unsigned int i = 0; i < num.size(); i++) {
            if(num[i] == '1'){
                digit += pow(2.0, (double)(num.size() - 1 - i));
            }
        }

        res = to_string(digit);
    } else if (base == "16") {
        while(num.size()%4 != 0){
            num = "0" + num;
        }
        for(unsigned int i = 0; i < num.size(); i+=4){
            int digit = 0;
            for(int j = 0; j < 4; j++){
                if(num[i+j] == '1'){
                    digit += (int) pow(2.0, 3.0 - j);
                }
            }

            switch(digit) {
                case 10:
                    res = res + "a";
                    break;

                case 11:
                    res = res + "b";
                    break;
                
                case 12:
                    res = res + "c";
                    break;
                
                case 13:
                    res = res + "d";
                    break;
                
                case 14:
                    res = res + "e";
                    break;
                
                case 15:
                    res = res + "f";
                    break;
                
                default:
                    res = res + to_string(digit);
                    break;
            }
        }
    }

    string final_res = "";
    int start = 0;
    for(unsigned int i = 0; i < res.size(); i++){
        if(res[i] != '0' || start){
            final_res = final_res + res[i];
            start = 1;
        }
    }

    if(final_res == ""){
        final_res = "0";
    }

    return final_res;
}

int main() {
    system("cls");
    
    while(1){
        system("cls");
        
        string num;
        string base = "0";

        while(base == "0"){
            italic(1);
            printf_header(0, 1);
            printf_text("insira um numero: ", 1);
            italic(0);

            cin >> num;

            system("cls");
            rand_sleep(200, 300);

            base = choice(num, base);

            system("cls");
            rand_sleep(200, 300);
        }
        
        string to_base = choice(num, base);

        system("cls");
        rand_sleep(200, 300);

        string num_aux = x_to_bin(num, base);
        string num_final = bin_to_x(num_aux, to_base);

        printf_header(0, 1);

        italic(1);
        printf_num(num, base, 1);
        italic(0);

        rand_sleep(500, 800);

        cout << " ";
        for(int i = 0; i < 5; i++){
            cout << ">";
            rand_sleep(300, 500);
        }
        cout << " ";

        rand_sleep(500, 800);

        italic(1);
        printf_num(num_final, to_base, 1);
        italic(0);

        press_any();
    }
    
    return 0;
}