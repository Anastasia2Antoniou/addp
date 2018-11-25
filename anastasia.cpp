#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

#define N 50000
using namespace std;

// O(n^2)
bool has_duplicates1(int a[], int n) {
  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      if (a[i] == a[j])
        return true;
    }
  }
  return false;
}

// Ταχύτερος κώδικας από το has_duplicates αλλά πάλι O(n^2)
bool has_duplicates2(int a[], int n) {
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j])
        return true;
    }
  return false;
}

//  O(nlogn)
bool has_duplicates3(int a[], int n) {
  sort(a, a + n); // O(nlogn)
  // O(n)
  for (int i = 0; i < n - 1; i++)
    if (a[i] == a[i + 1])
      return true;
  return false;
}

int main() {
  clock_t t1, t2;
  int a[N];

  // random data
  //   srand(time(NULL));
  //   for (int i = 0; i < N; i++) {
  //     a[i] = rand() % 2000000;
  //   }

  // worst case scenario
  for (int i = 0; i < N; i++) {
    a[i] = i;
  }
  auto rng = default_random_engine{};
  shuffle(a, a + N, rng);

  t1 = clock();
  cout << (has_duplicates1(a, N) ? "YES" : "NO") << endl;
  t2 = clock();
  cout << "Size " << N << ", elapsed time "
       << (double)(t2 - t1) / CLOCKS_PER_SEC << endl;

  t1 = clock();
  cout << (has_duplicates2(a, N) ? "YES" : "NO") << endl;
  t2 = clock();
  cout << "Size " << N << ", elapsed time "
       << (double)(t2 - t1) / CLOCKS_PER_SEC << endl;

  t1 = clock();
  cout << (has_duplicates3(a, N) ? "YES" : "NO") << endl;
  t2 = clock();
  cout << "Size " << N << ", elapsed time "
       << (double)(t2 - t1) / CLOCKS_PER_SEC << endl;
}