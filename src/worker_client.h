/*****************************************************************************
 *
 * mod_gearman.c - distribute checks with gearman
 *
 * Copyright (c) 2010 Sven Nierlein
 *
 *****************************************************************************/

#include <libgearman/gearman.h>

typedef enum {
    GM_WORKER_OPTIONS_NONE=   0,
    GM_WORKER_OPTIONS_DATA=   ( 1 << 0 ),
    GM_WORKER_OPTIONS_STATUS= ( 1 << 1 ),
    GM_WORKER_OPTIONS_UNIQUE= ( 1 << 2 )
} gm_worker_options_t;

typedef struct {
    int id;
} worker_parm;

void *client_worker();
void *get_job( gearman_job_st *, void *, size_t *, gearman_return_t * );
static int create_gearman_worker( gearman_worker_st *);