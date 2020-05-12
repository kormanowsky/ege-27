"""
Идея 3. Два массива. Сумма делится на m
"""
"""
В последовательности натуральных чисел, состоящей из n членов, 
найти пару элементов, сумма элементов в паре делится на m = 80 
и минимальна. Если в последовательности несколько пар с одинаковой 
минимальной суммой, вывести любую. Если пар, удовлетворяющих 
условию задачи, в последовательности нет, вывести два нуля. 
"""
n = int(input())
m = 80
# Инициализация двух половин
left_half = [0 for _ in range(m // 2 + 1)]
right_half = [0 for _ in range(m // 2 + 1)]
for _ in range(n):
    x = int(input())
    r = x % m
    # Особая проверка для r = 0 и r = 40
    if r == 0 or r == m // 2:
        if left_half[r] == 0 or x < left_half[r]:
            left_half[r] = x
        elif right_half[r] == 0 or x < left_half[r]:
            right_half[r] = x
    elif 1 <= r <= m // 2 - 1:
        if left_half[r] == 0 or x < left_half[r]:
            left_half[r] = x
    elif right_half[m - r] == 0 or x < right_half[m - r]:
        right_half[m - r] = x
# В a и b будет ответ
a = b = 0
for i in range(m // 2 + 1):
    # Проверяем, что оба элемнета есть в последовательности
    if left_half[i] != 0 and right_half[i] != 0:
        # Проверяем, что сумма минимальна
        if (a == 0 and b == 0) or left_half[i] + right_half[i] < a + b:
            a = left_half[i]
            b = right_half[i]
# Пара была найдена, если ни один элемент в паре не равен 0
if a != 0 and b != 0:
    print(a, b)
else:
    print(0, 0)
