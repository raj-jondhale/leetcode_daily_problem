/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    //iterate array from right to left
    for(int i = digitsSize-1; i >= 0; i--){
        if(digits[i] != 9){ //if last element is less than 9 then add 1 directly to last digit
            digits[i]++;
            break;
        }else{
            digits[i] = 0; //if last digit is 9 then make the last digit 0 by adding 1 and pass carry to further digits
        }
    }

    //if the first digit is 0
    if(digits[0] == 0){
            //increment size of result array by 1
        int size = digitsSize + 1;
        int* result = (int*) malloc(sizeof(int) * size);
        result[0] = 1;

        for(int i = 0; i < digitsSize; i++)
            result[i+1] = digits[i];

        *returnSize = size;
        return result; //return the increment array result e.g for 999 + 1 = 1000
    }else{
        *returnSize = digitsSize;
        return digits;
    }
}