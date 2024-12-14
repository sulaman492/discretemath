#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
string convertDecimalToBinary(int number);
string convertOctalToHexadecimal(int number);
int convertBinaryToDecimal(int number);
string convertOctalToBinary(int number);
int printMenu();
int convertOctalToDecimal(int number);
string convertBinaryToOctal(int number);
string convertBinaryToHexadecimal(int number);
int convertBinaryToDecimal(int number);
string convertDecimalToHexadecimal(int number);
string convertDecimalToOctal(int number);
string encryption(string text,int type);
int convertHexadecimalToDecimal(string number);
string convertHexadecimalToBinary(string number);
string convertHexadecimalToOctal(string number);
int lengthOfString(string strEncryption);
int printMenuConversion();
int printMenuEncryptionDecryption();
string stringValidation(string strEncryption,int length);

int stringtoINT(string str, int length, int base);

string decryption(string encryptedMessage, int base);
int calculatePower(int base, int exponent);
void gotoxy(int , int);
main()
{
    system("cls");
    int number;
    int choice;
    string n;
    int type=printMenu();
    Sleep(150);
    system("cls");
    if(type==1)
    {
        int option=printMenuConversion();
        system("cls");
        cout<<"Enter your number : ";                                                                                                                                                                                                                                                                                                                      
        if(option==1)                                                                                                                                                                   
        {                 
            cin>>number;                                                                                                                                                            
            cout<<"Binary           :  "<<convertDecimalToBinary(number)<<endl;             
            cout<<"Octal            :  "<<convertDecimalToOctal(number)<<endl;
            cout<<"Hexadecimal      :  "<<convertDecimalToHexadecimal(number)<<endl;                                                                                                                            
        }                                                                       
        if(option==2)
        {
            cin>>number;
            cout<<"Decimal          :  "<<convertBinaryToDecimal(number)<<endl;             
            cout<<"Octal            :  "<<convertBinaryToOctal(number)<<endl;
            cout<<"Hexadecimal      :  "<<convertBinaryToHexadecimal(number)<<endl;                  
        }                                              
        if(option==4)
        {
            cin>>number;
            cout<<"Decimal           :  "<<convertOctalToDecimal(number)<<endl;             
            cout<<"Binary            :  "<<convertOctalToBinary(number)<<endl;
            cout<<"Hexadecimal       :  "<<convertOctalToHexadecimal(number)<<endl;                  
        }   
        if(option==3)
        {
            cin>>n;
            cout<<"Decimal           :  "<<convertHexadecimalToDecimal(n)<<endl;             
            cout<<"Binary            :  "<<convertHexadecimalToBinary(n)<<endl;
            cout<<"Hexadecimal       :  "<<convertHexadecimalToOctal(n)<<endl;                  
        } 
    }           
    if(type==2)
    {
        int base;
        string strbase;
        string encryptionValue;
        string strforEncryption;
        int strLength;        
        int option=printMenuEncryptionDecryption();
        if(option==1)
        {
            string result="false";
            cout<<"Enter the message you want to encrypt : ";
            cin.ignore();
            getline(cin,strforEncryption);
            strLength = lengthOfString(strforEncryption);
            encryptionValue = stringValidation(strforEncryption, strLength);
            string encrypted[strLength]; 
            if (encryptionValue=="true")
            {
                cout << "Enter the base (Binary/Hexadecimal/Octal) in which text is to be encrypted: ";
                cin >> strbase;
                int ascii;
                //convertToASCII(strforEncryption, strLength, ascii); // converting alphabets to ascii representation
                if (strbase == "Binary" || strbase == "binary")
                {
                    result="true";
                    int ascii[strLength];
                    for(int i=0;i<strLength;i++)
                    {
                        ascii[i]=strforEncryption[i];
                    } 
                    for (int i = 0; i < strLength; i++)
                    {
                        encrypted[i] = convertDecimalToBinary(ascii[i]); // now converting that ascii represention into required base
                    }
                }
                if (strbase == "octal" || strbase == "Octal")
                {
                    result="true";
                    int ascii[strLength];
                    for(int i=0;i<strLength;i++)
                    {
                        ascii[i]=strforEncryption[i];
                    }
                    for (int i = 0; i < strLength; i++)
                    {
                        encrypted[i] = convertDecimalToOctal(ascii[i]); // now converting that ascii represention into required base
                    }
                }
                if (strbase == "Hexadecimal" || strbase == "hexadecimal")
                {
                    result="true";
                    int ascii[strLength];
                    for(int i=0;i<strLength;i++)
                    {
                        ascii[i]=strforEncryption[i];
                    }
                    for (int i = 0; i < strLength; i++)
                    {
                        encrypted[i] = convertDecimalToHexadecimal(ascii[i]); // now converting that ascii represention into required base
                    }
                }
                if (result=="true") // giving output only when base is valid
                {
                    cout << strforEncryption << " encrypted in base " << base << " is: "<<endl;
                    for (int i = 0; i < strLength; i++)
                    {
                        cout << encrypted[i] << " ";
                    }
                }
                else
                {
                    cout << "Invalid base";
                }
            }
            else
            {
                cout << "Invalid message entered. Message cannot contain a number";
            }
        }      
        if (option == 2) // decryption
        {
            cout << "Enter encrypted message(separated numbers with spaces):" << endl;
            cin.ignore();
            getline(cin, strforEncryption);
            if (strforEncryption.empty()) // if message is empty
            {
                cout << "Encrypted message cannot be empty!" << endl;
            }
            cout << "Enter base of encrypted message(Binary/Hexadecimal/Octal):" << endl;
            cin >> strbase;
            if (strbase == "Binary" || strbase == "binary")
            {
                base=2;
            }
            else if (strbase == "octal" || strbase == "Octal")
            {
                base = 8;
            }
            else if (strbase == "Hexadecimal" || strbase == "hexadecimal")
            {
                base = 16;
            }
            else
            {
                cout << "Invalid base entered. Please enter Binary, Decimal, Octal, or Hexadecimal." << endl;
            }
            if (base == 2 || base == 8 || base == 16)
            {
                string decrypted = decryption(strforEncryption, base); // decrypting message
                cout << "Decrypted Message: " << decrypted << endl; 
            }
        }   
    }       
    if (type == 3)
    {
        return 0;
    }
    if(type!=1 && type!=2 && type!=3)
    {
        cout << "Invalid option .Select 1/2/3";
    }                       
}         
int printMenu()
{
    int type;
    cout<<"                                       MENU                                     "<<endl;
    cout<<"________________________________________________________________________________"<<endl;
    cout<<"Do you want "<<endl;
    cout<<"1.conversion "<<endl;
    cout<<"2.encryption/decryption "<<endl;
    cout<<"3.exit"<<endl;
    cin>>type;
    return type;
}
int printMenuConversion()
{
    int option;
    cout<<"                                       MENU                                     "<<endl;
    cout<<"________________________________________________________________________________"<<endl;
    cout<<"1.DECIMAL"<<endl;
    cout<<"2.BINARY"<<endl;
    cout<<"3.HEXADECIMAL"<<endl;
    cout<<"4.OCTAL"<<endl;
    cout<<"Choose one of the above as input number system : "<<endl;
    cin>>option;   
    return option; 

}
int printMenuEncryptionDecryption()
{
    int option;
    cout<<"                                       MENU                                     "<<endl;
    cout<<"________________________________________________________________________________"<<endl;
    cout<<"1.you want to encrypt a message"<<endl;
    cout<<"2.you want to decrypt a message"<<endl;
    cout<<"Choose one of the following"<<endl;
    cin>>option;
    return option;
}
string convertDecimalToBinary(int number) {
    string n = to_string(number); 
    int i = 0;
    while (n[i] != '\0') {
        if (!(n[i]=='0'||n[i]=='1'||n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9')) {
            gotoxy(0, 1);
            cout << "                                         " << endl; 
            cout << "Invalid input" << endl;
            abort(); 
        }
        i++;
    }
    
    string binary = "";
    while (number > 0) {
        binary = to_string(number % 2) + binary;
        number = number / 2;
    }
    
    return binary;
}
string convertDecimalToHexadecimal(int number) {
    string n = to_string(number);
    int i = 0;
    while (n[i] != '\0') {
        if (n[i] < '0' || n[i] > '9') {
            gotoxy(0, 1);
            cout << "                                         " << endl;
            cout << "Invalid input";
            abort();
        }
        i++;
    }

    string hexadecimal = "";
    string hexNum;
    while (number > 0) {
        int remainder = number % 16;
        if (remainder == 10) {
            hexNum = "A";
        } else if (remainder == 11) {
            hexNum = "B";
        } else if (remainder == 12) {
            hexNum = "C";
        } else if (remainder == 13) {
            hexNum = "D";
        } else if (remainder == 14) {
            hexNum = "E";
        } else if (remainder == 15) {
            hexNum = "F";
        } else {
            hexNum = to_string(remainder);
        }
        hexadecimal = hexNum + hexadecimal;
        number = number / 16;
    }
    return hexadecimal;
}

string convertDecimalToOctal(int number) {
    string n = to_string(number);
    int i = 0;
    while (n[i] != '\0') {
        if (n[i] < '0' || n[i] > '9') {
            gotoxy(0, 1);
            cout << "                                         " << endl;
            cout << "Invalid input";
            abort();
        }
        i++;
    }

    string octal = "";
    while (number > 0) {
        octal = to_string(number % 8) + octal;
        number = number / 8;
    }
    return octal;
}

int convertBinaryToDecimal(int number) {
    string n = to_string(number);
    int i = 0;
    while (n[i] != '\0') {
        if (n[i] != '0' && n[i] != '1') {
            gotoxy(0, 1);
            cout << "                                         " << endl;
            cout << "Invalid input";
            abort();
        }
        i++;
    }

    int power = 0, sum = 0;
    while (number > 0) {
        sum = ((number % 10) * calculatePower(2, power)) + sum;
        number = number / 10;
        power++;
    }
    return sum;
}

string convertBinaryToHexadecimal(int number) {
    string n = to_string(number);
    int i = 0;
    while (n[i] != '\0') {
        if (n[i] != '0' && n[i] != '1') {
            gotoxy(0, 1);
            cout << "                                         " << endl;
            cout << "Invalid input";
            abort();
        }
        i++;
    }

    int power = 0, sum = 0;
    while (number > 0) {
        sum = ((number % 10) * calculatePower(2, power)) + sum;
        number = number / 10;
        power++;
    }

    string hexadecimal = "";
    string hexNum;
    while (sum > 0) {
        int remainder = sum % 16;
        if (remainder == 10) {
            hexNum = "A";
        } else if (remainder == 11) {
            hexNum = "B";
        } else if (remainder == 12) {
            hexNum = "C";
        } else if (remainder == 13) {
            hexNum = "D";
        } else if (remainder == 14) {
            hexNum = "E";
        } else if (remainder == 15) {
            hexNum = "F";
        } else {
            hexNum = to_string(remainder);
        }
        hexadecimal = hexNum + hexadecimal;
        sum = sum / 16;
    }
    return hexadecimal;
}

string convertBinaryToOctal(int number) {
    string n = to_string(number);
    int i = 0;
    while (n[i] != '\0')
    {
        if (n[i] != '0' && n[i] != '1') {
            gotoxy(0, 1);
            cout << "                                         " << endl;
            cout << "Invalid input";
            abort();
        }
        i++;
    }
    int power = 0, sum = 0;
    while (number > 0) {
        sum = ((number % 10) * calculatePower(2, power)) + sum;
        number = number / 10;
        power++;
    }

    string octal = "";
    while (sum > 0) {
        octal = to_string(sum % 8) + octal;
        sum = sum / 8;
    }
    return octal;
}

int convertOctalToDecimal(int number) {
    string n = to_string(number);
    int i = 0;
    while (n[i] != '\0') {
        if (n[i] < '0' || n[i] > '7') {
            gotoxy(0, 1);
            cout << "                                         " << endl;
            cout << "Invalid input";
            abort();
        }
        i++;
    }

    int power = 0, sum = 0;
    while (number > 0) {
        sum = ((number % 10) * calculatePower(8, power)) + sum;
        number = number / 10;
        power++;
    }
    return sum;
}

string convertOctalToBinary(int number) {
    string n = to_string(number);
    int i = 0;
    while (n[i] != '\0') {
        if (n[i] < '0' || n[i] > '7') {
            gotoxy(0, 1);
            cout << "                                         " << endl;
            cout << "Invalid input";
            abort();
        }
        i++;
    }

    string binary = "";
    while (number > 0) {
        binary = to_string(number % 8) + binary;
        number = number / 2;
    }
    return binary;
}

string convertOctalToHexadecimal(int number) {
    string n = to_string(number);
    int i = 0;
    while (n[i] != '\0') {
        if (n[i] < '0' || n[i] > '7') {
            gotoxy(0, 1);
            cout << "                                         " << endl;
            cout << "Invalid input";
            abort();
        }
        i++;
    }

    int power = 0, sum = 0;
    while (number > 0) {
        sum = ((number % 10) * calculatePower(8, power)) + sum;
        number = number / 10;
        power++;
    }

    string hexadecimal = "";
    string hexNum;
    while (sum > 0) {
        int remainder = sum % 16;
        if (remainder == 10) {
            hexNum = "A";
        } else if (remainder == 11) {
            hexNum = "B";
        } else if (remainder == 12) {
            hexNum = "C";
        } else if (remainder == 13) {
            hexNum = "D";
        } else if (remainder == 14) {
            hexNum = "E";
        } else if (remainder == 15) {
            hexNum = "F";
        } else {
            hexNum = to_string(remainder);
        }
        hexadecimal = hexNum + hexadecimal;
        sum = sum / 16;
    }
    return hexadecimal;
}

int convertHexadecimalToDecimal(string number) {
    for (int i = 0; i < number.length(); i++) {
        if ((number[i] < '0' || number[i] > '9') && (number[i] < 'A' || number[i] > 'F')) {
            gotoxy(0, 1);
            cout << "                                         " << endl;
            cout << "Invalid input";
            abort();
        }
    }
    int length = number.length();
    int value[length];
    int decimal = 0, power = 0;
    for (int i = 0; i < length; i++) {
        if (number[i] >= '0' && number[i] <= '9') {
            value[i] = number[i] - '0';
        }
        if (number[i] == 'A') {
            value[i] = 10;
        }
        if (number[i] == 'B') {
            value[i] = 11;
        }
        if (number[i] == 'C') {
            value[i] = 12;
        }
        if (number[i] == 'D') {
            value[i] = 13;
        }
        if (number[i] == 'E') {
            value[i] = 14;
        }
        if (number[i] == 'F') {
            value[i] = 15;
        }
    }
    for (int i = length - 1; i >= 0; i--) {
        decimal += value[i] * calculatePower(16, power);
        power++;
    }
    return decimal;
}

string convertHexadecimalToBinary(string number)
{
    int length = 0;
    while (number[length] != '\0') {
        length++;
    }
    int value[length];
    int decimal = 0, power = 0;
    for (int i = 0; i < length; i++) {
        if (number[i] == '0') value[i] = 0;
        else if (number[i] == '1') 
        {
            value[i] = 1;
        }
        else if (number[i] == '2') 
        {
            value[i] = 2;
        }    
        else if (number[i] == '3') 
        {
            value[i] = 3;
        }
        else if (number[i] == '4') 
        {
            value[i] = 4;
        }    
        else if (number[i] == '5')
        {
            value[i] = 5;
        } 
        else if (number[i] == '6') 
        {
            value[i] = 6;
        }    
        else if (number[i] == '7')
        {
             value[i] = 7;
        }     
        else if (number[i] == '8')
        { 
            value[i] = 8;
        }    
        else if (number[i] == '9')
        { 
            value[i] = 9;
        }
        else if (number[i] == 'A')
        {
             value[i] = 10;
        }     
        else if (number[i] == 'B')
        { 
            value[i] = 11;
        }    
        else if (number[i] == 'C')
        { 
            value[i] = 12;
        }
        else if (number[i] == 'D') 
        {
            value[i] = 13;
        }
        else if (number[i] == 'E')
        { 
            value[i] = 14;
        }
        else if (number[i] == 'F') 
        {
            value[i] = 15;
        }
        else {
          return "Invalid hexadecimal digit entered.";
        }
    }
    for (int i = length - 1; i >= 0; i--) {
        decimal += value[i] * calculatePower(16, power);
        power++;
    }
    if (decimal == 0) 
    {
        return "0";
    }
    string binary=" ";
    while(decimal>0)
    {
        binary=to_string(decimal%2)+binary;
        decimal=decimal/2;
    }
    return binary;

}
string convertHexadecimalToOctal(string number) {
    int length = 0;
    while (number[length] != '\0') {
        length++;
    }
    int value[length];
    int decimal = 0, power = 0;
    for (int i = 0; i < length; i++) {
        if (number[i] == '0') value[i] = 0;
        else if (number[i] == '1') 
        {
            value[i] = 1;
        }
        else if (number[i] == '2') 
        {
            value[i] = 2;
        }    
        else if (number[i] == '3') 
        {
            value[i] = 3;
        }
        else if (number[i] == '4') 
        {
            value[i] = 4;
        }    
        else if (number[i] == '5')
        {
            value[i] = 5;
        } 
        else if (number[i] == '6') 
        {
            value[i] = 6;
        }    
        else if (number[i] == '7')
        {
             value[i] = 7;
        }     
        else if (number[i] == '8')
        { 
            value[i] = 8;
        }    
        else if (number[i] == '9')
        { 
            value[i] = 9;
        }
        else if (number[i] == 'A')
        {
             value[i] = 10;
        }     
        else if (number[i] == 'B')
        { 
            value[i] = 11;
        }    
        else if (number[i] == 'C')
        { 
            value[i] = 12;
        }
        else if (number[i] == 'D') 
        {
            value[i] = 13;
        }
        else if (number[i] == 'E')
        { 
            value[i] = 14;
        }
        else if (number[i] == 'F') 
        {
            value[i] = 15;
        }
        else {
          return "Invalid hexadecimal digit entered.";
        }
    }
    for (int i = length - 1; i >= 0; i--) {
        decimal += value[i] * calculatePower(16, power);
        power++;
    }
    if (decimal == 0) 
    {
        return "0";
    }
    string octal = "";
    while (decimal > 0)
    {
        octal = to_string(decimal % 8) + octal;
        decimal =decimal/8;
    }
    return octal;
}
int lengthOfString(string strEncryption)
{
    int length=0;
    while(strEncryption[length]!='\0')
    {
        length++;
    }
    return length;
}
string stringValidation(string strEncryption,int length)
{
    int l;
    while(strEncryption[l]!='\0')
    {
        l++;
    }
    if(l==length)
    {
        return "true";
    }
    else
        return "false";
}
string decryption(string encryptedMessage, int base) {
    string decrypted = "";
    string tempSTR = "";
    int ascii = 0;
    int number = 0;

    for (char ch : encryptedMessage) {
        if (ch == ' ') { 
            if (!tempSTR.empty()) {
                if (base == 2) {
                    int length=tempSTR.size();
                    number = stringtoINT(tempSTR, length, 2); 
                    if (number == -1) {
                        cout << "Invalid binary number: " << tempSTR << endl;
                        return ""; 
                    }
                    ascii = convertBinaryToDecimal(number);
                } else if (base == 8) {
                    int length=tempSTR.size();
                    number = stringtoINT(tempSTR, length, 8); 
                    if (number == -1) {
                        cout << "Invalid octal number: " << tempSTR << endl;
                        return "";
                    }
                    ascii = convertOctalToDecimal(number);
                } else if (base == 16) {
                    ascii = convertHexadecimalToDecimal(tempSTR); 
                    if (ascii == -1) {
                        cout << "Invalid hexadecimal number: " << tempSTR << endl;
                        return ""; 
                    }
                }
                if (ascii < 0 || ascii > 255) {
                    cout << "Invalid ASCII value: " << ascii << endl;
                    return ""; 
                }
                decrypted += char(ascii);
                tempSTR = "";
            }
        } else {
            tempSTR += ch;
        }
    }
    if (!tempSTR.empty()) {
        if (base == 2) {
            number = stringtoINT(tempSTR, tempSTR.size(), 2);
            if (number == -1) {
                cout << "Invalid binary number: " << tempSTR << endl;
                return "";
            }
            ascii = convertBinaryToDecimal(number);
        } else if (base == 8) {
            number = stringtoINT(tempSTR, tempSTR.size(), 8);
            if (number == -1) {
                cout << "Invalid octal number: " << tempSTR << endl;
                return ""; 
            }
            ascii = convertOctalToDecimal(number);
        } else if (base == 16) {
            ascii = convertHexadecimalToDecimal(tempSTR);
            if (ascii == -1) {
                cout << "Invalid hexadecimal number: " << tempSTR << endl;
                return ""; 
            }
        }
        if (ascii < 0 || ascii > 255) {
            cout << "Invalid ASCII value: " << ascii << endl;
            return ""; 
        }
        decrypted += char(ascii);
    }

    return decrypted;
}


int stringtoINT(string str, int length, int base)
 {
    if (length == 0) return -1; 
    int result = 0;
    for (int i = 0; i < length; i++) {
        if (base == 16 && (isxdigit(str[i]))) {
            result = result * base + (isdigit(str[i]) ? (str[i] - '0') : (tolower(str[i]) - 'a' + 10));
        }
        else if (base != 16 && str[i] >= '0' && str[i] <= '9') {
            result = result * base + (str[i] - '0');
        } else {
            return -1; 
        }
    }
    return result;
}
    
int calculatePower(int base, int exponent)
{
    int result = 1; 
    if (exponent < 0) {
        cout << "Negative exponents are not supported in this implementation.\n";
        return -1; 
    }

    for (int i = 0; i < exponent; i++) {
        result *= base; // Multiply result by the base
    }
    return result;
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}