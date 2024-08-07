class Solution {
public:
    string numberToWords(int num) {
        string belowTen[] = {"", "One", "Two", "Three", "Four",
                             "Five", "Six", "Seven", "Eight", "Nine"};
        string belowTwenty[] = {"Ten", "Eleven", "Twelve", "Thirteen",
                                "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                                "Eighteen", "Nineteen"};
        string belowHundred[] = {"", "Ten", "Twenty", "Thirty",
                                 "Forty", "Fifty", "Sixty", "Seventy",
                                 "Eighty", "Ninety"};
        if (num == 0) {
            return "Zero";
        } else if (num > 0 && num < 10) {
            return belowTen[num];
        } else if (num >= 10 && num < 20) {
            return belowTwenty[num - 10];
        } else if (num >= 20 && num < 100) {
            return belowHundred[num / 10] +
                   (num % 10 == 0 ? "" : " " + numberToWords(num % 10));
        } else if (num >= 100 && num < 1000) {
            return belowTen[num / 100] + " Hundred" +
                   (num % 100 == 0 ? "" : " " + numberToWords(num % 100));
        } else if (num >= 1000 && num < 1000000) {
            return numberToWords(num / 1000) + " Thousand" +
                   (num % 1000 == 0 ? "" : " " + numberToWords(num % 1000));
        } else if (num >= 1000000 && num < 1000000000) {
            return numberToWords(num / 1000000) + " Million" +
                   (num % 1000000 == 0 ? "" : " " + numberToWords(num % 1000000));
        }
        return numberToWords(num / 1000000000) + " Billion" +
               (num % 1000000000 == 0 ? "" : " " + numberToWords(num % 1000000000));
    }
};
