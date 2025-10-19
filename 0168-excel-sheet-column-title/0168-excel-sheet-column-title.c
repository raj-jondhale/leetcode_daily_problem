char* convertToTitle(int columnNumber) {
       static char result[10];  // enough for 32-bit integer range (Excel columns)
    int i = 0;

    while (columnNumber > 0) {
        columnNumber--;  // Adjust because Excel is 1-indexed
        int remainder = columnNumber % 26;
        result[i++] = 'A' + remainder;
        columnNumber /= 26;
    }

    result[i] = '\0';

    // Reverse the string because we built it backwards
    for (int j = 0; j < i / 2; j++) {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }

    return result;
}