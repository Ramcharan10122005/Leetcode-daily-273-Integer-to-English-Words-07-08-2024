const char* belowTen[] = {"",     "One", "Two",   "Three", "Four",
                          "Five", "Six", "Seven", "Eight", "Nine"};
const char* belowTwenty[] = {"Ten",      "Eleven",  "Twelve",  "Thirteen",
                             "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                             "Eighteen", "Nineteen"};
const char* belowHundred[] = {"",      "Ten",   "Twenty",  "Thirty", "Forty",
                              "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

void numberToWordsHelper(int num, char* result) {
    if (num == 0) {
        strcpy(result, "Zero");
        return;
    } else if (num < 10) {
        strcat(result, belowTen[num]);
    } else if (num < 20) {
        strcat(result, belowTwenty[num - 10]);
    } else if (num < 100) {
        strcat(result, belowHundred[num / 10]);
        if (num % 10 != 0) {
            strcat(result, " ");
            numberToWordsHelper(num % 10, result);
        }
    } else if (num < 1000) {
        strcat(result, belowTen[num / 100]);
        strcat(result, " Hundred");
        if (num % 100 != 0) {
            strcat(result, " ");
            numberToWordsHelper(num % 100, result);
        }
    } else if (num < 1000000) {
        numberToWordsHelper(num / 1000, result);
        strcat(result, " Thousand");
        if (num % 1000 != 0) {
            strcat(result, " ");
            numberToWordsHelper(num % 1000, result);
        }
    } else if (num < 1000000000) {
        numberToWordsHelper(num / 1000000, result);
        strcat(result, " Million");
        if (num % 1000000 != 0) {
            strcat(result, " ");
            numberToWordsHelper(num % 1000000, result);
        }
    } else {
        numberToWordsHelper(num / 1000000000, result);
        strcat(result, " Billion");
        if (num % 1000000000 != 0) {
            strcat(result, " ");
            numberToWordsHelper(num % 1000000000, result);
        }
    }
}

char* numberToWords(int num) {
    char* result = (char*)malloc(1000 * sizeof(char));
    result[0] = '\0';
    numberToWordsHelper(num, result);
    return result;
}
