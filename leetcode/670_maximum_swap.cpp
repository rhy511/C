class Solution {
public:
    vector<int> element_list;
    void swap(int &a, int &b){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    int findMaxNumber(int size){
        int index = 0, max = 0;
        for(int i = 0; i < size; i++){
            if(element_list[i] > max){
                max = element_list[i];
                index = i;
            }
        }
        return index;
    }
    int maximumSwap(int num) {
        int quotient;   // 商數
        int element, max = 0, index, result;
        int tmp = num;
        // invalid case
        if(!num){
            return NULL;
        }
        // make the element_list
        while(tmp != 0){
            quotient = tmp/10;
            element = tmp - quotient*10;
            element_list.push_back(element);
            tmp = quotient; 
        }
        // only two elements left in the element_list
        if(element_list.size() == 2){
            if(element_list[0] > element_list[1]){
                tmp = element_list[0]*10 + element_list[1];
                return tmp;
            }else{
                swap(element_list[0], element_list[1]);
                tmp = element_list[0]*10 + element_list[1];
                return tmp;
            }
        }  
        //find the max index and swap the number
        index = findMaxNumber(element_list.size());
        if(index == element_list.size()-1 || element_list[index] == element_list[element_list.size()-1]){
            // 最高位數是max
            // 最高位數是max且其他位數也是max(代表還有其他位數可以做替換)
            int range = element_list.size() - 1;
            while(range > 0){
                index = findMaxNumber(range); 
                if(element_list[index] > element_list[range-1]){
                    swap(element_list[index], element_list[range-1]);
                    break;
                }
                range--;
            }    
        }else{
            // 最高位數不是max
            swap(element_list[index], element_list[element_list.size()-1]);
        }
        // form the result number
        for(int i  = 0; i < element_list.size(); i++){
            result += (element_list[i] * pow(10,i)); 
        }
        return result;
    }
};
