# Segment tree with lazy propagation
Segment tree의 경우, 1개의 값을 1회 업데이트하는 것에 O(log n)의 time complexity가 요구된다.
이때 만약, 어떤 interval의 값들을 전부 a라는 숫자를 더하거나 빼라는 식의 update를 해야하는 경우가 생긴다면, 최악의 경우 O(nlog n)이라는 time complexity가 요구되고 이는 naive하게 array로 다루었을 시 O(log n)이 드는 것보다 비효율적이다.
이를 효율적으로 수행하기 위하여, update query를 수행하는 경우에 해당 node가 update하는 interval에 모두 포함되는 경우 child node를 update하지 않고, lazy라는 array에 값을 저장해두어, 나중에 필요한 경우 update를 하는 방식을 Segment tree with lazy propagation이라고 한다.
