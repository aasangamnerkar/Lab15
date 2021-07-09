#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>

os_thread_t thread1;
os_thread_t thread2;
os_thread_t thread3;

int counter = 0;

void myThread1(void *args) {
  while (1) { // we must NEVER return from this function / thread
    double iSecret = rand() % 10 + 1;
    String output = "Thread 1: ";
    output += (String) iSecret;
    Serial.println(output);
    delay(1000);
  }
}

void myThread2(void *args) {
  while (1) { // we must NEVER return from this function / thread
    counter += 1;
    String output = "Thread 2: ";
    output += (String) counter;
    Serial.println(output);
    delay(500);
  }
}

void myThread3(void *args) {
  while (1) { // we must NEVER return from this function / thread
    digitalWrite(D2, HIGH);
    delay(125);
    digitalWrite(D2, LOW);
    delay(125);
    
  }
}

//WITH_LOCK(Serial) {
//   // your serial port code code here
//}


void setup() {
  pinMode(D2, OUTPUT);
	os_thread_create(&thread1, "anyName", OS_THREAD_PRIORITY_DEFAULT, myThread1, NULL, 1024);
  os_thread_create(&thread2, "anyName", OS_THREAD_PRIORITY_DEFAULT, myThread2, NULL, 1024);
  os_thread_create(&thread3, "anyName", OS_THREAD_PRIORITY_DEFAULT, myThread3, NULL, 1024);
  //os_mutex_create(&mutex);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

}