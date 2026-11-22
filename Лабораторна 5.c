#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define MAX 100

void print_array(double a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%.15g ", a[i]);
    puts("");
}

int main(void)
{
    int task, n;
    double a[MAX + 1];
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    puts("Лабораторна робота №5");
    puts("1 — №102, 2 — №109, 3 — №128, 4 — №165, 5 — №16, 6 — №107");
    printf("Виберіть завдання: ");
    if (scanf("%d", &task) != 1 || task < 1 || task > 6)
        return 1;

    printf("Кількість елементів (1–100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX)
        return 1;

    puts(task == 4 ? "Введіть тиск за кожен день (740–780):" : "Введіть елементи масиву:");
    for (int i = 0; i < n; i++) {
        if (task == 1 || task == 6) {
            int value;
            if (scanf("%d", &value) != 1)
                return 1;
            a[i] = value;
        } else if (scanf("%lf", &a[i]) != 1) {
            return 1;
        }
        if (task == 4 && (a[i] < 740 || a[i] > 780)) {
            puts("Тиск має бути від 740 до 780.");
            return 1;
        }
    }

    switch (task) {
    case 1: {
        int i = 0;
        while (i < n && (int)a[i] % 6 == 0)
            i++;
        if (i == n) {
            puts("Елементи видалення не знайдені.");
            break;
        }
        for (; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
        break;
    }
    case 2: {
        int k;
        double max = a[0];
        printf("Місце вставки (1–%d): ", n + 1);
        if (scanf("%d", &k) != 1 || k < 1 || k > n + 1)
            return 1;
        for (int i = 1; i < n; i++)
            if (a[i] > max)
                max = a[i];
        for (int i = n; i >= k; i--)
            a[i] = a[i - 1];
        a[k - 1] = max;
        n++;
        break;
    }
    case 3: {
        int max = 0;
        double replacement;
        printf("Число для заміни першого максимуму: ");
        if (scanf("%lf", &replacement) != 1)
            return 1;
        for (int i = 1; i < n; i++)
            if (a[i] > a[max])
                max = i;
        a[max] = replacement;
        break;
    }
    case 4: {
        int min = 0, max = 0, count = 0;
        double sum = 0, d;
        printf("Поріг d: ");
        if (scanf("%lf", &d) != 1)
            return 1;

        printf("Початковий масив: ");
        print_array(a, n);
        for (int i = 0; i < n; i++) {
            if (a[i] < a[min]) min = i;
            if (a[i] > a[max]) max = i;
            if (a[i] > d) count++;
            sum += a[i];
        }
        printf("Мінімум: %g (день %d)\n", a[min], min + 1);
        printf("Максимум: %g (день %d)\n", a[max], max + 1);
        printf("Середнє: %g\nДнів з тиском вище %g: %d\n", sum / n, d, count);
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (a[j] > a[j + 1]) {
                    double temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        printf("Впорядкований масив: ");
        print_array(a, n);
        return 0;
    }
    case 5: {
        double x, y;
        printf("Введіть числа a і b: ");
        if (scanf("%lf %lf", &x, &y) != 2)
            return 1;
        printf("а) ");
        for (int i = 0; i < n; i++) printf("%g ", a[i] * 2);
        printf("\nб) ");
        for (int i = 0; i < n; i++) printf("%g ", a[i] - x);
        printf("\nв) ");
        if (a[0] == 0)
            printf("Ділити на нуль не можна.");
        else
            for (int i = 0; i < n; i++) printf("%g ", a[i] / a[0]);
        printf("\nг) ");
        for (int i = 0; i < n; i++) printf("%g ", a[i] - 20);
        printf("\nд) ");
        for (int i = 0; i < n; i++) printf("%g ", a[i] * a[n - 1]);
        printf("\nе) ");
        for (int i = 0; i < n; i++) printf("%g ", a[i] + y);
        puts("");
        return 0;
    }
    case 6: {
        int value;
        if (n < 9) {
            puts("Для вставки на 10-те місце потрібно щонайменше 9 елементів.");
            return 1;
        }
        printf("Число для вставки: ");
        if (scanf("%d", &value) != 1)
            return 1;
        for (int i = n; i >= 10; i--)
            a[i] = a[i - 1];
        a[9] = value;
        n++;
        break;
    }
    }

    printf("Результат: ");
    print_array(a, n);
    return 0;
}
