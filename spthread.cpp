#include <string>
#include <sys/time.h>
#include <sys/resource.h>
#include <iostream>
#include <chrono>
#include "spthread.h"
#include <pthread.h>

using namespace std;

spthread::spthread(const pthread_attr_t *attr, void *(*start)(void *), void *arg){
	attributes = attr;
	func = start;
	args = arg;
	cout << "thread args stored\n";
}
int spthread::spawn(){
	start_time = std::chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now().time_since_epoch()).count();
	cout << "thread created \n";
	return pthread_create(&thread, attributes, func, args);
}
long long spthread::get_start_time(){
	return start_time;
}
long long spthread::get_total_time(){
	long long current_time = std::chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now().time_since_epoch()).count();
	return (current_time - start_time);
}
rusage spthread::get_cpu_time(){
	
}
long long spthread::get_blocked_time(){

}

