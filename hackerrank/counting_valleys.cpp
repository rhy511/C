int countingValleys(int steps, string path) {
    int count = 0;
    int pre_height = 0; 
    int height = 0;
    for(int i = 0;i < steps; i++){
        if(path[i] == 'U')
            height++;
        else
            height--;
        if(pre_height == -1 && height == 0)
            count++;
        pre_height = height;
    }
    return count;
}
