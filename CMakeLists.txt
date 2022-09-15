cmake_minimum_required(VERSION 3.17)
project(learnC)

set(CMAKE_CXX_STANDARD 14)

add_executable(learnC SequenceList/main.cpp )
add_executable(first SequenceList/method.cpp )

add_executable(main LinkList/main.cpp)
add_executable(LinkNode LinkList/LinkNode.cpp)


add_executable(DoubleMain DoubleLinkNode/DoubleMain.cpp)
add_executable(Double DoubleLinkNode/Double.cpp)

add_executable(Add LinkAdd/Add.cpp)
add_executable(LinkAddMain LinkAdd/LinkAddMain.cpp)
add_executable(Stack Stack/ArrayStack/Stack.cpp)
add_executable(StackApp Stack/ArrayStack/StackApp.cpp)
add_executable(NodeStack Stack/LinkNodeStack/NodeStack.cpp)

add_executable(QueueApp Queue/CircleQueue/ArrayQueue/QueueApp.cpp)
add_executable(CircleArrayQueue Queue/CircleQueue/ArrayQueue/CircleArrayQueue.cpp)
add_executable(migong Stack/migong/migong.cpp)
add_executable(strand strand/strand.cpp)
add_executable(countMaxSubstring strand/countMaxSubstring.cpp)
add_executable(hanoi Hanoi/hanoi.cpp)
add_executable(pathcount pathcount/pathcount.cpp)
add_executable(generalizedTable generalizedTable/generalizedTable.cpp)
add_executable(saddle.main Saddlepoint/saddle.main.cpp)
add_executable(sanddlepoint Saddlepoint/sanddlepoint.cpp)
add_executable(8queen 8queen/8queen.cpp)




add_executable(beishu lanqiao/beishu.cpp)
add_executable(test acwing/test.cpp)
add_executable(segment lanqiao/segment.cpp)
add_executable(prime lanqiao/prime.cpp)
add_executable(findme acwing/findme.cpp)


add_executable(cover acwing/cover.cpp)
add_executable(layervisit acwing/layervisit.cpp)
