/*************************************************************************
	> File Name: haizei/linklist.h
	> Author: 
	> Mail: 
	> Created Time: Thu 18 Jun 2020 07:44:48 PM CST
 ************************************************************************/

#ifndef _HAIZEI_LINKLIST_H
#define _HAIZEI_LINKLIST_H

#define offset(T, name) ((long long)(&(((T *)(0))->name)))

#define Head(p, T, name) ((T *)(((char *)p) - offset(T, name)))

struct LinkNode {
    struct LinkNode *next;  
};

#endif
