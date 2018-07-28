#include <stdio.h>

#include "src/thread/threadpool.h"

int main(){
    ThreadPool* t = ThreadPool::getInstance();
    std::future<long> fu1 = t->addTask([](long a, int b, int c){
        long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu1\n");
        return tmp;
    }, 10600, 4614, 2122);
    printf("fu1\n");
    std::future<long> fu2 = t->addTask([](long a, int b, int c){
        long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu2\n");
        return tmp;

    }, 2500, 4444, 1111);
    printf("fu2\n");
    std::future<long> fu3 = t->addTask([](long a, int b, int c){
        long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu3\n");
        return tmp;

    }, 56006, 7008, 909);
    printf("fu3\n");
    std::future<long> fu4 = t->addTask([](long a, int b, int c){
        long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu4\n");
        return tmp;
    }, 20600, 6666, 4444);
    printf("fu4\n");
    std::future<long> fu5 = t->addTask([](long a, int b, int c){
        long tmp = 0;
        while(1){
            tmp++;
            if (tmp>a*b*c){
                break;
            }
        }
        printf("fu5\n");
        return tmp;

    }, 21054, 7254, 1000);
    printf("fu5\n");
    std::cin.get();
    t->addThread();
     t->addThread();
      t->addThread();
       t->addThread();
    std::cout<<"fu1 "<<fu1.get()<<std::endl;
    std::cout<<"fu2 "<<fu2.get()<<std::endl;
    std::cout<<"fu3 "<<fu3.get()<<std::endl;
    std::cout<<"fu4 "<<fu4.get()<<std::endl;
    std::cout<<"fu5 "<<fu5.get()<<std::endl;

    return 0;
}
