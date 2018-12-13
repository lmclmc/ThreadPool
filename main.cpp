#include <stdio.h>
#include <sys/time.h>

#include "threadpool.h"

long ddd(int a, int b, int c){
    long tmp = 0;
    while(1){
        tmp++;
        if (tmp>a*b*c){
            break;
        }
    }
    printf("fu1\n");
    return tmp;
}
#define MAX (100000)
std::atomic<long> ss;
int main(){
	ss = MAX;
	struct timeval s, e;
	gettimeofday(&s, NULL);
	ThreadPool* t = ThreadPool::getInstance();
	for (int i=0; i<12; i++){
		t->addThread();
	}

	for (int i=0; i<MAX; i++){
		t->addTask([](int a, int b, int c){
			long tmp = 0;
			while (1){
				tmp++;
				if (tmp>a*b*c){
					break;
				}
			}
			ss--;
		}, 120, 120, 12);
	}
	while (1){
		ss--;
		if (ss<1) break;	
	}
	gettimeofday(&e, NULL);
	printf("time = %ld\n", (e.tv_sec-s.tv_sec)*1000*1000+e.tv_usec-s.tv_usec);
	pause();
	return 0;
}

#if 0
int main(){
    ThreadPool* t = ThreadPool::getInstance();
    std::future<long> fu1 = t->addTask(ddd, 106, 4614, 2102);
    printf("fu1\n");
    std::future<long> fu2 = t->addTask([](long a, int b, int c){
        volatile long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu2\n");
        return tmp;

    }, 25000, 444, 1101);
    printf("fu2\n");
    std::future<long> fu3 = t->addTask([](long a, int b, int c){
        volatile long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu3\n");
        return tmp;

    }, 56006, 208, 909);
    printf("fu3\n");
    std::future<long> fu4 = t->addTask([](long a, int b, int c){
        volatile long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu4\n");
        return tmp;
    }, 20060, 366, 4404);
    printf("fu4\n");
    std::future<long> fu5 = t->addTask([](long a, int b, int c){
        volatile long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu5\n");
        return tmp;

    }, 21504, 754, 1000);
    printf("fu5\n");

    std::future<long> fu6 = t->addTask([](long a, int b, int c){
        volatile long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu6\n");
        return tmp;

    }, 201054, 754, 105);
    printf("fu6\n");

    std::future<long> fu7 = t->addTask([](long a, int b, int c){
        volatile long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu7\n");
        return tmp;

    }, 12504, 754, 1000);
    printf("fu7\n");

    std::future<long> fu8 = t->addTask([](long a, int b, int c){
        volatile long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu8\n");
        return tmp;

    }, 11054, 1754, 1000);
    printf("fu8\n");

    std::future<long> fu9 = t->addTask([](long a, int b, int c){
        volatile long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu9\n");
        return tmp;

    }, 1054, 1754, 10020);
    printf("fu9\n");

    std::future<long> fu10 = t->addTask([](long a, int b, int c){
        volatile long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu10\n");
        return tmp;

    }, 11054, 754, 1400);
    printf("fu10\n");

    std::future<long> fu11 = t->addTask([](long a, int b, int c){
        volatile long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu11\n");
        return tmp;

    }, 11054, 17524, 100);
    printf("fu11\n");

    std::future<long> fu12 = t->addTask([](long a, int b, int c){
        volatile long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu12\n");
        return tmp;

    }, 110454, 174, 1000);
    printf("fu12\n");

for (int i=0; i<12; i++){
	t->addThread();
}
  //  std::cin.get();
 //    t->addThread();
//      t->addThread();
//       t->addThread();
	t->destoryPool();
#if 0
    std::cout<<"fu1 "<<fu1.get()<<std::endl;
    std::cout<<"fu2 "<<fu2.get()<<std::endl;
    std::cout<<"fu3 "<<fu3.get()<<std::endl;
    std::cout<<"fu4 "<<fu4.get()<<std::endl;
    std::cout<<"fu5 "<<fu5.get()<<std::endl;
    std::cout<<"fu6 "<<fu6.get()<<std::endl;
    std::cout<<"fu7 "<<fu7.get()<<std::endl;
    std::cout<<"fu8 "<<fu8.get()<<std::endl;
    std::cout<<"fu9 "<<fu9.get()<<std::endl;
    std::cout<<"fu10 "<<fu10.get()<<std::endl;
    std::cout<<"fu11 "<<fu11.get()<<std::endl;
    std::cout<<"fu12 "<<fu12.get()<<std::endl;
#endif
   // printf("%ld\n", global);

	pause();
    return 0;
}
#endif
