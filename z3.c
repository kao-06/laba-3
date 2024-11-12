#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void do_something(int a[], int b[], int n){
    int c[2 * n];
    int i = 0;
    int j = 0;
    int l = 0;
    int f = 0;
    while(l < 2 * n){
        if(i >= n){
            c[l] = b[j];
            j++;
            l++;
            f++;
        }
        if(j >= n){
            c[l] = a[i];
            i++;
            l++;
            f++;
        }
        if(a[i] < b[j] && f == 0){
            c[l] = a[i];
            i++;
            l++;
        }
        else{
            if(f == 0){
                c[l] = b[j];
                j++;
                l++;
            }
        }
    }
    for(i = 0;i < 2 * n;i++)
        printf("%d " "", c[i]);
    puts(""); 
}
void sort(int a[], int n){//gnome sort
    int i = 0;
    int sw;
    while(i < n){
        if(i == 0 || a[i - 1] <= a[i]) 
            i++;
        else{
            sw = a[i - 1];
            a[i - 1] = a[i];
            a[i] = sw;
            i--;
        }

    }
}
void rand_in(int a[], int n){
     srand(clock());
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
    int a[100];
    int b[100];
    int i, j, n, f;
    system("clear");
    while(1){
        puts("PLEASE ENTER SIZE OF ARRAYS(max size == 100)");
        n = int_in();
        if(n > 100 || n < 0)
            puts("ERROR SIZE OF ARRAY MUST BE <= 100 AND > 0");
        else
            break;
    }
    while(1){
        puts("PLEASE ENTER '1', IF YOU WANT TO ENTER ARRAY MANUALLY, OR ENTER '0', IF YOU WANT TO ENTER IT RANDOMLY");
        f = int_in();
        if(f == 0 || f == 1)
            break;
    }
    if(f == 0){
        rand_in(a, n);
        rand_in(b, n);
        puts("YOUR GENERATED ARRAYS:");
        for(int i = 0;i < n;i++)
            printf("%d " "", a[i]);
        puts("\n");
        for(int i = 0;i < n;i++)
            printf("%d " "", b[i]);
        puts("\n-----------------------------");
        sort(a, n);
        sort(b, n);
        puts("YOUR GENERATED SORTED ARRAYS:");
        for(int i = 0;i < n;i++)
        printf("%d " "", a[i]);
        puts("\n");
        for(int i = 0;i < n;i++)
            printf("%d " "", b[i]);
        puts("\n-----------------------------");
    }
    else{
        self_in(a, n);
        self_in(b, n);
        puts("YOUR ARRAYS:");
        for(int i = 0;i < n;i++)
            printf("%d " "", a[i]);
        puts("\n");
        for(int i = 0;i < n;i++)
            printf("%d " "", b[i]);
        puts("\n-----------------------------");
        
    }
    do_something(a, b, n);
    return 0;
}