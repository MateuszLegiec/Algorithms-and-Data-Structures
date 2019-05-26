#include <iostream>

using namespace std;

void quickSort(int tab[], int left, int right) {

      int low = left, high = right;
      int temp;
      int mid = tab[(left + right) / 2];

      while (low <= high) {

            while (tab[low] < mid)
                  low++;

            while (tab[high] > mid)
                  high--;

            if (low <= high) {
                  temp = tab[low];
                  tab[low] = tab[high];
                  tab[high] = temp;
                  low++;
                  high--;
            }
      };

      if (left < high)
            quickSort(tab, left, high);

      if (low < right)
            quickSort(tab, low, right);
}
