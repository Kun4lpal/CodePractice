string toHex(int num) {
        if (num == 0) return "0";
        string result;
        int count = 0;
        while (num && count++ < 8) {
            result = HEX[(num & 0xf)] + result;// essentially remainder
            num >>= 4;// ==? essentially num/16
        }
        return result;
}