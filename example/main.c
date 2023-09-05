#include <stdio.h>
#include <pthread.h>

// Paylaşılan değişken
int shared_variable = 0;

// Mutex tanımlama
pthread_mutex_t mutex;

// İlk iş parçacığı için fonksiyon
void *thread_function1(void *arg) {
    for (int i = 0; i < 10000; i++) {
        // Mutex kilidi al
        pthread_mutex_lock(&mutex);

        // Paylaşılan değişkeni güncelle
        shared_variable++;

        // Mutex kilidini serbest bırak
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// İkinci iş parçacığı için fonksiyon
void *thread_function2(void *arg) {
    for (int i = 0; i < 10000; i++) {
        // Mutex kilidi al
        pthread_mutex_lock(&mutex);

        // Paylaşılan değişkeni güncelle
        shared_variable--;

        // Mutex kilidini serbest bırak
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    // Mutex başlatma
    pthread_mutex_init(&mutex, NULL);

    // İş parçacıkları oluşturma
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_function1, NULL);
    pthread_create(&thread2, NULL, thread_function2, NULL);

    // İş parçacıklarının bitmesini beklemek
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Mutex'i yok etme
    pthread_mutex_destroy(&mutex);

    // Paylaşılan değişkenin son değerini yazdırma
    printf("Son paylaşılan değişken değeri: %d\n", shared_variable);

    return 0;
}
