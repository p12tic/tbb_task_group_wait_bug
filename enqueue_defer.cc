
#include <tbb/task_arena.h>
#include <tbb/task_group.h>
#include <iostream>
#include <thread>

int main()
{
    tbb::task_arena ta;
    tbb::task_group b;

    {
        tbb::task_group a;
        ta.enqueue(a.defer([]()
        {
            std::cout << "A1 start" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "A1 end" << std::endl;
        }));

        ta.enqueue(b.defer([]()
        {
            std::cout << "B1 start" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(4));
            std::cout << "B1 end" << std::endl;
        }));

        a.wait();

        ta.enqueue(b.defer([]()
        {
            std::cout << "B2 start" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(4));
            std::cout << "B2 end" << std::endl;
        }));
    }
    b.wait();
}
