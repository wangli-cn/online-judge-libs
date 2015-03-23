#define atomic_xadd(P, V) __sync_fetch_and_add((P), (V))
#define cmpxchg(P, O, N) __sync_val_compare_and_swap((P), (O), (N))
#define atomic_inc(P) __sync_add_and_fetch((P), 1)
#define atomic_dec(P) __sync_add_and_fetch((P), -1)
#define atomic_add(P, V) __sync_add_and_fetch((P), (V))
#define atomic_set_bit(P, V) __sync_or_and_fetch((P), 1<<(V))
#define atomic_clear_bit(P, V) __sync_and_and_fetch((P), ~(1<<(V)))

/* Compile read-write barrier */
#define barrier() asm volatile("": : :"memory")

/* Pause instruction to prevent excess processor bus usage */
#define cpu_relax() asm volatile("pause\n": : :"memory")

/* Atomic exchange (of various sizes) */
static inline void *xchg_64(void *ptr, void *x)
{
    __asm__ __volatile__("xchgq %0,%1"
            :"=r" ((unsigned long long) x)
            :"m" (*(volatile long long *)ptr), "0" ((unsigned long long) x)
            :"memory");

    return x;
}

static inline unsigned xchg_32(void *ptr, unsigned x)
{
    __asm__ __volatile__("xchgl %0,%1"
            :"=r" ((unsigned) x)
            :"m" (*(volatile unsigned *)ptr), "0" (x)
            :"memory");

    return x;
}

static inline unsigned short xchg_16(void *ptr, unsigned short x)
{
    __asm__ __volatile__("xchgw %0,%1"
            :"=r" ((unsigned short) x)
            :"m" (*(volatile unsigned short *)ptr), "0" (x)
            :"memory");

    return x;
}

/* Test and set a bit */
static inline char atomic_bitsetandtest(void *ptr, int x)
{
    char out;
    __asm__ __volatile__("lock; bts %2,%1\n"
            "sbb %0,%0\n"
            :"=r" (out), "=m" (*(volatile long long *)ptr)
            :"Ir" (x)
            :"memory");

    return out;
}


#define EBUSY 1
typedef unsigned spinlock;

static void spin_lock(spinlock *lock)
{
    while (1)
    {
        if (!xchg_32(lock, EBUSY)) return;

        while (*lock) cpu_relax();
    }
}

static void spin_unlock(spinlock *lock)
{
    barrier();
    *lock = 0;
}

static int spin_trylock(spinlock *lock)
{
    return xchg_32(lock, EBUSY);
}


typedef struct dumbrwlock dumbrwlock;
struct dumbrwlock
{
    spinlock lock;
    unsigned readers;
};

static void dumb_wrlock(dumbrwlock *l)
{
    /* Get write lock */
    spin_lock(&l->lock);

    /* Wait for readers to finish */
    while (l->readers) cpu_relax();
}

static void dumb_wrunlock(dumbrwlock *l)
{
    spin_unlock(&l->lock);
}

static int dumb_wrtrylock(dumbrwlock *l)
{
    /* Want no readers */
    if (l->readers) return EBUSY;

    /* Try to get write lock */
    if (spin_trylock(&l->lock)) return EBUSY;

    if (l->readers)
    {
        /* Oops, a reader started */
        spin_unlock(&l->lock);
        return EBUSY;
    }

    /* Success! */
    return 0;
}

static void dumb_rdlock(dumbrwlock *l)
{
    while (1)
    {
        /* Speculatively take read lock */
        atomic_inc(&l->readers);

        /* Success? */
        if (!l->lock) return;

        /* Failure - undo, and wait until we can try again */
        atomic_dec(&l->readers);
        while (l->lock) cpu_relax();
    }
}

static void dumb_rdunlock(dumbrwlock *l)
{
    atomic_dec(&l->readers);
}

static int dumb_rdtrylock(dumbrwlock *l)
{
    /* Speculatively take read lock */
    atomic_inc(&l->readers);

    /* Success? */
    if (!l->lock) return 0;

    /* Failure - undo */
    atomic_dec(&l->readers);

    return EBUSY;
}

static int dumb_rdupgradelock(dumbrwlock *l)
{
    /* Try to convert into a write lock */
    if (spin_trylock(&l->lock)) return EBUSY;

    /* I'm no longer a reader */
    atomic_dec(&l->readers);

    /* Wait for all other readers to finish */
    while (l->readers) cpu_relax();

    return 0;
}

int main()
{
    return 0;
}
