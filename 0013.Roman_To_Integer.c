int romanToInt(char * s){
    int l = strlen(s);
    int count[7];
    for(int i = 0; i < 7; i++){
        count[i] = 0;
    }

    for(int i = 0; i < l; i++){
        int index = -1;
        switch (s[i]){
            case 'M':
                index ++;
            case 'D':
                index ++;
            case 'C':
                index ++;
            case 'L':
                index ++;
            case 'X':
                index ++;
            case 'V':
                index ++;
            case 'I':
                index ++;
            default:
                break;
        }

        count[index] ++ ;
    }

    for( int i = 0; i <l-1; i++){
        switch (s[i]){
            case 'I':
                if(s[i+1] == 'V'||s[i+1] == 'X'){
                    count[0]-=2;
                }
                break;
            case 'X':
                if(s[i+1] == 'L'||s[i+1] == 'C'){
                    count[2]-=2;
                }
                break;
            case 'C':
                if(s[i+1] == 'D'||s[i+1] == 'M'){
                    count[4]-=2;
                }
                break;
            
            default:
                break;
        }
    }

    int result = 0;
    for(int i = 0 ; i < 7; i++){
        int m = 0;
        switch (i)
        {
        case 0:
            m = 1;
            break;
        case 1:
            m = 5;
            break;
        case 2:
            m = 10;
            break;
        case 3:
            m = 50;
            break;
        case 4:
            m = 100;
            break;
        case 5:
            m = 500;
            break;
        case 6:
            m = 1000;
            break;

        default:
            break;
        }
        result += m * count[i];
    }


    return result;
}