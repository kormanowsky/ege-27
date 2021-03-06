"""
Идея 2. Полезный индекс. Простой подсчет
"""
"""
Для последовательности из n целых неотрицательных чисел, меньших 1000, 
необходимо определить наиболее часто встречающуюся сумму цифр. 
"""
# Количество чисел
n = int(input())
"""
Сумма цифр числа, меньшего 1000, не может быть больше, чем 9 + 9 + 9 = 27, поэтому 
создаем массив на 28 элементов (индексы от 0 до 27), в котором каждый элемент 
- количество чисел с суммой, равной индексу. 
"""
sum_counts = [0 for _ in range(28)]
for _ in range(n):
    x = int(input())
    # Увеличиваем значение по индексу, равному сумме цифр, на 1
    sum_counts[x % 10 + (x // 10) % 10 + x // 100] += 1
max_sum_index = -1
max_sum_count = -1
for sum_index in range(28):
    # Если бы просили вывести наибольшую сумму из максимальных,
    # здесь нужно было бы поставить >=
    if sum_counts[sum_index] > max_sum_count:
        max_sum_index = sum_index
        max_sum_count = sum_counts[sum_index]
print(max_sum_index)
