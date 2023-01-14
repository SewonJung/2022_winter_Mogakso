# BOJ 2042 - 구간 합 구하기
left index l, right index r이 주어지면 [l, r]의 element의 합을 구하는 문제이다.\
update가 없다면, 누적 합을 관리하는 방식으로 문제를 해결할 수 있지만, update가 주어지기 때문에 segment tree를 사용해야 한다.\
이 때의 segment tree의 구성은 두 child node의 값의 합이 parent node이도록 한다.\
특정 구간의 합을 계산해야 하는 경우, 구간을 분할해가며 parent node들의 합을 통해 값을 계산하게 되며 update를 하는 경우 해당 index의 parent만을 계속 update해주면 된다.
각 경우 시간복잡도는 O(log n)이다.\
BOJ1275, BOJ2268, BOJ12837 등의 문제는 완전히 동일한 방식으로 해결할 수 있다.\
또한, BOJ11505의 경우 곱셈이기 때문에, 구간의 곱을 구하는 경우 분할한 구간이 해당되는 구간이 아닌 경우 곱셈 항등원인 1을 곱하도록 처리하면 같은 방식으로 해결가능하다.

# BOJ 2357 - 최솟값과 최댓값
2042와 마찬가지로 l, r이 주어지면 [l, r]에서의 최댓값과 최솟값을 구하는 문제이다.\
이 역시 segment tree를 통해 쉽게 해결할 수 있다.\
이 때의 segment tree의 구성은 최댓값인 경우 두 child node중 최댓값이 parent node가 되도록 한다.\
특정 구간의 최댓값을 계산해야 하는 경우, 구간을 분할해가며 max를 취해가며 값을 구할 수 있다.

# BOJ 14428 - 수열과 쿼리 16
upd
