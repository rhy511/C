long repeatedString(string s, long n) {
    if(s == "a")
        return n;
    int s_length = 0;
    long count = 0;
    for(char c : s){
        s_length++;
        if(c == 'a')
            count++;
    }
    int remainder = n % s_length;
    int r_count = 0;
    for(char c : s){
        if(!remainder)
            break;
        if(c == 'a')
          r_count++;
        remainder--;
    }
    count = count * (n / s_length) + r_count;
    return count;
}
