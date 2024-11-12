#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sum(int a[], int n){//task 1
    int sum = 0;;
    for(int i = 0;i < n;i++)
        sum += a[i];
    printf("%d \n", sum);
}
int max_ai_pos(int a[], int n){//task 1
    int max = INT64_MIN;
    int max_i = 0;
    for(int i = 0;i < n;i++)
        if(a[i] > max){
            max = a[i];
            max_i = i;
        }
    return max_i;
}
void do_somethingg(int a[], int n){ //task 2
    int i = 0;
    int c = 1;
    int k = 1;
    int n1 = n;
    while(k <= n / 4){
        if(c % 4 == 0){
            for(int j = n1;j > i;j--)
                a[j + 5] = a[j];
            c = 1;
            n1 += 5;
            for(int j = i + 1; j < i + 6;j++)
                a[j] = 0;
            i += 6;
            k++;
        }
        c++;
        i++;
    }
    for(int i = 0;i < (n / 4) * 5 + n;i++)
        printf("%d " "", a[i]);
    puts("");
}
void do_something(int a[], int n){ //task 1
    int p = 1;
    int k = 0;
    for(int i = 0;i < n;i++){
        if(a[i] < 0){
            p *= a[i];
            k++;
        }   
    }
    if(k == 0){
        p = 0;
        puts("THERE ARE NO NEGATIVE NUMBERS IN ARRAY");
    }
    printf("%d \n", p);
}
void rand_in(int a[], int n){
     srand(time(NULL));
     for (int i = 0; i < n; i++) 
        a[i] = rand() % 129 - 35;
}
int int_in(){
    while(1){
            int n;
		    int t = scanf("%d", &n);
		    while(getchar() != '\n'){}
		    if(!t)
			    puts("ERROR Please enter a NUMBER");
		    else {
                return n;
                break;
            }
	}
}
void self_in(int a[], int n){
    puts("PLEASE ENTER DATA IN ARRAY");
    int t, i;
    while(1){
        for(i = 0;i < n;i++){
            t = scanf("%d", &a[i]);
            if(!t){
                puts("ERROR Please enter a NUMBER");
                break;
                }
            }
        if(i == n)
            break;
        else{
            puts("PLEASE REINTER ARRAY DATA FROM BEGINIG");
            while(getchar() != '\n'){}
        }
    }
}
int main(){
    int n, f_r, b, n1, max_i;
    int a[100];
    f_r = -1;
    system("clear");
    while(1){
        puts("PLEASE ENTER '1', IF YOU WANT TO ENTER ARRAY MANUALLY, OR ENTER '0', IF YOU WANT TO ENTER IT RANDOMLY");
        n = int_in();
        if(n == 0 || n == 1)
            break;
    }
    if(n == 0)
        f_r = 1;
    else
        f_r = 0;
    while(1){
        puts("PLEASE ENTER SIZE OF ARRAYS(max size == 100)");
        n = int_in();
        if(n > 100 || n < 0)
            puts("ERROR SIZE OF ARRAY MUST BE <= 100 AND > 0");
        else
            break;
    }
    if(f_r == 1){
        rand_in(a, n);
        puts("YOUR GENERATED ARRAY:");
        for(int i = 0;i < n;i++)
            printf("%d " "", a[i]);
        puts("\n-----------------------------");
        }
    else{
        self_in(a, n);
        puts("YOUR ARRAY:");
        for(int i = 0;i < n;i++)
            printf("%d " "", a[i]);
        puts("\n-----------------------------");
        }
    while(1){
        puts("PLEASE ENTER NUMBER OF TASK(1 or 2)");
        n1 = int_in();
        if(n1 == 1 || n1 == 2)
            break;
    }
    if(n1 == 1){
        do_something(a, n);
        max_i = max_ai_pos(a, n);
        sum(a, max_i);
    }
    else
        do_somethingg(a, n);
    return 0;
}