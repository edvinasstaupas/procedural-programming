unsigned char hexToChar (int digit, char type) {
    unsigned char htc;
    if(digit >= 0 && digit < 16){
        if(digit > 9) {
            digit -= 10;
            if(type > 0) {
                htc = 65 + digit;
            } else {
                htc = 97 + digit;
            }
        }
        else {
            htc = digit + '0';
        }
    } else {
        htc = 48;
    }
    return htc;
}