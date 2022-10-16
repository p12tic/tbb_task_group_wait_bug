project(tbb_bug)

find_package(TBB)

add_executable(enqueue_defer enqueue_defer)
target_link_libraries(enqueue_defer TBB::tbb)

add_executable(task task.cc)
target_link_libraries(task TBB::tbb)

add_executable(task_in_task task_in_task.cc)
target_link_libraries(task_in_task TBB::tbb)
