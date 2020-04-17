#include <iostream>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 2


void doPrimes(void* arg){

  clock_t start = clock();
  int count = 0;
  int n;
  printf("Enter the number: ");
  scanf("%d", &n);
  for(int i = 2; i < n; i++){
    bool prime = true;
    for(int j = 2; j*j <= i; j++){
      if(i % j == 0){
        prime = false;
        break;
      }
    }
    if(prime){
      count++;
      if(count <= 100)
        cout << i << " ";
      else if(count > 348413)
        cout << i << " ";
    }
  }

  clock_t end = clock();
  cout << "\n\nThere are " << count << " primes numbers." << endl;
  cout << "Program took " << (double)(end  - start) / CLOCKS_PER_SEC << "seconds." << endl;

  pthread_exit(NULL);
}

int main(){
  pthread_t threads[NUM_THREADS];
  int rc;
  int i;

  for(i = 0; i < NUM_THREADS; i++){
    rc = pthread_create(&threads[i], NULL, doPrimes, (void *)i);

    if(rc){
      cout << "Error: unable to create thread, " << rc << endl;
      exit(-1);
    }
  } 
  pthread_exit(NULL);
}