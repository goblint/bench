#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

struct list_head {
  struct list_head *next, *prev;
};

struct node {
  int datum;
  struct list_head list;
}; 

struct list_head A, B;

#define offsetof(TYPE, MEMBER) ((unsigned int) &((TYPE *)0)->MEMBER)
#define list_entry(ptr, type, member) (type *)( (char *) ptr - offsetof(type,member) )

static inline void list_add(struct list_head *new,
			      struct list_head *head) {
        struct list_head *prev = head;
        struct list_head *next = head->next;
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_del(struct list_head *l) {
      struct list_head *ln = l->next;
      struct list_head *lp = l->prev;
      ln->prev = lp;
      lp->next = ln;
      l->next = (struct list_head *)((void *)0);
      l->prev = (struct list_head *)((void *)0);
}

static inline void list_move(struct list_head *list, struct list_head *head)
{
	list_del(list);
	list_add(list, head);
}

static inline void INIT_LIST_HEAD(struct list_head *list) {
	list->next = list;
	list->prev = list;
}

pthread_mutex_t mutex_A = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_B = PTHREAD_MUTEX_INITIALIZER;

void *generate(void *arg) {
  int i;
  struct list_head *l, *an;
  struct node *n; 
  for (i=1; i<100; i++) {
    n = malloc(sizeof(struct node));
    INIT_LIST_HEAD(&n->list);
    n->datum = i;
    pthread_mutex_lock(&mutex_A);
    list_add(&n->list, &A); 
    pthread_mutex_unlock(&mutex_A);
    sleep(1);
  }
  return NULL;
}

void *process(void *arg) {
  struct list_head *l, *ln, *lp, *bn;
  while (1) {
    pthread_mutex_lock(&mutex_A);
    // ! empty(&A)
    if (A.next != &A) {
      l = A.next;
      pthread_mutex_lock(&mutex_B);
      list_move(l,&B);
      pthread_mutex_unlock(&mutex_B);
      pthread_mutex_unlock(&mutex_A);
    }
    else
      pthread_mutex_unlock(&mutex_A);
    sleep(2);
  }
  return NULL;
}

void *dispose(void *arg) {
  struct list_head *l;
  struct node *n;
  while (1) {
    pthread_mutex_lock(&mutex_B);
    if (B.next != &B) {
      l = B.next;
      list_del(l);
      pthread_mutex_unlock(&mutex_B);
      n = list_entry(l, struct node, list);
      printf("Data disposed: %d\n", n->datum);
      n->datum *= -1;
    }
    else
      pthread_mutex_unlock(&mutex_B);
    sleep(5);
  }
  return NULL;
}

int main () {
  pthread_t t1, t2, t3;
  int i;
  struct node *n;

  // INIT_LIST_HEAD(&A);
  A.next = &A; A.prev = &A;
  // INIT_LIST_HEAD(&B);
  B.next = &B; B.prev = &B;

  pthread_create(&t1, NULL, generate, NULL);
  pthread_create(&t2, NULL, process, NULL);
  pthread_create(&t3, NULL, dispose, NULL);


  // THE REST IS JUST FOR TESTING 
  
#define list_for_each_entry(pos, head, member)				\
	for (pos = list_entry((head)->next, typeof(*pos), member);	\
	     &pos->member != (head); 	\
	     pos = list_entry(pos->member.next, typeof(*pos), member))
  for (i=0; i<10; i++) {
    pthread_mutex_lock(&mutex_A);
    pthread_mutex_lock(&mutex_B);

    printf("List A: ");
    list_for_each_entry(n, &A, list)
      printf("%d ", n->datum);

    printf("\nList B: ");
    list_for_each_entry(n, &B, list)
      printf("%d ", n->datum);
    printf("\n");

    pthread_mutex_unlock(&mutex_B);
    pthread_mutex_unlock(&mutex_A);
    sleep(3);
  }
  return 0;
}
