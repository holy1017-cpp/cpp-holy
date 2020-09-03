#include "threadEx.h"
#include <mutex>


namespace threadEx {

    void func1() {
        for (int i = 0; i < 10; i++) {
            //std::cout << "쓰레드 1 작동중! \n";
            printf("쓰레드 1 작동중! %d \n", i);
        }
    }

    void func2() {
        for (int i = 0; i < 10; i++) {
            //std::cout << "쓰레드 2 작동중! \n";
            printf("쓰레드 2 작동중! %d \n", i);
        }
    }

    void func3() {
        for (int i = 0; i < 10; i++) {
            //std::cout << "쓰레드 3 작동중! \n";
            printf("쓰레드 3 작동중! %d \n", i);
        }
    }

	void test() {
        thread t1(func1);
        thread t2(func2);
        thread t3(func3);

        t1.join();
        t2.join();
        t3.join();
        // 위 join이 다 끝날때까지 대기

        //t1.detach();
        //t2.detach();
        //t3.detach();
        // 일단 다 백그라운드 실행하고 다음으로 넘어감
        // 하지만 main이 종료되면 스레드도 종료됨

        std::cout << "메인 함수 종료 \n";
	}

    //--------------------------------------------------

    void worker(vector<int>::iterator start, vector<int>::iterator end,
        int* result) {
        int sum = 0;
        for (auto itr = start; itr < end; ++itr) {
            sum += *itr;
        }
        *result = sum;

        // 쓰레드의 id 를 구한다.
        thread::id this_id = std::this_thread::get_id();
        printf("쓰레드 %x 에서 %d 부터 %d 까지 계산한 결과 : %d \n", this_id, *start,
            *(end - 1), sum);
        // cout << 는 쓰기 어려움. << 마다 로직이 작동되기 때문
    }

    void test2() {
        vector<int> data(10000);
        for (int i = 0; i < 10000; i++) {
            data[i] = i;
        }

        // 각 쓰레드에서 계산된 부분 합들을 저장하는 벡터
        vector<int> partial_sums(4);

        // 오버로드 처리. 한번에 못넣나?
        void (* memfunc)(vector<int>::iterator start, vector<int>::iterator end,
            int* result) = &worker;
        //auto memfunc = static_cast<void (*)(int&, std::mutex&)>(&worker);

        vector<thread> workers;
        for (int i = 0; i < 4; i++) {
            workers.push_back(thread(memfunc, data.begin() + i * 2500,
                data.begin() + (i + 1) * 2500, &partial_sums[i]));
        }

        for (int i = 0; i < 4; i++) {
            workers[i].join();
        }

        int total = 0;
        for (int i = 0; i < 4; i++) {
            total += partial_sums[i];
        }
        std::cout << "전체 합 : " << total << std::endl;
    }

    void worker(int& result, std::mutex& m) {
        for (int i = 0; i < 10000; i++) {
            m.lock();
            result += 1;
            m.unlock();
        }
    }

    void worker() {
    }

    void testMutex()
    {

        int counter = 0;
        std::mutex m;  // 우리의 mutex 객체

        // 오버로드 처리. 한번에 못넣나?
        //void (* memfunc)(int&, std::mutex&) = &worker;
        auto memfunc = static_cast<void (*)(int&, std::mutex&)>(&worker);

        std::vector<std::thread> workers;
        for (int i = 0; i < 4; i++) {
            workers.push_back(std::thread(memfunc, std::ref(counter), std::ref(m)));

        }

        for (int i = 0; i < 4; i++) {
            workers[i].join();
        }

        std::cout << "Counter 최종 값 : " << counter << std::endl;
    }

    void worker0(int& result, std::mutex& m) {
        for (int i = 0; i < 10000; i++) {
            // lock 생성 시에 m.lock() 을 실행한다고 보면 된다.
            std::lock_guard<std::mutex> lock(m);
            result += 1;

            // scope 를 빠져 나가면 lock 이 소멸되면서
            // m 을 알아서 unlock 한다.
        }
    }

    void testMutex1()
    {

        int counter = 0;
        std::mutex m;  // 우리의 mutex 객체

        std::vector<std::thread> workers;
        for (int i = 0; i < 4; i++) {
            workers.push_back(std::thread(worker0, std::ref(counter), std::ref(m)));
        }

        for (int i = 0; i < 4; i++) {
            workers[i].join();
        }

        std::cout << "Counter 최종 값 : " << counter << std::endl;
    }

    void worker1(std::mutex& m1, std::mutex& m2) {
        for (int i = 0; i < 10; i++) {
            m1.lock();
            m2.lock();
            std::cout << "Worker1 Hi! " << i << std::endl;

            m2.unlock();
            m1.unlock();
        }
    }

    void worker2(std::mutex& m1, std::mutex& m2) {
        for (int i = 0; i < 10; i++) {
            while (true) {
                m2.lock();

                // m1 이 이미 lock 되어 있다면 "야 차 빼" 를 수행하게 된다.
                if (!m1.try_lock()) {
                    m2.unlock();
                    continue;
                }

                std::cout << "Worker2 Hi! " << i << std::endl;
                m1.unlock();
                m2.unlock();
                break;
            }
        }
    }

    void testMutex2()
    {
        std::mutex m1, m2;  // 우리의 mutex 객체

        std::thread t1(worker1, std::ref(m1), std::ref(m2));
        std::thread t2(worker2, std::ref(m1), std::ref(m2));

        t1.join();
        t2.join();

        std::cout << "끝!" << std::endl;
    }










}