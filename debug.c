#include "push_swap.h"
#include <stdio.h>

/* return 1 if 'sentinel' is reachable from 'head' */
static int reachable(t_nlst *head, t_nlst *sentinel)
{
    t_nlst *p = head;
    if (!sentinel) return 1;
    while (p) { if (p == sentinel) return 1; p = p->next; }
    return 0;
}

/* print up to 'limit' nodes from head, mark sentinel position */
static void dump_slice(const char *name, t_nlst *head, t_nlst *sentinel, int limit)
{
    t_nlst *p = head;
    int i = 0;

    fprintf(stderr, "%s: [", name);
    while (p && i < limit && p != sentinel) {
        fprintf(stderr, "%d ", p->n);
        p = p->next;
        i++;
    }
    if (p == sentinel) fprintf(stderr, "|SENT| ");
    while (p && i < limit) { fprintf(stderr, "%d ", p->n); p = p->next; i++; }
    fprintf(stderr, "]\n");
}

void ps_dbg_check(const char *tag, t_stack *a, t_stack *b)
{
#ifdef PS_DEBUG
    int la = get_count(a); if (la == -1) la = 3;
    int lb = get_count(b); if (lb == -1) lb = 3;

    fprintf(stderr, "\n-- %s --\n", tag);
    if (!reachable(a->head, a->p[a->top]))
        fprintf(stderr, "!! A sentinel unreachable\n");
    if (!reachable(b->head, b->p[b->top]))
        fprintf(stderr, "!! B sentinel unreachable\n");
    fprintf(stderr, "A.active_len=%d  B.active_len=%d\n", la, lb);
    dump_slice("A", a->head, a->p[a->top], 20);
    dump_slice("B", b->head, b->p[b->top], 20);
#endif
}

void ps_dbg_triplet_b(const char *tag, t_stack *b)
{
#ifdef PS_DEBUG
    if (b->head && b->head->next && b->head->next->next) {
        int x=b->head->n, y=b->head->next->n, z=b->head->next->next->n;
        fprintf(stderr, "%s: top3 B = [%d %d %d] (want DESC)\n", tag, x,y,z);
    }
#endif
}
