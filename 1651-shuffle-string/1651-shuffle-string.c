char* restoreString(char* s, int* indices, int indicesSize) {
    char* result = (char*) malloc((indicesSize + 1) * sizeof(char)); //solution string

    for(int i = 0; i < indicesSize; i++){
        result[indices[i]] = s[i]; // change position of char as per the indices
    }
    result[indicesSize] = '\0';
    return result;
}