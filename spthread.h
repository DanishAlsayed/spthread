#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

class spthread{
	public:
		pthread_t thread;
		spthread();
		spthread(const pthread_attr_t *attr, void *(*start)(void *), void *arg);
		int spawn();
		long long get_start_time();
		long long get_total_time();
		rusage get_cpu_time();
		long long get_blocked_time();
	private:
		const pthread_attr_t *attributes;
		void *args;
		void *(*func)(void *);
		long long start_time;
};
//spthread &operator=(const spthread &rhs);
