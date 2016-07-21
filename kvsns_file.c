#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "kvsns.h"
#include "kvsns_internal.h"
#include "kvsal/kvsal.h"

int kvsns_creat(kvsns_cred_t *cred, kvsns_ino_t *parent, char *name,
		mode_t mode, kvsns_ino_t *newfile)
{
	int rc;

	rc = kvsns_access(cred, parent, KVSNS_ACCESS_WRITE);
	if (rc != 0)
		return rc;

	return kvsns_create_entry(cred, parent, name,
				  mode, newfile, KVSNS_FILE);
}


