#include "spthread.h"
#include <iostream>

using namespace std;

void *func(void *threadarg);
spthread spt (NULL, &func, NULL);
int main(){
	spt.spawn();
	pthread_exit(NULL);
}
void *func(void *threadarg){
	cout << "start_time = "<<spt.get_start_time()<<endl;
	cout << "total_time = "<<spt.get_total_time()<<endl;
}
