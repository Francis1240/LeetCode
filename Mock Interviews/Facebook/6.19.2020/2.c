int read4(char *buf);


/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */
int _read(char* buf, int n) {
    int whole = n/4;
    int rem = n - 4 * whole;
    
    int index = 0;
    for(int i = 0; i < whole+1; i++){
        char tempBuf[4];
        int temp = read4(&tempBuf);
        int ti = index;
        while(index <  ti + temp){
            buf[index] = tempBuf[index-ti];
            index ++;
        }
        
    }
    if(strlen(buf)> n){
        buf[n] = '\0';
    } 
    return index;
}