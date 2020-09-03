#include "threadEx.h"
#include <mutex>


namespace threadEx {

    void func1() {
        for (int i = 0; i < 10; i++) {
            //std::cout << "������ 1 �۵���! \n";
            printf("������ 1 �۵���! %d \n", i);
        }
    }

    void func2() {
        for (int i = 0; i < 10; i++) {
            //std::cout << "������ 2 �۵���! \n";
            printf("������ 2 �۵���! %d \n", i);
        }
    }

    void func3() {
        for (int i = 0; i < 10; i++) {
            //std::cout << "������ 3 �۵���! \n";
            printf("������ 3 �۵���! %d \n", i);
        }
    }

	void test() {
        thread t1(func1);
        thread t2(func2);
        thread t3(func3);

        t1.join();
        t2.join();
        t3.join();
        // �� join�� �� ���������� ���

        //t1.detach();
        //t2.detach();
        //t3.detach();
        // �ϴ� �� ��׶��� �����ϰ� �������� �Ѿ
        // ������ main�� ����Ǹ� �����嵵 �����

        std::cout << "���� �Լ� ���� \n";
	}

    //--------------------------------------------------

    void worker(vector<int>::iterator start, vector<int>::iterator end,
        int* result) {
        int sum = 0;
        for (auto itr = start; itr < end; ++itr) {
            sum += *itr;
        }
        *result = sum;

        // �������� id �� ���Ѵ�.
        thread::id this_id = std::this_thread::get_id();
        printf("������ %x ���� %d ���� %d ���� ����� ��� : %d \n", this_id, *start,
            *(end - 1), sum);
        // cout << �� ���� �����. << ���� ������ �۵��Ǳ� ����
    }

    void test2() {
        vector<int> data(10000);
        for (int i = 0; i < 10000; i++) {
            data[i] = i;
        }

        // �� �����忡�� ���� �κ� �յ��� �����ϴ� ����
        vector<int> partial_sums(4);

        // �����ε� ó��. �ѹ��� ���ֳ�?
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
        std::cout << "��ü �� : " << total << std::endl;
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
        std::mutex m;  // �츮�� mutex ��ü

        // �����ε� ó��. �ѹ��� ���ֳ�?
        //void (* memfunc)(int&, std::mutex&) = &worker;
        auto memfunc = static_cast<void (*)(int&, std::mutex&)>(&worker);

        std::vector<std::thread> workers;
        for (int i = 0; i < 4; i++) {
            workers.push_back(std::thread(memfunc, std::ref(counter), std::ref(m)));

        }

        for (int i = 0; i < 4; i++) {
            workers[i].join();
        }

        std::cout << "Counter ���� �� : " << counter << std::endl;
    }

    void worker0(int& result, std::mutex& m) {
        for (int i = 0; i < 10000; i++) {
            // lock ���� �ÿ� m.lock() �� �����Ѵٰ� ���� �ȴ�.
            std::lock_guard<std::mutex> lock(m);
            result += 1;

            // scope �� ���� ������ lock �� �Ҹ�Ǹ鼭
            // m �� �˾Ƽ� unlock �Ѵ�.
        }
    }

    void testMutex1()
    {

        int counter = 0;
        std::mutex m;  // �츮�� mutex ��ü

        std::vector<std::thread> workers;
        for (int i = 0; i < 4; i++) {
            workers.push_back(std::thread(worker0, std::ref(counter), std::ref(m)));
        }

        for (int i = 0; i < 4; i++) {
            workers[i].join();
        }

        std::cout << "Counter ���� �� : " << counter << std::endl;
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

                // m1 �� �̹� lock �Ǿ� �ִٸ� "�� �� ��" �� �����ϰ� �ȴ�.
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
        std::mutex m1, m2;  // �츮�� mutex ��ü

        std::thread t1(worker1, std::ref(m1), std::ref(m2));
        std::thread t2(worker2, std::ref(m1), std::ref(m2));

        t1.join();
        t2.join();

        std::cout << "��!" << std::endl;
    }










}