#include <stdio.h>

#include "src/thread/threadpool.h"

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

int main(){
    ThreadPool* t = ThreadPool::getInstance();
    std::future<long> fu1 = t->addTask(ddd, 106, 4614, 212);
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

    }, 25000, 444, 111);
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

    }, 56006, 208, 99);
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
    }, 20060, 366, 444);
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

    }, 21504, 754, 100);
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

    }, 201054, 754, 15);
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

    }, 12504, 754, 100);
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

    }, 11054, 1754, 100);
    printf("fu8\n");
  //  std::cin.get();
 //    t->addThread();
//      t->addThread();
//       t->addThread();
    std::cout<<"fu1 "<<fu1.get()<<std::endl;
    std::cout<<"fu2 "<<fu2.get()<<std::endl;
    std::cout<<"fu3 "<<fu3.get()<<std::endl;
    std::cout<<"fu4 "<<fu4.get()<<std::endl;
    std::cout<<"fu5 "<<fu5.get()<<std::endl;
    std::cout<<"fu6 "<<fu6.get()<<std::endl;
    std::cout<<"fu7 "<<fu7.get()<<std::endl;
    std::cout<<"fu8 "<<fu8.get()<<std::endl;
   // printf("%ld\n", global);
    return 0;
}
