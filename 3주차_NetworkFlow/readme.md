# Network Flow
우선 network flow는 주로 directed graph에서 행해진다.\
Graph G = (V, E)에 대해 Edge (u, v)가 capacity c(u, v) >= 0을 가진다.\
또한 특별한 두 정점 Source, Sink(or Target)을 가지고 이를 s, t로 표기한다.

flow in G f : V * V -> R에 대해 아래의 성질이 성립한다.
1. ∀u, v∈V에 대해, 0 ≤ f(u, v) ≤ c(u,v)이어야 한다. (Capacity constraint)\
즉, 모든 network의 edge들에 대해 flow의 값은 그 edge의 capacity보다 작거나 같아야 하며, 음의 값을 가질 수는 없다.
2. ∀u∈V-{s,t} 에 대해, Σf(u,v) = Σf(v,u)이다.\
즉, s와 t를 제외한 모든 vertex에 대해 vertex로 들어오는 flow의 양은 vertex에서 나가는 flow의 양과 같아야 한다.


이제, 어떤 network의 flow의 크기를 |f|라고 하면, |f| = Σf(s,v) - Σf(v,s)이다.\
즉, source로 들어오는 flow의 양과 나가는 flow의 양만을 보면 그 network의 flow의 크기를 알 수 있다.

maximum flow problem이란, 어떤 graph G가 주어지면 G에서 |f|가 최대인 flow를 찾는 문제이다.

한편, flow에서의 Cut(S, T)는 아래와 같이 정의한다.\
G를 S와 T = V - S로 나누는 행동이다. 이때 S는 source vertex를 포함해야하며, T는 target vertex를 포함해야 한다.\
network flow of Cut(S, T), f(S, T) = ΣΣ f(u, v) - ΣΣ f(v, u) (u in S, v in T)로 정의된다.\
또한, Capacity of Cut(S, T) c(S, T) = ΣΣ c(u, v)로 정의된다.

minimum cut problem이란, 어떤 graph G가 주어지면 G의 cut중 최소의 flow 값을 찾는 문제이다.

# Max-Flow Min-Cut Thm
https://en.wikipedia.org/wiki/Max-flow_min-cut_theorem \
|Maximum flow| = |Mimumum cut|임이 알려져 있다.\
즉, G에서 maximum flow의 값을 찾는다면, minimum cut의 값도 알 수 있다.
또한 이는 후술할, Ford - Fulkerson Algorithm을 validate한다.

# Ford - Fulkerson Algorithm

그렇다면, 어떤 graph G에서 Maximum Flow를 어떻게 찾을 것인가?\
이에 대하여 여러가지 풀이가 있지만 우선, Ford - Fulkerson Algorithm에 대하여 먼저 알아보자.\
알고리즘의 동작 원리는 다음과 같다.\
1. 모든 edge의 flow를 0으로 두고 시작한다.
2. "dfs"를 이용해 s -> t의 추가 유량을 보낼 수 있는 경로 augmenting path를 찾아 flow을 증가시키는 것을 반복한다. 각 간선의 capacity에서 flow를 뺀 residual capacity를 이용하여, path를 찾고, 구한 path에서 가장 작은 residual capacity만큼 flow를 증가시킨다.
3. augmenting path를 찾을 수 없다면 종료한다.\

이렇게 구현하게 되면, path를 어떻게 선택하냐에 따라서 maximum flow가 아니지만, augmenting path가 존재하지 않는 경우가 존재한다.\
이는 reverse edge를 도입하여 해결할 수 있다. 실제로는 이동할 수 없는 방향이지만, 이 방향으로 flow를 추가한다는 것은, 원래의 flow를 감소시키는 것과 동일하기 때문이다.

한편, Ford - Fulkerson Algorithm에서 dfs를 사용하게 되어 생기는 문제가 존재하는데,
![image](https://user-images.githubusercontent.com/94056835/216622750-f8c1a625-57cd-48a1-a643-6b4afff9957a.png) \
위와 같은 그래프에서 dfs로 탐색을 하게 되면, 굉장히 비효율적인 탐색을 하게 된다.\
이를 해결하기 위해 2번의 augmenting path를 찾는 과정을 bfs를 이용한 것이 Edmonds - Karp Algorithm이다.\
