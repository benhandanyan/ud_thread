/*
 * types used by thread library
 */
#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include <sys/mman.h>

/**
 * Our thread control block
 */
struct tcb {
	int thread_id;
	int thread_priority;
	ucontext_t *thread_context;
	struct tcb *next;
};

typedef struct tcb tcb;

typedef struct {
  int count;
  tcb *q;
  tcb *q_end;
} sem_t;

typedef struct mboxnode {
  char       *message;
  int         length;
  int         sender;
  int         receiver;
  struct mboxnode *next;
} mboxnode;

typedef struct {
  struct mboxnode *first;
  struct mboxnode *last;
  sem_t *mutex;
} mbox;
