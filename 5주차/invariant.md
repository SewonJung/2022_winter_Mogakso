링크의 영상을 참조하였다.\
https://www.youtube.com/watch?v=4wyhvjQQ1Rw
# 
어떤 원형의 array가 주어진다. 이 array에서 아래의 연산을 무한정 반복할 수 있다.

"하나의 element를 골라 그 element 및 그 element와 adjacent한 원소 하나를 골라 +1을 하는 연산을 한다."

이때, 모든 수를 같게 할 수 있는가를 묻는 문제이다.

우선, 영상에서 나온 것 처럼 array의 size가 짝수라면 alternating sum이 invariant라는 점을 이용하여 alternating sum이 0이라면 같게 만들 수 있음을 알 수 있다.
그러나, array의 size가 홀수라면 원형을 이루고 있다는 특성 때문에 단순히 1회 alternating sum을 구하는 방식으로는 확정지을 수 없다. 예컨대, array의 size가 5일 때 1 0 1 0 0라는 array가 주어지게 되면,
alternating sum은 2가 되나, 실제로는 연산을 거듭하다보면 모든 수를 2로 같게 만들 수 있다. 그렇다면 어떻게 이러한 문제를 처리할 수 있을까?

슬라이딩 윈도우 기법을 사용하면 쉽게 해결할 수 있다.
array가 원의 형태를 띄고 있다는 점을 이용하여 1 0 1 0 0 1 0 1 0 0 으로 늘어뜨릴 수 있다. 이후의 해결 방법은 기존 array의 size만큼씩 앞에서부터 alternating sum을 구해보면서 그 값이 0이 되는 순간이 있는지를 확인해보면 된다.
이때, 0이 되는 순간이 존재한다면 이 array는 모든 수를 같게 만들 수 있는 array인 것이다. 이를 코드로 나타내면 아래와 같다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v) cin >> i;
  bool chk = false;
  if (n & 1){
    for (int i = 0; i < n; i++) v.push_back(v[i]);
    int ret = 0;
    for (int i = 0; i < n; i++){
      if (i & 1) ret += v[i];
      else ret -= v[i];
    }
    for (int i = 0; i < n; i++){
      chk |= ret == 0;
      if (i & 1) ret -= v[i]*2;
      else ret += v[i]*2;
    }
  }
  else{
    int ret = 0;
    for (int i = 0; i < n; i++){
      if (i & 1) ret += v[i];
      else ret -= v[i];
    }
    chk = ret == 0;
  }
  cout << (chk ? "Yes" : "No");
}
```
시간복잡도는 array의 size가 n일 때, O(n)이다.\
1 0 1 0 0 0에 대해서 제대로 No를, 1 0 1 0 0에 대해서 제대로 Yes를 출력하는 것을 확인할 수 있다.

invariant를 이용하여 특정한 state에 도달가능한 지를 체크하는 문제는 아이디어를 떠올리기 쉽지 않기에 항상 염두에 두어야 한다. 가장 자주 쓰이는 것은 permutation에서의 parity이다. permutation에서 n회 섞었을 때 나올 수 있는 조합 등을 체크하는 등 활용방법이 매우 많다. 또한, 이런 식으로 원형을 이루는 array에서 해당 array를 복사해서 늘어뜨려 놓는 테크닉도 생각보다 자주 쓰이는 테크닉이다.
