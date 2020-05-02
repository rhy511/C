#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

//  靜態初始化
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

int i = 0;


void* thread1(void *arg){
	for (;;){
		printf("thread1 loop...\n");
		pthread_mutex_lock(&mutex1);
		printf("thread1 wait cond...\n");
                //  等待條件變量的特殊情形
		pthread_cond_wait(&cond1, &mutex1);
		printf("thread1 work...%d\n", i);
		pthread_mutex_unlock(&mutex1);
		if (i >= 100)
			break;
	}
	pthread_exit(NULL);
	return NULL;
}
void* thread2(void *arg){
	_sleep(1);

	while (++i <= 100){
		printf("thread2 loop...\n");

		if (i % 10 == 0){
			pthread_mutex_lock(&mutex1);
			pthread_cond_signal(&cond1);
			pthread_mutex_unlock(&mutex1);
			_sleep(1);
		}
	}
	printf("thread2 exit\n");
	pthread_exit(NULL);
	return NULL;
}

int main(){
	pthread_t ntid1;
	pthread_t ntid2;

	pthread_create(&ntid1, NULL, thread1, NULL);
	pthread_create(&ntid2, NULL, thread2, NULL);

	//  阻塞當前的執行緒，直到另外一個執行緒運行結束
	pthread_join(ntid1, NULL);
	pthread_join(ntid2, NULL);

	pthread_mutex_destroy(&mutex1);
	pthread_cond_destroy(&cond1);
	printf("Finish ! \n");

	system("pause");
	return EXIT_SUCCESS;
}