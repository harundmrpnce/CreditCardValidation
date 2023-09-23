#include <iostream>

/* Luhn Algorithm
-------------------
1- Double every second digit from right to left, if doubled number is 2 digits, split them.
2- Add all single digits from step 1.
3- Add all odd numbered digits from right to left.
4- Sum results from steps 2&3.
5- If step 4 is divisible by 10, the credit card valid. 
*/ 

int step1_2(std::string creditCard);
int step3(std::string creditCard);
bool checkInt(std::string checked);
int* stringToArray(std::string creditCard);

int main() {
    std::string creditCard;

    do {
        std::cout << "Enter the credit card number(16 digit - no char): ";
        std::cin >> creditCard;
    } while(creditCard.length() != 16 || !checkInt(creditCard));
    
    if (!((step1_2(creditCard) + step3(creditCard)) % 10)) {
        std::cout << "VALID!";
    } else {
        std::cout << "NOT VALID!";
    }

    return 0;
}

int step1_2(std::string creditCard) {
    int* copiedCard = stringToArray(creditCard);
    int sum = 0;

    for (int i = 0; i < 15; i+=2) {
        copiedCard[i+1] = 0;
        copiedCard[i] *= 2;
        if(copiedCard[i] > 9) {
            copiedCard[i+1] = copiedCard[i] - 10;
            copiedCard[i] = 1;
        }
        sum += (copiedCard[i]+copiedCard[i+1]);
    }

    delete[] copiedCard;

    return sum;
}

int step3(std::string creditCard) {
    int* copiedCard = stringToArray(creditCard); 
    int sum = 0;

    for (int i = 1; i < 16; i += 2) {
        sum += copiedCard[i];
    }

    delete[] copiedCard;
    
    return sum;
}

bool checkInt(std::string checked) {
    for (char c : checked) {
        if(!std::isdigit(c)) {
            return false;
        }
    }
    
    return true;
}

int* stringToArray(std::string creditCard) {
    int* arr = new int[16];

    for (int i = 0; i < 16; i++) {
        arr[i] = creditCard[i] - '0';
    }

    return arr;
}



