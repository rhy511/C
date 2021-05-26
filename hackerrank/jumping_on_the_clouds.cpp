int jumpingOnClouds(vector<int> c) {
    int count = 0;
    for(int i = 0; i < c.size() - 1; i++){
       if(c[i + 1]){
           i++;
           count++;
       }else{
           if(!c[i + 2]){
               count++;
               i++;  
           }else{
               count++;
           }
       }
    }
    return count;
}
