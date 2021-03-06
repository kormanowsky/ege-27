/**
 * Идея 4. Степени двойки
 * В последовательности натуральных чисел, не превосходящих 1000, найти
 * количество пар, сумма элементов в которых делится на m = 87 и элемент с
 * бОльшим индексом больше элемента с меньшим индексом.
 */
#include <cmath>
#include <iostream>
using namespace std;
/**
 * Получает количество единиц в двоичной записи числа n.
 * Источник: geeksforgeeks.org
 * Таблица соответствий чисел от 0 до 15:
 * Десятичное Двоичное Число единиц
 * 0          0        0
 * 1          1        1
 * 2          10       1
 * 3          11       2
 * 4          100      1
 * 5          101      2
 * 6          110      2
 * 7          111      3
 * 8          1000     1
 * 9          1001     2
 * 10         1010     2
 * 11         1011     3
 * 12         1100     2
 * 13         1101     3
 * 14         1110     3
 * 15         1111     4
 * Зная количество единиц для числа из четырех цифр, рекурсивно посчитаем
 * общее количество единиц путем постоянного деления на 16 = 2 ** 4.
 */
int get_bits_count(unsigned long long int n) {
  int number_of_bits[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
  if (n == 0) {
    return 0;
  }
  return number_of_bits[n % 16] + get_bits_count(n / 16);
}

int main() {
  int n, // Количество чисел в последовательности
      m = 87, // Параметр m
      total_count = 0,
      x,  // Текущее число
      r,  // Остаток от деления текущего числа
      pr, // "Парный" с r остаток
      k, // Степень двойки для данного числа (номер степени)
      count_for_x, // Количество элементов, которые можно поставить в пару с x
      idx; // Номер части массива с элементами
  unsigned long long int numbers[m][2], // Массив с элементами.
      p, // Степень двойки для данного числа (2 в степени k)
      gp; // Степень двойки, больше которой нельзя брать числа
  // Инициализация
  cin >> n;
  for (int i = 0; i < m; ++i) {
    numbers[i][0] = 0;
    numbers[i][1] = 0;
  }
  for (int i = 0; i < n; ++i) {
    // Ввод нового элемента
    cin >> x;
    // Сброс счетчика пар, в которые можно поставить текущий элемент
    count_for_x = 0;
    // Вычисление значений
    r = x % m;
    pr = (m - r) % m;
    k = x / m;
    // По умолчанию, выбирается правая часть массива с элементами (биты от 0 до
    // 63)
    idx = 1;
    // Если степень данного числа больше, чем количество бит в одной переменной
    // типа unsigned long long int (64 бит), нужно использовать левую половину
    // массива с элементами
    if (k >= 64) {
      // В левой половине каждый индекс - бит с номером 64+индекс
      k -= 64;
      idx = 0;
      // Все биты правой части автоматически добавляются
      count_for_x += get_bits_count(numbers[pr][1]);
    }
    // Вычисление степени 2
    p = gp = (unsigned long long int)pow(2, k);
    // Если остаток больше парного, нужно взять и число с парным индексом этой
    // же степени
    if (r > pr) {
      gp *= 2;
    }
    // Добавление количества из нужной части массива с элементами
    count_for_x += get_bits_count(numbers[pr][idx] % gp);
    // Запись текущего элемента
    numbers[r][idx] += p;
    // Добавление к общему количеству
    total_count += count_for_x;
  }
  // Вывод ответа
  cout << total_count;
  return 0;
}