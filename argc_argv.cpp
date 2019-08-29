#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	// argc: argument count(參數總和)
    // argv: argument value(參數值)
	cout << "There is " << argc << " arguments" << endl;
	for(int i = 0; i < argc; i++){
		cout << "["<< i <<"]"<< argv[i] << endl;
	}
	// test getenv(請求環境變量值)
	char *p;
	if((p = getenv("USER"))){
		printf("USER = %s\n", p);
		printf("PATH : %s\n", getenv("PATH"));
		printf("HOME : %s\n", getenv("HOME"));
		printf("ROOT : %s\n", getenv("ROOT"));	
	}
	
	return 0;
}

